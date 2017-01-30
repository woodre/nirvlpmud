/*
  bear_hide.c
*/

inherit "obj/armor";

reset(arg) {
  set_id("bear hide");
  set_alias("hide");
  set_short("A grizzly bear hide");
  set_long("This is a beautiful copper colored hide from a grizzly bear.\n");
  set_type("armor");
  set_value(1500);
  set_weight(3);
  set_ac(4);
}

query_save_flag() { return 1; }

id(str) { return str=="hide" || str=="bear hide" || str=="grizzly bear hide" ||
                 str=="nooneelsebearhide"; }
