inherit "obj/armor";
reset(arg) {
  set_name("uniform");
  set_short("USPS Uniform");
  set_alias("armor");
  set_long(
    "\nThis is a standard issue United States Postal Service\n"+
    "uniform.  It is fairly large since it once belonged to\n"+
    "Newman.  It offers protection from wind, rain, and snow.\n"+
    "Although any sort of blade would go straight through it,\n"+
    "you feel proud to wear it nonetheless.\n\n");
  set_ac(3);
  set_type("armor");
  set_weight(1);
  set_value(500);
  set_save_flag();
}

