#include "/players/wocket/closed/ansi.h"

inherit "obj/treasure";

reset(arg){
    if(arg) return;
set_short("A fallen tear ("+GRN+"wockettell"+NORM+")");
set_long("This is a personal tell to wocket.\n"+
         "Your options are:\n"+GRN+ 
         "       tw              tell to wocket\n"+
         "       twe             emote to wocket\n"+
         "       form_tear       set short desc\n"+
      "       wipe tear       remove this object\n"+
NORM);
set_id("tear");
set_alias("wockettell");
}

get(){ return 0; }
drop(){ return 1; }
init(){
if(!restore_object("players/wocket/tellowners/"+this_player()->query_real_name())){
    save_object("players/wocket/tellowners/"+this_player()->query_real_name());
}
else
restore_object("players/wocket/tellowners/"+this_player()->query_real_name());
    add_action("form","form_tear");
    add_action("tw","tw");
    add_action("twe","twe");
    add_action("wipe","wipe");
}

tw(str){
if(find_player("wocket")){
    if(str){
    tell_object(find_player("wocket"),GRN+"(W) "+NORM+this_player()->query_name()+" tells you: "+GRN+str+"\n"+NORM);
    write(GRN+"(W) "+NORM+"You tell Wocket: "+GRN+str+"\n"+NORM);
    return 1;
    }
    notify_fail(GRN+"(W) What would you like to say?\n"+NORM);
    return 0;
    }
notify_fail("(W) Wocket is not here at the moment\n");
return 0;
}

twe(str){
if(find_player("wocket")){
    if(str){
    write(GRN+"(W) "+NORM+"You "+str+" from afar.\n");
tell_object(find_player("wocket"),GRN+"(W) "+NORM+this_player()->query_name()+" "+str+" from afar.\n");
    return 1;
    }
    notify_fail(GRN+"(W) What would you like to emote?\n"+NORM);
    return 0;
    }
notify_fail("(W) Wocket is not here at the moment.\n");
return 0;
}
form(str){
if(str){
set_short(str+" ("+GRN+"wockettell"+NORM+")");
set_long("This is a personal tell to wocket.\n"+
         "Your options are:\n"+GRN+ 
         "       tw              tell to wocket\n"+
         "       twe             emote to wocket\n"+
         "       form_tear       set short desc\n"+
      "       wipe tear       remove this object\n"+
NORM);
set_id(str);
    write("Ok.\n");
    save_object("players/wocket/tellowners/"+this_player()->query_real_name());
    return 1;
    }
return 0;
}

wipe(str){
if(str != "tear" && str != "wockettell"){
  notify_fail("What would you like to wipe away?\n");
  return 0;
}
write(GRN+"You wipe away the tear.\n"+NORM);
say(GRN+this_player()->query_name()+" wipes away a tear.\n"+NORM);
destruct(this_object());
return 1;
}
