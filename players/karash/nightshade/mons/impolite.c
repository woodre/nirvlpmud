inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("imp");
   set_alias("imp");
   set_short("Impolite");
set_long("This guy is so rude it makes you want to throttle him right now. Go for it!\n");
   set_level(3);
   set_hp(45);
   set_al(100);
   set_wc(7);
   set_ac(4);
set_chat_chance(40);
load_chat("Impolite says: You bastard! You cant kill me!\n");
load_chat("Impolite laughs at your impotence.\n");
load_chat("Impolite thinks you are nothing but a blick.\n");
load_chat("Impolite says: Hey, Im Huggybear!\n");
load_chat("Impolite thinks Fireblade is a wimp.\n");
load_chat("Impolite expresses his opinion that he rocks the mud!\n");
load_chat("Impolite says: You suck. Thats all there is to it.!\n");
   gold=clone_object("obj/money");
   gold->set_money(100);
   move_object(gold,this_object());
}
