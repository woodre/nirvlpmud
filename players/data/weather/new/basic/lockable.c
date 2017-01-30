/****************************************************************************
  /basic/lockable.c (C) by Ugh written Nov-1994 for Tubmud
****************************************************************************/

// messages simplified using the message system, Coogan, 14-Feb-1998
// made all events of width 2; Coogan, 26-Mar-1998

#include <describe.h>
#include <event.h>
#include <message.h>
#include <prop/item.h>

#define NO_KEY         -1
#define CANCEL_PRIO    300
#define FAIL(who,mess) with_player(who,#'notify_fail,({mess,1}))

inherit "basic/lock";
inherit "basic/handle";

private mixed unlock_text, 
              lock_text, 
              no_lock_found_text,
              no_key_to_lock_text,
              no_key_to_unlock_text,
              key_not_right_text,
              already_unlocked_text,
              already_locked_text,
              is_locked_text,
              is_still_open_text,
              default_locked;

private mixed key_test_function;
private mixed lock_code; // for default_key_test_function()
private mixed lockable = 1;
private mixed pickable = 1;
private status lockable_without_key;

private object search_key(object who);
private varargs status test_key(object key, status lockpicks_allowed);

varargs mixed query_unlock_text(object key,mapping args);
varargs mixed query_lock_text(object key,mapping args);
varargs mixed query_no_lock_found_text(mapping args);
varargs mixed query_no_key_to_lock_text(mapping args);
varargs mixed query_no_key_to_unlock_text(mapping args);
varargs mixed query_key_not_right_text(object key,mapping args);
varargs mixed query_already_unlocked_text(mapping args);
varargs mixed query_already_locked_text(mapping args);
varargs mixed query_is_locked_text(mapping args);
varargs mixed query_is_still_open_text(mapping args);

void set_unlock_text(mixed text);
void set_lock_text(mixed text);

void set_lockable(mixed is_lockable);
void set_pickable(mixed is_pickable);
void set_lockable_without_key(status is_lockable_without_key);

status query_lockable();
status query_lockable_without_key();
varargs status query_pickable(object lockpick);

void set_lock_code(mixed code); 
mixed query_lock_code();

string query_lock_state_description() {
  return query_lock() ? "locked" : "unlocked";
}

void set_default_locked(mixed l) {  // Coogan, 01-Dec-2001
  default_locked = l;
}

status query_default_locked() {
  return funcall(default_locked);
}

void set_lockable(mixed s) {
  lockable = s;
}

status query_lockable() {
  return funcall(lockable);
}

void set_lockable_without_key(status s) {
  lockable_without_key = s;
}

status query_lockable_without_key() {
  return lockable_without_key;
}

void set_pickable(mixed s) {
  pickable = s;
}

varargs status query_pickable(object lockpick) {
  if (closurep(pickable))
    return funcall(pickable,lockpick);
  return pickable;
}

void refresh() {  // Coogan, 01-Dec-2001
  handle::refresh();
  if (query_default_locked()) {
    close();
    lock();
  } else {
    unlock();
  }
}

void create() {
  handle::create();
  listen_event("lock",   CANCEL_PRIO);
  listen_event("unlock", CANCEL_PRIO);
}

void receive_event(mapping event, string type, int prio) {
  if (this_object() != event[E_TARGET])
    return;
  if (prio == CANCEL_PRIO)
    switch (type)
    {
    case "lock":
    case "unlock":
      if (event[E_KEY])
        break;
      event[E_KEY] = search_key(event[E_AGENT]) || NO_KEY;
      if (objectp(event[E_KEY]))
        event[E_KEY, 1] = describe(event[E_KEY], ARTICLE_NONE);
      break;
    }
  handle::receive_event(event,type,prio);
}

status do_open(mapping action) {
  object who;

  if (!action)
    action = ([ E_AGENT : this_player(); this_player()->query_name(),
                E_TARGET: this_object(); describe(this_object(),ARTICLE_NONE)]);
  who = action[E_AGENT];
  if (query_lock()) {
    if (who)
      FAIL(who,query_is_locked_text(action));
    return 0;
  } else {
    return handle::do_open(action);
  }
}

