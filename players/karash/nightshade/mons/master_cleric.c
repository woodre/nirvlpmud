inherit "obj/monster";
object gold, weap, duh;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("cleric");
   set_alias("cleric");
   set_short("Level 20 Cleric");
set_long(
"You are looking at one who has attained a perfect harmony with his god. His master can bestow upon his disciple great powers!\n");
   set_level(19);
   set_hp(475);
  set_wc(28);
   set_ac(16);
set_chance(20);
set_spell_dam(20);
set_spell_mess1("The cleric waves his symbol out in front of him and prays as a fiery pillar appears to consume his enemy!");
set_spell_mess2("The clerics eyes roll back in his head in prayer as a firey pillar appears to consume you!");
   gold=clone_object("obj/money");
  gold->set_money(2000);
   move_object(gold, this_object());
}

/* money was 3000+rnd(500) wc was 19 ac was 3 hp was 400 - mythos <6-17-96> */
