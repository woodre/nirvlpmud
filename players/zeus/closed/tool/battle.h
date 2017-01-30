/* Forces 2 living things to attack each other.
*/
#include "/players/zeus/closed/all.h"
battle_cmd(string str){
  string npc1s, npc2s;
  object npc1, npc2;
  if(!str){ 
          tell_object(ENV,"Usage: 'battle <npc1> <npc2>'\n"); 
          return 1; 
  }
  if(!sscanf(str, "%s %s", npc1s, npc2s)) return 0;
  npc1 = present(npc1s, environment(TP));
  npc2 = present(npc2s, environment(TP));
  if((!npc1 || !npc2) || (!npc1 && !npc2)) return 0;
  tell_object(ENV,
          "You command "+npc1->QN+" to attack "+npc2->QN+".\n\n");
  npc1->attack_object(npc2);
    MO(CO("/players/zeus/closed/tool/b_mon.c"), npc1);
  return 1;
}
