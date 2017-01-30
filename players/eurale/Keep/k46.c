#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "room/room";
object ob;
int full;

reset(arg) {
  if(arg) return;
full = 0;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You are standing in the the thigh-deep swamp water.  The\n"+
	"bottom is soft and squishy, making moving hard.  The cavern\n"+
	"echoes the splashing you make as you move through the water.\n"+
	"As you step into the muck, you feel a hard object with your \n"+
	"foot.\n";

items = ({
	"water","Dark brownish-green, you can't see through it",
	"cavern","A large bubble in this huge stone.  It has relatively\n"+
		"smooth sides and extends farther than you can see",
	"object","The water is too murky but you might be able to feel it",
});

dest_dir = ({

	"players/eurale/Keep/k45.c","north",
	"players/eurale/Keep/k47.c","south",
	"players/eurale/Keep/k43.c","east",
});

}

init() {
  ::init();
  add_action("feel","feel");
  add_action("push","push");
}

feel(str) {
if(!str) { write("What are you trying to feel?\n"); return 1; }
if(str == "object") {
  write("You feel around with your foot and discover that there is some\n"+
        "sort of pushable lid or door concealed in the mucky bottom.  A\n"+
	     "strange sort of suction is holding it in place...\n");
  say(tpn+" seems to be doing something...\n");
  return 1; }
}

push(str) {
if(!str) { write("Are you trying to push something?\n"); return 1; }
if( (str == "lid" || str == "door") && full == 1) {
  write("Try as you might but you can't budge the lid...\n"); return 1; }
if((str == "lid" || str == "door") && full == 0) {
  write("You feel around and find a spot where you can get your foot\n"+
	 "in a good position to move the lid.... and you push... \n\n");
  say(tpn+" makes a face as he strains against something in the water.\n");
  ob = this_player();
full = 1;
  call_out("suck1",3);
  return 1; }
}

suck1() {
tell_object(ob,
	"The lid pushes to the side and immediately you feel the swirl\n"+
	"of water around your legs.... getting stronger...\n\n");
  call_out("suck2",4);
  return 1; }

suck2() {
tell_object(ob,
	"The water is being sucked into a hole you've uncovered at an\n"+
	"alarming rate.... too strong for you to resist....\n\n");
  say("You see the water being to swirl about you... \n\n");
  call_out("suck3",4);
  return 1; }

suck3() {
tell_object(ob,
	"The dark, murky water rushes up your nose and you feel yourself\n"+
	"being pulled down...down....down... deeper into the water.\n");
  ob->move_player("disapppears#players/eurale/Keep/k64.c");
  command("look",ob);
  return 1; }
