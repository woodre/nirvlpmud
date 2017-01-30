#include "defs.h"
inherit "room/room";
int EGG, BABY;

reset(arg) {

if(!present("female")) {
  move_object(clone_object("players/eurale/Park/NPC/femtri"),TO); }

  if(arg) return;
set_light(0);
EGG = 1;
BABY = 1;

short_desc = "Jurassic Park";
long_desc =
	"  You walk back into the hillside opening only to discover that\n"+
	"you have entered the den of a fearsome triceratops.  There is\n"+
	"a large dirt mound with the top of what appears to be large\n"+
	"egg sticking up through it in the middle of this smelly, hot\n"+
	"cavern.  You can still hear the sounds of the jungle as they\n"+
	"echo off the cavern walls from outside.\n";

items = ({
  "mound","Dirt that has been piled up to protect and keep eggs warm",
  "egg","The single egg of a triceratops.  Maybe you could dig it out",
});

dest_dir = ({
	"players/eurale/Park/jp28.c","out",
});

}

init() {
  ::init();
  add_action("dig","dig");
}

dig(str) {
int num;
if(present("triceratops")) {
  write("The big female moves between you and her nest..\n");
  return 1; }
if(!present("archaeology spade",this_player())) {
  write("You'll need an archeology spade to dig here.\n"); return 1; }
if(!str) { write("What is it you're trying to dig up?\n"); return 1; }

if(str == "egg" && EGG == 1) {
  num = random(100);
  if(num < 60 && BABY == 1) {
    write("You begin to dig around the fragile egg and hear a 'crack'\n"+
	"as the point of your spade hits the shell...\n");
    move_object(clone_object("players/eurale/Park/NPC/baby_tri"),TO);
    BABY = 0;
    return 1; }
  else {
    write("You ever-so-carefully dig around the delicate egg until you\n"+
	"have unearthed this rare treasure.\n");
    move_object(clone_object("players/eurale/Park/OBJ/tri_egg"),TO);
    if(TP->query_guild_name() == "vampire" && !present("vamptask6",TP))
      move_object(clone_object("players/eurale/Park/vamp_task6.c"),TP);
    EGG = 0;
    return 1; }
 }

if(str == "egg" && EGG == 0) {
  write("You begin to dig around the delicate egg only to discover that\n"+
	"it has hatched and this is nothing but a shell piece.\n");
  return 1; }
}
