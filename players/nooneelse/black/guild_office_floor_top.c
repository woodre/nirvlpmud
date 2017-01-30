/*
  guild_office_floor_top.c
  took the master office - line 209 as per Nooneelse permission
*/

#include "/players/nooneelse/black/lib/defs.h"

inherit "room/room";

/* look below at load_officers_list to add/change/remove officers */
string officers_list, levels_list, office_list;
int nbr_of_lieutenants;

init() {
  :: init();

  add_action("press_button", "press");
  add_action("press_button", "push");
  add_action("door",         "north");
  add_action("door",         "south");
  add_action("door",         "east");
  add_action("door","west");
  add_action("read_list",    "read");
  add_action("read_list",    "examine", 2);
  add_action("read_list",    "look", 1);
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
    office_owner_name=find_office_name(1);
    if (find_player(office_owner_name))
      tell_object(find_player(office_owner_name), bell_msg);
    else
      write("Sorry, "+capitalize(office_owner_name)+" isn't in right now.\n");
  }
  if (direction=="south") {
    office_owner_name=find_office_name(2);
    if (find_player(office_owner_name))
      tell_object(find_player(office_owner_name), bell_msg);
    else
      write("Sorry, "+capitalize(office_owner_name)+" isn't in right now.\n");
  }
  if (direction=="east") {
    office_owner_name=find_office_name(3);
    if (find_player(office_owner_name))
      tell_object(find_player(office_owner_name), bell_msg);
    else
      write("Sorry, "+capitalize(office_owner_name)+" isn't in right now.\n");
  }
  if (direction=="west") {
    office_owner_name=find_office_name(4);
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
  /* If it's the owner or Nooneelse, let 'em in */
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)==GUILD_MASTER) return 0;
  if (direction=="north" &&
      this_player()->query_real_name()==find_office_name(1) ||
      this_player()->query_real_name()=="nooneelse") {
    return 0;
  }
  if(direction == "west" &&
    this_player()->query_real_name() == find_office_name(4) ||
    this_player()->query_real_name() == "nooneelse") {
    return 0;
  }
  if (direction=="south" &&
      this_player()->query_real_name()==find_office_name(2) ||
      this_player()->query_real_name()=="nooneelse") {
    return 0;
  }
  if (direction=="east" &&
      this_player()->query_real_name()==find_office_name(3) ||
      this_player()->query_real_name()=="nooneelse") {
    return 0;
  }
  /* anyone else, check the lock */
  if (direction=="north" &&
      "/players/nooneelse/black/guild_office_tn"->query_door()) {
    write(door_locked_msg);
    return 1;
  }
  if (direction=="south" &&
      "/players/nooneelse/black/guild_office_ts"->query_door()) {
    write(door_locked_msg);
    return 1;
  }
  if (direction=="east" &&
      "/players/nooneelse/black/guild_office_te"->query_door()) {
    write(door_locked_msg);
    return 1;
  }
  return 0;
}

read_list(str) {
  int i;
  string str2;
  if (!str) return 0;
  sscanf(str, "at %s", str2);
  if (str2=="list") str="list";
  if (str!="list") return 0;
  write("\nVampire Guild Officers\n\n");
  for (i=1; i<=12; i++) {
    if (officers_list[i]!="vacant")
      write(capitalize(officers_list[i])+" - Guild "+levels_list[i]+"\n");
  }
  return 1;
}

/* this is called from other objects to find out if someone is an officer */
find_officer(str) {
  int i, found_officer, level;
  found_officer = 0;
  level = 0;
  for (i=1; i<=12; i++) {
    if (str==officers_list[i]) {
      found_officer = 1;
      level=i;
    }
  }
  return levels_list[level];
}

/* this is called from other objects to find out what office is this officer */
find_office(str) {
  int i, found_officer, level;
  found_officer = 0;
  for (i=1; i<=12; i++) {
    if (str==officers_list[i]) {
      found_officer = 1;
      level=i;
    }
  }
  return office_list[level];
}

