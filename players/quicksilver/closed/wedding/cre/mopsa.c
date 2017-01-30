inherit "obj/monster";
 
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("mopsa");
   set_race("human");
   set_gender("female");
   set_short("Mopsa the minstrel");
   set_long("A small impish girl who's stature tells one nothing about her strong alto\n"+
            "voice.  As outgoing as she is small, she can talk to anyone about\n"+
            "anything.\n");
   set_level(100);
   set_hp(300000);
   set_al(0);
   set_wc(1);
   set_ac(1000000000);
}
