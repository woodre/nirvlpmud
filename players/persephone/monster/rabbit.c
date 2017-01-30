inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset(arg){
 ::reset(arg);
  if(!arg){
   object pill1,pill2,pill3,gold;
   pill1 = clone_object("players/persephone/closed/pilla.c");
   move_object(pill1, TOB);
   pill2 = clone_object("players/persephone/closed/pillb.c");
   move_object(pill2, TOB);
   pill3 = clone_object("players/persephone/closed/pillc.c");
   move_object(pill3, TOB);
   gold = clone_object("obj/money");
   gold->set_money(1000+random(1000));
   move_object(gold, TOB);
   set_name("rabbit");
   set_alias("bunny");
   set_short("A White Rabbit");
   set_long("A distinguished looking white rabbit with a splendid\n" +
           "top hat and coat with tails. He looks familiar to you\n" +
           "perhaps he is the Mad Hatter.\n");
   set_level (18);
   set_wc(26);
   set_ac(15);
   set_hp(450);
   set_al(-300);
   set_aggressive(0);
   set_gender(0);
  set_chat_chance(20);
    load_chat("White Rabbit snickers: That brat Alyss will never escape now.\n");
    load_chat("White Rabbit exclaims: Do you need a hat I have some nice hats!\n");
    load_chat("White Rabbit asks: I wonder what these pills do. Do you know?\n");
    load_chat("White Rabbit asks: Would you like to come to my tea party?\n");
    load_chat("White Rabbit boasts: You cannot touch me I am the kings friend.\n");
  }
}
