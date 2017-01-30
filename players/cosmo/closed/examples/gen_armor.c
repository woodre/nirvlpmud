
inherit "obj/armor";
reset(arg) {
  set_name("N");
set_short("S");
set_alias("armor");
  set_long(
  "desc.\n");
  set_ac(5);
  set_type("armor");
  set_weight(1);
  set_value(1000);
set_save_flag();
}

/*  if you want it non-saveable  */
query_save_flag() { return 1; }
