inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("wolf");
   set_short("A mean looking wolf");
   set_long("One of many creatures that came here due to the presence of the\n"+
            "Shadow Master.  Its green eyes peer into your soul and you\n"+
            "suddenly feel tired and afraid.\n");
   set_level(4);
   set_hp(60);
   set_ac(5);
   set_wc(10);
   set_al(-100);
   gold=clone_object("obj/money");
   gold->set_money(150);
   move_object(gold,this_object());
}
