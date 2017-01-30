#include <ansi.h>

string *ppl;

void reset(int arg)
{
	if(arg) return;
	
	ppl=({
/*
		"krillgeta",
		"glaxgor",
		"gogeta",
                "sipote",
                "psyco",
		"fury",
                "shadowman",
*/


                "hula",
		"laramie",
                "farrangul",
                "whitehawk",
                "whitefox", "fox",
                "harmen",
                "wulfpaws",

                "mythical",
  });
	
	call_out("remind", 300 + random(300));
}

void remind()
{
	object *us;
	int    s;
	string msg;
	string *cols;
	
	cols=({HIB,HIR,HIG,HIY,HIW,HIM,HIC});
	
	s = sizeof(us=users());
	
	switch(random(5))
	{
		case 0: msg = "\n\
	This is an automatic warning from Nirvana to stay away\n\
	from Elysium Mud as the administration is aware you play\n\
	there.\n\n";
		break;
    case 1: msg = "\n\
  Nirvana wishes to remind you that playing on Elysium\n\
  is entirely fruitless and seeks only to demoralize the\n\
  staff and community of Nirvana who have sacrifice their\n\
  time to bring you this mud.\n\n";
  	break;
    case 2: msg = "\n\
  Nirvana LPMud is a *free* game that has been in existence\n\
  for years. By supporting Elysium, you are spitting on the\n\
  work of countless developers.\n\n";
  	break;
  	case 3: msg = "\n\
  No one likes to have their code stolen. If you didn't know,\n\
  Elysium is responsible for hijacking and stealing a great\n\
  amount of work from this MUD .. and in doing so they have\n\
  wrongly and falsely alienated a great amount of the player\n\
  and development pool. Supporting their bullshit is an insult\n\
  to the hard work and determination that have made this mud\n\
  survive for over 14 years.\n\n";
    break;
    case 4: msg = "\n\
  You are receiving this warning as you continue to play Elysium\n\
  despite the warnings and reminders from the administration.\n\
  Continuing to play there, on a stolen mud, may result in your\n\
  removal from the game here.\n\n";
    break;
  }
  
  msg = cols[random(sizeof(cols))]+msg+NORM;
  
  while(s--)
  {
  	if(us[s] && 
  		member_array((string)us[s]->query_real_name(),ppl) > -1)
  	{
  		tell_object(us[s], msg);
    }
  }
  
  call_out("remind", 300 + random(300));
}
