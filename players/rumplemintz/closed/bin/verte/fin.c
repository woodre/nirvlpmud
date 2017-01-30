#include "../std.h"
main(str) {
   object fin;
   fin = CO("/players/mythos/closed/play/finger");
   MO(fin,TP);
   command("fin "+str,TP);
   destruct(fin);
   return 1; }
