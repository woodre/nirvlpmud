#include "/players/llew/closed/ansi.h"

inherit "obj/treasure";

reset(arg)
{
   if(arg) return;

   set_id("rod");
   set_short(CYN + "Rod of Calming" + NORM);
   set_long("This rod can be used to stop fighting in a room.  type \"calm\"\n");
   set_value(750+random(500));
   set_weight(1);
   set_dest_flag(1);

}

init()
{
   add_action("calm", "calm");
}

calm()
{
   object *room_inv;
   int i;

   room_inv = all_inventory(environment(this_player()));
   for (i = 0; i < sizeof(room_inv); i++)
   {
      room_inv[i]->stop_fight();
      room_inv[i]->stop_fight();
   }
   return 1;
}
