#include "/players/maledicta/ansi.h"

replace_text(string str, object user, object target)
{
   string x;

   if(str == "H") x = BOLD;
   if(str == "K") x = BLK;
   if(str == "R") x = RED;
   if(str == "Y") x = YEL;
   if(str == "B") x = BLU;
   if(str == "G") x = GRN;
   if(str == "C") x = CYN;
   if(str == "W") x = WHT;
   if(str == "M") x = MAG;
   if(str == "N") x = NORM;
   if(str == "9") x = "\n";

if(user){
   if(str == "1") x = user->query_possessive();
   if(str == "2") x = user->query_pronoun();
   if(str == "3") x = user->query_objective();
   if(str == "4") x = user->query_name();
   }

if(target){
   if(str == "5") x = target->query_possessive();
   if(str == "6") x = target->query_pronoun();
   if(str == "7") x = target->query_objective();
   if(str == "8") x = target->query_name();
   }
 
   return x;
}

filter_msg(string str, object user, object target)
{
   int x; string *words; string tmp;
   words = explode(str,"$");
   for(x=0;x<sizeof(words);x++)
   if(replace_text(words[x], user, target)) words[x] = replace_text(words[x], user, target);
   str = (implode(words,""))+NORM;
   return str;
}
