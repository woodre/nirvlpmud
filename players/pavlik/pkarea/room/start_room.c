inherit "room/room";
#include "/players/pavlik/pkarea/lib/defines.h"
#include "/players/pavlik/closed/colors.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The "+HIB+"Matrix"+HIW+" Chamber"+NORM;
  long_desc = "The "+HIB+"Matrix "+HIW+"Chamber"+NORM+".\n";
  dest_dir=({
	"/players/pavlik/pkarea/room/null", "out",
  });
}

short() {
  return HIW+"Entrance to the "+HIB+"Matrix"+NORM;
}

long() {
  write("The "+HIB+"Matrix "+HIW+"Chamber"+NORM+".\n"+
  "You stand in the Grand Chamber at the center of the Matrix.  From this central\n"+
  "point you can enter each of the various function rooms.  Type "+HIC+"exits"+NORM+" to list your\n"+
  "choices from this location.\n"+
  "    There is one obvious exit: out\n");
  return;
}

init() {
  ::init();
  if(this_player()->query_invis() && this_player()->query_level() < 20) {
	command("visible", this_player());
  }
  add_action("show_exits", "exits");
  add_action("info",       "info");
  add_action("lockers",    "lockers");
  add_action("equip",      "equip");
  add_action("observe",    "observe");
  add_action("out",        "out");
  add_action("no_can_do",  "quit");
}

show_exits() {
  write("\n"+
  "The following exits are avaliable : \n"+
  "  "+CYN+"info"+NORM+"          : Read valuable information about the Matrix.\n"+
  "  "+CYN+"lockers"+NORM+"       : Store or Recover your equipment.\n"+
  "  "+CYN+"equip"+NORM+"         : Get special Matrix equipment.  You can enter\n"+
  "                                 the Matrix after getting equipped.\n"+
  "  "+CYN+"observe"+NORM+"       : Observe action within the Matrix.\n"+
  "  "+CYN+"out"+NORM+"           : Leave the Matrix.\n"+
  "\n");
  return 1;
}

no_can_do() {
  write("Sorry, you cannot do that here.\n");
  return 1;
}

query_no_fight() { return 1; }
realm(){ return "NT"; }

info() {
  this_player()->move_player("to the information complex#players/pavlik/pkarea/room/info_room");
  return 1;
}

lockers() {
  this_player()->move_player("to the locker room#players/pavlik/pkarea/room/locker_room");
  return 1;
}

equip() {
  if(sizeof(all_inventory(this_player())) > 1) {
	write(
	"You must store all your regular items in the locker room before you may enter\n"+
	"the equipment room.\n");
	return 1;
  }
  this_player()->move_player("to the equipment room#players/pavlik/pkarea/room/equip_room");
  return 1;
}

observe() {
  this_player()->move_player("to the observatory#players/pavlik/pkarea/room/observe_room");
  return 1;
}

out() {
  move_object(this_player(), "players/pavlik/pkarea/room/locker_room");
  if(present(this_player()->query_real_name()+"_locker", environment(this_player()))) {
	write("You must get your items from the locker room first.\n");
	move_object(this_player(), this_object());
	return 1;
  }
  move_object(this_player(), this_object());
  write("Fine, leave then.\n");
  return 1;
}

