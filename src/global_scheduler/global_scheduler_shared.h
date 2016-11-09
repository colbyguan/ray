#ifndef GLOBAL_SCHEDULER_SHARED_H
#define GLOBAL_SCHEDULER_SHARED_H

#include "task.h"

#include "utarray.h"

/** Contains all information that is associated with a local scheduler. */
typedef struct {
  /** The ID of the local scheduler in Redis. */
  int id;
} local_scheduler;

typedef struct scheduling_algorithm_state scheduling_algorithm_state;

typedef struct {
  /** The global scheduler event loop. */
  event_loop *loop;
  /** The global state store database. */
  db_handle *db;
  /** The local schedulers that are connected to Redis. */
  UT_array *local_schedulers;
  /** The state managed by the scheduling algorithm. */
  scheduling_algorithm_state *scheduling_algorithm_state;
} global_scheduler_state;

void assign_task_to_local_scheduler(global_scheduler_state *state,
                                    task *original_task,
                                    node_id node_id);

#endif /* GLOBAL_SCHEDULER_SHARED_H */
