inherit "obj/monster";
object gold, weap, duh;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("fighter");
   set_alias("fighter");
   set_short("Level 20 Fighter");
set_long(
"This guy stands seven feet tall and carries himself like he fears nothing. He didnt become the master of the fighters guild for nothing!");
   set_level(19);
   set_hp(475);
/* Figured master of fighter's guild should have decent wc  -Snow */
  set_wc(38);
   set_ac(16);
set_chance(20);
set_spell_dam(10);
set_spell_mess1("You see the Master execute a blurring double attack!");
set_spell_mess2("You cannot follow the blades as the Master executes a blurring double attack!");
   gold=clone_object("obj/money");
  gold->set_money(2000);
   move_object(gold, this_object());
}
