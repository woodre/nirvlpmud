/* gives monitor info on target player/npc [hp, sp, etc]
*/
#include "/players/zeus/closed/all.h"
#define TQL (int)ob->query_level()
#define YA tell_object(environment()

know_cmd(str){
  object ob, enemy;    int NM, i,f,s,t;
  if(!str) return 0;
  ob = find_player(str);    if(!ob) ob = find_living(str);
  if(!ob) return 0;
  i = (int)ob->query_intoxination()*100 / (TQL+3);
  f = (int)ob->query_stuffed()*100 / (TQL*8);
  s = (int)ob->query_soaked()*100 / (TQL*8);
  t = (int)ob->query_infuse()*100 / ((TQL*9)/2);
  enemy = (object)ob->query_attack();
        YA,HIW+ob->QN+":"+NORM);
  if(ob->checkNM())
          NM = 1;
  YA,"\t HP ["+ob->query_hp()+"/"+ob->query_mhp()+"]  ");
  if(NM)
          YA,"SP [???/"+ob->query_msp()+"]  ");
  else
          YA,"SP ["+ob->query_spell_point()+"/"+ob->query_msp()+"]  ");
  YA,"I "+i+"%  F "+f+"%  S "+s+"%  T "+t+"%  A: "+
          ob->query_alignment()+"\n");
  if(enemy){
          YA,HIW+enemy->QN+":"+NORM+" HP ["+enemy->query_hp()+"]  ");
          YA,"WC: "+enemy->query_wc()+"  AC: "+enemy->query_ac()+"  A: "+
                          enemy->query_alignment()+"\n");     }
  if(environment(ob)){
    YA,HIW+"Room: "+NORM+environment(ob)->short()+"\n");
  }
  return 1; 
}

