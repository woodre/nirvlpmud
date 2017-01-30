#include "../def.h"

cmd_gadvance()
{
  int rank;
  int cost;
  if((rank=TP->query_guild_rank()) == 10)
  {
    write("You have maxed the guild.\n");
    return 1;
  }
  
  switch(rank)
  {
    case 1: cost = 350000; break;
    case 2: cost = 562500; break;
    case 3: cost = 1125000; break;
    case 4: cost = 1500000; break;
    case 5: cost = 2500000; break;
    case 6: cost = 3000000; break;
    case 7: cost = 3500000; break;
    case 8: cost = 4500000; break;
    case 9: cost = 5000000; break;
  }

  
  if(TP->query_free_exp() < cost)
  {
    write("You need "+cost+" xp to advance to your next rank.\n");
    return 1;
  }
  
  write("You can advance at Pai Mei.\n");
  
  return 1;
}
