/*
  show_player.h
*/

#include "/players/eurale/defs.h"

/* --------- look at a player -------- */
show_player(str) {
  string what, who;
  object target_obj;
  what = query_verb();

if(!str) {
  TP->look();
  return 1; }

if(what == "examine" || what == "exa") {
  TP->look("at " + str);
  target_obj = present(str, ROOM);
if(target_obj) {
  if(present("vampire fangs", target_obj))
    write("~o~  This player is a fellow vampire!\n");
  if(present("vampire bite", target_obj))
    write("~:~  This player has been bitten by a vampire!\n");
  return 1; }
}

if(what == "look" || what == "l") {
  if(str == "at") return 0;
  sscanf(str, "at %s", who);
    /* look at someone or something */
if(who) {
  target_obj = present(who, ROOM);
  if(!target_obj) target_obj = present(who, TP);
  if(!target_obj) return 0;
  TP->look("at " + who);
    if(target_obj) {
      if(present("vampire fangs", target_obj))
        write("~o~  This player is a fellow vampire!\n");
      if(present("vampire bite", target_obj))
        write("~:~  This player has been bitten by a vampire!\n");
    return 1; }
}

else {
  if(TP->query_brief())
    tell_object(TP, ROOM->short()+"\n");
  else
    command("look", TP);
    }
  }
  return 0;
}
