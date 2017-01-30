inherit "obj/armor";

reset(arg){
   ::reset(arg);
   if (arg) return;
   set_short("A Dragon Amulet");
   set_long("An amulet worn by all members of the Dragon Fist Order.\n");
   set_ac(1);
   set_weight(1);
   set_value(100);
   set_alias("amulet");
   set_name("amulet");
  set_type("amulet");
}
