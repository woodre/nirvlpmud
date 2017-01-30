#include <ansi.h>
#include <security.h>

void reset(int arg)
{
	if(arg) return;

	call_out("remind", 1800 + random(2400));
}

void remind()
{
	object *us;
	int    s;
	string msg;
	string *cols;
	
	cols=({HIB,HIR,HIG,HIY,HIW,HIM,HIC});
	
	s = sizeof(us=users());
#define rc cols[random(sizeof(cols))]
	msg = "                "+rc+"Don't forget to vote!\n"+NORM+
       "\n"+
	      "                Vote "+rc+"every 12 hours"+NORM+" at:\n"+
	      rc+"http://www.topmudsites.com/cgi-bin/topmuds/rankem.cgi?id=nirvana\n\n"+NORM+
	      "                Vote "+rc+"every 24 hours"+NORM+" at:\n"+
	      rc+"http://www.mudconnector.com/mud-bin/vote_rank.cgi?mud=Nirvana\n"+NORM+
	      "\t\t["+rc+"VOTE VOTE VOTE!"+NORM+"]\n"+
	      "Thanks!\n";
	      
  msg="\n"+msg+"\n";
  while(s--)
  {
  	if(us[s] && environment(us[s]) && !in_editor(us[s]) &&
  	   (int)us[s]->query_level() < 5000)
  	{
  		tell_object(us[s], msg);
  	}
  }
  
  call_out("remind", 1800 + random(2400));
}
