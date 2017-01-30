/* Recode of Grimm's castle - time to put this baby back in the game!
 * Rumplemintz - original Dopple!
 */

#include <ansi.h>

#define NAME "Grimm"
#define DEST "room/vill_green"

int id(string str) { return str == "arrow"; }

string short() { return "A LARGE " + HIY + "neon" + NORM + " arrow " +
                        "pointing south"; }

void long() {
  write(
"A salesman notices you are interested in his sign and jumps out to greet you.\n"+
"The salesman says:  Are you level 5 or below?\n"+
"The salesman says:  Do you want the easy life?\n"+
"The salesman says:  Do you want some easy cash in a hurry?\n"+
"The salesman says:  Of COURSE you do!  All you have to do is enter the wild\n"+
"                    and crazy world of make believe!\n"+
"The salesman says:  If you AREN'T level 5 or below, just go south anyway\n"+
"                    and then go DOWN!\n"+
"With that, the salesman struts off to write some more sales pitches.\n\n");
}

void init() {
  add_action("south", "south");
}

int south() {
  this_player()->move_player("south#/players/grimm/newbie/rooms/entrance");
/*
  this_player()->move_player("south#players/grimm/guild");
*/
  return 1;
}

void reset(int arg) {
  object room, quest;

/* Not right now, not sure if we need these or not...
  load_object("/players/grimm/fixer");
  load_object("/players/grimm/closed/obj/mystic");
  load_object("/players/grimm/closed/obj/barb");
  load_object("/players/grimm/closed/obj/speed");
  room = find_object("room/quest_room");
  if (!present("sage", room)) {
    quest = clone_object("obj/quest_obj");
    quest->set_name("sage");
    quest->set_hint("Wake the Sage of ReesePort for more details.\n");
    move_object(quest, room);
  }
  */
  if (arg)
    return;
  move_object(this_object(), DEST);
}

int is_castle() { return 1; }
