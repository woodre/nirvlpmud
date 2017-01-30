inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("patron");
   set_alias("man");
   set_short("Drunken patron");
set_long(
"A drunken patron. He wants your money to buy more beer.\n");
   set_level(3);
set_aggressive(1);
   set_hp(70);
   set_al(0);
   set_wc(7);
   set_ac(4);
   set_chance(30);
   set_spell_dam(5);
set_spell_mess1("The drunk breaks a bottle on the counter!\n");
set_spell_mess2("The drunk cuts you with the broken bottle.\n");
   gold=clone_object("obj/money");
   gold->set_money(100);
   move_object(gold,this_object());
}
