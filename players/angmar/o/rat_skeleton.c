#pragma strong_types

inherit "obj/treasure";

void
reset(status arg) {
  if (arg)
    return;
  set_name("skeleton");
  set_alias("rat skeleton");
  set_short("A rat skeleton");
  set_long(
"A perfectly preserved rat skeleton.  The jailer's lunch, perhaps?\n");
  set_value(1);
  set_weight(1);
}

status query_destruct_when_sold(){ return 1; }
