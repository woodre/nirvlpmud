inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_name("A castle guard's sword");
      set_alias("sword");
      set_short("A castle guard's sword");
      set_long("A standard issue castle guardsman's sword.\n");
      set_class(10);
      set_weight(4);
      set_value(700);
}
