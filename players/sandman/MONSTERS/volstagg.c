inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object armor;
      armor = clone_object("players/sandman/ARMORS/doublet");
      move_object(armor, this_object());
      set_name("volstagg");
      set_alias("big guy");
      set_short("Volstagg");
      set_long("The rotund leader of the Warriors Three.\n");
      set_ac(13);
      set_wc(22);
      set_race("immortal");
      set_level(16);
      set_hp(300); /* Changed from 400 to 300. -Feldegast 1/26/01 */
      set_al(200);
      set_chat_chance(15);
      load_chat("Volstagg belows: Am I not the bravest in Asgard?\n");
      load_chat("Volstagg says: Let us go my companions, Midgard awaits!\n");
      set_a_chat_chance(20);
      load_a_chat("Volstagg shouts: Now you face the Warriors Three!!\n");
      add_money(50*random(30)); /* 0-1500 coins - Feldegast 1/26/01 */
   }
}
