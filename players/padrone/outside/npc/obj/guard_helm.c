/*
 * guard_helm.c
 * Helm for drunken guard
 */

inherit "obj/armor";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("metal helmet");
  set_alias("helmet");
  set_type("helmet");
  set_ac(1);
  set_weight(3);
  set_value(75);
  set_short("a metal helmet");
}
