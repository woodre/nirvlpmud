#include "DEFS.h"
inherit "room/room";
int g, mon;
object player;

reset(arg) {
  if(arg) return;
set_light(0);
g = 0;
mon = 1;

short_desc = "A heavy fog";
long_desc =
	"  You step into a heavy fog.  Nothing is very clear.  You can\n"+
	"actually feel the moisture on your face from the air.  In front\n"+
	"of you is an arched opening in a very tall stone wall.  The\n"+
	"diffused light from the overhead lamps allow you to just make\n"+
	"out the shapes of spiked iron rods along the top of the wall.\n"+
	"Either whatever is on the inside wants to keep you out..... or,\n"+
	"whatever is on the inside is being kept in.  There is a sign\n"+
	"attached to the wall next to the opening.  There is also a \n"+
	"chain with a handle coming down through a hole in the arch\n"+
	"above the gate.\n";

items = ({
	"wall","A high and thick stone wall.... must be at least 10 feet\n"+
		"tall with spiked rods running along the top",
	"opening","A heavy metal gate seals the opening and whatever\n"+
		"this compound is",
	"lamps","Shielded lights on high poles",
	"sign","Fiendsville, 1989.... May God forgive us for what we've done",
	"gate","The gate looks securely closed",
	"chain","Odd... maybe you should pull it",
});

dest_dir = ({
	"players/eurale/RMS/warp.c","warp",
	"players/eurale/Fiend/mm2.c","north",
});

}

exit() {
  if(TP) TP->clear_fight_area(); }

init() {
  ::init();
  add_action("open","open");
  add_action("pull","pull");
  add_action("north","north");
  TP->set_fight_area();
}

open(str) {
  if(!str) { write("What would you like to open?\n"); return 1; }
  if(str == "gate") {
	if(g == 1) { write("The gate is already open..\n"); return 1; }
  write("You try with all your might but the gate won't budge\n");
  say(capitalize(TPRN)+" pulls with all thier might but the gate won't budge.\n");
  return 1; }
}

pull(str) {
  if(!str) { write("What do you want to pull?\n"); return 1; }
  if(str == "chain" || str == "handle") {
  write("From somewhere inside you hear a bell ring.....\n");
  if(mon == 1) {
  player = this_player();
  mon = 0;
  call_out("enter",6);
   return 1; }
  return 1; }
}

enter() {
  say(
	"\n\nThe sound of heavy footsteps approaches the gate from inside..\n\n");
  call_out("enter1",7);
  return 1; }

enter1() {
  say(
	"The big heavy door unbolts from the inside and slowly opens...\n\n");
  move_object(clone_object("players/eurale/Fiend/NPC/frank"),TO);
  g = 1;
  call_out("enter2",7);
  return 1; }

enter2() {
  command("look",player); return 1; }


north() {
if(g == 0) { write("The heavy gate blocks your way.\n"); return 1; }
if(g == 1 && !present("frankenstein")) {
  TP->move_player("north#players/eurale/Fiend/mm2.c");
  return 1; }

if(g == 1 && present("frankenstein")) {
  write("Frankenstein blocks your entrance..\n");
  say("Frankenstein blocks your entrance..\n");
  return 1; }
}
