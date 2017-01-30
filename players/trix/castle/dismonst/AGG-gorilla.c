inherit "obj/monster";
#include "/players/mizan/closed/Tracking-D.c"
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("gorilla");
   set_race("human");
   set_alias("man");
   set_short("A gorilla");
   set_long("A huge muscular man whose duty is to avoid people too young or wearing badly\n"+
            "to enter the disco. He looks calm and relaxed but if you're not ok I wouldn't\n"+
            "try to enter if I was you.\n");
   set_level(11);
   set_hp(165);
   set_al(300);
   set_wc(15);
   set_ac(9);
   set_aggressive(1);
   set_chat_chance (5);
   load_chat("The gorilla flexes his muscles.\n");
   load_chat("The gorilla looks calmly at the crowd.\n");
   gold=clone_object("obj/money");
   gold->set_money(450+random(51));
   move_object(gold,this_object());
}
