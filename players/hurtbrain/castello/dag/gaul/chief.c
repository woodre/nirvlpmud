inherit "obj/monster";
reset(arg){
   object gold,ob1;
   ::reset(arg);
   if(arg) return;
   set_name("abraracourcix");
   set_race("human");
   set_alias("chief");
   set_short("Abraracourcix, the chief");
  set_long("He is a big man with an enormous belly. He stands on a very big\n" +
   "shield waiting for someone.\n");
   set_level(17);
   set_hp(425);
   set_al(50);
   set_wc(24);
   set_ac(14);
   set_chat_chance (30);
   load_chat("Abraracourcix says : 'I would know where Asterix and Obelix are gone.'\n");
   load_chat("Abraracourcix shouts : 'Hey you soldiers...let's go north!\n");
   load_chat("Abraracourcix falls from his shield.\n");
   gold=clone_object("obj/money");
   gold->set_money(300 + random(30));
   move_object(gold,this_object());
   ob1=clone_object("players/hurtbrain/castello/dag/gaul/shield");
   move_object(ob1,this_object());
}
