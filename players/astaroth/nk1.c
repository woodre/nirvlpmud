inherit "obj/monster";
reset(arg) {
  if(!arg)
  ::reset(arg);
  set_name("johnathan");
  set_level(1);
  set_alias("newkid");
  set_race("man");
  set_hp(15);
  set_aggressive(1);
  set_al(-1000);
  set_short("Johnathan");
  set_long("This is an evil new kid.\n" +
           "He belongs on the chopping block.\n" +
           "");
  set_wc(5);
  set_ac(3);
}
