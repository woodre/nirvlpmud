#include "../scar.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/m_efuns";

main() {
   int i, no, color;
   object *list;

   list = users();
   if(color = (int) previous_object()->query_ansi()) write(RED);
   write("["+pad("",68,'-')+"]\n");
   if(color) write(CYA);
    write("   Name:\tLevel:\tGuild:\tGender:\tLocation:\n");
  if(color) write(RED);
   write("["+pad("",68,'-')+"]\n");
   if (color) write(NOSTYLE);
   for (i = 0, no = 0; i < sizeof(list); i++) {
    if(list[i]->query_invis()) continue;

      if (!(list[i]->query_pl_k() && list[i]->query_level() < 20) &&
    !(environment(list[i]) && list[i]->query_fight_area() &&
    list[i]->query_level() < 20) )
         continue;

      write(++no + ". ");
      write(list[i]->query_name());

      if (no < 10)
         if (strlen(list[i]->query_name()) > 4)
            write("\t");
         else
            write("\t\t");
      else
         if (strlen(list[i]->query_name()) > 3)
            write("\t");
         else
            write("\t\t");

      if (list[i]->query_pl_k())
         write(list[i]->query_level() + "*\t");
      else
         write(list[i]->query_level() + "\t");

      if (!list[i]->query_guild_name())
    write("None\t");
    else {
    write(extract(list[i]->query_guild_name(),0,6));
    write("\t");
    }

      if (list[i]->query_gender() == "male") write("   M\t");
      else if (list[i]->query_gender() == "female") write("   F\t");
      else if (list[i]->query_gender() == "creature") write("   C\t");

      if (!environment(list[i])) write("Logging In");
else write(colour_pad(environment(list[i])->short(), 35));
      write(NOSTYLE+"\n");
   }
   if (color) write(RED);
   write("["+pad("",68,'-')+"]\n");
   if (color) write(NOSTYLE);
   return 1;
}
