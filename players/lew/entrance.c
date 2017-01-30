#include "room.h"

object student, card;
int C;  /*  one id card  */

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money, card;
    if (!student || !living(student)) {
C = 1;
	student = clone_object("obj/monster_lars");
	call_other(student, "set_name", "student");
	call_other(student, "set_level", 9);
	call_other(student, "set_hp", 100);
	call_other(student, "set_wc", 15);
	call_other(student, "set_al", 0);
	call_other(student, "set_short", "An overworked student");
	call_other(student, "set_long",
"This student looks tired and overworked, and may have become a bit mean.\n");
	call_other(student, "set_aggressive", 1);
	call_other(student, "set_spell_mess1",
"The studente says: I hate this f__kin' place!!");
	call_other(student, "set_spell_mess2",
"The student says: Get out while you still can!");
	call_other(student, "set_chance", 20);
	move_object(student, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(500));
        move_object(money, student);
    }
}

TWO_EXIT( "players/lew/res_hall", "east",
	 "players/lew/state_st", "west",
"The Miesian nightmare",

"You are in the Miesian nightmare, the new entrance to the dorms."+
  "\n",1)

init() {
  ::init();

    add_action("search", "search");
    add_action("goin", "enter");
     add_action("east","east");

}

/*  moved the card to room /players/lew/commons  3/29/97  */
/*
search(str) {
    card=clone_object("players/lew/card1");
    if(!str) { write("Try searching the ground.\n"); return 1; }
    if(present("card", this_player())) return 0;
    if(str != "ground") return 0;
    move_object(card, this_player());
    write("You find a meal card and pick it up.\n");
    return 1;
}
*/
search(str) {
if(present("student")) {
  write("The angry student screams, 'Not while I'm here!'\n");
  return 1; }
if(!str) { write("Try searching the ground.\n"); return 1; }
if(str == "ground" && C == 1) {
  write("You search the ground and find an ID card.\n");
  move_object(clone_object("players/lew/card2.c"),this_player());
  C = 0;
  return 1; }
else {
  write("You search furiously and find nothing.\n");
  return 1; }
}

east() {
if(present("student")) {
  write("The student pokes you and says, 'You don't belong here!'\n");
  return 1; }
else {
  this_player()->move_player("east#players/lew/res_hall.c");
  return 1; }
}

long() {
  ::long();
  if(this_player()->query_attrib("int") > random(40)) {
     write("There may be something on the ground...\n");
  }
}
