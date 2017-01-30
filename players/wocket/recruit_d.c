#include "../DEFS.h"
#define SAVE   "players/dune/closed/guild/daemons/recruit"
#define SAVEME save_object(SAVE)
string *recruitpairs;

add_recruitpair(str){
  if(!recruitpairs)
    recruitpairs = ({ "blank1|blank2" });
  recruitpairs += ({ str });
  SAVEME;
}

remove_recruitpair(str){
  if(member_array(str,recruitpairs) != -1)
    recruitpairs -= ({ str });
    SAVEME;
}

load_daemon(){
  if(!restore_object(SAVE))
  if(!recruitpairs)
    recruitpairs = ({ "blank1|blank2" });
    SAVEME;
}

check_recruitee(player){
string *pair;
int i,a,flagged;
  a = sizeof(recruitpairs);
  for(i=0;i<a;i++){
    pair = explode(recruitpairs[i],"|");
    if(pair[0] == player->query_real_name()){
      flagged = 1;
      present(GUILD_ID,player)->set_recruitee(pair[1]);
      return 1;
    }
  }
  if(!flagged){
    present(GUILD_ID,player)->set_recruitee(0);
    return 0;
  }
}