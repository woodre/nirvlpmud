#include "/players/pestilence/define.h"

study(str) {
  object ob, myob, conshad;
  int obwc, obac;
  int calc_sp;
if(this_player()->query_guild_rank() < 5){ write("You can't use this skill yet.\n"); return 1; }
/*
  if(TP->query_level() < 15) {
    write("You are not high enough level to confuse yet.\n");
    return 1; }
*/
  if(TP->query_ghost()) {
    write("You can't study a mob while your dead.\n");
    return 1; }
  calc_sp=(160 -
                      ((TP->query_level()*3/4) + 
                      (TP->query_extra_level()*3/4) +
                      (TP->query_attrib("str")/2) +
                      (TP->query_attrib("sta")/2) +
                      (TP->query_attrib("wil")/2)));
  
  if(TP->query_sp() < calc_sp) {
    write("You don't have the energy to study.\n"); return 1; }
  myob = present("destroyer_ob", TP);
  if(myob->query_spell_delay()) {
    write("You can't use this skill again so soon.\n"); return 1; }
  if(!str && !TP->query_attack()) { write("Study who?\n"); return 1; }
  if(!str) ob = TP->query_attack();
  if(!ob) ob = present(str, environment(TP));
  if(!ob || !present(ob, environment(TP))){
    write("You don't see "+str+".\n"); return 1; }
  if(!living(ob)) {
    write("You can't study lifeless objects.\n"); return 1; }
  if(ob->is_player()) {
    write("You can't study players.\n"); return 1; }
  if(ob->is_studied()) {
    write(ob->query_name()+" is already studied.\n"); return 1; }
  write("You concentrate very hard on "+ob->query_name()+", and learn a few weakenesses\n");
  conshad = clone_object("/players/pestilence/closed/destroyer/obj/studyshad.c");
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
