#include "/players/snow/dervish/def.h"

dervish_heal() {
  object me, myob;
  int hp, sp, hpadd, spadd;
  me = this_player();
  myob = present(GID, me);
  if(!me || !myob) { write("Something is wrong.\n"); return 1; }
  if(me->query_level() < 18) {
    write("You are not high enough level to use this Mystic ability yet.\n");
    return 1; }
  if(me->query_ghost()) {
    write("You lack substance.\n"); return 1; }
  if(me->query_attrib("pie") < 20) {
    write("You lack devotion.\n"); return 1; }
  if(myob->query_spell_delay()) {
    write("You cannot cast a spell again so soon.\n"); return 1; }
  if(me->query_sp() < 1) {
    write("You do not have enough energy.\n"); return 1; }
  if(me->query_attack()) {
    write("You cannot cast a spell in combat.\n"); return 1; }
  write(BOLD+RED+"\tYou are engulfed in a hot pillar of sand...\n"+
        "\tYour wounds are filled with fire!\n"+
        "\tYour body shakes with pleasure.\n\n"+OFF+OFF);
  say(BOLD+RED+me->query_name()+" is engulfed in a hot pillar of sand...\n"+
      me->query_name()+" shakes with pleasure.\n\n"+OFF+OFF);
  hp = me->query_hp();
  hpadd = me->query_mhp() - hp;
  sp = me->query_sp();
  if(sp >= hpadd) spadd = hpadd;
  if(hpadd > sp) { hpadd = sp; spadd = sp; }
  me->add_spell_point(-spadd);
  me->add_hit_point(hpadd);
  myob->add_spell_delay(random(100)+ 50);
  return 1; }