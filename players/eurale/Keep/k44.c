#include "/players/eurale/defs.h"
inherit "room/room";
int here;

reset(arg) {
  if(arg) return;
here = 1;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You are standing in almost thigh-deep swamp water.  The\n"+
	"bottom is soft and squishy, making moving hard.  The cavern\n"+
	"echoes the splashing you make as you move through the water.\n"+
	"The ripples on the surface of the water here would indicate\n"+
	"that some kind of large 'thing' is hidden underneath.\n";

items = ({
	"water","Dark brownish-green, you can't see through it",
	"cavern","A large bubble in this huge stone.  It has relatively\n"+
		"smooth sides and extends farther than you can see",
	"thing","You cannot see down through the water, and something\n"+
		"tells you that you probably DON'T want to but you may\n"+
		"be able to 'feel' it with your foot",
	"ripples","Disruptive ripples to the rest of the water",
});

dest_dir = ({

	"players/eurale/Keep/k43.c","north",
	"players/eurale/Keep/k41.c","east",
	"players/eurale/Keep/k47.c","west",
});

}

init() {
  ::init();
  add_action("feel","feel");
}

feel(str) {
if(!str) { write("What are you trying to feel?\n"); return 1; }

if(str == "thing" && here == 0) {
  write("You feel with your foot and stub your toe on a huge rock...\n");
  TP->heal_self(-random(30));
  return 1; }

if(str == "thing" && here == 1) {
if(this_player()->query_extra_level() < 10) {
    write("A huge dragon head pops up out of the water....\n\n"+
	  "Dripping, it looks you in the eyes and hisses...\n\n"+
	  "Come back when you have the experience to make this\n"+
	  "a decent fight...for now you are too puny!!\n\n"+
	  "and the head slowly sinks back into the water..\n\n");
  say("A dragon head pops out of the water, hisses, then resubmerges.\n");
    return 1; }

  else {
    write("The water begins to bubble......\n\n"+
	  "and with a "+HIC+"HUGE SPLASH"+NORM+" a fearsome creature\n"+
	  "emerges from the murky water....\n\n");
    say("The water SPLASHES and a fearsome dragon appears...\n");
    move_object(clone_object("players/eurale/Keep/NPC/sea_dragon"),TO);
    here = 0;
    return 1; }
  return 1; }
}
