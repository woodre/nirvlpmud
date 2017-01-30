inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object weapon;
      weapon = clone_object("players/sandman/WEAPONS/g_axe");
      move_object(weapon, this_object());
      set_name("gate keeper");
      set_alias("keeper");
      set_short("Gate Keeper of Medenna");
      set_long("A swift angle of death, his sole desire is to protect the\n"+
               "holy city from intruders. He is swathed from head to toe\n"+
               "in black scaled armor. A red sash proclaims him as a member\n"+
               "of the rajah's elite guards.\n");
      set_ac(10);
      set_wc(18);
      set_race("human");
      set_level(15);
      set_hp(225);
      set_al(0);
      set_chat_chance(25);
      load_chat("Gate Keeper says: 'yell' your name to enter the city.\n");
      load_chat("Gate Keeper says: only those who 'yell' thier name may pass.\n");
      set_spell_dam(10);
      set_chance(15);
      set_spell_mess1("The Keeper's axe swipes across your chest, biting deep.\n");
      set_spell_mess2("Gate Keeper says: For the Rajah I die!!!\n");
   }
}
