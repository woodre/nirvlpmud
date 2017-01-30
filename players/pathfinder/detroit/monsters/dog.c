inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("rotweiler");
   set_race("dog");
   set_alias("dog");
   set_short("A sleek black rotweiler");
   set_long("\n"+
"A sleek black rotweiler.  You notice it has no bark, and no nails and is\n"+
"extremely ferocious.  You can see the slobber rolling off his tongue and\n"+
"teeth as he glares at you with extremely hateful eyes, sending a chill\n"+
"down your spine.\n");
   set_level(18);
   set_aggressive(1);
   set_hp(200+random(300));
   set_al(-100);
   set_wc(30);
   set_ac(15);
   set_chance(20);
   set_spell_dam(10);
   set_spell_mess1("The rotweiler chomps on your neck with its mighty jaws.\n");
   set_spell_mess2("The rotweiler takes a chunk of your arm off with its teeth!\n");
   set_chat_chance(2);
   gold=clone_object("obj/money");
   gold->set_money(random(1500)+1500);
   move_object(gold,this_object());
}

