inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_type("misc");
   set_short("Hades's amulet");
   set_long("Hades's amulet of searching.\n");
   set_ac(1);
   set_weight(1);
   set_value(100000);
   set_alias("amulet");
   set_name("amulet");
   set_save_flag(0);
}
id(str) {return str == "amulet" || str == "searching";}
