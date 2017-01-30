#include "std.h"

int count;
object santa;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object list, emoter, tree;
   if (!present("tree")) {
    tree = clone_object("players/boltar/things/tree.c");
     move_object(tree, this_object());
}
    if (!santa || !living(santa)) {
	santa = clone_object("obj/monster");
call_other(santa, "set_name", "santa");
call_other(santa, "set_alias", "claus");
call_other(santa, "set_short", "Santa Claus"); 
call_other(santa, "set_object", this_object());
	call_other(santa, "set_hp", 350);
call_other(santa, "set_ac", 9);
	call_other(santa, "set_wc", 15);
	call_other(santa, "set_al", 1000);
call_other(santa, "set_whimpy");
	call_other(santa, "set_long",
   "Its the jolly fat man from the north pole itself.\n");
	call_other(santa, "set_aggressive", 0);
call_other(santa, "set_level", 15);
call_other(santa, "set_move_on_reset", 0);
	call_other(santa, "set_spell_mess1",
  "Santa casts a Christmas saver snow spell.");
	call_other(santa, "set_spell_mess2",
  "Santa casts a Christmas saver snow spell on you.");
	call_other(santa, "set_chance", 40);
move_object(santa, this_object());
call_other(santa, "set_spell_dam", 12);
call_other(santa, "set_chat_chance", 27);
call_other(santa, "load_chat", "Santa says: Ho ho ho!\n");
call_other(santa, "load_chat", "Santa says: On donner on cupid on comet on vixen.\n");
call_other(santa, "load_chat", "Santa says: Merry Christmas! \n");
call_other(santa, "load_chat", "Santa says: Have you been good this year little one.\n");
call_other(santa, "load_chat", "Santa says: Where are my reindeer?\n");
call_other(santa, "load_chat", "Santa says: Rudolph, I need you.\n");
call_other(santa, "set_a_chat_chance", 25);
call_other(santa, "load_a_chat", "Santa says: The list, the list I must burn the list!\n");
call_other(santa, "load_a_chat", "Santa says: You are being very naughty. Its going to be coal for you this year.\n");
	money = clone_object("obj/money");
        call_other(money, "set_money", random(600));
        move_object(money, santa);
list = clone_object("obj/treasure");
        call_other(list, "set_id", "list");
        call_other(list, "set_read", "You are unable to read Santa's criptic writing. You notice\n" +
 "something about you being naughty however.\n");
        call_other(list, "set_short", "A list of who is naughty and nice");
        call_other(list, "set_value", 300);
        call_other(list, "set_long", "A list of who is naughty and nice.\n");
        call_other(list, "set_weight", 0);
        move_object(list, santa);
     emoter = clone_object("players/boltar/things/emoter.c");
     move_object(emoter, santa);
    }
}

TWO_EXIT("players/boltar/santaland/santa_house.c", "west",
 "players/boltar/santaland/wk_shp_ent.c", "east",
        "Santa's workshop office",
  "This room looks like a simple office common to that of the 19th century\n"+
  "However it looks rather jolly and nice. Designs of toys are all over\n"+
  "the room, as well as many completed and partially completed toys.\n" 
 , 1)
