inherit "obj/monster";
 
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("dorcas");
   set_race("human");
   set_gender("female");
   set_short("Dorcas the minstrel");
   set_long("This dark woman has the face of an angel and a voice to match.  Far from\n"+
            "grating, her soprano is soft and inviting, telling the story of her life\n"+
            "with every note.\n");
   set_level(100);
   set_hp(300000);
   set_al(0);
   set_wc(1);
   set_ac(1000000000);
}
