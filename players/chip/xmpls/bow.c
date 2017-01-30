inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("bow");
  set_alias("shortbow");
  set_short("Short Bow");
  set_long(
 "   The bow is small in nature and doesn't appear to be a \n"+
 "a very powerful weapon.  It is made entirely of wood and \n"+
 "the string is worn and frayed.\n" );
  set_type("bow");
  set_class(16);
  set_weight(2);
  set_value(800);
  }