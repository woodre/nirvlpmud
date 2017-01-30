
inherit "obj/monster";

reset(arg) {
     object money, gem;
     ::reset(arg);
     if(!arg) {
          set_name("dragon");
          set_race("dragon");
          set_level(17);
          set_hp(425);
          set_al(-800);
          set_short("a young, blue dragon");
          set_long("Even at this age, the dragon is a fearsome opponent.\n");
          set_aggressive(0);
          set_wc(24);
          set_ac(14); 
          set_chance(20);
          set_spell_mess1("The dragon breathes lightning.");
          set_spell_mess2("The dragon breathes lightning at you.");
          set_spell_dam(random(30)); 
          money=clone_object("obj/money");
          money->set_money(500);
          gem=clone_object("obj/treasure");
          gem->set_id("diamond");
          gem->set_alias("gem");
          gem->set_short("a flawless diamond");
          gem->set_value(500);
          gem->set_weight(1);
          move_object(money, this_object());
          move_object(gem, this_object()); }
}
