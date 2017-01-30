#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(string str) {
   string verb, color;
   int x;
   x = (random(13)+1);
   switch(x) {
     case 1: color = RED; break;
     case 2: color = YEL; break;
     case 3: color = GRN; break;
     case 4: color = BLU; break;
     case 5: color = CYN; break;
     case 6: color = MAG; break;
     case 7: color = HIR; break;
     case 8: color = HIY; break;
     case 9: color = HIG; break;
     case 10: color = HIB; break;
     case 11: color = HIC; break;
     case 12: color = HIM; break;
     case 13: color = HIW; break;
   }
   if(!str) 
   {
      notify_fail("Say what?\n");
      return 0; 
   }
   if(strlen(str) > 1) {
     switch(str[strlen(str)-2..strlen(str)-1]) {
        case ":)": verb = "smile"; break;
        case ":(": verb = "frown"; break;
        case ";)": verb = "wink";  break;
        case ";(": verb = "sadly wink"; break;
        case ":\\": verb = "wryly say"; break;
     }
     if(str[strlen(str)-1] == '?')
       verb = "ask";
     else if(str[strlen(str)-1] == '!')
       verb = "exclaim";
     else
       verb = "say";
   }
   else verb = "say";
   write("You " + verb + ": "+str+"\n");
   say(color+capitalize((string)this_player()->query_real_name())+" "+verb+"s"+NORM+": "+str+"\n");
   return 1; 
}

get_help()
{
  string help;
  help = "A replacement for the say command";
  return help;
}
