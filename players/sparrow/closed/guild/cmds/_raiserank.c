#include <ansi.h>
cmd_raiserank()
{
  int rank, cost, mems, funds, failure;

  if((rank = this_player()->query_guild_rank()) == 20)
  {
    write("You have already mastered your Parish.\n"+
          "Now go and spread the "+HIK+"Dark Word"+NORM+" throughout the realm!\n");
    return 1;
  }

  switch(rank)
  {
    case 1:
      cost = 40000;
      mems = 1200;
      funds = 5000;
      break;
    case 2:
      cost = 80000;
      mems = 7200;
      funds = 12000;
      break;
    case 3:
      cost = 230000;
      mems = 20000;
      funds = 50000;
      break;
    case 4:
      cost = 400000;
      mems = 50000;
      funds = 100000;
      break;
    case 5:
      cost = 500000;
      mems = 100000;
      funds = 200000;
      break;
    case 6:
      cost = 750000;
      mems = 200000;
      funds = 300000;
      break;
    case 7:
      cost = 1000000;
      mems = 300000;
      funds = 500000;
      break;
    case 8:
      cost = 1000000;
      mems = 500000;
      funds = 750000;
      break;
    case 9:
      cost = 2000000;
      mems = 750000;
      funds = 1000000;
      break;
    case 10:
      cost = 2000000;
      mems = 1000000;
      funds = 1250000;
      break;
    case 11:
      cost = 2000000;
      mems = 1250000;
      funds = 1500000;
      break;
    case 12:
      cost = 2000000;
      mems = 1500000;
      funds = 2000000;
      break;
    case 13:
      cost = 2000000;
      mems = 1750000;
      funds = 2500000;
      break;
    case 14:
      cost = 2000000;
      mems = 2000000;
      funds = 3000000;
      break;
    case 15:
      cost = 2000000;
      mems = 2500000;
      funds = 3500000;
      break;
    case 16:
      cost = 3000000;
      mems = 3000000;
      funds = 4000000;
      break;
    case 17:
      cost = 3000000;
      mems = 3500000;
      funds = 5000000;
      break;
    case 18:
      cost = 3000000;
      mems = 4000000;
      funds = 6000000;
      break;
    case 19:
      cost = 3000000;
      mems = 5000000;
      funds = 8000000;
  }
  if(this_player()->query_free_exp() < cost )
  {
    write("You require "+HIK+"["+HIC+cost+HIK+"]"+NORM+" experience to grow your renown.\n");
    failure = 1;
  }
  if(previous_object()->queryParish() < mems ) {
    write("You require "+HIK+"["+HIC+mems+HIK+"]"+NORM+" Parish members to grow your renown.\n");
    failure = 1;
  }
  if(previous_object()->queryWorth() < funds ) {
    write("You require "+HIK+"["+HIC+funds+HIK+"]"+NORM+" gold in your coffers to grow your renown.\n");
    failure = 1;
  }
  if(failure) {
    return 1;
  }
  write("You are ready to increase your dark influence.\n"+
        "Your altar has been prepared for the advancement ritual.\n");
  return 1;
}
