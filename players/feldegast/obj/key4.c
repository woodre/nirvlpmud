inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("key#30303");
  set_alias("key");
  set_short("A copper key");
  set_long("This is a simply made copper key.\n");
  set_weight(1);
  set_value(5);
}
