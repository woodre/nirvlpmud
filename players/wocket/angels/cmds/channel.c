#include "/players/wocket/closed/ansi.h"

angeltalk(string str){
object *everyone,member;
int i;
everyone = users();
if (present("ifonlybardscouldntmakeobjects",this_player())->query_silence() == 1){
  write("You must turn on your guild line before you may speak.\n");
  return 1;
}
for( i = 0; i < sizeof(everyone); i++){
    member = present("ifonlybardscouldntmakeobjects",everyone[i]);
if(member){
  if(member->query_silence() != 1){
    tell_object(everyone[i],str+NORM+"\n");
}
  }
}
}

channelsay(string str){
string arg;
arg = HIY+" _\n"+NORM+HIW+">"+HIC+"|"+HIW+"< "+HIC+this_player()->query_name()+" says: "+NORM+str;
angeltalk(arg);
}

channelemote(string str){
string arg;
arg = HIY+" _\n"+NORM+HIW+">"+HIC+"|"+HIW+"< "+HIC+this_player()->query_name()+NORM+" "+str;
angeltalk(arg);
}
