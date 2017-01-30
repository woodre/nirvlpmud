/* Fixed a typo.  Verte [11-30-01] */
inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object bone;
      bone = clone_object("players/persephone/bone");
      move_object(bone, this_object());
      set_name("puppy");
      set_alias("dog");
      set_short("Cute little puppy");
      set_long("This is the dog you always wanted as a kid.\n");
      set_ac(4);
      set_wc(7);
      set_race("canine");
      set_level(4);
      set_hp(50);
      set_al(150);
      set_chat_chance(15);
      load_chat("A puppy dog barks happily :)\n");
      load_chat("A puppy dog wags its tail. It's happy to see you.\n");
      set_a_chat_chance(20);
      load_a_chat("A puppy dog whimpers in pain!\n");
      load_a_chat("A puppy dog gives you a pathetic stare.\n");
   }
}
