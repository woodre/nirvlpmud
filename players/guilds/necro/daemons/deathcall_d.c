#include "../DEFS"

#define DEATH "/log/DEATHS"

string lastdead;

void newdeathcheck(){
    string temp, *temp_array;   /* 12/02/2006 - Rumplemintz */
    string YEAR;
    string jnk1,playername,playkill;
    int playexp,playgold,lastnumb;
    temp = read_file(DEATH);
    if(temp)
	temp_array = explode(temp, "\n");
    else
	/* Heh. -Feld
	  tell_object(find_player("wocket"),"no temp\n");
	*/
	return;
    lastnumb = sizeof(temp_array)-1;
    sscanf(ctime(time()),"%s200%s",jnk1,YEAR);
    if(lastdead != temp_array[lastnumb]){
	if(sscanf(temp_array[lastnumb],"%s 200"+YEAR+
	    " %s %d exp %s gold killed by %s.",jnk1,playername,playexp,playgold,playkill) == 5){
	    CHAT_D->tell_guild("<"+HIR+"RoD"+OFF+"> "+capitalize(playername)+
	      " has now crossed over into the realm of the dead.\n",1);
	}
	lastdead = temp_array[lastnumb];
    }
}

string query_lastdead(){ return lastdead; }
