#include "../def.h"
#define SCALE(a,b,c,d) call_other(ROOT+"util/scale","show_scale",a,b,c,d)
inherit LIBBASE;

main(str, targ, usr, gob) {
  
  write("              Tribute Coffer\n\
     E "+SCALE(gob->query_tribute(),gob->query_tribute_max(), 40,0));
  write(" F\n");
  return 1;
}
