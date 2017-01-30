inherit "obj/monster";
reset(arg){
   object hat, jeans, bottle;
   ::reset(arg);
   if(arg) return;
   set_name("chilli");
   set_race("human");
   set_short("Chilli");
   set_long(
   "    This is C of TLC.  Chilli along with Left-Eye Lopez and T-Boz\n"+
   "make up one of hip-hops greatest groups.  Chilli is wearing a \n"+
   "hat...to the back of course and her baggy pants.  She is very\n"+
   "beautiful and you know that she `ain't too proud to beg'.\n");
   set_level(20);
   set_hp(500);
   set_ac(20);
   set_wc(27);
   set_al(500);
}
