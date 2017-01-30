#define tp this_player()->qury_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("crystal goblet");
   set_alias("goblet");
   set_short("A beatiful crystal goblet");
   set_long(
      "A crystal goblet carved with dueling dragons upon it.\n");
   set_weight(0);
   set_value(150);
}
