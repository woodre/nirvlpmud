#include "/players/snow/dervish/def.h"

dervish_train(str){
  int x, y, z;
  object me, myob;
  me = this_player();
  myob = present(GID, me);
  x = myob->query_skill_pt();
  y = myob->query_parry();
  z = myob->query_offparry();
    if(!str){ write("What did you wish to raise?\n"); return 1; }
    if(x < 1) { write("You don't have any skill points to spend.\n"); return 1; }
    if(str == "parry"){
      if(y > 4){ write("You have already gained mastery of the parry skill.\n"); return 1; }
      myob->add_parry(1);
      myob->add_skill_pt(-1);
      myob->dervish_resett();
      write("You train your parry skill to "+(y+1)+".\n");
      return 1;}
    if(str == "offwield parry" || str == "offparry"){
      if(z  > 4){ write("You have already gained mastery of the offwield parry skill.\n"); return 1; }
      myob->add_offparry(1);
      myob->add_skill_pt(-1);
      myob->dervish_resett();
      write("You train your offwield parry skill to "+(z+1)+".\n");
      return 1; }
    }
