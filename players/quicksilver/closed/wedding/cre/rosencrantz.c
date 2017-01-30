inherit "obj/monster";
 
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("rosencrantz");
   set_race("human");
   set_gender("male");
   set_short("Rosencrantz the minstrel");
   set_long("A short man with dark curly hair and a smile that goes straight to your\n"+
            "heart.  He's always ready with a joke or a song to cheer the\n"+
            "downtrodden.\n");
   set_level(100);
   set_hp(300000);
   set_al(0);
   set_wc(1);
   set_ac(1000000000);
}
