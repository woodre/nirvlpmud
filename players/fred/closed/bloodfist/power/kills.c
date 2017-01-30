#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  string *pk_names;
  int *pk_nums, a, sa, tpk, td;
  pk_names = (string*)PO->query_pk_names();
  pk_nums = (int*)PO->query_pk_nums();
  sa = sizeof(pk_names);
  td = (int)PO->query_total_deaths();
  if(sa <= 0)
    TOU"You have not killed anyone yet.\n");
  else {
    TOU " Name       Kills\n");
    for(a = 0; a < sa; a++)
    {
      TOU pad(" "+capitalize(pk_names[a]), 14)+pk_nums[a]+"\n");
      tpk += pk_nums[a];
    }
    if(sa == 1 && tpk == 1)
      TOU "\nYou have killed 1 player 1 time.\n");
    else if(sa == 1 && tpk > 1)
      TOU "\nYou have killed 1 player "+tpk+" times.\n");
    else
      TOU "\nYou have killed "+sa+" different players "+tpk+" times.\n");
  }
  if(td == 0)
    TOU "You have not died yet since joining Bloodfist.\n");
  else if(td == 1)
    TOU "You have died 1 time since joining Bloodfist.\n");
  else
    TOU "You have died "+td+" times since joining Bloodfist.\n");
  return 1;
}

