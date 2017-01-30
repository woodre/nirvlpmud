inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_name("A gnome's sword");
      set_alias("sword");
      set_short("A gnome's sword");
      set_long("A sword that once belonged to a gnome.\n");
      set_class(7);
      set_weight(3);
      set_value(450);
}
