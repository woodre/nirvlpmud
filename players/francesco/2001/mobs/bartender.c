inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("bartender");
   set_race("human");
   set_alias("bartender");
      set_short("The bartender");
     set_long("This female bartender moves graciously around the lounge without\n"+
              "any worries for the absence of gravity.  She wears a light blue\n"+
              "suit and a strange conical hat.\n");
   set_level(10);
   set_hp(150);
   set_al(0);
   set_wc(14);
   set_ac(8);
 move_object(clone_object("/players/francesco/2001/items/pill1.c"),this_object());
}
