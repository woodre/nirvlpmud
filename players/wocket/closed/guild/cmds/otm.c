#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/closed/guild/defs.h"

cmd(string str){
    if(!str){
     return 0;
    }
write("You whisper something to your orieka.\n");
say(this_player()->query_name()+" whispers something to "+ORIEKA->query_o_cap_name()+".\n");
GUILD_D->create_say(str);
return 1;
}
