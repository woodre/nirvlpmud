#define tp this_player()->query_name()
#define tg this_player()->query_gender()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("maker");
  set_short();
  set_weight(30000);
  set_value(0);
  call_out("make",10);
}