status do_lock(mapping action) {
  mixed key;
  object who;

  if (!action)
    action = ([ E_AGENT : this_player(); this_player()->query_name(),
                E_TARGET: this_object(); describe(this_object(),ARTICLE_NONE)]);
  who = action[E_AGENT];
  key = action[E_KEY];
  if (key == NO_KEY)
    key = 0;
  if (query_open()) {
    if (who)
      FAIL(who,query_is_still_open_text(action));
    return 0;
  } else if (!query_lockable()) {
    if (who)
      FAIL(who,query_no_lock_found_text(action));
    return 0;
  } else if (query_lock()) {
    if (who)
      FAIL(who,query_already_locked_text(action));
    return 0;
  } else {
    if (!query_lockable_without_key()) {
      if (!key) {
        if (who)
          FAIL(who,query_no_key_to_lock_text(action));
        return 0;
      } else if (!test_key(key, member(action,E_TOOL))) {  // E_TOOL added,
        if (who)                                        // Coogan, 12-Jan-2001
          FAIL(who, query_key_not_right_text(key,action));
        return 0;
      }
    }
    message(query_lock_text(key,action),who);
    lock();
    return 1;
  }
}

status do_unlock(mapping action) {
  mixed key;
  object who;

  if (!action)
    action = ([ E_AGENT : this_player(); this_player()->query_name(),
                E_TARGET: this_object(); describe(this_object(),ARTICLE_NONE)]);
  who = action[E_AGENT];
  key = action[E_KEY];
  if (key == NO_KEY)
    key = 0;
  if (!query_lockable()) {  // moved this to here, Coogan, 21-Nov-2001
    if (who)
      FAIL(who,query_no_lock_found_text(action));
    return 0;
  }
  if (!query_lock()) {
    if (who)
      FAIL(who,query_already_unlocked_text(action));
    return 0;
  }
  if (!query_lockable_without_key()) {
    if (!key) {
      if (who)
        FAIL(who,query_no_key_to_unlock_text(action));
      return 0;
    } else if(!test_key(key, member(action, E_TOOL))) {  // E_TOOL added,
      if (who)                                          // Coogan, 12-Jan-2001
        FAIL(who,query_key_not_right_text(key,action));
      return 0;
    }
  }
  message(query_unlock_text(key,action),who);
  unlock();
  return 1;
}

int apply_action(string action, int level, mixed arg) {
  if (!mappingp(arg))
    return 0;
  if (this_object() != arg[E_TARGET])
    return 0;
  switch (action) {
  case "open":
  case "close":
    return handle::apply_action(action, level, arg);
  case "unlock":
    return do_unlock(arg);
  case "lock":
    return do_lock(arg);
  case "pick lock":  // added this, Coogan, 11-Jan-2001
    if (query_lock())
      return do_unlock(arg);
    return do_lock(arg);
  }
  return 0;  // Coogan, 26-Mar-2011
}

