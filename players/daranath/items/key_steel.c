#define tp this_player()->qury_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("key");
   set_alias("steel key");
   set_short("A small steel key");
   set_long(
        "A small steel key which looks like it might unlock something.\n");
   set_weight(0);
   set_value(1);
}
