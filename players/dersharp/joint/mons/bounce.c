inherit "obj/monster";
reset(arg){
   object earring;
   ::reset(arg);
   if(arg) return;
   set_name("vince");
   set_race("human");
   set_short("A Bouncer");
   set_long(
   "    A six-foot eight mound of flesh and muscle.  Vince used\n"+
   "to be an American Gladiator before coming here to serve as\n"+
   "bouncer for Tremors.  He is a nice guy unless you try to get\n"+
   "into the club without paying, then he......\n");
   set_level(16);
   set_hp(425);
   set_ac(12);
   set_wc(22);
   set_al(25);
   set_chat_chance(2);
   load_chat("Vince says: Man those bands rock this place!\n");
   load_chat("Vince says: Hey you gotta go in here!\n");
   earring= clone_object("/players/dersharp/joint/armor/earring");
   move_object(earring, this_object());
}
