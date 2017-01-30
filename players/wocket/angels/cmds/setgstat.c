#define save_path "players/wocket/angels/members/"
#include "/players/wocket/closed/ansi.h"

int setgstat(string str){
string who;
object ob;
int newgstat;

if(!str){
write("Usage: setgstat <who> <stat>\n");
return 1;
}
sscanf(str,"%s %d",who,newgstat);
if(!newgstat){
  write("Usage: setgstat <who> <stat>\n");
return 1;
}
ob = find_player(who);
if(!ob){
  write("Player not found.\n");
  return 1;
}
if (!present("ifonlybardscouldntmakeobjects",ob)){
  write(ob->query_name()+" is not an angel.\n");
return 1;
}
tell_object(ob,HIC+"Your angels guild stat has been set to "+newgstat+".\n"+NORM);
write("You have set "+ob->query_name()+"'s guild stat to "+newgstat+".\n");
present("ifonlybardscouldntmakeobjects",ob)->set_gstat(newgstat);
command("saveme",ob);
return 1;
}
