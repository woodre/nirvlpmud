inherit "obj/monster";
 
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("guildenstern");
   set_race("human");
   set_gender("male");
   set_short("Guildenstern the minstrel");
   set_long("Light haired, fair skinned and tall, he makes music come alive by putting\n"+
            "his lips to a pipe.  His eyes will tell you everything about him if\n"+
            "he'll let you look in them.\n");
   set_level(100);
   set_hp(300000);
   set_al(0);
   set_wc(1);
   set_ac(1000000000);
}
