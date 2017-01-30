/*
 * s_trunk.c
 * tree trunk for Sam the Giant
 */

inherit "obj/weapon";

void
reset(status arg)
{
  if (arg)
    return;
  weapon::reset(arg);
  set_name("huge tree trunk");
  set_alias("trunk");
  set_short("A huge tree trunk");
  set_class(40);
  set_weight(150);
  set_value(30);
}
