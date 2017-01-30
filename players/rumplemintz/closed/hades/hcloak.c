inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_type("misc");
   set_short("Hades's cloak");
   set_long("Hades's cloak of feather falling.\n");
   set_ac(1);
   set_weight(2);
   set_value(100000);
   set_alias("cloak");
   set_name("cloak");
   set_save_flag(0);
}
id(str) {return str == "cloak" || str == "falling";}
