#define tp this_player()->query_name()
#define tg this_player()->query_gender()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("nameless");
  set_alias("figure");
  set_short("A Hooded Figure- the Nameless");
  set_long("A Dark Figure.  He stands tall and mysterious.\n"+
           "The only thing that you can make out of him besides\n"+
           "his ceremonial robes is a Dark Jewel Broach set above\n"+
           "where his heart should be.\n");
  set_weight(100000);
  set_value(0);
}
