inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("key#2020202");
  set_alias("key");
  set_short("A steel key");
  set_long(
    "This is a steel key.\n"
  );
  set_weight(1);
  set_value(5);
}
