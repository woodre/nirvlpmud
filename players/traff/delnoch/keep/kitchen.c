/* KITCHEN.C - Part of Delnoch Keep.  In this room players may get 1
    free 15 pt. heal by figuring out clues.  Also a couple of the
    Monsters carry the same heal, ROLL.C.  An array is used to keep
    track of the players that have gotten a free heal and prevents
    them from getting more than 1 per reboot.
    Changes as of 6-1-96:
    Color added, paths changed to fit new directory structure.
*/
#include "/players/traff/closed/ansi.h"
#define tp this_player()->query_name()

inherit "room/room";
string *found_roll;

reset(arg){

  if(!present("cook"))  {
  move_object(clone_object("/players/traff/delnoch/mon/cook.c"),this_object());  }

  if(!present("helper"))  {
  move_object(clone_object("/players/traff/delnoch/mon/cookhelp.c"),this_object());  }

  if(!arg){

    found_roll = ({ }); /* allocate starting point */
    set_light(1);
    long_desc=(MAG+
"This is where the meals are prepared for the keep residents.\n"+
"A large wood burning stove dominates the center of the room.  At the\n"+
"side of the stove is a long counter.  There is a tray of fresh\n"+
"dinner rolls on the counter.  There are pots and pans on the\n"+
"stove, and various utensils scattered around the room.\n"+NORM);

    items=({
"floor","The floor is rough flagstone from the mountains",
"stove","A wood burning stove",
"oven","A large oven, it is part of the stove",
"counter","It looks like a cutting board, but about 6 feet long",
"rolls","They look and smell great.  Several are missing already",
"tray","A large tray full of rolls, a few are missing",
"pots","Full of soups and vegatables you guess",
"pans","More food cooking for the next meal",
"utensils","You know, knives, forks, spoons, ladles and such",
 });

    dest_dir=({
      "/players/traff/delnoch/keep/scullery.c","north",
      "/players/traff/delnoch/keep/easthall.c","south",
      });
    }
  }

short() {return HIC+"Kitchen"+NORM;}

is_member(str, arr) {
  int i,so;
  for(i = 0, so = sizeof(arr); i < so; i++) {
    if(arr[i] == str) return 1;
  }
  return 0;
}
init()  {
 ::init();
  add_action("search","search");
  add_action("swipe","swipe");
}

search(str)  {

  if(!str) {
    write("Search what?\n");
    return 1; }

  write("You search the "+str+" but find nothing of interest.\n");
  return 1; }

/* This checks the array to see if player has gotten a free roll.
   if not it moves the roll to the player. */
swipe(str) {
object food;
  if(!str) {
    write("You can't do that.\n");
    return 1; }
    if(is_member(tp,found_roll)) {
      write("Don't be so greedy!\n");
    return 1; }
    food = clone_object("/players/traff/delnoch/obj/roll.c");
    if (!call_other(this_player(), "add_weight",
	call_other(food, "query_weight"))) {
	write("You can't carry more.\n");
	destruct(food);
	return 1;
    }
    move_object(food, this_player());
    write("You swipe a roll.\n");
    say(call_other(this_player(), "query_name")+" swipes a roll.\n");
    found_roll += ({ tp });
    return 1;
}

