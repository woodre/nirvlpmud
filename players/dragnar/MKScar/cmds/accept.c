#include "../scar.h"
#define TPN this_player()->query_name()
main(str) {
  if(str == "challenge") {
    if(previous_object()->QMKIssued()) {
      previous_object()->CMKForfeits();
      previous_object()->MKBegin();
      /* CHANNELD->broadcast(TPN+" accepts the challenge!\n", 0, "Blood"); */
      CHANNELD->transmit_message( CHANNAME, TPN+" accepts the challenge!\n" );
      return 1;
    }
  }
}
