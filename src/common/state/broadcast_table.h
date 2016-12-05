#ifndef BROADCAST_TABLE_H 
#define BROADCAST_TABLE_H 

#include "common.h"
#include "table.h"
#include "db.h"
#include "task.h"

typedef void (*broadcast_table_peek_done_callback)(
    object_id object_id,
    int manager_count,
    OWNER const char *manager_vector[],
    void *user_context);

void broadcast_table_lookup(db_handle *db_handle,
                          object_id object_id,
                          retry_info *retry,
                          broadcast_table_peek_done_callback done_callback,
                          void *user_context);

typedef void (*broadcast_table_done_callback)(object_id object_id,
                                           void *user_context);

void broadcast_table_add(db_handle *db_handle,
                         object_id object_id,
                         retry_info *retry,
                         broadcast_table_done_callback done_callback,
                         void *user_context);

void broadcast_table_decr(db_handle *db_handle,
                          object_id object_id,
                          retry_info *retry,
                          broadcast_table_done_callback done_callback,
                          void *user_context);

#endif /* OBJECT_TABLE_H */
