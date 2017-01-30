#include "/players/feldegast/defines.h"

object ob;

void set_shadow(object targ) {
  if(ob)
  {
    FTELL("Something attempted to reset your quicktyper shadow.\n");
    if(TP) write(TPN+" was the player name.\n");
    if(previous_object()) write(file_name(previous_object())+" was the previous_object.\n");
    return;
  }
  shadow(targ,1);
  ob = targ;
}
history() {
  FTELL(this_player()->query_real_name()+" checked your quicktyper history.\n");
  return;
}
query_quicktyper(arg)
{
  FTELL(this_player()->query_real_name()+" queried your quicktyper.\n");
  return;
}
