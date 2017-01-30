/*
 * Channel daemon
 */
#include "../DEFS.h"


void overchannel(string str) {
/* For announcements */
  object everyone, member;
  int i;
  everyone = users();
  for(i = 0; i < sizeof(everyone); i++) {
    member = present(GUILD_ID, everyone[i]);
    if(member && member->muffled() < 1)
      tell_object(everyone[i],
        BLINK+BOLD+"<<_CYBERNET_>>>"+OFF+OFF+" "+str+"\n");
  }
}


void tell(object ob, string str) {
/* Guild channel */
  object everyone, member;
  int i;
  everyone = users();
  for(i = 0; i < sizeof(everyone); i++) {
    member = present(GUILD_ID, everyone[i]);
    if(member && member->muffled() < 1) {
      tell_object(everyone[i],
        RED+"CYBERNET~~~"+END+" "+BOLD+OPN+END+" "+RED+
        ">>>"+END+" "+str+"\n");
    }
  }
}


void tellOfficers(object ob, string str) {
/* Guild channel for officers */
  object everyone, member;
  int i;

  everyone = users();
  for(i = 0; i < sizeof(everyone); i++) {
    member = present(GUILD_ID, everyone[i]);
    if(member && member->guild_officer()) {
      if(member->muffled() < 1) 
        tell_object(everyone[i],
        BLUE+"--OFFICERNET--"+END+" "+BOLD+OPN+END+" "+
        BLUE+"--"+END+" "+str+"\n");
    }
  }
}


void emote(object ob, string str) {
/* Guild channel emote */
  int i;
  object people, memb;

  people = users();
  for(i = 0; i<sizeof(people); i++) {
    memb = present(GUILD_ID, people[i]);
    if(memb && memb->muffled() < 1) {
      tell_object(people[i],"\n"+
        RED+"(CYBER)"+OFF+" "+OPN+" "+str+"\n");
    }
  }
}


