/*
  fire_elemental.c
*/

/*
  This is a message elemental.  It's left in a room.  A message is sent
  to the owner when anyone enters the room.
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "obj/treasure";

string message, elemental_owner_name, str;

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(666);
}

short() { elemental_speak(); }

long() { elemental_speak(); }

elemental_speak() {
  write(NORM+CYN+"A small fire elemental.\n"+NORM);
  if (find_living(elemental_owner_name))
    if(this_player()->query_invis()<find_living(elemental_owner_name)->query_level())
    tell_object(find_living(elemental_owner_name),
                NORM+BLU+"===>"+
                NORM+CYN+this_player()->query_name()+
                " is at your fire elemental.\n"+NORM);
  return 1;
}

set_message(str) { message = str; }
set_elemental_owner(str) { elemental_owner_name = str; }

id(str) { return (str=="fireelemental" ||
                  str=="fire elemental" ||
                  str==elemental_owner_name+"fireelemental" ||
                  str=="elemental"); }
