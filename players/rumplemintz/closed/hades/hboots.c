inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_type("boots");
   set_short("Hades's boots");
   set_long("Hades's boots of ogre strength.\n");
   set_ac(1);
   set_weight(1);
   set_value(100000);
   set_alias("boots");
   set_name("boots");
   set_save_flag(0);
}
id(str){return str == "strength" || str == "boots";}
