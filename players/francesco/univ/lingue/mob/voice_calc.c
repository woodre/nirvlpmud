inherit "obj/monster";
   object gold;
id(str) {return str=="voice";}
reset(arg){
   ::reset(arg);
   set_level(1);
   set_hp(4750);
   set_wc(30);
   set_ac(15);
   set_chat_chance(10);
   load_chat("A recorded voice says:  What is the english translation for 'calcolatore'?\n");
}
