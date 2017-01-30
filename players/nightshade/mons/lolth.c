inherit "obj/monster";

reset(arg){
   object gold,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("Statue of Lolth");
   set_alias("lolth");
   set_short("Lolth");
set_long("A statue of Lolth bestowed with a portion of the evil Godess' powers to punish those who would defile her monument!\n");
   set_level(22);
   set_hp(500);
   set_al(-5000);
   set_wc(30);
   set_ac(20);
set_chance(15);
set_spell_dam(20);
set_spell_mess1("The six heads of Lolths whip bite into the unfortunate victim!");
set_spell_mess2("You feel a searing pain as all of Lolths whip heads connect on your body!");
weapon=clone_object("/players/nightshade/weap/whip");
   move_object(weapon, this_object());
gold=clone_object("obj/money");
gold->set_money(random(500)+4500);
move_object(gold, this_object());
}
