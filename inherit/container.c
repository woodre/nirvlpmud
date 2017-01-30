#pragma strict_types
#pragma save_types
#pragma combine_strings

/***   Container.c   ***/
/* a lockable container */

inherit "inherit/base/base_obj";

#include "/include/fn/newline.h"

#define NAME         (string)this_player()->query_name()
#define REAL         (string)this_player()->query_name(1)
#define CAP          (string)this_player()->query_cap_name()
#define QUERY_TRAPS  (int)this_player()->query_traps()
#define QUERY_LOCKS  (int)this_player()->query_locks()


/* the container */

int container_weight;   /* weight container currently holds */
int max_weight;         /* max weight container can carry   */
int closed;             /* 0 == not closable, 1 == closed, 2 == open  */

/* the lock */

string *lock_attempts;
string lock_id;
string lock_desc;
string key_id;
int lock_difficulty;
status is_locked;


/* the trap */

string *trap_attempts;
string *trap_detects;
string trap_id;
string trap_desc;
int    trap_difficulty;
int    trap_damage;
string trap_message;
status is_trapped;



void reset(status arg) {
  /* reset attempts once per reset */
  lock_attempts = ({});
  trap_attempts = ({});
  trap_detects  = ({});
  if(arg) return;
}

status get() { return 1; }


status can_put_and_get() {
  if(closed && closed == 1) write("The "+ query_name() +" is closed.\n");
  return (closed != 1);
}


string query_object_type() { return "Container"; }


/**********************************************************************/
/* the container */

int query_max_weight()           { return max_weight; }
int query_container_weight()     { return container_weight; }
int query_closed()               { return closed; }

int set_max_weight(int w)        { return max_weight = w; }
int set_container_weight(int w)  { return container_weight; }  
int set_closed(int i)            { return closed = i; }


status add_weight(int w) {
/* if there are weight problems with containers take out the comments
  int i, wt;
  object *inv;

  inv = all_inventory();
  container_weight = 0;
  for(i = 0; i < sizeof(inv); i++) {
    wt = (int)inv[i]->query_weight();
    if(wt + container_weight > max_weight && !inv[i]->drop()) {   
#ifdef NATIVE_MODE
      inv[i]->move(environment());
#else
      move_object(inv[i],environment());
#endif
      write("Something falls out of the "+ query_name() +".\n");
    }
    else {
      container_weight += wt;
    }
  }
*/
  if(container_weight + w > max_weight) return 0;
  return 1;
}

status prevent_insert() {
  if(container_weight) {
    write("You can't when there are things in the "+ query_name()+ ".\n");
    return 1;
  }
  return 0;
}

void extra_info(status wiz) {
  if(closed && closed == 1) {
    long(wiz);
    return;
  }
  if(!container_weight) {
    write("It looks empty.\n");
  }
  else if(container_weight == max_weight) {
    write("It looks full.\n");
  }
  else {
    write("It is about "+((container_weight*100)/max_weight)+"\% full.\n");
  }
}


/***********************************************************************/
/* the lock */


string *set_lock_attempts(string *arg) { 
  return lock_attempts = (arg) ? arg : ({}); 
}

string set_lock_id(string str)      { return lock_id = str; }
string set_lock_desc(string str)    { return lock_desc = str; }
string set_key_id(string str)       { return key_id = str;  }
int set_lock_difficulty(int i)      { return lock_difficulty = i; }
status set_locked(status i)         { return is_locked = (i) ? 1 : 0; }

string *set_trap_attempts(string *arg) { 
  return trap_attempts = (arg) ? arg : ({}); 
}
string set_trap_id(string str)      { return trap_id = str;  }
string set_trap_desc(string str)    { return trap_desc = str; }
int    set_trap_difficulty(int i)   { return trap_difficulty = i; }
int    set_trap_damage(int i)       { return trap_damage = i;  }
string set_trap_message(string str) { return trap_message = str; }
status set_trapped(status i)         { return is_trapped = (i) ? 1 : 0; }


