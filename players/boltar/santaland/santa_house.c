#include "std.h"

int count;
object mclaus;
object st;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object toy, cookie, stove, gwand, pin;
     int z;
      z = random(9);
    toy = clone_object("players/boltar/things/toy.c");
  if (!present("stove")) {
   stove = clone_object("players/boltar/things/stove2.c");
     move_object(stove, this_object());
}
    if (!mclaus || !living(mclaus)) {
	mclaus = clone_object("obj/monster");
call_other(mclaus, "set_name", "claus");
call_other(mclaus, "set_short", "Mrs. Claus"); 
	call_other(mclaus, "set_hp", 150);
call_other(mclaus, "set_ac", 6);
	call_other(mclaus, "set_wc", 10);
	call_other(mclaus, "set_al", 1000);
call_other(mclaus, "set_whimpy");
	call_other(mclaus, "set_long",
    "Its Santa's wife, the jolly Mrs. Claus.\n");
	call_other(mclaus, "set_aggressive", 0);
call_other(mclaus, "set_level", 7);
	call_other(mclaus, "set_spell_mess1",
  "Mrs Claus casts a Christmas saver snow spell.");
	call_other(mclaus, "set_spell_mess2",
  "Mrs Claus casts a Christmas saver snow spell on you.");
	call_other(mclaus, "set_chance", 40);
move_object(mclaus, this_object());
call_other(mclaus, "set_spell_dam", 10);
call_other(mclaus, "set_chat_chance", 27);
call_other(mclaus, "load_chat", "Mrs Claus says: Do you want some cookies?\n");
call_other(mclaus, "load_chat", "Mrs. Claus says: Merry Christmas! \n");
call_other(mclaus, "load_chat", "Mrs Claus says: Have you been good this year little one.\n");
	money = clone_object("obj/money");
        call_other(money, "set_money", random(300));
        move_object(money, mclaus);
pin = clone_object("obj/weapon");
        call_other(pin, "set_id", "pin");
        call_other(pin, "set_name", "pin");
         call_other(pin, "set_long", "A large, heavy rolling pin");
        call_other(pin, "set_value", 300);
        call_other(pin, "set_short", "A rolling pin");
        call_other(pin, "set_weight", 2);
        call_other(pin, "set_class", 6);
        move_object(pin, mclaus);
     gwand = clone_object("players/boltar/things/gwand.c");
     move_object(gwand, mclaus);
     move_object(toy, mclaus);
 }
/*
        st = next_inventory(find_living("claus"));
*/
   st = present("stove");
   if(!present("cookie", st)){
     while(z < 12) {
      cookie = clone_object("players/boltar/things/cookie.c");
      move_object(cookie, st);
       z += 1;
   }
}
}

ONE_EXIT("players/boltar/santaland/santa_office.c", "east",
         "Mrs. Claus's kitchen",
  "You are in a very nice and very large kitchen typical of the 19th Century.\n"+
  "Everything is white with highlights in other various bright and jolly colors.\n"+
  "You can smell cookies in the oven, and sense a general good will around you.\n" +
  "The smell fills your head until all you can think about is to have some cookies" 
  , 1)
