
/* the hall of fame.  Keeps track of top pkers. */

#include "defs.h"
inherit "room/room";
string killers;           /* the list */
string name; int level, num_members;
int *kills;               /* total pk kills */
int pkpts;               /* player killing points */

reset(){
   short_desc = "Hall of Fame";
   long_desc = 
"Great statues of long dead heroes decorate this great, long hall\n"+
"that seems to be just too small to hold all of this greatness within\n"+
"it.  There is a list of those who are on their way to getting a statue\n"+
"at the end of the hall\n";
   set_light(1);
   killers = ({ });  kills = ({ });
}

init(){
   add_action("list", "list");
}

list(){
   int i;
   restore_object(APATH+"killers");
   write(">The Nirvana Player Killing Hall of Fame<\n");
   for(i=0; i < sizeof(killers) && i < 10; i++){
       write(i+". "+justify(capitalize(killers[i]), 14)+
            justify(kills[i], 5)+justify(pkpts, 7)+
            "\n");
    }
    return 1;
}

add_killer(string str, int lvl, int xlvl){
   /* if you don't understand this, go out and shoot someone */
      /* That's what I did. */
   int i, j, tmp, pktmp, tpts;
   string temp;
   restore_object(APATH+"killers");

   /* 1 pkpt/level < 15, 2 pkpts/level > 15, 2 pkpts/exlevel */

   if(lvl < 15) tpts = lvl;
   else tpts = (lvl - 14) + ((lvl - 14) * 2) + (xlvl * 2); 

   if(!killers || member_array(str, killers) == -1){
      /* a new member! */
      restore_object("players/"+str);
      if(!name){
         return -1;
      }
      if(level > 19) return -2;
      killers += ({ str }); kills += ({ 1 }); pkpts += ({ tpts });
      num_members++;
   }
   else {
      /* old member, add to their kills */
      for(i=0; i < sizeof(killers); i++) if(killers[i] == str) break;
      kills[i]++;
      pkpts[i] += tpts;
   }
   /* sort by total kills. I'll use an evil bubble sort */
   for(i=1; i < sizeof(kills); i++){
      for(j=sizeof(kills)-1; j >= i; j--){
         if(kills[j-1] < kills[j]){
            tmp = kills[j-1];
            temp = killers[j-1];
            pktmp = pkpts[j-1];
            kills[j-1] = kills[j];
            killers[j-1] = killers[j];
            pkpts[j-1] = pkpts[j];
            kills[j] = tmp;
            killers[j] = temp;
            pkpts[j] = pktmp;
         }
       }
   }
   save_object(APATH+"killers");
   return 1;
}

remove_killer(str){
   string templist;
   int i;
   restore_object(APATH+"killers");
   if(member_array(str, killers) == -1) return -1;
   killers = filter_array(killers, "removal", this_object(), str);
   save_object(APATH+"killers");
   return 1;
}

removal(n, str){
   if(n != str) return 1;
   else {
      int i;
      for(i=0; i < sizeof(killers); i++) if(killers[i] == str) break;
      kills = filter_array(kills, "removal2", this_object(), i);
      pkpts = filter_array(pkpts, "removal3", this_object(), i);
      return 0;
   }
}

removal2(int bounty, int index){
   if(bounty == kills[index]) return 0;
   else return 1;
}

removal3(int pts, int index){
   if(pts == pkpts[index]) return 0;
   else return 1;
}

member_killers(str){
   restore_object(APATH+"killers");
   if(member_array(str, killers) == -1) return 0;
   else return 1;
}

query_kills(str){
   restore_object(APATH+"killers");
   if(member_array(str, killers) != -1){
	  return kills[member_array(str, killers)];
   }
   return 0;
}

query_pkpts(str){
    restore_object(APATH+"killers");
    if(member_array(str, killers) != -1){
       return pkpts[member_array(str, killers)];
    }
    return 0;
}
