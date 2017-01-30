  inherit "obj/armor";
  reset(arg) {
   if(arg) return;
   set_name("bat cape");
   set_alias("cape");
   set_short("Cape of Batman");
   set_long("The cape of Batman\n");
   set_value(1000);
   set_weight(1);
   set_ac(1);
   set_type("amulet");
}
