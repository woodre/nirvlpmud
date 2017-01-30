inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Biago");
  set_alias("biago");
  set_short("Biago and Helen");
  set_long("Biago and Helen are two lovely shop keepers.\n");
  set_level(30);
  set_ac(80);
  set_wc(80);
  set_hp(10000);
  set_al(10000);
  set_aggressive(0);
}

id(str)
{
  return str == "biago" || str == "helen" ;
}