string *query_lock_attempts()  { return lock_attempts; }
string query_lock_id()         { return lock_id; }
string query_lock_desc()       { return lock_desc; }
string query_key_id()          { return key_id;  }
int query_lock_difficulty()    { return lock_difficulty; }
status query_locked()          { return is_locked; }

string *query_trap_attempts()  { return trap_attempts; }
string query_trap_id()         { return trap_id;  }
string query_trap_desc()       { return trap_desc; }
int    query_trap_difficulty() { return trap_difficulty; }
int    query_trap_damage()     { return trap_damage;  }
status query_trapped()         { return is_trapped;   }

string query_trap_message()    { 
  return (trap_message) ? process_msg(add_newline(trap_message)) : "";
}


/************************************************************************/
/* actions */


void init() {
  ::init();
  if(!closed) return;
  add_action("open","close");
  add_action("open","open");
  if(!lock_id || key_id == "no_key") return;
  add_action("lock","lock");
  add_action("lock","unlock");
  add_action("detect", "detect");
  add_action("disarm", "disarm");
  add_action("arm", "arm");
  add_action("pick_lock", "pick");
}


/* open|close container */

void container_open(string verb) {  
  if(is_trapped) { 
    write("You set off a trap!\n"); 
    say(NAME +" sets off a trap!\n"); 
    write(query_trap_message()); 
    this_player()->hit_player(trap_damage); 
    is_trapped = 0;
  } 
  if(closed == 2) {  
    if(verb == "open") {
      write("But why? It's already open!\n");  
      return;
    }  
  }  
  else {
    if(verb != "open") {
      write("But why? It's already closed!\n");  
      return;
    }  
  }
  if(is_locked && key_id != "no_key") { 
    write("You can't "+ verb +" the "+ query_name() +", it's locked!\n");  
    return; 
  } 
  write("You "+ verb +" the "+ query_name() +".\n");  
  say(NAME +" "+ verb +"s the "+ query_name() +".\n");
  closed = (verb == "open") ? 2 : 1;  
}  


