/* steal force takes a corpse and gives 1 point of cp to a darkside player */
#include <ansi.h>
#include "defs.h"

inherit CMDBASE;

main() {

   object corpse;
   string extra, mon_color;

  skill_type = "telepathy";
mon_color = previous_object()->query_mon_color();
if(USER->query_ghost()){
return 0;
}	

if( skill_check( 1 ) ) return 1;
 
corpse = present("corpse", environment(USER));

 if (!corpse) {
      write("There is no corpse.\n");
      return 1;
       }
write(
""+mon_color+"[]"+NORM+" You bend to one knee and feel the power of the darkside gather\n"+
""+mon_color+"[]"+NORM+" around you. The corpse rises into the air, its essence feeding\n"+
""+mon_color+"[]"+NORM+" your hunger, increasing the force within you.\n");
say(
capitalize(USER->query_real_name())+" bends to one knee and feeds from the essence of the fallen.\n");
   if (sscanf(file_name(corpse),"obj/corpse%s",extra)!=1) return 1;
   previous_object()->adj_cp(1);
   destruct(corpse);
   return 1;
   }
