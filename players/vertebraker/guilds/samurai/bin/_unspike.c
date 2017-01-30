#include "../def.h"

cmd_unspike(str)
{
  object ob;
  object gob;
  int   y;
  
  if(TP->query_guild_rank() < 1) return 0;
  ob = present("headspike", TP);
  
  if(!str || !sscanf(str, "%d", y)){
    write("Usage: 'unspike <# of heads>'\n");
    return 1;
  }
  
  gob = previous_object();
  if( !gob )
    return 0;

  if(!ob){
    write("You don't have a headspike.\n");
    return 1;
  }
  else
  {
    string sh;
    int    amt;
    object head;
    sh = ob->short();
    sscanf(sh, "%s[%d]", sh, amt);
    
    if(y > amt)
    {
      write("You only have "+amt+" heads on the spike.\n");
      return 1;
    }
    
    write("You pull "+y+" heads from the massive spike.\n");
    say(TP->QN+" pulls "+y+" heads from the massive spike.\n");

    amt -= y;

    if( ob->query_value() < 1 )
      gob->add_head_count( -y );
        
    while(y --)
    {
      head = clone_object("/obj/treasure");
      head->SetMultipleIds( ({ "decapitated head", "samurai_head", }) );
      head->set_alias("head");
      head->set_short("A decapitated head");
      head->set_long("\
A decapitated head. You can't tell exactly whose head it\n\
belongs to, it is too decayed.\n");
      head->set_value(1);
      move_object(head, TP);
    }

    ob->set_short("a spike of many heads ["+amt+"]");
    ob->set_long("\
A long spike containing "+amt+" heads.\n");
  }
  return 1;
}
