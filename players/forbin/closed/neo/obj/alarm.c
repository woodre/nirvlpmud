inherit "obj/treasure";

#include "../defs.h"

object Owner;

reset()
{
  set_id("invis_neo_alarm");
  set_weight(50000000);
  set_value(0);
  enable_commands(); 
  call_out("destroy_alarm", 1800);
  call_out("alarm_ready", 4);  
}

catch_tell(string str) 
{
  string str1, str2;
  object target;
  if(!Owner || find_living((string)Owner->QRN))
  {
    remove_call_out("destroy_alarm"); 
    destruct(this_object());
  }
  if(sscanf(str, "%s %s.", str1, str2) != 2) return;
  if (lower_case(str2) == "arrives") 
  {
    target = find_living(lower_case(str1));
    
    if(target == Owner) 
      return;
    
    if(target && 
       find_living((string)Owner->QRN)) 
    {
      tell_object(Owner,"\n\t"+ 
        present("neoobj", Owner)->query_pgcol()+"(("+HIW+"o"+
        present("neoobj", Owner)->query_pgcol()+")) "+NORM+
        "Your alarm at "+(string)environment()->short()+
        " goes off.\n\t"+
        present("neoobj", Owner)->query_pgcol()+"(("+HIW+"o"+
        present("neoobj", Owner)>query_pgcol()+")) "+NORM+
        present("neoobj", Owner)->query_sgcol()+(string)target->QN+NORM+
        " has entered the area.\n\n");  
      call_out("destroy_alarm",1);
      return 1;
    }
  }
  return 1;
}

alarm_ready()
{
  if(!Owner || !find_living((string)Owner->QRN) || !root())
  {
    remove_call_out("destroy_alarm");
    call_out("destroy_alarm",1);
    return 1;
  }
  tell_object(Owner,
    present("neoobj", Owner)->query_pgcol()+
    "Your symbiotic alarm burrows into the ground and is active.\n"+NORM);
  return 1;
}
 
destroy_alarm() 
{ 
  if(find_living((string)Owner->QRN))
  {
    tell_object(Owner,
      "Your alarm at "+(string)environment()->short()+" dies.\n");
    present("neoobj", Owner)->sub_alarm(1);  
  }
  destruct(this_object()); 
}

void set_owner(object x) { Owner = x; }
object query_owner() { return Owner; }

get() { return 0; }

