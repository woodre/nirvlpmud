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
set_long("Towering over you, the Undead Reaver stands 10 feet tall at its\n"+
         "shoulder. Four identical arms end in large, scythe-like\n"+
         "bone extentions, sharpened to a perfect edge.\n"+
         "The Undead Reaver is a perfect killing machine.\n");
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
set_spell_mess1("Undead Reaver pummels its foe!\n");
set_chance(10+random(5));
set_spell_dam(35+random(40));

 gold = clone_object("obj/money");
  gold->set_money(random(3000)+4500);
/* average coins of 6000, exactly per monster guide */
move_object(gold,this_object());
   }
  }

