/* 7.8.01: V rm'd the display of "Kills" for Npc's and marked
             Masakado as an npc as well. */
#include "../scar.h"
#include <ansi.h>

main() {
   object *scars, scar, blood;
   status npc_flag;
   mixed i, mylevel, level, pkills, xlevel, color;
   string name;

   mylevel = (int) this_player()->query_level();
   scars = (object *) CHANNELD->on_channel( CHANNAME );
   if (color = (int) previous_object()->query_ansi()) write(RED);
   write(pad("",70,'=')+"\n");
   if(color) write(CYA);
   write("Name:\t\t\tRank:\tScore:\tLevel:\tKills:\tMuffs:\n");
   if(color) write(RED);
   write(pad("",70,'=')+"\n");
   if(color) write(NOSTYLE);
   for (i = 0; i < sizeof(scars); i++) {
      scar = scars[i];
      if (!scar || !(blood = environment(scar))) continue;
      if(!environment(blood)) continue;
      if (blood->query_invis()) continue;

      npc_flag = 0;
      name = capitalize(blood->query_real_name());
      if(blood->id("masakado") || (status)blood->query_npc() || ((status)blood->is_player() && (status)blood->query_level() >= 21))
        npc_flag = 1;
      if(npc_flag) level = "Unknown";
      else level = blood->query_level();
      xlevel = blood->query_extra_level();
      pkills = scar->query_pkills();

      name = pad(name,24);
      write(name);
      write(pad(scar->QMKRank(),8));
      write(pad(scar->QMKScore(),8));
      name = level;
      if(xlevel > 0) {
         name += "+"+xlevel+"";
      }
      write(pad(name,8));
      if(!npc_flag)
      write(pad(pkills,8));
      else write(" ---    ");
      if (scar->query_muffled()) write("Yes\n"); else write("No\n");
   }
   if (color) write(RED);
   write(pad("",70,'=')+"\n");
   if (color) write(NOSTYLE);
   return 1;
}
