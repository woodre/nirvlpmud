/* Verte changed Time of confusion shadow and spell delay
  to reflect attribs, extra level, & level .. should
  be a lot more awesome now.
*/
#include "/players/snow/dervish/def.h"

confuse(str) {
  object ob, myob, conshad;
  int obwc, obac;
  int calc_sp;
  if(TP->query_level() < 15) {
    write("You are not high enough level to confuse yet.\n");
    return 1; }
  if(TP->query_ghost()) {
    write("You cannot confuse while you are a ghost.\n");
    return 1; }
  calc_sp=(160 -
                      ((TP->query_level()*3/4) + 
                      (TP->query_extra_level()*3/4) +
                      (TP->query_attrib("mag")/2) +
                      (TP->query_attrib("pie")/2) +
                      (TP->query_attrib("wil")/2)));
  
  if(TP->query_sp() < calc_sp) {
    write("You lack the energy to confuse.\n"); return 1; }
  if(TP->query_attrib("pie") < 15) {
    write("You lack in faith.\n"); return 1; }
  myob = present(GID, TP);
  if(myob->query_spell_delay()) {
    write("You cannot cast a spell again so soon.\n"); return 1; }
  if(!str && !TP->query_attack()) { write("Confuse what?\n"); return 1; }
  if(!str) ob = TP->query_attack();
  if(!ob) ob = present(str, environment(TP));
  if(!ob || !present(ob, environment(TP))){
    write("You can't see "+str+".\n"); return 1; }
  if(!living(ob)) {
    write("You cannot confuse inanimate objects.\n"); return 1; }
  if(ob->is_player()) {
    write("You cannot confuse players.\n"); return 1; }
  if(ob->is_confused()) {
    write(ob->query_name()+" is already confused.\n"); return 1; }
  write("You scream and whirl maniacally!\n");
  say(TP->query_name()+" screams and whirls maniacally!\n");
  tell_room(environment(TP), BOLD+ob->query_name()+
    " is surrounded by whipping particles of sand!\n"+OFF);
  conshad = clone_object("/players/snow/dervish/objects/conshad.c");
  conshad->set_victim(ob);
  conshad->set_time((TP->query_level()/2) + (TP->query_extra_level()/3)+
                    (TP->query_attrib("mag")/4) +
                    (TP->query_attrib("pie")/4) +
                    (TP->query_attrib("wil")/4));
  /* myob->set_spell_delay(200); */
  myob->set_spell_delay(275-
  (TP->query_attrib("wil"))-
  (TP->query_attrib("mag")) -
  (TP->query_attrib("pie"))-
  (TP->query_level() * 5)-
  (TP->query_extra_level()/2));

  TP->add_spell_point(-calc_sp);
  return 1; }
