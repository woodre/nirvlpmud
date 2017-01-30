#include "../DEFS.h"


status main(string str)
{
/* Process for becoming a CyberNinja Renegade */
  if (!str)
  {
    write("Usage: renegade [commit].\n"+
          "       Be sure to read 'cyber renegade'\n\n");
    write("Current mode: "+BOLD);
    if ((int)IPTP->query_nohonor() == 0) write("HONORABLE");
    if ((int)IPTP->query_nohonor() == 1) write("RENEGADE");
    write(OFF+"\n");
    return 1; 
  }

  if (str == "commit")
  {
    if (IPTP->query_nohonor())
    {
      write("You are already Renegade.\n");
      return 1;
    }
    IPTP->set_nohonor();
    write(BOLD+"YOU ARE NOW A RENEGADE CYBERNINJA\n"+
          "NO CYBERNINJA HONOR RULES APPLY.\n\n"+OFF);
    IPTP->set_honor(-5);
    IPTP->save_me();
    call_other(CHANNELD, "overchannel", TPN+" has become a Renegade!\n");
    write_file(LOGDIR + "/RENEGADE", TRN+" became renegade. ("+ctime()+")\n");
  }

  return 1;
}
