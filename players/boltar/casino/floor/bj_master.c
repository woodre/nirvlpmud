#include "plasma.h"

check_value(string str) {
   string this_card, *cards;
   int score, x, tmp, aces;
   
   cards = explode(str,"_");
   
   for(x = 0; x < sizeof(cards); x++) {
      if(sscanf(cards[x],"%s %s",this_card,str));
      if(sscanf(this_card,"%d",tmp)) score += tmp;
      if(!sscanf(this_card,"%d",tmp)) {
         score += 10;
         if(this_card == "Ace") { score += 1; aces += 1; } } }
   
   while(aces) {
      if(score > 21) score -= 10;
      aces -= 1; }
   
   if(score > 21) return -1;
   return score; }
