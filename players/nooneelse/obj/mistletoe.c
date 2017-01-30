/*
  mistletoe.c
*/

inherit "obj/treasure";

reset(arg) {
  set_id("mistletoe");
  set_alias("nooneelsemistletoe");
  set_short("Mistletoe");
  set_long("This is a sprig of mistletoe.  Druids love this stuff!\n");
  set_value(50);
  set_weight(1);
}

query_save_flag() { return 1; }

id(str) { return str=="mistletoe" || str=="nooneelsemistletoe" ||
                 str=="holy item"; }
