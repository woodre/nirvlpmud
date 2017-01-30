inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("bow");
  set_alias("bow");
  set_short("DEST Bow");
  set_long(
 "   The bow is small in nature and doesn't appear to be a \n"+
 "a very powerful weapon.  It is made entirely of wood and \n"+
 "the string is worn and frayed.\n" );
  set_type("sword");
  set_class(5000);
  set_weight(100);
  set_value(800);
  }