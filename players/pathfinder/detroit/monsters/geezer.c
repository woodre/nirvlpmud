inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("geezer");
   set_race("human");
   set_alias("man");
   set_aggressive(1);
   set_short("An old geezer");
   set_long("\n"+
"  An old geezer with grey hair and a nasty shotgun pointed at you!\n");   
   set_level(20);
   set_hp(400+random(300));
   set_al(500);
   set_wc(26);
   set_ac(13);
   set_chance(20);
   set_spell_dam(17);
   set_spell_mess1("Geezer blows a hole in you with the shotgun!\n");
   set_spell_mess2("Geezer clonks you on the head with the buttstock!\n");
   set_chat_chance(2);
   load_chat("Old geezer yells at you to get out of his house!\n");
   load_chat("Old geezer pumps the shotgun and points it at you.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1500)+1000);
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/shotgun"), this_object());
}
   
 

