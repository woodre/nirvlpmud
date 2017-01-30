inherit "obj/monster";

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Illusion");
   set_race("unknown");
   set_alias("illusion");
   set_short("An Illusion");
   set_long("This is just an illusion.\n");
   set_level(1);
   set_hp(1);
   set_ep(0);
   set_al(0);
   set_wc(1);
   set_ac(1);
}
