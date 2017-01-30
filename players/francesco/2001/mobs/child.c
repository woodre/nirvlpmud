inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("child");
   set_race("human");
   set_alias("child");
      set_short("A child");
     set_long("This 13 years old child is doing a hard workout to keep his\n"+
              "fitness up.  The lack of gravity here makes his movements \n"+
              "somehow hilarious since he is still not acquainted to the \n"+
              "lunar atmosphere.  He wears only a gym suit that hides\n"+
              "his weak musculature completely.\n");
   set_level(10);
   set_hp(150);
   set_al(0);
   set_wc(14);
   set_ac(8);
move_object(clone_object("/players/francesco/2001/items/pill3.c"),this_object());
}
