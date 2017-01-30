/*  Approved by wizardchild and sandman */
#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure";

reset(arg){
    set_id("squeaktalk");
}

init(){
    add_action("ssay","say");
    add_action("ssay","'");
call_out("normal",20+random(100));
}

int ssay(string str){
if (!str){
return 0;
}

say(this_player()->query_name()+" says in a high pitched voice: "+BOLD+str+NORM+"\n");
write("You say in a high pitched voice: "+BOLD+str+NORM+"\n");
return 1;
}

normal(){
remove_call_out("normal");
write("You have run out of helium.\n");
destruct(this_object());
}
