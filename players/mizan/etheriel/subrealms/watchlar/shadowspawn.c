inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("shadowspawn");
   set_race("shadowspawn");
   set_alias("shadowspawn");
   set_short("A silvery shadowspawn");
   set_long("  You question what it is hovering here before you, a silvery\n"+
"  mass constantly shifting shape, and then decide that it is not worth it.\n"+
"  All that you know is that it looks rather tough, and it is not happy \n"+
"  to see you.\n");
   set_level(19);
   set_hp(488);
   set_al(-1000);
   set_wc(28);
   set_ac(15);
   set_chance(20);
   set_spell_dam(33);
   set_spell_mess1("Shadowspawn blasts you with a wave of raw evil...\n");
   set_spell_mess2("You cringe.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(500)+3600);
   move_object(gold,this_object());
}
