inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("halvorsen");
   set_race("human");
   set_alias("halvorsen");
      set_short("Mr. Halvorsen");
     set_long("The chief of the lunar base Clavius is a short man with some fat\n"+
              "on his hips and stomach.  He wears a space suit, without helmet.\n"+
              "His main issue is to make Clavius as much as earthlike as possible.\n");
   set_level(14);
   set_hp(220);
   set_al(0);
   set_wc(18);
   set_ac(11);
   set_chat_chance(13);
   load_chat("Mr. Halvorsen says:  This Monolith thing is an actual problem. I am very worried.\n");
   move_object(clone_object("/players/francesco/2001/items/map2.c"),this_object());
}
