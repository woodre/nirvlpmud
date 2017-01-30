inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_type("shield");
   set_short("Hades's shield");
   set_long("Hades's shield of resist fire.\n");
   set_ac(1);
   set_weight(2);
   set_value(100000);
   set_alias("shield");
   set_name("shield");
   set_save_flag(0);
}
id(str){return str == "fire" || str == "shield";}
