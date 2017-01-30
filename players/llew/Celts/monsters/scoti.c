
inherit "obj/monster";

reset(arg) {
::reset(arg);
if(!arg) {
   object gold,rand_armor;
   string arm;
   switch(random(5)) {
      case 0:  arm="sc_neckguard.c"; break;
      case 1:  arm="sc_boots.c"; break;
      case 2:  arm="sc_bracers.c"; break;
      case 3:  arm="sc_helmet.c"; break;
      case 4:  arm="sc_buckler.c"; break;
   }
   rand_armor=clone_object("/players/llew/Celts/armor/"+arm);
   gold=clone_object("obj/money");
   gold->set_money(random(750)+400);
   move_object(gold,this_object());
   move_object(rand_armor,this_object());

   set_name("raider");
   set_level(10);
   set_alias("scoti");
   set_race("human");
   set_hp(random(100)+150);
   set_al(-400);
   set_short("Scoti raider");
   set_long("Scoti raider from across the sea.  Very skilled in the\n"+
      "art of using two weapons, they are agile and quick, though\n"+
      "not very strong.  The raider is dark haired and dressed in leather.\n");
   set_wc(random(6)+9);
   set_ac(random(6)+7);
   set_dead_ob(this_object());
   set_gender("male");
   set_alt_name("scoti raider");
   }
}

heart_beat() {
   ::heart_beat();
   already_fight=0;
   attack();
}

monster_died() {
   say("Raider gurgles up blood and falls over dead.\n");
}
