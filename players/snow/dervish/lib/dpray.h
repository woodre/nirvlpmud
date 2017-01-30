#include "/players/snow/dervish/def.h"

dervish_pray() {
  object me, myob;
  object poison, next;
  string a,b;
  me = this_player();
  myob = present(GID, me);
  if(!me || !myob) { write("Something is wrong.\n"); return 1; }
  if(me->query_level() < 14) {
    write("You are not high enough level to use this Mystic ability yet.\n");
    return 1; }
  if(me->query_ghost()) {
    write("You lack substance.\n"); return 1; }
  if(me->query_attrib("pie") < 19) {
    write("You lack devotion.\n"); return 1; }
  if(myob->query_spell_delay()) {
    write("You cannot cast a spell again so soon.\n"); return 1; }
  if(me->query_sp() < 40) {
    write("You do not have enough energy.\n"); return 1; }
  if(me->query_attack()) {
    write("You cannot cast a spell in combat.\n"); return 1; }
  write(BOLD+RED+"\tYou writhe about, spinning in ecstacy!\n"+OFF+OFF);
  say(BOLD+RED+me->query_name()+" writhes about, spinning in ecstacy!\n"+OFF+OFF);
  poison = first_inventory(me);
        while (poison) {
                next = next_inventory(poison);
                if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
                        poison->id("poison")) {
                        tell_object(me,
                        BOLD+RED+"Poison is destroyed"+OFF+BOLD+"..."+OFF+"\n");
                        destruct(poison);
                }
                poison = next;
        }
  me->add_spell_point(-40);
  me->add_hit_point(random(me->query_attrib("pie"))+32);
  myob->add_spell_delay(random(60)+15);
  return 1; }
