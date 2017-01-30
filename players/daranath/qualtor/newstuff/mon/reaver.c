inherit "/players/daranath/closed/monster1.c";

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

set_name("Undead Reaver");
set_short("The Undead Reaver");
set_alias("reaver");
set_alt_name("Reaver");
set_race("undead");
set_gender("creature");
set_long("Towering over you, the Undead Reaver stands 10 feet tall at its\n"+
         "shoulder. Four identical arms end in large, scythe-like\n"+
         "bone extentions, sharpened to a perfect edge.\n"+
         "The Undead Reaver is a perfect killing machine.\n");
set_level(21);
set_ac(20);
set_wc(43 + random(6));
set_hp(550 + random(200));
set_al(-(450+random(450)));
set_aggressive(0);
set_a_chat_chance(80);
load_a_chat("Undead Reaver hits you very hard.\n");
load_a_chat("Undead Reaver hits you with a bone crushing sound.\n");
load_a_chat("Undead Reaver massacres you to small fragments.\n");
load_a_chat("Undead Reaver rears back and lets out a blood curdling roar.\n");
load_a_chat("This area reeks of the undead.\n");

set_mult(2);
set_mult_chance(30);
set_mult_dam1(15);
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

