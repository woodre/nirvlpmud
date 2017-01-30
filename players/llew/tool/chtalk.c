#include "/players/llew/closed/ansi.h"

chtalk(str){
   string who,what,chwhat;
   string *words, *colors;
   int n;
   chwhat = "";
   colors = ({ NORM+RED,HIR,NORM+BLU,HIB,NORM+GRN,HIG,NORM+YEL,HIY,NORM+CYN,HIC,NORM+MAG,HIM,NORM+WHT,HIW });
   if(!str) return 0;
   what = str;
      words = explode(what," ");
      for(n=0;n < sizeof(words);++n) {
         chwhat += colors[random(14)]+words[n]+" ";
      }
      chwhat=chwhat+NORM;
      tell_room(environment(this_player()),capitalize(this_player()->query_real_name())+" says, \""+chwhat+"\"\n");
   return 1;
}