private object search_key(object who) {
  object *keys, *keyrings;
  int i;
#if 0  // Coogan, 07-Mar-1998; this should prevent something like
       // 'You unlock the door with the key of your second bag.'
  keys = deep_inventory(who);
#else
  keys = all_inventory(who);
  // added next if() and for(), Coogan, 06-Jul-1999
  if (sizeof(keyrings = filter_objects(keys, "id", "keyring")))
    for (i = sizeof(keyrings); i-->0; )
      keys += all_inventory(keyrings[i]);
#endif
  for (i = sizeof(keys); i--; ) {
    int kkk;
    kkk = with_player(who, #'test_key, keys[<i+1]);
    if (kkk)
      return keys[<i+1];
  }
  return 0;  // Coogan, 26-Mar-2011
}

varargs void set_key_test_function(mixed func, object handler) {
  if (stringp (func)) {
    if (handler) 
      key_test_function = symbol_function(func, handler);
    else
      key_test_function = symbol_function(func) || 
                          symbol_function(func, previous_object());
  }
  else if (closurep (func)) 
      key_test_function = func;
}

private varargs status test_key(object key, status lockpick_allowed) {
  if (!accessible(key,this_player()))
    return 0;
  if (lockpick_allowed    &&
      query_pickable(key) &&
      key->query_property(P_PICKLOCK)) 
    return 1;
  if (key_test_function)
    return funcall(key_test_function, key, this_object());
}

void set_unlock_text(mixed text) {
  unlock_text = text;
}

varargs mixed query_unlock_text(object key, mapping args) {
  if (closurep(unlock_text))
    return funcall(unlock_text,key,this_object(),args);
  else
    return unlock_text ||
           ({({ M_PL_THE, M_PL_VERB, "unlock", M_ME_THE, " with ", M_THE,
                M_OBJECT, key, "." })});
}

void set_lock_text(mixed text) {
  lock_text = text;
}

varargs mixed query_lock_text(object key, mapping args) {
  if (closurep(lock_text))
    return funcall(lock_text,key,this_object(),args);
  else
    return lock_text ||
           ({({ M_PL_THE, M_PL_VERB, "lock", M_ME_THE, " with ", M_THE,
                M_OBJECT, key, "." })});
}

void set_is_locked_text (mixed text) {
  is_locked_text = text;
}

varargs mixed query_is_locked_text(mapping args) {
  return funcall(is_locked_text, args) ||
         ({({ M_WRITE, M_THE, this_object(), " is locked." })});
}

void set_no_lock_found_text(mixed text) {
  no_lock_found_text = text;
}

varargs mixed query_no_lock_found_text(mapping args) {
  return funcall(no_lock_found_text,args) ||
         ({({ M_PL_THE, M_PL_VERB, "search", " for a lock in ", M_THE, M_OBJECT,
              this_object(), " but ", M_PL_VERB, "do", "n't find one." })});
}

void set_no_key_to_unlock_text(mixed text) {
  no_key_to_unlock_text = text;
}

varargs mixed query_no_key_to_unlock_text(mapping args) {
  return funcall(no_key_to_unlock_text,args) ||
         ({({ M_WRITE, "But you have nothing to unlock ", M_THE, M_OBJECT,
              this_object(), " with." })});
}

void set_key_not_right_text(mixed text) {
  key_not_right_text = text;
}

varargs mixed query_key_not_right_text(object key,mapping args) {
  if (closurep(key_not_right_text))
    return funcall(key_not_right_text,key,args);
  else
    return key_not_right_text ||
           ({({ M_WRITE, M_THE, key, M_VERB, "do", key,
                "n't fit into the lock of ",
                M_THE, M_OBJECT, this_object(), "." })});
 // lockpicks can be plural, so I changed 'doesn't' to 'do', Coogan, 18-Nov-1998
}

void set_already_unlocked_text(mixed text) {
  already_unlocked_text = text;
}

varargs mixed query_already_unlocked_text(mapping args) {
  return
    funcall(already_unlocked_text,args) ||
      ({({ M_WRITE, "But ", M_THE, this_object(), " is already unlocked!" })});
}

void set_already_locked_text(mixed text) {
  already_locked_text = text;
}

varargs mixed query_already_locked_text(mapping args) {
  if (closurep(already_locked_text))
    return funcall(already_locked_text,this_object(),args);
  else
    return already_locked_text ||
           ({({ M_WRITE, "But ", M_THE, this_object(),
                " is already locked!" })});
}

void set_is_still_open_text(mixed text) {
  is_still_open_text = text;
}

varargs mixed query_is_still_open_text(mapping args) {
  return funcall(is_still_open_text,args) ||
         ({({ M_WRITE, "But ", M_THE, this_object(), " is still open!" })});
}

void set_no_key_to_lock_text(mixed text) {
  no_key_to_lock_text = text;
}

varargs mixed query_no_key_to_lock_text(mapping args) {
  return funcall(no_key_to_lock_text,args) ||
         ({({ M_WRITE, "But you have nothing to lock ", M_THE, M_OBJECT,
              this_object(), " with." })});
}

private status default_key_test_function(object key) {
  return key->query_code() == query_lock_code();
}

void set_lock_code(mixed code) {
  if (!lock_code && code)
    set_key_test_function(#'default_key_test_function);
  else if (lock_code && !code)
    set_key_test_function(0);
  lock_code = code;
}

mixed query_lock_code() {
  return funcall(lock_code);
}

