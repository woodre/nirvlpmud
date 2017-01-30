#include "../defs.h"

status main(string str, object gob, object player)
{
	
  if((int)player->query_ghost()) return 0;
  
  command("score", player);
	return 1;	
}
