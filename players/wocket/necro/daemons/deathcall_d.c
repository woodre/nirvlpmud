#include "../defs.h"
inherit "/obj/monster.c";
#define DEATH "/log/DEATHS"
string lastdead;


newdeathcheck(){
string *temp;
string YEAR;
string jnk1,playername,playkill;
int playexp,playgold,lastnumb;
  temp = read_file(DEATH);
  if(temp){
  temp = explode(temp,"\n");
  }else{
/* Heh. -Feld
  tell_object(find_player("wocket"),"no temp\n");
*/
  return;
  }
  lastnumb = sizeof(temp)-1;
  sscanf(ctime(time()),"%s200%s",jnk1,YEAR);
  if(lastdead != temp[lastnumb]){
    if(sscanf(temp[lastnumb],"%s 200"+YEAR+" %s %d exp %s gold killed by %s.",jnk1,playername,playexp,playgold,playkill) == 5){
      CHAT_D->tell_guild(ROD+" "+capitalize(playername)+" has now crossed over into the realm of the dead.\n",1);
    }
    lastdead = temp[lastnumb];
  }
}
query_lastdead(){ return lastdead; }
