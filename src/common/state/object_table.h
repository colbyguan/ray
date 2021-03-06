#ifndef OBJECT_TABLE_H
#define OBJECT_TABLE_H

#include "common.h"
#include "table.h"
#include "db.h"
#include "task.h"

/*
 *  ==== Lookup call and callback ====
 */

/* Callback called when the lookup completes. The callback should free
 * the manager_vector array, but NOT the strings they are pointing to.
 */
typedef void (*object_table_lookup_done_callback)(
    object_id object_id,
    int manager_count,
    OWNER const char *manager_vector[],
    void *user_context);

/**
 *  Return the list of nodes storing object_id in their plasma stores.
 *
 *  @param db_handle Handle to object_table database.
 *  @param object_id ID of the object being looked up.
 *  @param retry Information about retrying the request to the database.
 *  @param done_callback Function to be called when database returns result.
 *  @param user_context Context passed by the caller.
 *  @return Void.
 */
void object_table_lookup(db_handle *db_handle,
                         object_id object_id,
                         retry_info *retry,
                         object_table_lookup_done_callback done_callback,
                         void *user_context);

/*
 *  ==== Add object call and callback ====
 */

/* Callback called when the object add/remove operation completes. */
typedef void (*object_table_done_callback)(object_id object_id,
                                           void *user_context);

/**
 * Add the plasma manager that created the db_handle to the
 * list of plasma managers that have the object_id.
 *
 * @param db_handle Handle to db.
 * @param object_id Object unique identifier.
 * @param retry Information about retrying the request to the database.
 * @param done_callback Callback to be called when lookup completes.
 * @param user_context User context to be passed in the callbacks.
 * @return Void.
 */
void object_table_add(db_handle *db_handle,
                      object_id object_id,
                      retry_info *retry,
                      object_table_done_callback done_callback,
                      void *user_context);

/*
 *  ==== Remove object call and callback ====
 */

/**
 * Object remove function.
 *
 * @param db_handle Handle to db.
 * @param object_id Object unique identifier.
 * @param retry Information about retrying the request to the database.
 * @param done_callback Callback to be called when lookup completes.
 * @param user_context User context to be passed in the callbacks.
 * @return Void.
 */
/*
void object_table_remove(db_handle *db,
                         object_id object_id,
                         lookup_callback callback,
                         void *context);
                         retry_info *retry,
                         object_table_done_callback done_callback,
                         void *user_context);
*/

/*
 *  ==== Subscribe to be announced when new object available ====
 */

/* Callback called when object object_id is available. */
typedef void (*object_table_object_available_callback)(object_id object_id,
                                                       void *user_context);

/**
 * Subcribing to new object available function.
 *
 * @param db_handle Handle to db.
 * @param object_id Object unique identifier.
 * @param object_available_callback callback to be called when new object
 * becomes
 *        available.
 * @param subscribe_context caller context which will be passed back in the
 *        object_available_callback.
 * @param retry Information about retrying the request to the database.
 * @param done_callback Callback to be called when subscription is installed.
 * @param user_context User context to be passed in the callbacks.
 * @return Void.
 */

void object_table_subscribe(
    db_handle *db,
    object_id object_id,
    object_table_object_available_callback object_available_callback,
    void *subscribe_context,
    retry_info *retry,
    object_table_done_callback done_callback,
    void *user_context);

/* Data that is needed to register new object available callbacks with the state
 * database. */
typedef struct {
  object_table_object_available_callback object_available_callback;
  void *subscribe_context;
} object_table_subscribe_data;

/*
 *  ==== Result table ====
 */

/**
 * Callback called when the add/remove operation for a result table entry
 * completes. */
typedef void (*result_table_done_callback)(object_id object_id,
                                           void *user_context);

/**
 * Add information about a new object to the object table. This
 * is immutable information like the ID of the task that
 * created the object.
 *
 * @param db_handle Handle to object_table database.
 * @param object_id ID of the object to add.
 * @param task_id ID of the task that creates this object.
 * @param retry Information about retrying the request to the database.
 * @param done_callback Function to be called when database returns result.
 * @param user_context Context passed by the caller.
 * @return Void.
 */
void result_table_add(db_handle *db_handle,
                      object_id object_id,
                      task_id task_id,
                      retry_info *retry,
                      result_table_done_callback done_callback,
                      void *user_context);

/** Callback called when the result table lookup completes. */
typedef void (*result_table_lookup_callback)(object_id object_id,
                                             task *task,
                                             void *user_context);

/**
 * Lookup the task that created an object in the result table.
 *
 * @param db_handle Handle to object_table database.
 * @param object_id ID of the object to lookup.
 * @param retry Information about retrying the request to the database.
 * @param done_callback Function to be called when database returns result.
 * @param user_context Context passed by the caller.
 * @return Void.
 */
void result_table_lookup(db_handle *db_handle,
                         object_id object_id,
                         retry_info *retry,
                         result_table_lookup_callback done_callback,
                         void *user_context);

#endif /* OBJECT_TABLE_H */
