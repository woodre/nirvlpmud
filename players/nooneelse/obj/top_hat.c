/*
  top_hat.c - made from skins
*/

inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("top hat");
  set_short("A top hat");
  set_long("A black silk top hat.\n");
  set_value(300);
  set_weight(1);
  set_ac(2);
  set_type("helmet");
}

id(str) {
  return str=="helmet" ||
         str=="top hat" ||
         str=="hat" ||
         str=="black top hat";
}
