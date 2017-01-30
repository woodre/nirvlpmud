#include "../def.h"

cmd_quit()
{
  if(TP->query_level() < 21)
  command("id :left the game.", TP);
  return 0;
}
