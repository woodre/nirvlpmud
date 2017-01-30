#include "/players/eurale/closed/ansi.h"
#include "std.h"
#define TPRN this_player()->query_real_name()
#define TP this_player()
#define TO this_object()
int shield;

reset(arg) {
  if(arg) return;
/*
if(!present("portal")) {
  move_object(clone_object("players/eurale/OBJ/portal"),TO); }
*/
set_light(1);
}

init() {
  add_action("South","south");
  add_action("Church","church");
  add_action("Warp","warp");
  add_action("On","on");
  add_action("Off","off");
  add_action("North","north");
  add_action("west"); add_verb("west");
if(TPRN != "eurale" && shield == 1) {
  write("You feel an "+HIC+"ELECTRIC SHOCK"+NORM+" and see a "+HIW+
    "FLASH OF WHITE LIGHT"+NORM+" as \n"+
    "you rebound off the "+HIR+"DEFENSE SHIELD"+NORM+".\n\n");
  TP->move_player("off the shield#room/church");
  }
 }

South() {
if(TPRN == "eurale") {
  TP->move_player("south#players/eurale/testroom.c");
  return 1; }
write("An invisible force prevents you from going there...\n");
return 1;
}

Warp() {
  move_object(this_player(),"/players/eurale/RMS/warp.c");
  command("look",this_player());
  return 1; }

Church() {
  TP->move_player("church#room/church.c");
  return 1; }

static On() {
  shield = 1;
  write("You "+BOLD+"activate"+NORM+" the shield.\n");
  return 1; }

static Off() {
if(TPRN != "eurale") {
  write("You are not allowed to do that!!!!!!!\n");
  return 1; }
 shield = 0;
write("You "+BOLD+"deactivate"+NORM+" the shield.\n");
return 1; }

short() { return BOLD+"Eurale's Imagination"+NORM; }

long() {
if(shield == 1) write(
  BOLD+"Eurale's Imagination (shielded).....\n"+NORM);
else write(
  BOLD+"Eurale's Imagination (unshielded).....\n"+NORM);
write(
"     Your eyes slowly close and you find yourself floating in space. \n"+
"As you begin to focus on the things around you, you become aware that \n"+
"you are in a place like no other you've ever visited.  It is not an \n"+
"unpleasant sensation.... but one where you seem to be engulfed in \n"+
"a dark and soothing mist that swirls about you.  You can just make \n"+
"out a glimmering portal set in the darkness.  Relax, enjoy the \n"+
"sensation and let the tensions of the battle drain from your body \n"+
"and mind........ \n"+
"                       Obvious exits:  "+BOLD+"church or warp"+NORM+"\n\n");
  }

west() {
  call_other(this_player(), "move_player", "west#players/eurale/Drygulch/dgs4.c");
  return 1;
  }

North() {
if(TPRN == "eurale") {
  TP->move_player("north#players/eurale/VAMPIRES/RMS/vguild_hall.c");
  return 1; }
write("An invisible force stops you from going that way.\n");
return 1; }