/* this is called from other objects to find out the officer's name */
find_office_name(arg) { return officers_list[arg]; }

/* this is called from other objects to find out the officer's name */
find_office_level(arg) { return levels_list[arg]; }

/* called from voting board to know when all votes are in */
query_nbr_lieutenants() { return nbr_of_lieutenants; }

reset (arg) {
  if (arg) return 0;

  no_castle_flag=1;
  short_desc=("A well lit hall");
  long_desc=("This well lit hall has four doors.\n"+
             "Some names are printed in black on a list on the wall.\n");
  set_light(1);
  officers_list = allocate(13);
  levels_list = allocate(13);
  office_list = allocate(13);
  load_officers_list();
  items =
    ({
      "door", "Which door?  (north, south, east)",
      "doors",
      "They are polished rosewood panels.  There is a button next to each one",
      "north door",
        "It is a polished rosewood panel with a button next to it.  The name\n"+
        capitalize(find_office_name(1))+
        " is etched into the panel in flaming letters",
      "south door",
        "It is a polished rosewood panel with a button next to it.  The name\n"+
        capitalize(find_office_name(2))+
        " is etched into the panel in flaming letters",
  "west door",
    "It is a polished rosewood panel with a button next to it.  The name \n"+
    capitalize(find_office_name(4))+
    " is etched into the panel in flaming letters",
      "east door",
        "It is a polished rosewood panel with a button next to it.  The name\n"+
        capitalize(find_office_name(3))+
        " is etched into the panel in flaming letters",
    });
  dest_dir =
    ({
      "/players/nooneelse/black/guild_office_tn", "north",
      "/players/nooneelse/black/guild_office_ts", "south",
      "/players/nooneelse/black/guild_office_te", "east",
	"/players/nooneelse/black/guild_office_tw","west",
      "/players/nooneelse/black/guild_office_floor_2", "down",
    });
  if (!present("vampbulletinboard", this_object()))
    move_object(clone_object("/players/nooneelse/black/guild_voting"),
                this_object());
}

load_officers_list() {
  officers_list[0] = "vacant";
  levels_list[0] = "dummy office";
  office_list[0] = "dummy office";
  officers_list[1] = "eurale";
  levels_list[1] = "Master";
  office_list[1] = GUILD_OFFICE_TN;
  officers_list[2] = "nancy";
  levels_list[2] = "Vampire Underlord";
  office_list[2] = GUILD_OFFICE_TE;
  officers_list[3] = "magus";
  levels_list[3] = "Vampire Underlord";
  office_list[3] = GUILD_OFFICE_TW;
  officers_list[4] = "nooneelse";
  levels_list[4] = "Master";
  office_list[4] = GUILD_OFFICE_TW;
  officers_list[5] = "vacant";
  levels_list[5] = "Lieutenant";
  office_list[5] = GUILD_OFFICE_2N;
  officers_list[6] = "sado";
  levels_list[6] = "Lieutenant";
  office_list[6] = GUILD_OFFICE_2E;
  officers_list[7] = "vacant";
  levels_list[7] = "Lieutenant";
  office_list[7] = GUILD_OFFICE_2S;
  officers_list[8] = "vacant";
  levels_list[8] = "Lieutenant";
  office_list[8] = GUILD_OFFICE_2W;
  officers_list[9] = "wamphyri";
  levels_list[9] = "Lieutenant";
  office_list[9] = GUILD_OFFICE_1N;
  officers_list[10] = "james";
  levels_list[10] = "Lieutenant";
  office_list[10] = GUILD_OFFICE_1E;
  officers_list[11] = "abel";
  levels_list[11] = "Lieutenant";
  office_list[11] = GUILD_OFFICE_1S;
  officers_list[12] = "charrise";
  levels_list[12] = "Lieutenant";
  office_list[12] = GUILD_OFFICE_1W;

  nbr_of_lieutenants = 11;
}
