#include <security.h>
#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"

#define II WTC+"++"+NORM
#define V WTC+"+++++"+NORM
#define III HIW+"+++"+NORM
#define VII HIW+"+++++++"+NORM
#define LONGLINE V+III+II+VII+II+III+V+V+III+V+III+V+III+V+V+III+II+VII+II+III+V

status main() {
  object *everyone, *wizards, who;
  int s, hour, min, sec;
  string idle_string;

  s = sizeof(everyone = users());
  wizards = ({ });

  while(s --)
    if((int)(who = everyone[s])->query_level() > 19 && interactive(who) && environment(who))
    wizards += ({ who });

  s = sizeof(wizards);
  write("\n"+LONGLINE+"\n\n");
  while(s --) {
    who = wizards[s];
    sec = query_idle(who);
    idle_string = "";
    if(min = (sec / 60)) sec -= (min * 60);
    if(hour = (min / 60)) min -= (hour * 60);
    if(hour) idle_string += (""+hour+"h");
    if(min) idle_string += (""+min+"m");
    if(sec) idle_string += (""+sec+"s");
    write(colour_pad("", 2, ' '));
    if(in_editor(who)) write(colour_pad(HIR+"*"+NORM, 1));
    else write(colour_pad("", 1, ' '));
    if(who->query_level() <= 40) write(colour_pad(capitalize((string)who->query_real_name()), 15));
    else if(who->query_level() < 100) write(colour_pad(WTC2+capitalize((string)who->query_real_name())+NORM, 15));
    else write(colour_pad(WTC+capitalize((string)who->query_real_name())+NORM, 15));
    write(colour_pad("", 2, ' '));
    write(colour_pad(idle_string, -9));
    write(colour_pad("", 2, ' '));
    write((string)who->get_path());
    write("\n");    
  }
  write("\n"+LONGLINE+"\n"); 
  return 1;
}
