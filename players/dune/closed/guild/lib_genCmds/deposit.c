#include "../DEFS.h"


status main(string str)
{
  int num, bal, deposited, atmBal;
  if(!str || !sscanf(str, "%d", num) || num <= 0)
  {
    write("Specify an amount to deposit.\n");
    return 1;
  }
  bal = (int)IPTP->balance();
  if(bal < num)
  {
    write("You do not have that many credits.\n");
    return 1;
  }
  IPTP->addToBalance(-num);
  deposited = (int)call_other(POOLD, "depositCredits", num);
  IPTP->save_me();
  atmBal = (int)call_other(POOLD, "query_credits");
  write("You are charged a small service fee of "+(num-deposited)+" credits.\n"+
        "You deposit "+deposited+" credits into the CyberNinja ATM.\n"+
        "The ATM now contains: "+atmBal+" credits.\n");
  write_file(LOGDIR + "/ATM", TRN+" deposited "+deposited+
    " credits. ("+ctime()+")\n");
  return 1;
}
