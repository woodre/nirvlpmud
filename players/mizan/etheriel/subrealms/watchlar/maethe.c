inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("maethe");
   set_race("maethe");
   set_alias("maethe");
   set_ep(829000);
   set_short("ghost of a Maethe");
   set_long("	Practically transparent, and difficult to see with the dark blue\n"+
      "  background that permeates this castle, these undead mages are double the \n"+
      "  threat that they pose, which is already quite imposing enough.\n");
   set_level(18);
   if(1 == random(40))
      set_hp(8000);
   else
      set_hp(330+(random(100)));
   set_al(-1000);
   if(1 == random(36))
      set_wc(120);
   else
      set_wc(28+(random(7)));
   set_ac(16);
   set_chance(20);
   set_spell_dam(22);
   set_spell_mess1("You are ripped to shreds by a sonic blast!");
   set_spell_mess2("Maethe rocks you with an unearthly force of a shockwave!");
   set_chat_chance(4);
   load_chat("Maethe chants strange words quietly.\n");
   load_chat("Maethe peers into you.\n");
   load_chat("Maethe mumbles incoherently.\n");
   if(1 == random(9)) set_aggressive(1);
   gold=clone_object("obj/money");
   gold->set_money(random(900)+2200);
   move_object(gold,this_object());
}
