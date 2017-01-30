#include "/players/wocket/closed/ansi.h"
inherit "obj/treasure";

reset(){
    set_id("smurftell");
    set_long("This is a smurftell.  'ssay' and 'stell' to use.\n");
}

init(){
    ::init();
    add_action("ssay","ssay");
    add_action("stell","stell");
    add_action("smile","smile");
}

int smile(){
tell_room(environment(this_player()),HIB+this_player()->query_name()+" the smurf"+NORM+" smiles smurfy like.\n");
return 1;
}
int ssay(string str){
tell_room(environment(this_player()),HIB+this_player()->query_name()+" the smurf "+NORM+"says: "+str+"\n");
return 1;
}

int stell(string str){
string who,tell;
object ob;
if(sscanf(str,"%s %s",who,tell)==2){
ob = find_player(who);
if(!ob){
write("Player not found.\n");
return 1;
}
tell_object(ob,HIB+this_player()->query_name()+" the smurf "+NORM+"tells you: "+tell+"\n");
write(HIB+"You tell "+ob->query_name()+": "+NORM+tell+"\n");
return 1;
}
write("Usage: stell <who> <what>\n");
return 1;
}
