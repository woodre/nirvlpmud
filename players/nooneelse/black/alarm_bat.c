/*
 alarm_bat.c
*/

/*
  This is a message bat.  It's left in a room with a message that's
  displayed to anyone entering the room.
*/

inherit "obj/treasure";

string message, bat_owner_name, str;

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(666);
}

short() { bat_speak(); }

long() { bat_speak(); }

bat_speak() {
  write("A small gray bat.\n");
  write(capitalize(bat_owner_name)+"'s bat squeaks:\n     '"+message+"'\n\n");
  if (find_living(bat_owner_name))
    if(this_player()->query_invis()<find_living(bat_owner_name)->query_level())
    tell_object(find_living(bat_owner_name), "===>"+
                this_player()->query_name()+" is at your alarm bat.\n");
  return 1;
}

set_message(str) { message = str; }
set_bat_owner(str) { bat_owner_name = str; }

id(str) { return (str=="alarmbat" ||
                  str==bat_owner_name+"alarmbat" ||
                  str=="bat"); }
