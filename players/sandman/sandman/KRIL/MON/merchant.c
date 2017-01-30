inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object gold;
      gold = clone_object("obj/money");
     gold->set_money(random(200));
      move_object(gold, this_object());
      set_name("merchant");
      set_alias("merchant");
      set_short("Merchant");
     set_long("This is one of the many merchants who traverse the land of\n"
+             "Krillyn. Notice the squinted eyes, the death grip he has on\n"
+             "his money pouch. Sure signs of the merchant class.\n");
      set_ac(7);
      set_wc(12);
      set_race("human");
      set_level(9);
      set_hp(90);
      set_aggressive(0);
      set_al(0);
      set_chat_chance(15);
       load_chat("A merchant checks his coin purse suspiciously.\n");
      load_chat("A merchant hawks his wares by the side of the road.\n");
      set_a_chat_chance(10);
   load_a_chat("A merchant yells: Help, someone call the watch!!\n");
    load_a_chat("A merchant screams: Unhand me you ruffian!\n");
   }
}
