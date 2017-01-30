/*
  bear_skin.c
*/

inherit "obj/armor";

reset(arg) {
  set_id("bear skin");
  set_alias("skin");
  set_short("A bear skin");
  set_long("A tattered grizzly bear skin.\n");
  set_type("armor");
  set_value(1000);
  set_weight(2);
  set_ac(2);
}

id(str) { return str=="skin" || str=="bear skin" || str=="grizzly bear skin" ||
                 str=="nooneelsebearskin"; }
