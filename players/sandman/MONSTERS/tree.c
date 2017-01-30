inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object treas;
      treas = clone_object("players/sandman/OBJ/acorn");
      move_object(treas, this_object());
      set_name("tree");
      set_alias("evil tree");
      set_short("An Evil Tree");
      set_long("An evil gnarled tree.\n");
      set_ac(12);
      set_wc(20);
      set_race("plant");
      set_level(15);
      set_hp(230);
      set_al(-300);
      set_chat_chance(10);
      load_chat("An Evil Tree uproots and moves towards you.\n");
      load_chat("An Evil Tree ruffles its branches menacingly.\n");
      set_a_chat_chance(20);
      load_a_chat("A Tree crushes you with its limbs!\n");
   }
}
