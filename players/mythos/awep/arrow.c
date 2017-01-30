inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("arrow");
  set_alias("arrow");
  set_short("arrow");
  set_long("An arrow of good make.  It is light and\n"+
    "sturdy.  Perhaps you can use it?\n");
  set_class(1);
  set_weight(1);
  set_value(5);
  set_hit_func(this_object());
}

