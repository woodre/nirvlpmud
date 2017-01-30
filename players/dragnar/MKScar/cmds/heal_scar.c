#include "../scar.h"

main() {
   int r;
   r = previous_object()->QMKRank();
   write("You mumble some magic words and your scar slowly fades away.\n");
   if(intp(r) && r > 0 && r < 201) {
     RANK->Delete(r);
   }
   destruct(previous_object());
   return 1;
}
