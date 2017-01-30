#include "/players/llew/closed/ansi.h"

cg(str){
   string who,what,chwhat;
   string *words, *colors;
   int n;
   chwhat = "";
   colors = ({ NORM+RED,NORM+BLINK+RED,NORM+HIR,BLINK+HIR,NORM+BLU,NORM+BLINK+BLU,NORM+HIB,BLINK+HIB,NORM+GRN,NORM+BLINK+GRN,NORM+HIG,BLINK+HIG,NORM+YEL,NORM+BLINK+YEL,NORM+HIY,BLINK+HIY,NORM+CYN,NORM+BLINK+CYN,NORM+HIC,BLINK+HIC,NORM+MAG,NORM+BLINK+MAG,NORM+HIM,BLINK+HIM,NORM+WHT,NORM+BLINK+WHT,NORM+HIW,BLINK+HIW });
   if(!str) return 0;
   what = str;
      words = explode(what," ");
      for(n=0;n < sizeof(words);++n) {
         chwhat += colors[random(14)]+words[n]+" ";
      }
      chwhat=chwhat+NORM;
   "/obj/user/one_chan"->chan_msg(capitalize(this_player()->query_real_name())+" gossips: "+chwhat+"\n","gossip");
   return 1;
}

