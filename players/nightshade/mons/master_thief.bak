inherit "obj/monster";
object gold, weap, duh;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("thief");
   set_alias("thief");
   set_short("Level 20 Thief");
set_long(
"As the guildmaster of the thieves guild, this guy has become\n"+
"very powerful.\n");
   set_level(19);
   set_hp(475);
  set_wc(28);
   set_ac(16);
set_chance(20);
set_spell_dam(15);
set_spell_mess1("The disappears for a moment and appears behind his enemy and sticks his blade in their back!");
set_spell_mess2("The thief disappears for a moment, and you suddenly feel a blade in your back!");
   gold=clone_object("obj/money");
  gold->set_money(2000);
   move_object(gold, this_object());
}
/* money was 3000+rnd(500) wc was19 ac was 8 hp was 400 - mythos <6-17-96> */
