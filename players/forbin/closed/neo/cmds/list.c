#include "../defs.h"

status main(string str, object gob, object player)
{
	string *m;
	string a;
	int b;

  if((int)player->query_ghost()) return 0;

	if(!str)
	{
		tell_object(player,
		  "Correct syntax is: "+SGC+"'"+PGC+"list tentacles"+SGC+"'"+NORM+"\n");
		return 1;
	}
	
  if(str == "tentacles" || str == "tents")
  {
    tell_object(player,
      "\n"+PGC+"Tentacle Assignments"+NORM+"\n");
    for(b = 0; b < 10; b++)
    {
    	a = b+1;
      tell_object(player," "+
        SGC+colour_pad(""+a,-2)+PGC+" ["+NORM+
        colour_pad(colour_pad(""+CAP((string)gob->query_tents(b,b+1))+"", -((12+strlen((string)gob->query_tents(b,b+1))) / 2)), 12)+PGC+"]\n"+NORM); 
    }
  return 1;
  }      
}
