inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_name("A Generic Sword");
      set_alias("sword");
      set_short("A Generic Sword");
      set_long("A sword made to do some minor damage.\n");
      set_class(6);
      set_weight(3);
      set_value(400);
}
