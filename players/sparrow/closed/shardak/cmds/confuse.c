#include <ansi.h>
#include "/bin/wiz/cmd_defs.h"
#include "../macros.h"
#include "../def.h"

int main()
{
 object att, *ob;
 int    h, s;

 needrank(4);
 needmana(30);

  write("\n\
You stop fighting and reach up into the air with both arms.\n\
A globe of swirling "+GRN+"green"+NORM+" light appears just within your\n\
grasp.\n\
The globe explodes in a crescendo of glittering beams of light.\n");
  say((string)this_player()->query_name()+" \
stops fighting and reaches up into the air with both arms.\n\
A globe of swirling "+GRN+"green"+NORM+" light appears.\n\
The globe explodes in a crescendo of glittering beams of light.\n");

 s = sizeof(ob = all_inventory(ENVTP));

 while(h < s)
 {
  if(att = (object)ob[h]->query_attack())
  {
   ob[h]->stop_fight();
   att->stop_fight();
  }
  h ++;
 }
 this_player()->add_sp(-40);
  return 1;
}
