/*
  air_elemental.c
*/

/*
  This is a message elemental.  It's left in a room with a message that's
  displayed to anyone entering the room.
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
  write(NORM+CYN+"A small air elemental.\n"+NORM);
  write(NORM+BLU+capitalize(elemental_owner_name)+"'s elemental speaks:\n     '"+
        NORM+CYN+message+NORM+BLU+"'\n\n"+NORM);
  if (find_living(elemental_owner_name))
    if(this_player()->query_invis()<find_living(elemental_owner_name)->query_level())
    tell_object(find_living(elemental_owner_name),
                NORM+BLU+"===>"+
                NORM+CYN+this_player()->query_name()+
                " is at your air elemental.\n"+NORM);
  return 1;
}

set_message(str) { message = str; }
set_elemental_owner(str) { elemental_owner_name = str; }

id(str) { return (str=="airelemental" ||
                  str=="air elemental" ||
                  str==elemental_owner_name+"airelemental" ||
                  str=="elemental"); }
