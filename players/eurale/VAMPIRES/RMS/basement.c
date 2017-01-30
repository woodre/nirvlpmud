/*
  Basement where coffins are kept
*/

#if 1 /* Changed by Rumplemintz - see new code below */
inherit "room/room";
#include "check.h"
#include "/players/eurale/defs.h"
object obj, what_obj;
string str;

reset(arg) {
  if(!present("board")) {
    move_object("players/eurale/VAMPIRES/OBJ/wiz_board",TO); 
  }
  if(arg) return;
set_light(-2);
short_desc = "Vampire Basement";
long_desc =
  "This is the dark and damp basement of the Vampire Guild Hall.  It\n"+
  "looks to have been carved out of one huge obsidian boulder.  All\n"+
  "the vampire coffins are kept here.  Each vampire can open their own\n"+
  "coffin with 'coffin' and then enter it with 'enter coffin'.\n";

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/vguild_hall","up",
});

no_castle_flag = 1;
}

init() {
  ::init();

  add_action("get_coffin",   "coffin");
  add_action("enter_coffin", "enter");
}

get_coffin() {
if(!TP) return 0;
if(TP->is_npc()) return 0;
  /*  Check to see if they have an open coffin  */
obj = 0;
what_obj = first_inventory(TO);
while (what_obj) {
  if(what_obj->query_coffin_owner_name() == TPRN) obj = what_obj;
  what_obj = next_inventory(what_obj);
}

if(obj) {
  write("You already have a coffin here.\n");
  return 1; }

obj = clone_object("players/eurale/VAMPIRES/RMS/coffin.c");
obj->set_coffin_owner_name(TPRN);
move_object(obj,TO);
tell_not_me(
  capitalize(TPRN)+" whispers some arcane words and "+
  TP->query_possessive()+" coffin opens..\n");
write("You whisper some arcane words and your coffin opens.\n");
return 1;
}

enter_coffin(str) {
if(!str || str != "coffin") return; /* fixed 2004.08.12 -forbin from !str == "coffin" to str != "coffin" */
  /* See if the coffin is open  */
  obj=0;
what_obj=first_inventory(this_object());
while (what_obj) {
  if(what_obj->query_coffin_owner_name() == TPRN) obj = what_obj;
  what_obj = next_inventory(what_obj);
}

if(!obj) {
  write("You must first open your coffin.\n");
  return 1; }

tell_not_me(
  capitalize(TPRN)+" climbs into "+TP->query_possessive()+" coffin.\n");
write("You climb into your coffin and close the lid.\n");
move_object(TP,obj);
command("look",TP);
return 1;
}

is_castle() { return 1; }
clean_up() { return 0; }
realm() { return "NT"; }

#else

/*
 * Vampire Guild Basement - Coffins are kept here
 * Changed the coffin to an obj instead of a room, moved the enter function
 * into it instead of here, changed the check to present() instead of a
 * while() loop, type cast everything for strict_types
 * Rumplemintz
 */

#pragma strict_types

inherit "room/room";

void reset(int arg) {
  if (!present("board"))
    move_object("players/eurale/VAMPIRES/OBJ/wiz_board", this_object());
  if (arg)
    return;
  ::reset();
  set_light(-2);
  short_desc = "Vampire Basement";
  long_desc =
"This is the dark and damp basement of the Vampire Guild Hall.  It\n" +
"looks to have been carved out of one huge obsidian boulder.  All\n" +
"the vampire coffins are kept here.  Each vampire can open their own\n" +
"coffin with 'coffin' and then enter it with 'enter coffin'.\n";
  no_castle_flag = 1;
  set_no_clean(1);
  add_exit("players/eurale/VAMPIRES/RMS/vguild_hall", "up");
  add_property("no_teleport");
}

void init() {
  ::init();
  add_action("get_coffin", "coffin");
}

int get_coffin() {
  object coffin;

  if (!this_player() || this_player()->is_npc())
    return 0;

  if (present(this_player()->query_real_name()+"_coffin")) {
    write("You already have a coffin here.\n");
    return 1;
  }
  coffin = clone_object("players/eurale/VAMPIRES/OBJ/coffin");
  coffin->set_owner(this_player()->query_real_name());
  move_object(coffin, this_object());
  say(this_player()->query_name() + " whispers some arcane words and " +
      this_player()->query_possessive() + " coffin opens..\n", this_player());
  write("You whisper some arcane words and your coffin opens.\n");
  return 1;
}

#endif

