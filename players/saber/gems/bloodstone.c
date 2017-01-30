#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("stone");
 set_short("A bloodstone");
  set_alias("bloodstone");
  set_long(
 "A dark gray stone with red flecks.\n"
    );
   set_weight(0);
   set_value(50);
}
init()
{  add_action("polish_stone", "polish");   }
 polish_stone(str)
{  if ((!str) || !id(str)) return 0;
  write("You polish the stone.\n");
 say(tp+" polishes the stone.\n");
    return 1;   }

quest_ob()  { return 1; }
