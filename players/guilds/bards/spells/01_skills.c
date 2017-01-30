#include "/players/guilds/bards/def.h"
/*
 * Lists bard skill information
 * Illarion  - 4/03
 */
 
status main() {
  int x;
  object gob;
  mixed *skills;
  gob=previous_object();
  skills=(mixed)gob->query_skill_information();
  if(sizeof(skills)==0) {
    notify_fail("You have no Bard skills.\n");
    return 0;
  }
  write(MAG+"----------------"+HIM+" Bard Skills"+NORM+MAG+" ----------------"+NORM+"\n");
  write("  Name         Level      Practiced\n");
  for(x=0;x<sizeof(skills);x+=3) {
    write(pad(""+skills[x],17));
    write(pad(""+skills[x+1],6));
    write(call_other(OBJ+"scale","show_scale",skills[x+2],100,20));
    write("\n");
  }
  return 1;
}
