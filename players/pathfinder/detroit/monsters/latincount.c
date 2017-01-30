inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("latin count");
   set_race("human");
   set_alias("gang");
   set_alias("member");
   set_short("A member of the Latin Counts");
   set_long("\n"+
"  A member of the Latin Counts gang.  You see him reach for his pistol\n"+
"as you come into view, he points it into your face as if you are not\n"+
"wanted around here.\n");
  set_level(18);
   set_hp(300+ random(200));
   set_al(-500);
   set_wc(22);
   set_aggressive(1);
   set_ac(15);
   set_chance(20);
   set_spell_dam(11);
set_spell_mess1("Count blows your head off with his pistol.\n");
   set_chat_chance(2);
   load_chat("Count tells you: Wanna go man, wanna go... right here!\n");
   gold=clone_object("obj/money");
   gold->set_money(500+random(300));
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/9mm"), this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/clipb"), this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/clipb"), this_object());
   
}

