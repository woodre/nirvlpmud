
inherit "obj/monster";

reset(arg) {
     object money, amulet;
     ::reset(arg);
     if(!arg) {
          set_name("vampire");
          set_race("undead");
          set_level(20);
          set_hp(525);
          set_al(-1000);
          set_short("a vampire");
          set_long("This pale-skinned man smiles at you. His charm seems\n"+
                   "to make up for the fangs he bears as he draws nearer.\n");
          set_aggressive(0);
          set_wc(30);
          set_ac(17); 
          set_chance(20);
          set_spell_mess1("The vampire drains the life of its victim.");
          set_spell_mess2("The vampire's touch drains the life from you.");
          set_spell_dam(random(40)); 
          money=clone_object("obj/money");
          money->set_money(3000 + random(1000));
          amulet=clone_object("obj/treasure");
          amulet->set_id("amulet");
          amulet->set_alias("ruby amulet");
          amulet->set_short("a ruby amulet");
          amulet->set_value(1000);
          amulet->set_weight(1);
          move_object(money, this_object());
          move_object(amulet, this_object()); }
}
