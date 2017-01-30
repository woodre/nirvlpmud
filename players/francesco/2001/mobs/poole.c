inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("poole");
   set_race("human");
   set_alias("poole");
      set_short("Poole");
     set_long("Poole wears a very comfortable silvery space suit, without helmet.\n"+
              "He is on charge of the mission.  He knows very well the structure\n"+
              "and the features of the Discovery.  Stands about 6 feet tall.\n");
   set_level(13);
   set_hp(195);
   set_al(0);
   set_wc(17);
   set_ac(10);
   set_chat_chance(11);
   load_chat("Poole mumbles:  Hal is behaving strangely during the last few days.\n");
   move_object(clone_object("/players/francesco/2001/items/map3.c"),this_object());
}
