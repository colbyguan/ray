#ifndef GLOBAL_SCHEDULER_ALGORITHM_H
#define GLOBAL_SCHEDULER_ALGORITHM_H

#include "common.h"
#include "global_scheduler_shared.h"
#include "task.h"

/* ==== The scheduling algorithm ====
 *
 * This file contains declaration for all functions and data structures
 * that need to be provided if you want to implement a new algorithms
 * for the global scheduler.
 *
 */

/** Internal state of the scheduling algorithm. */
typedef struct scheduling_algorithm_state scheduling_algorithm_state;

/**
 * Initialize the scheduler state.
 *
 * @return Internal state of the scheduling algorithm.
 */
scheduling_algorithm_state *make_scheduling_algorithm_state(void);

void free_scheduling_algorithm_state(scheduling_algorithm_state *s);

void handle_task_waiting(task *task, void *user_context);

void handle_object_available(object_id obj_id);

void handle_object_unavailable(object_id obj_id);

void handle_local_scheduler_heartbeat(void);

void handle_new_local_scheduler(void);

#endif /* GLOBAL_SCHEDULER_ALGORITHM_H */
