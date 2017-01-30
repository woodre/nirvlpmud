#include "/players/earwax/inherit/ansi.h"

int query_rank_required() { return 1; } /* return whatever rank needed */

int main() {
  write(HIB+"You use the color codes this way\n");
  write(HIR+"and so on and use NORM to stop color, always use NORM\n"+NORM);
  return 1;
}
