inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("scroll");
   set_short("A scroll");
   set_long(
  "\n"+
  "You are formally invited to the sanctum of Saber.\n"+
  "\n"+
  "Come over and chat?\n"+
  "I'll listen if you want...\n"+
  "\n"+
  "                                                  -- Saber\n");
   set_weight(0);
   set_value(0);
}
