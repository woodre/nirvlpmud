inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("slingshot");
  set_alias("slingshot");
  set_short("A slingshot");
  set_long("Made from the forked crotch of a hazelnut bush, it does\n"+
           "not look to be very powerful.  It is obviously homemade.\n");
  set_class(5);
  set_weight(1);
  set_value(200);
  set_hit_func(this_object());
}

