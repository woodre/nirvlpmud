#include "/players/jenny/define.h"
string giberish, techie;
string *words;
int n;
main(str) {

   if(sscanf(str,"%s %s",words) != 1) return 0;
giberish = "";
words = explode(giberish," ");
for(n=0;n < sizeof(words);++n);

giberish += crypt(words(n), 0)+" ";

write("you say:  "+words+"\n");
   say(BOLD+MAG+TPN+" says: "+BOLD+YEL+giberish+NORM+"\n");
   return 1; }
