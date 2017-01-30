#include "/obj/ansi.h"

status main(string str, object ob, object User) 
{
  object plyr;
  string who;
  string what;
  string myname;
  
  if(!str) 
  { 
    write("Use -> wt <who> <msg>\n"); 
    return 1; 
  }
  if(sscanf(str,"%s %s",who,what) != 2) 
  {
    write("Use -> wt <who> <msg>\n"); 
    return 1; 
  }
  
  plyr = find_living(who);

  myname = (string)User->query_real_name();

  if(!plyr) 
  { 
    write(capitalize(who)+" is not online now.\n");
    return 1; 
  }
  
  plyr->add_tellhistory(capitalize(myname) + " tells you: " + what);
  plyr->Replyer(myname);
  tell_object(plyr, capitalize(myname)+" tells you: "+HIR+what+NORM+"\n");
  write(HIK+"You tell "+capitalize(who)+": "+HIR+what+NORM+"\n");
  return 1;
}
