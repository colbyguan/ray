#include "task.h"
#include "task_table.h"

#include "global_scheduler_algorithm.h"

/** The part of the global scheduler state that is maintained by the scheduling
 *  algorithm. */
struct scheduling_algorithm_state {
};

scheduling_algorithm_state *make_scheduling_algorithm_state(void) {
  scheduling_algorithm_state *state =
      malloc(sizeof(scheduling_algorithm_state));
  return state;
}

void free_scheduling_algorithm_state(scheduling_algorithm_state *s) {
  free(s);
}

void handle_task_waiting(task *original_task, void *user_context) {
  global_scheduler_state *state = (global_scheduler_state *) user_context;
  printf("XXX: WOOHOOOO!!!!!\n");
  assign_task_to_local_scheduler(state, original_task, NIL_ID);
}

void handle_object_available(object_id obj_id) {
  /* Do nothing for now. */
}

void handle_object_unavailable(object_id obj_id) {
  /* Do nothing for now. */
}

void handle_local_scheduler_heartbeat(void) {
  /* Do nothing for now. */
}

void handle_new_local_scheduler(void) {
  /* Do nothing for now. */
}
