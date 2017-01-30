inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
  object gold;
  gold = clone_object("obj/money");
  gold->set_money(500);
  move_object(gold,this_object());
     set_name( "GIANT" );
     set_short("A large GIANT");
     set_alias("giant");
     set_race( "giant");
     set_long("A really HUGE giant.\n");
     set_level(20);
     set_heal(1,8);
     set_ac(17);
     set_wc(30);
     set_hp(500);
     set_al(-300);
     set_aggressive(0);
set_spell_mess1("The giant steps on his foes.");
set_spell_mess2("The giant steps on you!.");
     set_chance(10);
     set_spell_dam(50);
   }
}
