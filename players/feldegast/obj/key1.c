inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  set_id("key#1010101");
  set_alias("key");
  set_short("A magical key");
  set_long(
    "This is a steel key with the word 'Magic' etched on it.\n"
  );
  set_weight(1);
  set_value(5);
}
