/* All the communication commands.
*/
#include "/players/zeus/closed/all.h"
#define YA tell_object(environment()

toggle_cmd(str){
 if(str != "invis") return 0;
        if(!vis){
                vis = 1;
YA,HIW+"[]  Vis mode "+NORM+BOLD+"on"+NORM+HIW+"  - Zeus\n"+NORM);
                return 1;       }
        else if(vis){
                vis = 0;
YA,HIW+"[]  Vis mode "+NORM+BOLD+"off"+NORM+HIW+"- Someone\n"+NORM);
                return 1;       }
        return 1;}

tell_cmd(str) {
    if(!str) return 0;
    if(!sscanf(str, "%s %s", swho, swhat)) return 0;
    who = find_player(swho);
    if(!who) return 0;
        if(vis) name = (string)TP->QRN;
        else name = "someone";
   move_object(this_object(), environment());
    tell_object(who,
      capitalize(name)+" tells you: "+swhat+"\n\n");
    YA,HIW+"Okay\n"+NORM);
    if(who->query_real_name() != "caelin")
    who->add_tellhistory(capitalize(name)+" tells you: "+swhat+"\n");
    return 1; }

telle_cmd(str) {
    if(!str) return 0;
    if(!sscanf(str, "%s %s", swho, swhat)) return 0;
    who = find_player(swho);
    if(!who) return 0;
        if(vis) name = (string)TP->QRN;
        else name = "someone";
    tell_object(who, "[afar] "+capitalize(name)+" "+swhat+"\n");
    YA,HIW+"Okay\n"+NORM);
    return 1; }

say_cmd(str){
  object temp, temp2;
  if((temp = find_player("caelin")))
  {
    if((temp2 = present("zpill", temp)))
    {
      if(environment(temp) == environment(this_player()))
      {
        temp2->pill_room(str);
        return 1;
      }
    }
  }
  if(!str) return 0;
  if(vis) name = (string)TP->QRN;
  else name = "someone";
  TR(environment(TP), capitalize(name)+" says: "+str+"\n");
  return 1; 
}

emote_cmd(str){
    if(!str) return 0;
        if(vis) name = (string)TP->QRN;
        else name = "someone";
    TR(environment(TP), capitalize(name)+" "+str+"\n");
    return 1; }

filer(str) {
  if(!str) return 0;
  write_file("/players/zeus/WORK_REPORT",ctime(time())+" "+str+"\n");
  write_file(
    "/log/WR/zeus_workreport",ctime(time())+" "+str+"\n");
YA,BOLD+"[]  "+NORM+HIW+"Report done.\n"+NORM);
return 1;}

tm(str){
  object a;
  if(!str) return 0;
  if(!(a = find_player("maledicta"))) return 0;
  tell_object(a, "Zeus tells you: "+str+"\n");
  a->add_tellhistory("Zeus tells you: "+str+"\n");
  write("You tm: "+str+"\n");
  return 1;
}

tv(str){
  object a;
  if(!str) return 0;
  if(!(a = find_player("vertebraker"))) return 0;
  tell_object(a, "Zeus tells you: "+str+"\n");
  a->add_tellhistory("Zeus tells you: "+str);
  write("You tv: "+str+"\n");
  return 1;
}
 
mtell(str) {
   if(!str) return 0;
   if(!sscanf(str, "%s %s", swho, swhat)) return 0;
   who = find_player(swho);
   if(!who) return 0;
   if(vis) name = (string)TP->QRN;
   else name = "someone";
   move_object(this_object(), environment());
   tell_object(who, "Mythos quietly tells you : "+swhat+"\n\n");
   YA,HIW+"Okay\n"+NORM);
   return 1;
}
