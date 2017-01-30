/*
 * kf_chopper.c
 * meat chopper for kung fu cook
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("meat chopper");
  set_alt_name("chopper");
  set_class(9);
  set_value(30);
  set_weight(2);
}
