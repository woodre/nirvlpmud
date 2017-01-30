/*
 *  global/server/memory
 */

#pragma strong_types  // Coogan, 24-Aug-2001
#pragma no_shadow     // Coogan, 26-Mar-2011

#include "memory.h"

/* static memory, when this object is destructed */
#define SMEM "/global/server/static_mem"

/* memory access permissions */
#define MAP_READ  1             /* may read the variable */
#define MAP_WRITE 2             /* may change the variable */
#define MAP_CHMOD 4             /* may change its access mode */

#define ERROR error
#define NULL null

inherit "basic/create";

string *error = ({ "ERROR" });  /* unique error code */
string *null = ({ "NULL" });    /* make an initialized 0 different from 0 */

mapping mem = ([]);             /* internal memory */
mapping modes = ([]);           /* access modes */


void create() {
  mixed tmp;

  if (tmp = (mixed)SMEM->export_memory()) {
    mem = tmp[0];
    modes = tmp[1];
  }
}

void notify_destruct() {
  SMEM->import_memory(({ mem, modes }));
}

static mixed set_key(mapping m, string *key, mixed value) {
  mixed node;
  int t;

  for (t = 0; t < sizeof(key) - 1; t++) {
    node = m[key[t]];

    if (!node)
      node = m[key[t]] = ([]);
    else if (!mappingp(node))
      return ERROR;
  }
  m[key[t]] = value ? value : NULL;
  return 0;  // Coogan, 26-Mar-2011
}

static mixed query_key(mapping m, string *key) {
  mixed node;
  int t;

  for (t = 0; t < sizeof(key) - 1; t++) {
    node = m[key[t]];
    if (!mappingp (node))
      return ERROR;
  }
  if (!(node = m[key[t]]))
    return ERROR;
  return node == NULL ? 0 : node;
}

int verify_access(string *key, object who) {
  mixed mode;

  mode = query_key(modes, key);

  if (mode != ERROR) {  /* access control mode is set */
    if (pointerp(mode)) {
      switch (mode[0]) {
      case AM_PATH:    /* access for objects with this path */
        if (mode[1] == implode(explode(object_name(who), "/") [0..<2], "/"))
          return MAP_READ | MAP_WRITE | MAP_CHMOD;
        break;
      case AM_WIZ: /* access for objects made by this wiz */
        if (mode[1] == explode(object_name(who), "/") [1])
          return MAP_READ | MAP_WRITE | MAP_CHMOD;
        break;
      case AM_ACCESS_LIST: /* access for files from this list */
        break;
      case AM_CAPABILITY: /* access for clients which have the magic number */
        break;      
      }
    }
    else if (intp(mode)) {
    }
    else if (stringp(mode)) {
        if (mode == object_name(who))
          return MAP_READ | MAP_WRITE | MAP_CHMOD;
        else
          return MAP_READ;
    }
    return 0;
  }
  return MAP_READ | MAP_WRITE | MAP_CHMOD;
}

int set_mode(string *key, mixed access) {
  if (!(verify_access(key, previous_object()) & MAP_CHMOD))
    return 1;
  set_key(modes, key, access);
  return 0;  // Coogan, 27-Mar-2011: should be a return set_key()
             // but set_key() is still of type mixed
}

varargs int set_memory(string *key, mixed value) {
  if (!(verify_access(key, previous_object()) & MAP_WRITE))
    return 1;
  set_key(mem, key, value);
  return 0;  // Coogan, 27-Mar-201: should be a return set_key()
             // but set_key() is still of type mixed1
}

varargs mixed query_memory(string *key, mixed fail) {
  mixed value; 

  if (!(verify_access(key, previous_object()) & MAP_READ))
    return fail;
  value = query_key(mem, key);
  return value == ERROR ? fail : value;
}

