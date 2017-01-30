#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("puddle");
   set_alias("water");
   set_short("A puddle of filthy water");
   set_long(
  "A puddle of filthy water fed from a trickling upon the\n"+
   "stairs above.  A small silver key lies in the water.\n");
   set_weight(0);
   set_value(1);
}

get()  { return 0; }
