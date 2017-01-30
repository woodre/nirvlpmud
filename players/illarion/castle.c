#include "/players/illarion/dfns.h"
#define DEST "room/mount_top2"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "booth" || str == "trail"; }

short() {
  return "A New York City telephone booth.\n"+
         "A steep trail down the north side of the plateau";
}

long(str) {
  if(str=="trail") {   
    write("This steep but stable-looking trail cuts down the north side of\n"+
          "the plateau, quickly disappearing from sight.  Although steep,\n"+
          "it appears to be a stable climb down, for those that wish to\n"+
          BLD("descend")+" the trail.\n");
    return;
  }
  write(
"A phonebooth made of dirty metal and glass, that undoubtedly contains a\n"+
"dirty phone, and the remnants of a large, dirty phonebook.  Visions of a\n"+
"man in tights and a cape flash into your head, but you banish them as an\n"+
"irresponsible fantasy.  Nevertheless, the booth certainly does not belong\n"+
"in quite this place.  The door is standing ajar, and you could certainly\n"+
BLD("enter")+" the booth.\n");
}

init() {
add_action("enter","enter");
    add_action("cmd_descend","descend");
}

status enter(string str) {
    if(str != "booth")
	return 0;
  TP->move_player("into the phone booth#"+HROOM+"booth");
  return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
    call_other("/players/illarion/obj/bscarf","XXX");
    call_other("/players/illarion/wedding/wring","XXX");
}
is_castle(){return 1;}
cmd_descend(str) {
   if(str != "trail") return 0;
   write("You carefully descend the trail to the base of the plateau.\n");
   this_player()->move_player("down the trail#"+PROOM+"ontrail");
   return 1;
}
