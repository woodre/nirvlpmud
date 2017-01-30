inherit "obj/monster";

object gold, spear;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("harpy");
set_short("A dangerous harpy");
    set_race("demon");
set_long(
"These creatures are terrifying.  You seem to recall hearing somewhere\n"+
"that each circle of hell has it's guardians.  Well meet the guardians of\n"+
"circle two.  These beasts look like womens torsos on the bodies of vultures.\n"+
"Their hair is tangled and resembles animal fur in many respects.  You also\n"+
"pay close attention to the very sharp spears that they have pointed at you.\n"+
"They are screaming at frothing blood at the mouth.  You are terrified!\n");
spear = clone_object("players/unsane/closed/hell/spear.c");
move_object(spear, this_object());
init_command("wield spear");
gold = clone_object("obj/money");
gold -> set_money (random (500) + 200);
set_a_chat_chance(15);
load_a_chat("Harpy screams at you!\n");
load_a_chat("Harpy says:  Blood!  Blood!  Humanoid blood!\n");
load_a_chat("The Harpies begin to cackle.\n");
move_object(gold, this_object());
   set_level(15);
   set_ac(12);
   set_wc(22);
  set_hp(300);
   set_al(-1000);
  set_aggressive(1);
}
}
