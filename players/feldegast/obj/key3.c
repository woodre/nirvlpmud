inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("key#301");
  set_alias("key");
  set_short("An iron key");
  set_long(
    "A simple iron key.\n"
  );
  set_weight(1);
  set_value(5);
}
