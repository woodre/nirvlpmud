inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object bookt;
   bookt = clone_object("players/persephone/obj/book.c");
   move_object(bookt, TOB);
   set_name("Einstein");
   set_alias("womble");
   set_short("Einstein Womble");
   set_long("Einstein is the famed Womble of science he is perhaps\n" +
            "the smallest of the wombles but can be quick\n");
   set_level(4);
   set_wc(8);
   set_ac(3);
   set_hp(65);
   set_al(100);
   set_aggressive(0);
   set_gender(0);
   set_chance(0);
   set_spell_dam(0);
   set_chat_chance(50);
    load_chat("Einstein exclaims: E=MC2!\n");
    load_chat("Einstein opens up his book and begins reading.\n");
    load_chat("Einstein scratches his head.\n");
    load_chat("Einstein stares at the trees wondering where his testubes are\n");
   set_a_chat_chance(40);
    load_a_chat("Einstein exclaims: I am against fighting!\n");
    load_a_chat("Einstein states: Nuclear research should be used for peaceful purposes\n");
    load_a_chat("Einstein sobs: Stop hitting me\n");
  }
}

