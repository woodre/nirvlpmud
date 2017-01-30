/*  Originally created by Wocket adopted by Dreamspeakr Nirvana 1/23/98 */

    
#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

reset(arg){
    if(arg) return;
set_short(MAG+"A pleasant dream"+NORM);
set_long("This is a personal tell to dreamspeakr.\n"+
         "Your options are:\n"+MAG+ 
         "       drt                   tell to dreamspeakr\n"+
         "       dre                   emote to dreamspeakr\n"+
         "       drop dream            to remove dream\n"+
NORM);
set_id("dream");
set_alias("dreamtell");
}

get(){ return 0; }
drop(){ destruct(this_object()); return 1; }
init(){
    add_action("drt","drt");
    add_action("dre","dre");
}

drt(str){
if(find_player("dreamspeakr")){
    if(str){
    tell_object(find_player("dreamspeakr"),MAG+"(D) "+NORM+this_player()->query_name()+" tells you: "+MAG+str+"\n"+NORM);
    write(MAG+"(D) "+NORM+"You tell Dreamspeakr: "+MAG+str+"\n"+NORM);
    return 1;
    }
    notify_fail(GRN+"(D) What would you like to say?\n"+NORM);
    return 0;
    }
notify_fail("(D) Dreamspeakr is not here at the moment\n");
return 0;
}

dre(str){
 if(find_player("dreamspeakr")){
    if(str){
    write(MAG+"(D) "+NORM+"You "+str+" from afar.\n");
    tell_object(find_player("dreamspeakr"),MAG+"(D) "+NORM+this_player()->query_name()+" "+str+" from afar.\n");
    return 1;
    }
    notify_fail(MAG+"(D) What would you like to emote?\n"+NORM);
    return 0;
    }
notify_fail("(D) Dreamspeakr is not here at the moment.\n");
return 0;
}
