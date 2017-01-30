#include "/players/boltar/things/esc.h"

#include "/obj/clean.c"

short()
{
     return "An emoter";
}

query_value()
{
        return 200;
}

  query_weight() {   return 1; }
long()
{
   write("An emoter. Just type 'z message' and everybody in the room will see\n"+
   "your name followed by the message\n");
}

init() {
     add_action("z", "z");
}

id(str) {
    return str == "emoter" || str == "An emoter";
}

z(str) {
string nurf;
nurf = esc+"[0m"+esc+"[4m"+esc+"[35m"+esc+"[40m";
say(call_other(this_player(),"query_name",0)+
" "+nurf+str+esc+"[0m\n");
/*
" -->" + str+"\n");
*/

write("you emote: " + call_other(this_player(), "query_name") + " " + str + "\n");
    return 1;
}

get() {
      write("The emoter feels magical.\n");
    return 1;
}


