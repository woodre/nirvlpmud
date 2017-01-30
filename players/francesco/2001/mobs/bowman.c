inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("bowman");
   set_race("human");
   set_alias("bowman");
      set_short("Bowman");
     set_long("Bowman wears a very comfortable silvery space suit, without helmet.\n"+
              "He is on charge of controlling the hardware of the Discovery.\n"+
              "Stands about 6 feet tall.\n");
   set_level(13);
   set_hp(195);
   set_al(0);
   set_wc(17);
   set_ac(10);
   set_chat_chance(11);
   load_chat("Bowman mumbles:  I cant understand why Poole is so worried about Hal.\n");
   move_object(clone_object("/players/francesco/2001/items/map3.c"),this_object());
}
