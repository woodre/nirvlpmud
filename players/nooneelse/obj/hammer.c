/*
 hammer.c
*/

inherit "obj/weapon";

reset(arg) {
  ::reset(arg);

  set_name("hammer");
  set_alias("mallet");
  set_class(10);
  set_weight(3);
  set_value(100);
  set_short("a heavy wooden hammer");
  set_long("It is a heavy wooden mallet.\n");
}
