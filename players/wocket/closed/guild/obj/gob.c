#include "/players/wocket/closed/ansi.h"

string name;
int suenik;


id(str){ return str == "oriekagob"; }

init(){
    add_action("call_orieka","summon");
    add_action("guild_save","remember");
    add_action("guild_say","say");

restore_object("players/wocket/closed/guild/masters/"+this_player()->query_real_name());
}

short(){ return "A binding to "+capitalize(name); }

call_orieka(){
object ob;
ob = clone_object("/players/wocket/closed/guild/orieka2.c");
ob -> set_master(this_player()->query_real_name());
ob -> set_name(name);
ob -> restore_me();
move_object(ob,environment(this_player()));
say(this_player()->query_name()+" says:  "+BOLD+"SEUNIK"+NORM+"\n");
write("You say:  "+BOLD+"SEUNIK"+NORM+"\n");
return 1;
}

guild_say(str){
string first,last;
string query,cmd;
sscanf(str,"%s %s",first,last);
if(!last){ first = str; last = ""; }
query = "query_"+first;
if(call_other(this_object(),query)==1){
write("You say: "+BOLD+capitalize(first)+NORM+" "+last+"\n");
return 1;
}
return 0;

}

guild_save(){
save_object("players/wocket/closed/guild/masters/"+this_player()->query_real_name());
write(BOLD+"Guild status saved.\n"+NORM);
return 1;
}


set_o_name(str){ name = str; }

query_suenik(){ return 1; }
query_o_name(){ return name; }
