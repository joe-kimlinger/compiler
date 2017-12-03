#ifndef SCRATCH_H
#define SCRATCH_H

struct scratch_set{
	struct scratch_set *next;
	int scratches[7];
};

int scratch_alloc();
struct scratch_set *scratch_create(struct scratch_set *n);
void scratch_push();
void scratch_pop();
void scratch_free( int r );
const char * scratch_name( int r );

#endif
