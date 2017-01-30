/*  Jurassic Park  */

#include "defs.h"
inherit "room/room";
int T;  /* tooth variable to make sure only 1  */

reset(arg) {

if(!present("rex")) {
  move_object(clone_object("players/eurale/Park/NPC/rex4"),TO); }
  T = 1;  /* 2005.04.08 moved so always a tooth with each rex -Forbin */

  if(arg) return;
set_light(0);
/* T = 1; */ /*  tooth here  */

short_desc = "Jurassic Park";
long_desc =
	"  You have entered a land covered with a dense growth of trees \n"+
	"that blocks out most of the sun.  The vegetation is very tall \n"+
	"and consists of huge ferns and very thick vines which fall from \n"+
	"high up in the trees.  The air is hot and humid and you can hear \n"+
	"the sound of huge animals all around you. \n";

items = ({
	"trees","The trees are very tall with thick growth at the top. \n"+
		"They provide protection and shelter",
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
		"fronds that reproduce by spores instead of seeds",
	"vines","Large, thick, rope-like stems of plants that climb the \n"+
		"trees and run along the ground",
});

dest_dir = ({
	"players/eurale/Park/jp75.c","south",
});

}

init() {
  ::init();
  add_action("pry","pry");
}

pry(str) {
if(str == "tooth" && present("rex")) {
  write("The big 'rex' take a nasty nip at your hand....\n");
  TP->heal_self(-random(30));
  return 1; }
if(!str) { write("Pry what?\n"); return 1; }
if(str == "tooth" &&
    present("corpse",environment(this_player())))
  if(present("corpse",environment(this_player()))->query_name() == "rex") {

 if(T == 1) {
  write("You pry the bloody tooth from the dead 'rex's mouth.\n");
  move_object(clone_object("players/eurale/Park/OBJ/tooth"),TP);
  T = 0;
  return 1; }
 else {
  write("You try to pry out a tooth and discover that there are\n"+
	"no more loose ones to be had.\n");
  return 1; }

  return 1; }
}
