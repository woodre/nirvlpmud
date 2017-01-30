inherit "obj/armor";
reset(arg) {
  if(!arg) 
  ::reset(arg);
  set_name("grammy");
  set_alias("award");
  set_ac(1);
  set_type("amulet");
  set_weight(4);
  set_value(800);
  set_short("A Grammy award");
  set_long("This is an award won for music not played.\n" +
           "It is easy to hide behind.\n" +
           "");
}
