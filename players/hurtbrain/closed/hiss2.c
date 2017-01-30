inherit "obj/monster";
reset(arg){
   object gold,amulet,berzerker;
   ::reset(arg);
   if(arg) return;
   set_name("hiss");
   set_race("dragon");
   set_alias("dragon");
   set_short("Hiss, black dragon of acid");
   set_long("Hiss, a giant green dragon, leads the invasion force!\n");
   set_level(1);
   set_hp(100);
   set_al(0);
   set_wc(0);
   set_ac(0);
}
