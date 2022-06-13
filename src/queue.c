#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
	return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc) {
	/* TODO: put a new process to queue [q] */
	if (q->size < MAX_QUEUE_SIZE) {
		q->proc[q->size] = proc;
		q->size += 1;
	}
	return;
}

struct pcb_t *dequeue(struct queue_t *q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size != 0) {
		struct pcb_t *temp_proc = NULL;
		int max_pri = 0;
		int max_idx = 0;
		for (int i = 0; i < q->size; i++) {
			if (q->proc[i]->priority > max_pri) {
				temp_proc = q->proc[i];
				max_pri = temp_proc->priority;
				max_idx = i;
			}
		}
		for (int j = max_idx; j < q->size - 1; j++) {
			q->proc[j] = q->proc[j + 1];
		}
		q->proc[q->size - 1] = NULL;
		q->size--;
		return temp_proc;
	}
	return NULL;
}
