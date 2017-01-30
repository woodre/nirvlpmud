#include <ansi.h>
string *colors;

reset(arg) {
  if( !colors )
    colors = ({ HIK, HIR, HIG, HIB, HIY, HIM, HIC, HIW });
}

int
cmd_half_xp() {
  object *us;
  int s;
  
  if( this_player()->query_level() < 1000 )
    return 0;
    
  s = sizeof(us = users());

  while(s--) {
    if(us[s] && (int)us[s]->query_level() < 20)
    {
      tell_object(us[s], colors[ random(sizeof(colors)) ] +"\nThe Elders of Nirvana just CURSED you with "+colors[ random(sizeof(colors)) ]+"HALF EXPERIENCE"+NORM+"!\n\n");
    }
  }
  write("Ok.\n");
  return 1;
}
