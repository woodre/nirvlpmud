inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("cabbage patch kid");
   set_level(6);
   set_alias("kid");
   set_race("doll");
   set_hp(90);
   set_al(25);
   set_short("A dazed cabbage patch kid");
   set_long("The cute cabbage patch kid has a glazed look it its eyes.\n"+
      "It gazes at the ceiling oddly.  It seems to be sucking on something odd.\n");
   set_wc(10);
   set_ac(5);
   set_alt_name("quest_cabbage");
   move_object(clone_object("/players/llew/Toys/misc/potato_arm"),this_object());
}
