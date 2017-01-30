#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	string pre;
	
	if(!CHAND){
		write("The guild line is currently down.\n");
		return 1;
	}
	
	if(!str){
		write("You must say something!\n");
		return 1;
	}
	
	pre = "";
  	pre += BLU+"("+RED+"[ "+NORM;
  	
  	if(str[0] == ':')
  		pre += NORM;
  	else
  		pre += capitalize((string)User->query_real_name())+" intones:   "+NORM;
  	
  	CHAND->channel_message(CHAN_NAME, str, pre);
  	return 1;
}