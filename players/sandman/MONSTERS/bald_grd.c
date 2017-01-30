inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name("guard");
      set_alias("giant guard");
      set_short("Giant Guard");
      set_long("One of the giants who owe allegience to Baldar the Brave.\n");
      set_ac(12);
      set_wc(20);
      set_race("giant");
      set_level(15);
      set_hp(225);
      set_aggressive(1);
      set_al(0);
      set_chance(20);
      set_spell_mess1("A giant kicks you in the gut!\n");
      set_spell_mess2("You feel your bones crack as another blow hits you!\n");
      set_spell_dam(15);
   }
}
