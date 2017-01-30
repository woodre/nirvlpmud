inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object honey;
   honey = clone_object("players/persephone/obj/honey");
   move_object(honey, TOB);
   set_name("bee");
   set_alias("bumblebee");
   set_short("A Pretty Bee");
   set_long("A little Honey Bee that seems to flit around the wild flowers\n" +
            "He seems extremely cute and harmless\n\n");
   set_level (4);
   set_wc(7);
   set_ac(4);
   set_hp(60);
   set_al(0);
   set_aggressive(0);
   set_gender(0);
   set_chance(5);
   set_spell_dam(5);
    set_spell_mess1("The Bee flies around agitated trying to sting someone\n");
    set_spell_mess2("The bee lands on your arm and stings you OUCH!!!\n");
   set_chat_chance(45);
    load_chat("The Bee buzzes: Bzz Bzz Bzz\n");
    load_chat("The Bee sits on a flower\n");
    load_chat("The Bee flies around\n");
    load_chat("The Bee hums: Hmm Hmm Hmm\n");
   set_a_chat_chance(50);
    load_a_chat("The Bee lands on your arm\n");
    load_a_chat("The Bee looks agitated\n");
    load_a_chat("The Bee flies around the tree\n");
  }
}
