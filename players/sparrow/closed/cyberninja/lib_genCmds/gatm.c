#include "../DEFS.h"


status main(string str)
{
  int bal;
  bal = (int)call_other(POOLD, "query_credits");
  write(LINE+"The CyberNinja ATM balance is:\n"+
        bal+" credits\n"+LINE);
  return 1;
}
