/* Bully in the playground /players/pathfinder/detroit/monsters/bully */
 
inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("bully");
   set_race("bully");
   set_alias("bully");
   set_ep(30000);
   set_short("A schoolyard bully");
   set_long("\n"+
"A schoolyard bully.  You know, the type that always beat you up.  Well\n"+
"right now he is glaring at you like you can't take him.  He is beating up\n"+
"all the other children in the schoolyard.\n");
   
   set_level(10);
   set_hp(75+ random(75));
   set_al(-500);
   set_wc(16);
   set_ac(6);
   set_chat_chance(2);
   load_chat("Bully says: Didn't I beat you up last week?\n");
   load_chat("Bully says: You ain't got shit compared to me punk!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(250)+150);
   move_object(gold,this_object());
   weapon=clone_object("players/pathfinder/detroit/weapons/knife");
   move_object(weapon,this_object());
}   
