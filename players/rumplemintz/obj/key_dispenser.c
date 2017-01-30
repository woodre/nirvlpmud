/*
 * key dispenser - use make 'type' 'code' key
 *                 the specified key
 * -- Rumplemintz
 *
 */

#include "/players/rumplemintz/obj/door.h"

inherit "/obj/treasure";

object key;
string type, code;

void
reset(status arg) {
  if(arg)
    return;
  set_id("dispenser");
  set_short("Key dispenser");
  set_long(""+
"This is a key dispenser.  To use it, use the command 'make'.\n");
}

int get(){ return 1; }

void
init() {
  add_action("make_key", "make");
}

status
make_key(string str){
  if (!str || sscanf(str, "%s %s key", type, code) !=2) {
    write("Usage: make <type> <code> key \n");
    return 1;
  }
  key = clone_object("/players/rumplemintz/obj/key");
  key->set_key_data(type+" "+code);
  write("You are handed a key with type: "+
         key->query_type()+" - and code: "+
         key->query_code()+" .\n");
#ifndef LD
  transfer(key, this_player());
#else
  move_object(key, this_player());
#endif
  return 1;
}