status open(string str) {
  object ob;
  string verb;

  verb = query_verb();
  if(!str) {
    notify_fail(verb +" what?\n");
    return 0;
  }  
  ob = present(str, environment(this_player()));
  if(!ob) ob = present(str, this_player());
  if(!ob) {
    notify_fail("There is no "+ capitalize(str) +" here.\n");
    return 0;
  }
  if(ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  container_open(verb);
  return 1;
}


/* lock|unlock container */

void container_lock(object key, string verb) { /* verb "lock" */    
  if(!lock_id || key_id == "no_key") {
    is_locked = 0;
    return;
  }
  if(is_trapped) { 
    write("You set off a trap!\n"); 
    say(NAME +" sets off a trap!\n"); 
    write(query_trap_message()); 
    this_player()->hit_player(trap_damage); 
    is_trapped = 0;
  } 
  if(is_locked) { 
    if(verb == "lock") { 
      write("But why? It's already locked!\n");  
      return;  
    }
  }  
  else {
    if(verb != "lock") { 
      write("But why? It's already unlocked!\n");  
      return;  
    }
  }
  if(!key) { 
    write("You have to "+ verb +" the "+ query_name() +" with something!\n"); 
    return; 
  }
  if(!key_id) key_id = "key"; 
  if(key_id) {  
    if(key -> id(key_id)) { 
      write("You "+ verb +" the "+ query_name() +".\n");
      say(NAME +" "+ verb +"s the "+ query_name() +".\n");
      is_locked = (verb == "lock") ? 1 : 0;  
      if(closed == 2 && is_locked) {
        closed = 1;
        write("You close the "+ query_name() +".\n");
      }
    } 
    else {
      write("Your "+ (string)key->short() +" doesn't fit in the lock!\n"); 
    }
    return; 
  } 
} 


status lock(string str) {  
  object ob, key;  
  string verb;
  string key_name;  
    
  verb = query_verb();
  if(!str) {
    notify_fail(verb +" what?\n");
    return 0;
  }
  if(key_id == "no_key") {
    container_lock(0, verb);    
    return 1;  
  }
  if(sscanf(str, "%s with %s", str, key_name)) {  
    if(!(key = present(key_name, this_player()))){ 
      write("But you don't have a "+ capitalize(key_name) +"!\n"); 
      return 1; 
    } 
    ob = present(str, environment(this_player()));
    if(!ob) ob = present(str, this_player());
    if(!ob) {
      notify_fail("There is no "+ capitalize(str) +" here.\n");
      return 0;
    }
    if(ob != this_object()) {
      notify_fail("You can't do that!\n");
      return 0;
    }
    container_lock(key, verb);    
    return 1;  
  }  
  notify_fail(verb +" <what> with <item>\n");
  return 0; 
}      


/***********************************************************************/
/* look at 'lock' on 'container' */

status look_at(string str) {
  if(str == lock_id) {
    write(((lock_desc) ? process_msg(lock_desc) : ""));
    write("It appears to be "+((is_locked) ? "" : "un") +"locked.\n"); 
    if(!key_id) key_id = "key";

    if(key_id != "no_key") {
      write("The "+ lock_id +" requires a "+ key_id +".\n");
    } 
    return 1;
  }
  else if(str == trap_id && member(trap_detects, CAP) != -1) {    
    write(((trap_desc) ? process_msg(trap_desc) : ""));
    return 1;
  }
  return 0;
}


/********************************************************************/
/* disarm trap */

status disarm(string str) {
  object ob;

  if(QUERY_TRAPS == 0) {
    notify_fail("You do not have the skill to disarm traps.\n");
    return 0;
  }
  if(!str || sscanf(str,"trap on %s",str) != 1) {
    notify_fail("disarm trap on what?\n");
    return 0;
  }
  if(!(ob = present(str, environment(this_player())))) {
    if(!(ob = present(str, this_player()))) {
      notify_fail("There is no "+ capitalize(str) +" here.\n");
      return 0;
    }
  }
  if(ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if(member(trap_detects, REAL) != -1) {
    write("There are no traps you can see to disarm.\n");
    return 1;
  }
  if(member(trap_detects, CAP) == -1) {
    write("You have to detect a trap before you can disarm it!\n");
    return 1;
  }
  if(member(trap_attempts, REAL) != -1) {
    write("You think you have already disarmed the trap.\n");
    return 1;
  } 
  write("You attempt to disarm the trap.\n");
  if(!is_trapped) return 1;
  if(!trap_attempts) trap_attempts = ({});
  if(lock_difficulty && !trap_difficulty) trap_difficulty = lock_difficulty;
  if(random(QUERY_TRAPS+1) >= random(trap_difficulty+1)){
    is_trapped = 0;
  }
  trap_attempts += ({ REAL, });
  write("You think you have disarmed the trap.\n");
}

/********************************************************************/
/* arm trap */

status arm(string str) {
  object ob;

  if(QUERY_TRAPS == 0) {
    notify_fail("You do not have the skill to arm traps.\n");
    return 0;
  }
  if(!str || sscanf(str,"trap on %s",str) != 1) {
    notify_fail("arm trap on what?\n");
    return 0;
  }
  if(!(ob = present(str, environment(this_player())))) {
    if(!(ob = present(str, this_player()))) {
      notify_fail("There is no "+ capitalize(str) +" here.\n");
      return 0;
    }
  }
  if(ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if(member(trap_detects, REAL) != -1) {
    write("There are no traps you can see to arm.\n");
    return 1;
  }
  if(member(trap_detects, CAP) == -1) {
    write("You have to detect a trap before you can arm it!\n");
    return 1;
  }
  write("You attempt to arm the trap.\n");
  if(is_trapped) return 1;
  if(!trap_difficulty) trap_difficulty = lock_difficulty;
  if(random(QUERY_TRAPS+1) >= random(trap_difficulty+1)){
    write("You arm the "+ trap_id +".\n");
    is_trapped = 1;
    write("You arm the "+ trap_id +".\n");
    trap_attempts = ({});
    trap_detects  = ({ CAP, });
  }
  else {
    write("You set the "+ trap_id +" off.\n");
    say(NAME +" sets off a trap!\n"); 
    write(query_trap_message()); 
    this_player()->hit_player(trap_damage); 
    is_trapped = 0;
  }
  return 1;
}


/***********************************************************************/
/* pick lock */

status pick_lock(string str) {
  object ob;
  if(QUERY_LOCKS == 0) {
    notify_fail("You do not have the skill to pick locks.\n");
    return 0;
  }
  if(!str || sscanf(str,"lock on %s",str) != 1) {
    notify_fail("pick lock on what?\n");
    return 0;
  }
  if(!(ob = present(str, environment(this_player())))) {
    if(!(ob = present(str, this_player()))) {
      notify_fail("There is no "+ capitalize(str) +" here.\n");
      return 0;
    }
  }
  if(ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if(!lock_id || !closed) {
    write("The "+ query_name() +" does not have a lock which you pick.\n");
    return 1;
  }
  write("You attempt to pick the "+ lock_id +".\n");
  if(!lock_attempts) lock_attempts = ({});
  if(is_trapped) {
    write("You set off a trap!\n"); 
    say(NAME +" sets off a trap!\n"); 
    write(query_trap_message()); 
    this_player()->hit_player(trap_damage); 
    is_trapped = 0;
  } 
  if(member(lock_attempts, REAL) != -1) {
    write("You give up...\n");
    return 1;
  }
  if(member(lock_attempts, CAP) != -1 ||
     random(QUERY_LOCKS+1) >= random(lock_difficulty+1)) {
    is_locked = !is_locked;

    if(closed == 2 && is_locked) {
      closed = 1;
      write("You close the "+ query_name() +".\n");
    }
    tell_room(environment(this_player()),"Click!\n");
    write("You "+((is_locked) ? "" : "un") +"lock the "+ lock_id +".\n");
    if(member(lock_attempts, CAP) == -1) lock_attempts += ({ CAP, });
  }
  else {
    write("You give up...\n");
    lock_attempts += ({ REAL, });
  }
  return 1;
}

/***********************************************************************/


status detect(string str) {
  object ob;

  if(!this_player()->query_traps()) {
    notify_fail("You do not have the skill to detect traps.\n");
    return 0;
  }
  if(!str || sscanf(str,"trap on %s",str) != 1) {
    notify_fail("detect trap on what?\n");
    return 0;
  }
  if(!(ob = present(str, environment(this_player())))) {
    if(!(ob = present(str, this_player()))) {
      notify_fail("There is no "+ capitalize(str) +" here.\n");
      return 0;
    }
  }
  if(ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if(!trap_detects) trap_detects = ({});
  if(!trap_id || member_array(REAL, trap_detects) != -1) {
    write("There are no traps that you can detect.\n");
    if(member(trap_detects, REAL) == -1) trap_detects += ({ REAL, });
    return 1;
  }
  if(member(trap_detects, CAP) != -1) {
    write("You find the "+ trap_id +" again.\n");
    return 1;
  }
  if(!trap_difficulty) trap_difficulty = lock_difficulty;
  if(random(QUERY_TRAPS+1) >= random(trap_difficulty+1)){
    write("You find a "+ trap_id +".\n");
    trap_detects += ({ CAP, });  /* success */
  }
  else {
    write("There are no traps that you can detect.\n");
    trap_detects += ({ REAL, }); /* failed */
  }
  return 1;
}

