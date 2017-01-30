#include "/players/wocket/closed/ansi.h"
int setrank(string str){
object ob;
string who;
int newrank;
if (!str){
  notify_fail("Usage: setrank <who> <rank>\n");
return 0;
}
sscanf(str,"%s %d",who,newrank);
if(!newrank){
  notify_fail("Usage: setrank <who> <rank>\n");
  return 0;
}
ob = find_player(who);
if (!ob){
  notify_fail("Player not found.\n");
  return 0;
}
if(!present("ifonlybardscouldntmakeobjects",ob)){
  notify_fail(ob->query_name()+" is not an angel.\n");
return 0;
}
tell_object(ob,HIC+"Your angel rank has been set to "+newrank+".\n"+NORM);
write("You have set "+ob->query_name()+"'s rank to "+newrank+".\n");
present("ifonlybardscouldntmakeobjects",ob)->set_rank(newrank);
command("saveme",ob);
return 1;
}
