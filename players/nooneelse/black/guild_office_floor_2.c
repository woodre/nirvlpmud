/*
  guild_office_floor_2.c
*/

#include "/players/nooneelse/black/lib/defs.h"

inherit "room/room";

init() {
  :: init();

  add_action("press_button", "press");
  add_action("press_button", "push");
  add_action("door",         "north");
  add_action("door",         "east");
  add_action("door",         "south");
  add_action("door",         "west");
}

press_button(str) {
  string direction, button, bell_msg, office_owner_name;
  if (!str) return 0;
  sscanf(str, "%s %s", direction, button);
  if ((direction!="north" && direction!="east" && direction!="south" &&
       direction!="west") || button!="button") {
    write("Use:  press <direction> button\n");
    return 1;
  }
  bell_msg="BRRRrrriiinnnggg!  "+capitalize(this_player()->query_real_name())+
           " is ringing the door bell to your office.\n";
  if (direction=="north") {
    office_owner_name=
      "/players/nooneelse/black/guild_office_floor_top"->find_office_name(5);
    if (find_player(office_owner_name))
      tell_object(find_player(office_owner_name), bell_msg);
    else
      write("Sorry, "+capitalize(office_owner_name)+" isn't in right now.\n");
  }
  if (direction=="east") {
    office_owner_name=
      "/players/nooneelse/black/guild_office_floor_top"->find_office_name(6);
    if (find_player(office_owner_name))
      tell_object(find_player(office_owner_name), bell_msg);
    else
      write("Sorry, "+capitalize(office_owner_name)+" isn't in right now.\n");
  }
  if (direction=="south") {
    office_owner_name=
      "/players/nooneelse/black/guild_office_floor_top"->find_office_name(7);
    if (find_player(office_owner_name))
      tell_object(find_player(office_owner_name), bell_msg);
    else
      write("Sorry, "+capitalize(office_owner_name)+" isn't in right now.\n");
  }
  if (direction=="west") {
    office_owner_name=
      "/players/nooneelse/black/guild_office_floor_top"->find_office_name(8);
    if (find_player(office_owner_name))
      tell_object(find_player(office_owner_name), bell_msg);
    else
      write("Sorry, "+capitalize(office_owner_name)+" isn't in right now.\n");
  }
  return 1;
}

door() {
  string direction, door_locked_msg, my_name;
  my_name = this_player()->query_real_name();
  door_locked_msg=
      "The door is locked.  You might try ringing the bell to see if\n"+
      "anyone is there.\n"+
      "Use:  press "+query_verb()+" button\n";
  direction = query_verb();
  /* If it's the owner, Nooneelse or an assistant, let 'em in */
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)==GUILD_MASTER ||
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)==GUILD_ASSISTANT)
    return 0;
  if (direction=="north" &&
      this_player()->query_real_name()==
      "/players/nooneelse/black/guild_office_floor_top"->find_office_name(5)) {
    return 0;
  }
  if (direction=="east" &&
      this_player()->query_real_name()==
      "/players/nooneelse/black/guild_office_floor_top"->find_office_name(6)) {
    return 0;
  }
  if (direction=="south" &&
      this_player()->query_real_name()==
      "/players/nooneelse/black/guild_office_floor_top"->find_office_name(7)) {
    return 0;
  }
  if (direction=="west" &&
      this_player()->query_real_name()==
      "/players/nooneelse/black/guild_office_floor_top"->find_office_name(8)) {
    return 0;
  }
  /* anyone else, check the lock */
  if (direction=="north" &&
      "/players/nooneelse/black/guild_office_2n"->query_door()) {
    write(door_locked_msg);
    return 1;
  }
  if (direction=="east" &&
      "/players/nooneelse/black/guild_office_2e"->query_door()) {
    write(door_locked_msg);
    return 1;
  }
  if (direction=="south" &&
      "/players/nooneelse/black/guild_office_2s"->query_door()) {
    write(door_locked_msg);
    return 1;
  }
  if (direction=="west" &&
      "/players/nooneelse/black/guild_office_2w"->query_door()) {
    write(door_locked_msg);
    return 1;
  }
  return 0;
}

reset (arg) {
  if (arg) return 0;

  no_castle_flag=1;
  short_desc=("A well lit hall");
  long_desc=("This well lit hall has four doors.\n");
  set_light(1);
  items =
    ({
      "door", "Which door?  (north, east, south, west)",
      "doors",
      "They are polished rosewood panels.  There is a button next to each one",
      "north door",
        "It is a polished rosewood panel with a button next to it.  The name\n"+
        capitalize("/players/nooneelse/black/guild_office_floor_top"->
                   find_office_name(5))+
        " is etched into the panel in flaming letters",
      "east door",
        "It is a polished rosewood panel with a button next to it.  The name\n"+
        capitalize("/players/nooneelse/black/guild_office_floor_top"->
                   find_office_name(6))+
        " is etched into the panel in flaming letters",
      "south door",
        "It is a polished rosewood panel with a button next to it.  The name\n"+
        capitalize("/players/nooneelse/black/guild_office_floor_top"->
                   find_office_name(7))+
        " is etched into the panel in flaming letters",
      "west door",
        "It is a polished rosewood panel with a button next to it.  The name\n"+
        capitalize("/players/nooneelse/black/guild_office_floor_top"->
                   find_office_name(8))+
        " is etched into the panel in flaming letters",
    });
  dest_dir =
    ({
      "/players/nooneelse/black/guild_office_2n", "north",
      "/players/nooneelse/black/guild_office_2e", "east",
      "/players/nooneelse/black/guild_office_2s", "south",
      "/players/nooneelse/black/guild_office_2w", "west",
      "/players/nooneelse/black/guild_office_floor_1", "down",
      "/players/nooneelse/black/guild_office_floor_top", "up",
    });
}
