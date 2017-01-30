inherit "obj/weapon";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("ladle");
  set_short("A heavy mead ladle");
  set_long("A ladle used to stir and serve mead.\n");
  set_value(850);
  set_weight(3);
  set_class(14);
}
