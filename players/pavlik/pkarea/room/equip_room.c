inherit "room/room";
#include "/players/pavlik/pkarea/lib/defines.h"
#include "/players/pavlik/closed/colors.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=HIW+"The "+HIB+"Matrix"+NORM+" Equipment Room";
  long_desc=
  "The "+CYN+"equipment chamber"+NORM+".\n"+
  "You are now in the equipment chamber.  Members gather what equipment they can\n"+
  "at this point before entering the Matrix.  A large counter occupies one side\n"+
  "of the room.  Behind the counter an old battle-scarred veteran of the Matrix\n"+
  "distributes equipment.  There is a sign on the wall behind the counter.\n";
  dest_dir=({
	"/players/pavlik/pkarea/room/null", "enter matrix",
	"/players/pavlik/pkarea/room/null", "leave",
  });
  items=({
	"sign",
	"            "+CYN+"Matrix Equipment Room"+NORM+"            \n"+
	"All combantants recieve one weapon and one piece\n"+
	"of armor before entering the Matrix.  Use the\n"+
	HIC+"equip"+NORM+" command before continuing",
  });
}

short() {
  return HIW+"Entrance to the "+HIB+"Matrix"+NORM;
}

init() {
  ::init();
  if(this_player()->query_invis() && this_player()->query_level() < 20) {
	command("visible", this_player());
  }
  add_action("enter", "enter");
  add_action("leave", "leave");
  add_action("equip", "equip");
  add_action("no_can_do", "quit");
  add_action("no_can_do", "drop");
  add_action("no_can_do", "get");
  add_action("no_can_do", "give");
}

no_can_do() {
  write("Sorry, you cannot do that here.\n");
  return 1;
}

query_no_fight() { return 1; }
realm(){ return "NT"; }

equip(str) {
  object obj;

  if(sizeof(all_inventory(this_player())) > 1) {
	write(
	CYN+"Ghornak scowls:"+NORM+" Ye gots all I'm gonna give ya.  Now git!\n");
	return 1;
  }
  if(!str) {
	write(
	CYN+"Ghornak scowls:"+NORM+" Ye can take one weapon and this 'ere piece o armor.\n"+
	"What da ya want? <sword/spear/mace> ");
	input_to("equip");
	return 1;
  }
  if(str == "sword" || str == "spear" || str == "mace") {
	write("\n"+
	"Ghornak takes a "+str+" from under the counter and hands it to you.\n"+
	"The scarred equipment man also gives you a leather jerkin.\n\n");
	say(capitalize(this_player()->query_name())+" takes a "+str+" and armor from Ghornak.\n");
	move_object(clone_object("players/pavlik/pkarea/weapons/basic_"+str), this_player());
	move_object(clone_object("players/pavlik/pkarea/armor/basic_armor"), this_player());
	return 1;
  }
  write(CYN+"Ghornak scowls:"+NORM+" What da ya want? <sword/spear/mace> ");
  return 1;
}
	
enter(str) {
  object *ob;

  if(str != "matrix") return 0;

  ob = all_inventory(this_player());
  if(sizeof(ob) < 3) {
	write("You might want to consider getting equipped first.\n");
	return 1;
  }
  if(sizeof(ob) > 3) {
	write(CYN+"Illegal Inventory."+NORM+"\n");
	for(i=0; i<sizeof(ob); i++) {
		if(!(call_other(ob[i], "id", "soul")) destruct(ob[i]);
	}
	call_other(this_player(), "recalc_carry", 0);
	write("Your inventory has been cleared.\n");
	return 1;
  }
  enter_matrix();
  return 1;
}

leave() {
  object *ob;
  int i;

  ob = all_inventory(this_player());
  if(sizeof(ob) > 1) {
	write("You return the equipment to Ghornak and leave.\n");
	say(capitalize(this_player()->query_name())+" returns the equipment to Ghornak.\n");
	for(i=0; i<sizeof(ob); i++) {
		if(!(call_other(ob[i], "id", "soul"))) destruct(ob[i]);
	}
	call_other(this_player(), "recalc_carry", 0);
  }
  this_player()->move_player("out#players/pavlik/pkarea/room/start_room");
  return 1;
}

enter_matrix() {
  return 1;
}

