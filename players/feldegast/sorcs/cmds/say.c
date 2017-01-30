#include "/players/wocket/closed/ansi.h"
cmd(str){
int a;
string first;
string verb1,verb2;
if(!str){
  write("What would you like to say?\n");
  return 1;
}
a = strlen(str);
first = str[a-1];
switch(first){
case '!': verb1 = "exclaim"; verb2 = "exclaims"; break;
case '?': verb1 = "ask"; verb2 = "asks"; break;
default: verb1 = "say"; verb2 = "says"; break;
}
write("You "+verb1+", \""+str+OFF+"\"\n");
say(this_player()->query_name()+" "+verb2+", \""+str+OFF+"\"\n");
return 1;
}
