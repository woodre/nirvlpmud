inherit "/players/mo/rig/MON/std/mob";

reset(arg)
{

  ::reset(arg);
  if(arg) return;

  set_short(query_name()+", a geologist");
  set_long(
  capitalize(query_possessive())+" hair is beautiful!\n");
}
