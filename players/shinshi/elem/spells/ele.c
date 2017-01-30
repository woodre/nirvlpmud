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
		write("What would you like to say to your fellow Elementalists?\n");
		return 1;
	}
	
	pre = "";
  	pre += MAG+" <"+NORM+"-"+MAG+"> "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+MAG+" <"+NORM+"-"+MAG+"> "+NORM;

  	if(PO->query_gwiz())
  		pre += RED+"(GUILD WIZARD) "+NORM;
  		
  	else if(PO->query_elder())
  		pre += YEL+"(ELDER) "+NORM;
  	
  	if(str[0] == ':')
  		pre += NORM;
  	else
  		pre += capitalize((string)User->query_real_name())+":   "+NORM;
  	
  	CHAND->channel_message(CHAN_NAME, str, pre);
  	return 1;
}