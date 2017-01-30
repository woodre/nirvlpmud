inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("quest token");
  set_alias("statue");
  set_short("A tiny statue");
  set_long(
    "This is a tiny statue of a sandtiger carved from sandstone.\n"+
    "It could fit into the palm of your hand, but it shows enormous\n"+
    "artistic talent.\n"
  );
  set_weight(1);
  set_value(50);
}
