inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object gold;
   object glasses;
   gold = clone_object("obj/money");
   gold->set_money(150);
   glasses = clone_object("players/persephone/obj/glass.c");
   move_object(glasses, TOB);
   move_object(gold, TOB);
   set_name("wimbledon");
   set_alias("womble");
   set_short("Wimbledon the Womble");
   set_long("The most playful of the Wombles Wimbledon has a mischevious\n" +
            "outlook on life. If you look closely he has a bright\n" +
            "glint in his eyes as he returns your glance\n");
   set_level(6);
   set_wc(10);
   set_ac(5);
   set_hp(100);
   set_al(300);
   set_aggressive(0);
   set_gender(0);
   set_chance(0);
   set_spell_dam(0);
   set_chat_chance(35);
    load_chat("Wimbledon tickles you all over the body.\n");
    load_chat("Wimbledon ties your shoe laces together.\n");
    load_chat("Wimbledon exclaims: I am bored lets play a game\n");
    load_chat("Wimbledon asks: Have you seen Einstein\n");
   set_a_chat_chance(40);
    load_a_chat("Wimbledon cries: Stop picking on me\n");
    load_a_chat("Wimbledon sobs: You big bully\n");
    load_a_chat("Wimbledon screams: Heironomus help me\n");
  }
}

