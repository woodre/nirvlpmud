inherit "/players/mythos/amon/forest/monster1.c";

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

set_name("Undead Guard");
set_short("An Undead Guardian stands silently");
set_alias("guard");
set_alt_name("Guard");
set_race("undead");
set_gender("creature");
set_long("Standing silently before the tent's entrance, this undead guardian\n"+
         "protects Shou Lung's wife. Rotting and decomposing all the time\n"+
         "only dark magic can hold his body together long enough for\n"+
         "him to engage in battle.\n");
set_level(18);
set_ac(15);
set_wc(25 + random(4));
set_hp(350 + random(100));
set_al(-(250+random(350)));
set_aggressive(0);

set_mult(2);
set_mult_chance(30);
set_mult_dam1(12);
set_mult_dam2(12);

set_spell_mess2("Undead Reaver rears up and strikes you will all 4 arms!\n");
set_spell_mess1("Undead Guardian opens its mouth in a silent scream!\n");
set_chance(8+random(5));
set_spell_dam(25+random(20));

 gold = clone_object("obj/money");
  gold->set_money(random(3000)+2000);
/* average coins of 3500, exactly per monster guide */
move_object(gold,this_object());
   }
  }

