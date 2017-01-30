#include "../scar.h"
#define LOG LOGDIR+"Forfeit"

main() {
  if(previous_object()->QMKIssued()) {
    if(previous_object()->QMKForfeits()>= 4) {
      write("You have fofeited too many times and lose Rank.\n");
      RANK->Demote(this_player()->query_name());
      previous_object()->CMKForfeits();
    }
    previous_object()->AMKForfeits();
    previous_object()->MKTimeOut();
    write_file(LOG, ctime(time())+": "+this_player()->query_name()+" has "+previous_object()->QMKForfeits()+" Forfeits.\n");
    previous_object()->SCDelay();
    return 1;
  }
}
