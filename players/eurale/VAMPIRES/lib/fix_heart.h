/*
  fix heart - restarts players/fangs heartbeats
*/

#include "/players/eurale/defs.h"

/* -------- Fix this player's title or their heart beat ---------- */
fix_heart(str) {

if(str == "heart" || str == "heartbeat" || str == "heart beat") {
if(TP->query_ghost()) {
  write("You are dead and cannot fix your heartbeat.\n");
  return 1; }

  if(find_call_out("do_fix_beat") != -1)
  {
    write("You are already fixing your heartbeat...\n");
    return 1;
  }
  write("You raise your arm back...\n");
  call_out("do_fix_beat", 5, this_player());
  return 1;
}
}

void
do_fix_beat(object ob)
{
  object v;

  ob->heart_beat();
  ob->set_heart_beat(1);

  if(v = present("vampire fangs", ob))
  {
     v->heart_beat();
     v->set_heart_beat(1);
  }

  
  tell_object(ob, "\
You slam your fist into your chest.\n\
Your "+HIR+"HEARTBEAT"+NORM+" returns to a normal rhythm.\n");
  return;
}
