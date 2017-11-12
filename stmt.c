#include "stmt.h"
extern int typecheck_result;

struct stmt * stmt_create( stmt_kind_t kind, struct decl *d, struct expr *init_expr, struct expr *e, struct expr *next_expr, struct stmt *body, struct stmt *else_body ){
	struct stmt *s = malloc(sizeof(*s));
	s->kind = kind;
	s->decl = d;
	s->init_expr = init_expr;
	s->expr = e;
	s->next_expr = next_expr;
	s->body = body;
	s->else_body = else_body;
	return s;
}

void stmt_print(struct stmt *s, int indent){
	if (s->decl){
	   decl_print(s->decl, indent);
	} else {
		int i;
		for (i = 0; i < indent; i++) printf("\t");

		switch(s->kind){
			case STMT_EXPR:
				expr_print(s->expr);
				printf(";\n");
				break;

			case STMT_IF_ELSE:
				printf("if (");
				expr_print(s->expr);
				printf(")\n");
				stmt_print(s->body, indent);
				if (s->else_body){
					printf(" else {\n");
					stmt_print(s->else_body, indent + 1);
					printf("}");
				}
				printf("\n");
				break;

			case STMT_FOR:
				printf("for (");
				if (s->init_expr) expr_print(s->init_expr);
				printf(";");
				if (s->expr) expr_print(s->expr);
				printf(";");
				if (s->next_expr) expr_print(s->next_expr);
				printf(")\n");
				for (i = 0; i < indent; i++) printf("\t");
				printf("{\n");
				stmt_print(s->body, indent + 1);
				for (i = 0; i < indent; i++) printf("\t");
				printf("}\n");
				break;

			case STMT_PRINT:
				printf("print ");
				expr_print(s->expr);
				printf(";\n");
				break;

			case STMT_RETURN:
				printf("return");
				if (s->expr){
					printf(" ");
					expr_print(s->expr);
				}
				printf(";\n");
				break;

			case STMT_BLOCK:
				printf("{\n");
				stmt_print(s->body, indent + 1);
				for (i = 0; i < indent; i++) printf("\t");
				printf("}\n");
				break;
			default:
				break;
		}
	}
	if (s->next) stmt_print(s->next, indent);
}

void stmt_resolve( struct stmt *s){
	if (s){
		if (s->kind == STMT_BLOCK)
			scope_enter();
		decl_resolve(s->decl);
		expr_resolve(s->init_expr);
		expr_resolve(s->expr);
		expr_resolve(s->next_expr);
		stmt_resolve(s->body);
		stmt_resolve(s->else_body);
		if (s->kind == STMT_BLOCK){
			scope_exit();
		}
		stmt_resolve(s->next);
	}
}

void stmt_typecheck( struct stmt *s )
{
	if (!s) return;
	struct type *t;
	struct expr *e;
	if (s->body)
		s->body->expect_return = s->expect_return;
	if (s->next)
		s->next->expect_return = s->expect_return;
	if (s->else_body)
		s->else_body->expect_return = s->expect_return;
	switch(s->kind) {
		case STMT_EXPR:
			t = expr_typecheck(s->expr);
			type_delete(t);
			break;
		case STMT_IF_ELSE:
			t = expr_typecheck(s->expr);
			if(t->kind!=TYPE_BOOLEAN) {
				printf("type error: expecting boolean in if statement conditional, got ");
				type_print(t);
				printf(" (");
				expr_print(s->expr);
				printf(")\n");
				typecheck_result = 0;
			}
			type_delete(t);
			stmt_typecheck(s->body);
			stmt_typecheck(s->else_body);
			break;
		case STMT_DECL:
			decl_typecheck(s->decl);
			break;
		case STMT_FOR:
			t = expr_typecheck(s->init_expr);
			type_delete(t);
			t = expr_typecheck(s->expr);
			if (t->kind != TYPE_BOOLEAN){
				printf("type error: expecting boolean in for loop conditional, got ");
				type_print(t);
				printf(" (");
				expr_print(s->expr);
				printf(")\n");
				typecheck_result = 0;
			}
			t = expr_typecheck(s->next_expr);
			type_delete(t);
			stmt_typecheck(s->body);
			break;
		case STMT_PRINT:
			e = s->expr;
			while (e){
				t = expr_typecheck(e->left);
				switch (t->kind){
					case TYPE_FUNCTION:
						printf("type error: cannot print function %s\n", e->left->name);
						typecheck_result = 0;
						break;
					case TYPE_ARRAY:
						printf("type error: cannot print array %s\n", e->left->name);
						typecheck_result = 0;
						break;
					case TYPE_VOID:
						printf("type error: cannot print void\n");
						typecheck_result = 0;
						break;
					default:
						break;
				}
				e = e->right;
			}
			break;
		case STMT_RETURN:
			t = expr_typecheck(s->expr);
			if (!type_equals(t, type_copy(s->expect_return))){
				printf("type error: expected return of type ");
				type_print(s->expect_return);
				printf(" but instead got ");
				type_print(expr_typecheck(s->expr));
				printf(" (");
				expr_print(s->expr);
				printf(")\n");
				typecheck_result = 0;
			}
			break;
		case STMT_BLOCK:
			stmt_typecheck(s->body);
			break;
		default:
			break;
	}
	stmt_typecheck(s->next);
}
