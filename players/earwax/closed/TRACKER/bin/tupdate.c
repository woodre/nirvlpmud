#include "../defs.h"

status main(string arg) {
  object ob;

  ob = clone_object(TRACKER_OBJ);
  move_object(ob,this_player());
  destruct(present(TRACKER_ID+" 2",this_player()));
  return 1;
}
