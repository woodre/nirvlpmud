inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object gold;
      gold = clone_object("obj/money");
      gold->set_money(random(400));
      move_object(gold, this_object());
      set_name("raven");
      set_alias("odin's raven");
      set_aggressive(1);
      set_short("Odin's Raven");
      set_long("One of Odin's trusty ravens.\n");
      set_ac(12);
      set_wc(10);
      set_race("animal");
      set_level(7);
      set_hp(250);
      set_al(0);
      set_chance(15);
      set_spell_mess1("Raven snaps at you with his beak!\n");
      set_spell_mess2("Raven rakes you with it's sharp claws.\n");
      set_spell_dam(20);
   }
}
