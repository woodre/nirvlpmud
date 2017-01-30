inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object weapon;
      weapon = clone_object("players/sandman/WEAPONS/war_hammer");
      move_object(weapon, this_object());
      set_name("warrior");
      set_alias("viking warrior");
      set_short("Viking Warrior");
      set_long("One of the timeless guardians of Asgard.\n");
      set_ac(13);
      set_wc(21);
      set_race("immortal");
      set_level(16);
      set_hp(300);
      set_aggressive(1);
      set_al(0);
      set_chance(20);
      set_spell_mess1("The warrior slams you with his hammer!\n");
      set_spell_mess2("You feel your bones crack as another blow hits you!\n");
      set_spell_dam(5);
      add_money(500);
   }
}
