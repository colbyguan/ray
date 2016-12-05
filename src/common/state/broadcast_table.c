#include "broadcast_table.h"
#include "redis.h"

void broadcast_table_lookup(db_handle *db_handle,
                         object_id object_id,
                         retry_info *retry,
                         broadcast_table_peek_done_callback done_callback,
                         void *user_context) {
  init_table_callback(db_handle, object_id, __func__, NULL, retry,
                      done_callback, redis_broadcast_table_peek, user_context);
}

void broadcast_table_add(db_handle *db_handle,
                      object_id object_id,
                      retry_info *retry,
                      object_table_done_callback done_callback,
                      void *user_context) {
  init_table_callback(db_handle, object_id, __func__, NULL, retry,
                      done_callback, redis_broadcast_table_add, user_context);
}

void broadcast_table_decr(db_handle *db_handle,
                      object_id object_id,
                      retry_info *retry,
                      object_table_done_callback done_callback,
                      void *user_context) {
  init_table_callback(db_handle, object_id, __func__, NULL, retry,
                      done_callback, redis_broadcast_table_decr, user_context);
}