/*
 mapper_bat.c
*/

/*
  This is a mapper bat.  It's left in a room with a # that's
  displayed to the owner upon entering the room.
*/

inherit "obj/treasure";

string bat_owner_name;

int room_nbr;

query_save_flag() { return 1; }

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(666);
}

short() { bat_speak(); }

long() { bat_speak(); }

bat_speak() {
  write("A small brown bat.\n");
  if (this_player()->query_real_name()==bat_owner_name)
    write("The bat squeaks: '"+capitalize(bat_owner_name)+
          " you remember this room as # "+room_nbr+".'\n");
}

set_room_nbr(arg) { room_nbr = arg; }
query_room_nbr() { return room_nbr; }
set_bat_owner(arg) { bat_owner_name = arg; }
query_bat_owner() { return bat_owner_name; }

id(str) { return (str=="mapperbat" ||
                  str==bat_owner_name+"mapperbat" ||
                  str=="bat"); }
