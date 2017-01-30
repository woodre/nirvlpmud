/*
  earth_elemental.c
*/

/*
  This is a earth (mapper) elemental.  It's left in a room with a # that's
  displayed to the owner upon entering the room.
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "obj/treasure";

string elemental_owner_name;

int room_nbr;

query_save_flag() { return 1; }

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(666);
}

short() { elemental_speak(); }

long() { elemental_speak(); }

elemental_speak() {
  write(NORM+CYN+"A small earth elemental.\n"+NORM);
  if (this_player()->query_real_name()==elemental_owner_name)
    write(NORM+BLU+"The elemental speaks: '"+
          NORM+CYN+capitalize(elemental_owner_name)+
          " you remember this room as # "+room_nbr+".'\n"+NORM);
}

set_room_nbr(arg) { room_nbr = arg; }
query_room_nbr() { return room_nbr; }
set_elemental_owner(arg) { elemental_owner_name = arg; }
query_elemental_owner() { return elemental_owner_name; }

id(str) { return (str=="earthelemental" ||
                  str=="earth elemental" ||
                  str=="mapperelemental" ||
                  str==elemental_owner_name+"earthelemental" ||
                  str=="elemental"); }
