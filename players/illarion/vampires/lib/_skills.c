#include "../def.h"
#define SCALE(a,b,c,d) call_other(ROOT+"util/scale","show_scale",a,b,c,d)
inherit LIBBASE;

main(str, targ, usr, gob) {
  mixed skills, skill_info;
  int x,s;
  skills = gob->query_skills();
  if(!skills) {
    write("You have no skills.\n");
    return 1;
  }
  skill_info = SKDAEM->query_skill_information(skills);
  s=sizeof(skill_info);
  write("  Skill            Level       Progress\n");
  for(x=0;x<s;x+=3) {
    write(pad(""+skill_info[x],20)+
          pad(""+skill_info[x+1],8)+
          SCALE(skill_info[x+2], 100, 20, 0)+
          "\n");
  }
  return 1;
}
