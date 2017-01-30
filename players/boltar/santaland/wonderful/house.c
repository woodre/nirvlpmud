#include "std.h"

int count;
object george;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object petals, bell, tree;
   if (!present("tree")) {
    tree = clone_object("players/boltar/things/tree2.c");
     move_object(tree, this_object());
}
    if (!george || !living(george)) {
	george = clone_object("obj/monster");
call_other(george, "set_name", "george");
call_other(george, "set_alias", "bailey");
call_other(george, "set_short", "George Bailey"); 
call_other(george, "set_object", this_object());
	call_other(george, "set_hp", 350);
call_other(george, "set_ac", 6);
	call_other(george, "set_wc", 10);
	call_other(george, "set_al", 1000);
call_other(george, "set_whimpy");
	call_other(george, "set_long",
   "George Bailey, the man who always wanted to leave Bedford falls but\n never did.\n");
	call_other(george, "set_aggressive", 0);
call_other(george, "set_level", 12);
call_other(george, "set_move_on_reset", 0);
move_object(george, this_object());
call_other(george, "set_chat_chance", 27);
call_other(george, "load_chat", "George says: Zuzu's petals!!!!\n");
call_other(george, "load_chat", "George says: Merry Christmas! \n");
call_other(george, "load_chat", "George says: Clarence, where did you go?\n");
call_other(george, "load_chat", "George says: Can't you stop playing that song\n");
call_other(george, "load_chat", "George says: I wish I had never been born.\n");
	money = clone_object("obj/money");
        call_other(money, "set_money", random(600));
        move_object(money, george);
petals = clone_object("obj/treasure");
        call_other(petals, "set_id", "petals");
        call_other(petals, "set_short", "Zuzu's petals");
        call_other(petals, "set_value", 300);
        call_other(petals, "set_long", "The petals from Zuzu's flower.\n");
        call_other(petals, "set_weight", 0);
        move_object(petals, george);
     bell = clone_object("players/boltar/things/bell.c");
     move_object(bell, george);
    }
}

TWO_EXIT("players/boltar/santaland/wonderful/resdi_st.c", "east",
 "players/boltar/santaland/wonderful/bedroom.c", "up",
        "George's house",
  "You have entered the home of George Bailey, you notice a large staircase\n"+
  "leading upstairs and a large christmas tree in the livingroom. The house\n"+
  "is warm and cosey with the smell of holliday cooking in the air.\n"
 , 1)
