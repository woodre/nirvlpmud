#include "/players/feldegast/closed/guild/defines.h"
do_command(str) {
  object target;
  if(this_player()->query_sp()<10) {
    write("You don't have enough energy to rush.\n");
    return 1;
  }
  if(!str) {
    write("Rush who?\n");
    return 1;
  }
  target=present(str,environment(this_player()));
  if(!target) {
    write(capitalize(str)+" is not here.\n");
    return 1;
  }
  if(target->is_player() && !target->query_pk() && !TP->query_pk()) {
    write("You cannot do that.\n");
    return 1;
  }
  target->attack_object(this_player());
  write("You rush into battle.\n");
  say("\n"+TPN+" rushes "+target->query_name()+".\n");
  return 1;
}
