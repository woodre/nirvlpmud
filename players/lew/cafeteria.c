#include "room.h"

object burger;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
   object money, mushroom;
   if (!burger || !living(burger)) {
   burger = clone_object("obj/monster");
	call_other(burger, "set_name", "burger");
        call_other(burger, "set_alias", "hamburger"); /* Rumplemintz */
	call_other(burger, "set_level", 10);
	call_other(burger, "set_hp", 150);
	call_other(burger, "set_wc", 15);
   call_other(burger, "set_exp", 1000);
	call_other(burger, "set_al", -100);
	call_other(burger, "set_short", "A killer hamburger");
	call_other(burger, "set_long",
"This is one of the many hamburgers that the cafeteria cooks try\n" +
"pass as real food.  As you can see, this one isn't quite done. \n");
	call_other(burger, "set_aggressive", 1);
	call_other(burger, "set_spell_mess1",
"The burger screams as it sizzles on the grill.");
  call_other(burger, "set_chance", 10);
   call_other(burger, "set_spell_mess2",
"Burger says:  Go ahead, eat me.  I DARE you.");
	call_other(burger, "set_chance", 20);
	move_object(burger, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(500));
        move_object(money, burger);
   mushroom = clone_object("players/lew/shroom");
        move_object(mushroom, burger);
    }
}

TWO_EXIT("players/lew/lounge2", "north",
        "players/lew/res_hall", "south",
"The Cafeteria",

"You have entered the Cafeteria.  Carefull the food here is known to\n" +
"be somewhat fatal.  To the north is McCormic lounge.\n",1)

/*  additions by Eurale  3/29/97  */
init() {
  ::init();
  add_action("north","north");
  add_action("show","show");
}

north() {
if(present("burger")) {
  write("The hamburger SLAPS you with a pickle.\n");
  return 1; }
else {
  write("The nastiest looking cafeteria lady you've ever seen steps\n"+
	"in front of you and snarls, 'Nobody goes that way without\n"+
	"a meal card.  Show me yours!'\n");
  return 1; }
}

show(str) {
object ob;
ob = present("mealcard",this_player());
if(str == "card" || str == "meal card" && !ob) {
  write("She says, 'Nice try bozo!'\n");
  return 1; }
else {
  write("She says, 'This looks like a forgery! I'll keep it.\n");
  this_player()->move_player("north#players/lew/lounge2.c");
  destruct(ob);
  return 1; }
}
