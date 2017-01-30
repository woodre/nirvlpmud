inherit "obj/weapon";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("oak staff");
  set_alias("staff");
  set_short("Oak Staff");
  set_long("This is a five foot long oak staff.\n");
  set_value(400);
  set_weight(3);
  set_class(15);
}
