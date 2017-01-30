inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("navigator");
   set_race("human");
   set_alias("navigator");
      set_short("Navigator of the Space Shuttle 5");
     set_long("The navigator pilot must be ready to execute all the commands said\n"+
              "by the captain and eventuallly to substitute him.  He is frantically\n"+
              "busy working around all the intrumentation of the Space Station, even\n"+
              "in long interplanetary trips.  He wears a silvery suit, his hair is\n"+
              "well trimmed and his health looks great.\n");
   set_level(13);
   set_hp(195);
   set_al(0);
   set_wc(17);
   set_ac(10);
 move_object(clone_object("/players/francesco/2001/items/tool.c"),this_object());
}
