inherit "obj/treasure";
reset(arg) {
 if(arg) return;
  set_short("spell component");
  set_long("a spell component.\n");
  set_alias("component");
  set_weight(1);
  set_value(10);
}
