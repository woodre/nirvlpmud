#include "/players/pestilence/define.h"
#include "/players/pestilence/ansi.h"


main(string str) {
  object ob, myob, conshad;
  int obwc, obac;
  int calc_sp, str_bonus;
  str_bonus = present("pesty_guild",this_player())->query_combat();
if(this_player()->query_guild_rank() < 6){ write("You can't use this skill yet.\n"); return 1; }
  if(TP->query_level() < 18) {
    write("You are not high enough level to use sickness.\n");
    return 1; }
  if(TP->query_ghost()) {
    write("You can't use sickness while you're dead.\n");
    return 1; }
  calc_sp=(160 -
                      ((TP->query_level()*3/4) + 
                      (TP->query_extra_level()*3/4) +
                      (TP->query_attrib("str")/2) +
                      str_bonus +
                      (TP->query_attrib("wil")/2)));
  
  if(TP->query_sp() < calc_sp) {
   write("You are too weak to use sickness.\n"); return 1; }
  myob = present("dknight_ob", TP);
  if(myob->query_spell_delay()) {
    write("You can't use this skill again so soon.\n"); return 1; }
  if(!str && !TP->query_attack()) { write("Sickness who?\n"); return 1; }
  if(!str) ob = TP->query_attack();
  if(!ob) ob = present(str, environment(TP));
  if(!ob || !present(ob, environment(TP))){
    write("You don't see "+str+".\n"); return 1; }
  if(!living(ob)) {
    write("You can't make lifeless objects sick.\n"); return 1; }
  if(ob->is_player()) {
    write("You can't use sickness on players.\n"); return 1; }
  if(ob->is_studied()) {
    write(ob->query_name()+" is already Sickened.\n"); return 1; }
  write("You draw deep from your "+HIK+"HATRED"+NORM+" and give "+ob->query_name()+" the "+HIR+"SiCkNeSs"+NORM+".\n");
   conshad = clone_object("/players/pestilence/closed/dark/obj/studyshad.c");
  conshad->set_victim(ob);
  conshad->set_time((TP->query_level()/2) + (TP->query_extra_level()/4)+
                    (str_bonus /2) +
                    (TP->query_attrib("pie")/4) +
                    (TP->query_attrib("wil")/4));
  /* myob->set_spell_delay(200); */
  myob->set_spell_delay(275-
  (TP->query_attrib("wil"))-
  (str_bonus) -
  (TP->query_attrib("pie"))-
  (TP->query_level() * 5)-
  (TP->query_extra_level()/2));

  TP->add_spell_point(-calc_sp);
  return 1; }
