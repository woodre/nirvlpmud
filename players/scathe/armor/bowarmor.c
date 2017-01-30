inherit "obj/armor";

reset(arg){
   ::reset(arg);
   if (arg) return;
   set_short("Light Leather Armor");
   set_long("Light flexible armor perfect for an archer.\n");
   set_ac(2);
   set_weight(2);
   set_value(750);
   set_alias("armor");
   set_name("leather");
   set_type("armor");
}
