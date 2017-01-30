/* Object called by sgrenade */

#define TO this_object()

object MEAT;

stunning(arg) {
  if(arg->query_npc()) MEAT = arg;
  shadow(MEAT,1);
}

heart_beat() {
  MEAT->stop_fight();
  MEAT->stop_fight();
}

attack() {
  MEAT->stop_fight();
  MEAT->stop_fight();
}

catch_tell() {
  MEAT->stop_fight();
  MEAT->stop_fight();
}

