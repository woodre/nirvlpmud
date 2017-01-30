#define tp this_player()->query_name()
#define tg this_player()->query_gender()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("horn");
  set_alias("horni");
  set_short("A beautiful horn");
  set_long("A horn off the head of a unicorn.\n");
  set_weight(4);
  set_value(2000);
}
