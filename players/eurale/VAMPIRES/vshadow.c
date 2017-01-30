/*
  Vampire Shadow
 */

#include "/players/eurale/defs.h"
  object player;

Etest() {
  return "Vamp Shadow working..."; }

start_vampstuff(who) {
  player = who;
  shadow(player, 1);
  return 1; }

test_dark() { return 0; }

stop_vampstuff() {
  shadow(player, 0);
  destruct(TO);
  return 1; }

quit() {
  shadow(player,0);
  player->quit();
  return 1;
}

look(str) {
  object fangs;
  fangs = present("vampire fangs",player);
  if(fangs) {
    fangs->light_up(3);
    player->look(str);
    fangs->light_up(-3); }
  else { player->look(str); }
return 1;
}

move_player(str) {
  object fangs;
  fangs = present("vampire fangs",player);
  if(fangs) {
    fangs->light_up(3);
    if(!player->move_player(str)) { fangs->light_up(-3); }
    else fangs->light_up(-3); }
  else { player->move_player(str); }
}
