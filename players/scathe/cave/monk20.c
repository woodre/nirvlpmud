#include "lib.h"
inherit ROOM;
int R;

void create() {
    ::create();
    set_short("Just for Kicks");
    set_long("\
  You enter a calm and serene garden, and you are overwhelmed at the\n\
beauty and fragrances which surround you.  A great deal of time and\n\
effort have been put into this accomplishment.  You have entered the\n\
domain of the Monks of the Dragon Fist Order.  Tread carefully stranger.\n");
    set_light(1);
    set_exits(([
	"west":"/players/scathe/cave/monk19",
	]));
}
void reset(int arg) {
    int x;
    object monster;

    ::reset(arg);
    if (!present("grandmaster", this_object())) {
	x = 1;
	while (x--) {
	    monster = clone_object("/players/scathe/monsters/gmaster");
	    move_object(monster, this_object());
	}
    }
}
void init() {
    ::init();
    add_action("dir","pick");
  add_action("search","search");
}
status dir(string arg) {
   write("The Grandmaster notices your feeble thief attempt, and kicks your teeth in\n");
   this_player()->hit_player(15);
   return 1;
}

search(str) {
if(present("monk")) {
  write("The monk folds your hands and says, 'Pray with me.'\n");
  return 1; }
if(!str) { write("What are you trying to search?\n"); return 1; }
if(str == "garden" && R == 0) {
  write("You search through the plants and foliage of the garden\n"+
	"and discover part of a rod.\n");
  move_object(clone_object("players/scathe/closed/rod1.c"),this_player());
  R = 1;
  return 1; }
else {
  write("You search the garden and find nothing but earthworms.\n");
  return 1; }
}
