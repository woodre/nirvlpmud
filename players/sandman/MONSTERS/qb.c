inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object ball;
      ball = clone_object("players/sandman/WEAPONS/foot_ball");
      move_object(ball, this_object());
      set_name("quarterback");
      set_alias("jerk");
      set_short("A quarterback");
      set_long("This is the most popular guy in school.\n");
      set_ac(5);
      set_wc(9);
      set_race("human");
      set_level(5);
      set_hp(75);
      set_al(150);
      set_chat_chance(15);
      load_chat("Quarterback says: I am so handsome!\n");
      load_chat("Quarterback says: I am so cool!\n");
      set_a_chat_chance(20);
      load_a_chat("Quarterback says: Now i must kill you nerd!\n");
   }
}
