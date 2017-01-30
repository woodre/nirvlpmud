inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_name("A mall guard's sword");
      set_alias("sword");
      set_short("A mall guard's sword");
      set_long("A standard issue mall guardsman's sword.\n");
      set_class(10);
      set_weight(4);
      set_value(700);
}
