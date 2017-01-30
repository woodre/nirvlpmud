#include <ansi.h>
string *colors;

reset(arg) {
  if( !colors )
    colors = ({ HIK, HIR, HIG, HIB, HIY, HIM, HIC, HIW });
}

int
cmd_double_xp() {
  object *us;
  int s;
  
  if( this_player()->query_level() < 1000 )
    return 0;
    
  s = sizeof(us = users());

  while(s--) {
    if(us[s] && (int)us[s]->query_level() < 20)
    {
      if(!present("double_xp_object", us[s]))
      {
        move_object(clone_object("/obj/secure/double_obj.c"), us[s]);
        tell_object(us[s], colors[ random(sizeof(colors)) ] +"\nThe Elders of Nirvana just granted you "+colors[ random(sizeof(colors)) ]+"DOUBLE EXPERIENCE"+NORM+"!\n\n");
      }
    }
  }
  write("Ok.\n");
  return 1;
}
