#include "/players/wocket/closed/ansi.h"

asay(string str){
if(!str){
    write("What would you like to say?\n");
return 1;
}
    write("You resonate, "+HIC+"\""+NORM+str+HIC+"\"\n"+NORM);
    say(this_player()->query_name()+" resonates, "+HIC+"\""+NORM+str+HIC+"\"\n"+NORM);
return 1;
}


hymn(string str){
object ob,member;
ob = first_inventory(environment(this_player()));
while(ob){
member = present("ifonlybardscouldntmakeobjects",ob);
if(member){
tell_object(ob,this_player()->query_name()+" softly hymns, \""+str+"\" to "+this_player()->query_possessive()+" fellow angels.\n");
}
else {
tell_object(ob,this_player()->query_name()+" softly sings a hymn.\n");
}
ob = next_inventory(ob);
}
return 1;
}


immitate(string str){
string who,what;
if (!str){
    write("Who would you like to immitate?\n");
    return 1;
}
sscanf(str,"%s %s",who,what);
if(!what){
    write("Usage: immitate <person> <what>\n");
    return 1;
}
say("."+capitalize(who)+" says: "+what+"\n");
write("You immitate "+capitalize(who)+" saying: "+what+"\n");
    return 1;
}
