#include "/players/snow/dervish/def.h"

dervish_chant() {
  object me, myob;
  me = this_player();
  myob = present(GID, me);
  if(!me || !myob) { write("Something is wrong.\n"); return 1; }
  if(me->query_level() < 10) {
    write("You are not high enough level to use this Mystic ability yet.\n");
    return 1; }
  if(me->query_ghost()) {
    write("You lack substance.\n"); return 1; }
  if(me->query_attrib("pie") < 19) {
    write("You lack devotion.\n"); return 1; }
  if(myob->query_spell_delay()) {
    write("You cannot cast a spell again so soon.\n"); return 1; }
  if(me->query_sp() < 20) {
    write("You do not have enough energy.\n"); return 1; }
  if(me->query_attack()) {
    write("You cannot cast a spell in combat.\n"); return 1; }
  write(BOLD+RED+"\tYou scream and spin wildly about!\n"+OFF+OFF);
  say(BOLD+RED+me->query_name()+" screams and spins wildly about!\n"+OFF+OFF);
  me->add_spell_point(-20);
  me->add_hit_point(random(me->query_attrib("pie"))+8);
  myob->add_spell_delay(random(20)+5);
  return 1; }
