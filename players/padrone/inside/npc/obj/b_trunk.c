/*
 * b_trunk.c
 * tree trunk for Billy the Giant
 */

inherit "obj/weapon";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("tree trunk");
  set_alias("trunk");
  set_short("A tree trunk");
  set_long("A tree trunk");
  set_class(30);
  set_weight(100);
  set_value(20);
}
