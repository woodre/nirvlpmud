/* SILENT ZAP */
#include "/players/pestilence/define.h"


main(str) {
  object ob, sand;
  if(str && (ob = present(str, environment(this_player()))))
  sand=clone_object("/players/pestilence/closed/dark/mob/booger.c");
  move_object(sand, environment(ob));
  ob->attacked_by(sand);
  ob->hit_player(100000000, "other|vertebraker");
  destruct(sand);
return 1;
}
