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
