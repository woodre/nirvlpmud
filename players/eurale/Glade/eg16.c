#include "defs.h"
inherit "room/room";
int F;

reset(arg) {
  if(arg) return;
set_light(1);
F = 1;

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  The path through this stand of hardwoods is shaded and delightful.\n"+
  "The wildflowers seem to grow abundantly throughout the woods.\n";

items = ({
  "path","Dirt covered with fallen leaves",
  "hardswoods","Oak, Ash and Elm",
  "wildflowers","Small, dainty flowers of every imaginable color",
});

dest_dir = ({
  "players/eurale/Glade/eg17.c","north",
  "players/eurale/Glade/eg2.c","south",
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("pick","pick");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

pick(str) {
object ob;
if(!str) { write("Pick what?\n"); return 1; }
if(str == "flower" || str == "flowers" || str == "wildflower"
  || str == "wildflowers") {
  if(F == 1) {
    write("As you bend over to pick one of the lovely wildflowers, a\n"+
	  "sudden movement catches your eye....\n");
    ob = clone_object("players/eurale/Glade/NPC/killer_frog.c");
    move_object(ob,this_object());
    ob->attack_object(TP);
    F = 0;
    return 1; }
  else {
    write("The wind through the trees sounds like a voice saying,\n"+
	  "'Leave the forest undisturbed....move on.'\n");
    return 1; }
return 1; }
}
