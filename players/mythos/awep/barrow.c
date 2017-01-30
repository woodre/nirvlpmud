inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("broken");
  set_alias("broken arrow");
  set_short("broken arrow");
  set_long("An arrow that has been broken... you may as well throw it away.\n");
  set_class(0);
  set_weight(0);
  set_value(0);
  set_hit_func(this_object());
}

