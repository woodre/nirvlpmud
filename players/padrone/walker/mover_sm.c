/*
 * silent_move_object for the castle mover
 * Rumplemintz - for Nirvana
 */

inherit "obj/treasure";

void reset(status arg)
{
   if (arg)
      return;
   set_name("silent_move_object");
   set_value(0);
   set_short(0);
   set_alias("treasure");
}
