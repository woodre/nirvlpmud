#include "../def.h"
cmd_accuse(str)
{
  object ob;

  if(!str) ob = this_player()->query_attack();

  else ob = present(str, environment(this_player()));

  if(!ob) return (write("Who do you want to accuse ?\n"), 1);
  if(!this_player()->valid_attack(ob))
    return (write("Impossible.\n"), 1);

  if(query_attribute("accused", ob))
    return (write(ob->query_name() + " has already been accused.\n"), 1);

  add_attribute("accused", ob);
  write("\n\tWhirling around, you glare angrily and point a finger at the heathen!\n"+
       "\n\t"+HIR+"I ACCUSE YOU, "+upper_case(ob->query_name())+", OF WITCHCRAFT!\n\n"+NORM);
  return 1;
}
