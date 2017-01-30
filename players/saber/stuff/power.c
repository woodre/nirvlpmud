#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("power system");
   set_alias("system");
    set_short("A power system");
   set_long("A power system for a Boomer.  It looks like it could be worth something...\n");
   set_weight(1);
   set_value(1000);
}

quest_ob()  { return 1; }
