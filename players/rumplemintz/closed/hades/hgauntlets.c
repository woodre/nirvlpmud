inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_type("misc");
   set_short("Hades's gauntlets");
   set_long("Hade's gauntlets of resist fire.\n");
   set_ac(1);
   set_weight(1);
   set_value(100000);
   set_alias("fire");
   set_name("gauntlets");
   set_save_flag(0);
}
id(str){return str == "acid" || str == "gauntlets";}
