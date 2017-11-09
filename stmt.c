#include "stmt.h"

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
				for (i = 0; i < indent; i++) printf("\t");
				printf("{\n");
				stmt_print(s->body, indent + 1);
				for (i = 0; i < indent; i++) printf("\t");
				printf("}");
				if (s->else_body){
					printf(" else {\n");
					stmt_print(s->else_body, indent + 1);
					for (i = 0; i < indent; i++) printf("\t");
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
				stmt_print(s->body, indent + 1);
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
		stmt_resolve(s->next);
		if (s->kind == STMT_BLOCK)
			scope_exit();
	}
}

void stmt_typecheck( struct stmt *s )
{
	struct type *t;
	struct expr *e;
	struct expr *et;
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
			}
			t = expr_typecheck(s->next_expr);
			type_delete(t);
			stmt_typecheck(s->body);
			break;
		case STMT_PRINT:
			e = s->expr;
			while (e && e->left){
				if (e->left)
					et = e->left;
				else
					et = e;
				t = expr_typecheck(et);
				switch (t->kind){
					case TYPE_FUNCTION:
						printf("type error: cannot print function %s\n", et->name);
						break;
					case TYPE_ARRAY:
						printf("type error: cannot print array %s\n", et->name);
						break;
					case TYPE_VOID:
						printf("type error: cannot print void\n");
						break;
					default:
						break;
				}
				e = e->right;
			}
			break;
		case STMT_RETURN:
			break;
		case STMT_BLOCK:
			stmt_typecheck(s->body);
			break;
		default:
			break;
	}
}
