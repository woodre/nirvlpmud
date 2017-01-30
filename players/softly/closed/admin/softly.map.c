#include "/players/softly/closed/ansi.h"

reset(arg)  
{
  if(arg) return;
}

init() 
{ 
  add_action("wmap", "wmap"); 
}

wmap() 
{ 
  write_file("/players/softly/softly.map",
	     ("\n\n"+
	      "\t   "+HIG+"~"+NORM+BOLD+"*"+HIG+"~ "+HIM+"Softly's World "+HIG+"~"+NORM+BOLD+"*"+HIG+"~\n"+NORM+
"\t       (Not to scale)\n\n"+
"    "+BLK+BOLD+"N"+NORM+"                          "+RED+"R"+NORM+"ocky "+RED+"P"+NORM+"oint\n"+
"    |              "+BOLD+"Cottage"+NORM+"     Light"+HIY+"house\n"+NORM+ 
" "+BLK+BOLD+" W"+NORM+"-o-"+BLK+BOLD+"E"+NORM+"  "+BOLD+"Frozen"+NORM+"       |          /\n"+
"    |     "+BOLD+"Pond"+NORM+"     "+GRN+"Forest"+NORM+"       /\n"+
"    "+BLK+BOLD+"S"+NORM+"                /          - - Jetty\n"+
"            Shack -           /\n"+
"                  |          /\n"+
"Signpost - "+GRN+"Forest"+NORM+" + "+GRN+"Forest"+NORM+" -  - Beach\n"+
"                  |               \\\n"+
"                Road             Beach\n"+
"                 /\n"+
"            - - +  "+RED+"Red\n"+NORM+
"            |   | House\n"+
"         Church |\n"+
"                |\n"+    
"       Clothing + - -\n"+                     
"                |   Porch\n"+
"                |\n"+
"          "+GRN+"Herbs"+NORM+" + Variety\n"+
"                |\n"+ 
"       School - + Brothel Mill\n"+
"                |         /\n"+
"       "+YEL+"Detective"+NORM+"   -   -\n\n"));
	     return 1;
	     }
  
  
