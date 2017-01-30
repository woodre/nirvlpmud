int glvl;
int change;
int fury;
int furytimer;
int meldlvl;
int meld;
int meldtimer;
int stunned;

#include "/players/stark/defs.h"
#include "/players/stark/wolf/lib/hb.h"
#include "/players/stark/wolf/lib/pray.h"


short() { return "Werewolf GOB"; }
extra_look(){ return "This person is a werewolf"; }
long(){ return write("werewolf gob.\n"); }
id(string str) { return str == "were_guild_object"; }
drop() { return 1; }
get() { return 1; }

reset(arg){
    set_heart_beat(1);
    if(arg) return;
}


init(){
restore_object("/players/stark/wolf/players/"+TPRN);

add_action("pray","pray");
add_action("save_guild","weresave");
}


save_guild(){
        save_object("players/stark/wolf/players/"+TP->query_real_name());
        write("Saving object\n");
        return 1;
}

query_auto_load(){
        save_object("players/stark/wolf/players/"+TP->query_real_name());
        return "/players/stark/wolf/gob:";
}





  
