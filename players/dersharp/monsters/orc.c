inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("orc");
   set_short("A mangy looking orc");
   set_long("This orc is currently busy eating the remains of an adventurer \n"+
            "who bothered his last meal.\n");
   set_level(3);
   set_hp(45);
   set_ac(4);
   set_wc(7);
   set_al(-50);
   set_chat_chance(2);
   load_chat("Orc looks up from its dinner and notices you!\n");
   gold=clone_object("obj/money");
   gold->set_money(100);
   move_object(gold,this_object());
}
