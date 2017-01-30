#include "../scar.h"

main() {
  if(this_player()->query_real_name() == "dragnar" || this_player()->query_real_name()=="beck") {
    RANK->ResetList();
    write("Resetting the rankings...\n");
    return 1;
  }
}
