#include "/players/languilen/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg){
     set_id("ltell");
     set_short("An ltell device");
     set_long("This tell device will let you talk to Languilen with ease.\n\
Usage: ltell <msg> or ltell :<msg> to emote.\n\
To get rid of this device type notell.\n");
}

drop(){ return 1; }
get(){ return 1;}

init(){
     write("L-tell loaded.\n"+NORM);
     add_action("remove_ltell","notell");
     add_action("ltt","ltell");
}


int ltt(string str){
    string msg;
    object ob;

    if (!str){
       write("Usage: ltell <message>\n");
       return 1;
    }
    sscanf(str,"%s",msg);
    ob = find_player("languilen");
    if (!ob){ write("Languilen is not here right now.\n");
       return 1;
    }

    if(!ob->query_interactive()){
       write("- Languilen has disconnected -");
       return 1;
    }
    if(msg[0] == ':'){
       msg = msg[1..strlen(msg)];
       if(!msg){ return 1; }
       write(HIB+"You emote "+NORM+this_player()->query_name()+" "+msg+"\n");
       tell_object(ob,HIB+this_player()->query_name()+NORM+" "+msg+"\n");
       return 1;
    }
    write(HIB+"You tell Languilen: "+NORM+msg+"\n");
    tell_object(ob,HIB+this_player()->query_name()+NORM+" tells you: "+msg+"\n");
    return 1;
}

int remove_ltell(){
    destruct(this_object());
    write("L-tell removed.\n");
    return 1;
}
