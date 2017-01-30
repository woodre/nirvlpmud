#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/closed/guild/defs.h"

cmd(string str){
string arg1,arg2;
write("You whisper something to "+ORIEKA->query_o_cap_name()+".\n");
say(this_player()->query_name()+" whispers something to "+ORIEKA->query_o_cap_name()+".\n");
sscanf(file_name(environment(this_player())),"%s/%s",arg1,arg2);
    if(arg1 == "room"){
write(ORIEKA->query_o_cap_name()+" summons a soft mist the surrounds the room.\n");
write("You fade away from this reality into another.\n\n");
say(ORIEKA->query_o_cap_name()+" summons a soft mist that surrounds the room.\n");
say(this_player()->query_name()+" fades from this reality.\n");
move_object(this_player(),"/players/wocket/closed/guild/alt_village/"+arg2);
command("glance",this_player());
say("A mist gently rolls in.\n");
say(this_player()->query_name()+" fades into this reality.\n");   
        return 1;
        }
    if(arg1 == "players"){
string a1,a2,a3,a4,a5;
      if(sscanf(arg2,"%s/%s/%s/%s/%s",a1,a2,a3,a4,a5) == 5){
      if(a1 == "wocket"){
        if(a2 == "closed"){
          if(a3 == "guild"){
            if(a4 == "alt_village"){

write(ORIEKA->query_o_cap_name()+" summons a soft mist the surrounds the room.\n");
write("You fade away from this reality into another.\n\n");
say(ORIEKA->query_o_cap_name()+" summons a soft mist that surrounds the room.\n");
say(this_player()->query_name()+" fades from this reality.\n");
move_object(this_player(),"room/"+a5);
command("glance",this_player());
say("A mist gently rolls in.\n");
say(this_player()->query_name()+" fades into this reality.\n");
return 1;
            }
          }
        }
      }
   }
    write(ORIEKA->query_o_cap_name()+" shakes its head.\n");
    say(ORIEKA->query_o_cap_name()+" shakes its head.\n");
     return 1;
    }
return 0;
}
