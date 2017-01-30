/*  personal tell command  */

#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"

main(str) {
	
	object *us;
	int s;
  string who, what;
     
  if(!str || sscanf(str,"%s %s",who,what) < 2) 
  {
    notify_fail("Syntax: 'tell <player> <message>'\n");
    return 0; 
  }
  
  who = lower_case(who);
  
  us = users();
  s = sizeof(us); 
  
  while(s--) 
  {
    if(us[s] && us[s]->query_real_name() == who) 
    {
      if(us[s]->query_invis()) write(WTC+capitalize(who)+" is invisible.\n"+NORM);
      if(!us[s]->query_interactive()) write(WTC+CAP(who)+" is disconnected.\n"+NORM);
      else if(query_idle(us[s]) > 120) write(WTC+CAP(who)+" is idle.\n"+NORM);
      if(in_editor(us[s])) write(WTC+capitalize(who)+" is editing.\n"+NORM);
      if(this_player()->query_invis())
        tell_object(us[s], HIW+"("+WTC+"invis"+HIW+") "+WTC+"Forbin tells you: "+NORM+what+"\n");
      else
        tell_object(us[s], WTC+"Forbin tells you: "+NORM+what+"\n");
      us[s]->add_tellhistory(WTC+CAP(TPRN)+" told you:"+NORM+" "+what);
      us[s]->Replyer("forbin");
      write(WTC+"You speak to "+CAP(who)+": "+NORM+what+"\n");
      return 1;      
    }
  }
  notify_fail("No such player logged on.\n");
  return 0; 
}
