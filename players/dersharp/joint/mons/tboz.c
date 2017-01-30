inherit "obj/monster";
reset(arg){
   object hat, glasses, sweatshirt;
   ::reset(arg);
   if(arg) return;
   set_name("t-boz");
   set_race("human");
   set_short("T-Boz");
   set_long(
   "    The second-most beautiful member of TLC, T-Boz is cool!\n"+
   "She has an air of authority and seems to exude a sense of\n"+
   "self-awareness.  She is wearing a Grambling University \n"+
   "sweat-shirt and looks upon you with a small grin.\n");
   set_level(20);
   set_hp(500);
   set_ac(17);
   set_wc(30);
   set_al(300);
}

