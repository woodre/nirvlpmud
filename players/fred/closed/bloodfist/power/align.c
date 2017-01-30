#include "/players/fred/closed/bloodfist/defs.h"
#define KILL_NEUTRAL_ALIGNMENT          10

status main(string str, object PO, object User)
{
  int my_align;
  string al_title;
  my_align = (int)User->query_alignment();
  if(str) return 0;
  
  if(my_align > KILL_NEUTRAL_ALIGNMENT * 64) 
	  al_title = "white lord";
  else if(my_align > KILL_NEUTRAL_ALIGNMENT * 32)
	  al_title = "paladin";
  else if(my_align > KILL_NEUTRAL_ALIGNMENT * 16)
	  al_title = "crusader";
  else if(my_align > KILL_NEUTRAL_ALIGNMENT * 8)
    al_title = "good";
  else if (my_align > KILL_NEUTRAL_ALIGNMENT * 4)
    al_title = "honorable";
  else if (my_align > - KILL_NEUTRAL_ALIGNMENT * 4)
    al_title = "neutral";
  else if (my_align > - KILL_NEUTRAL_ALIGNMENT * 8)
    al_title = "malicious";
  else if (my_align > - KILL_NEUTRAL_ALIGNMENT * 16)
    al_title = "evil";
  else if (my_align > - KILL_NEUTRAL_ALIGNMENT * 32)
    al_title = "infamous";
  else if (my_align > - KILL_NEUTRAL_ALIGNMENT * 64)
    al_title = "black knight";
  else
    al_title = "lord of evil";

  TOU "Your alignment is: "+al_title+"\n");
  return 1;
}

