/* Child in the playground /players/pathfinder/detroit/monsters/child */
 
inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("child");
   set_race("child");
   set_alias("child");
   set_short("A loud-mouthed child");
   set_long("\n"+
"You see a sniveling little child who keeps pointing and laughing at you\n"+
"making you more and more angry until you can't take it anymore and just\n"+
"want to kill it and kill it.\n");
   set_level(5);
   set_hp(30+random(30));
   set_al(-100);
   set_wc(8);
   set_ac(3);
   set_chat_chance(2);
   load_chat("Child says: your mama's on crack rock!.\n");
   load_chat("Child points and laughs at you!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(75)+25);
   move_object(gold,this_object());
}   
 

