inherit "obj/treasure";

void
reset(status arg) {
  if(arg)
    return;
  set_name("fish");
  set_alias("dead fish");
  set_short("A dead fish");
  set_long("It smells.\n");
  set_value(1);
  set_weight(1);
}

status query_destruct_when_sold() { return 1; }
