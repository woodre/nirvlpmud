inherit "obj/armor";
reset(arg) {
  set_name("helmet");
  set_short("A motorcycle helmet");
  set_alias("helmet");
  set_long(
    "\nAn all white helmet, typically worn by a motorcycle\n"+
    "rider. It is reminescent of the types of bike helmets\n"+
    "that were prevalent in the 1970s -- yes, it has a certain\n"+
    "disco aura to it.  This helmet once belonged to Newman,\n"+
    "but he traded it to Kramer for a radar detector.\n\n");
  set_ac(1);
  set_type("helmet");
  set_weight(1);
  set_value(100);
  set_save_flag();
}

