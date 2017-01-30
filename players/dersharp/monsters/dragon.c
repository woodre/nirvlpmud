inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("dragon");
   set_alias("dragon");
   set_short("a dragon");
   set_long("This is one of the evil creatures that the Shadow Master has \n"+
       "brought here to protect his domain.\n");
   set_level(10);
   set_hp(1000);
   set_wc(1);
   set_ac(20);
}
