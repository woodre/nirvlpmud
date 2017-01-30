inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("altarboy");
   set_race("human");
   set_alias("boy");
   set_short("An altarboy");
   set_long("A young altarboy.  He looks clever and innocent.\n");
   set_level(14);
   set_hp(210);
   set_al(100);
   set_wc(18);
   set_ac(11);
   set_aggressive(0);
   set_chance(10);
   set_spell_dam(random(1)+1);
   set_spell_mess1("Altarboy spits on you.");
   set_spell_mess2("Altarboy punches you.");    
   gold=clone_object("obj/money");
   gold->set_money(800 + random(50));
/* set_gender added by Vertebraker [5.25.01] */
   set_gender("male");
   move_object(gold,this_object());
}
