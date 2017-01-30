#include "/players/pain/color.h"

id(str) {
    return str == "ring";
}

reset(arg) {
  if(arg) return;
}


long() {
    write("A "+BOLD+BLUE+"Sapphire"+END+" and "+BOLD+"Platinum"+END+" ring.\n");
    write("Created by Pain for "+BOLD+BLUE+capitalize(environment(this_object())->query_real_name())+END+".\n");
    write("Usage: pring <msg> and pring :<emote>\n");
}

short() {
     return "A "+BOLD+BLUE+"Sapphire"+END+" and "+BOLD+"Platinum"+END+" ring (worn)";
}
drop() {return 1;}

query_auto_load() {
    return "/players/pain/closed/items/ring.c:";
}

init() {
  add_action("pring","pring");
}

pring (str) {
string what, who;
  if(!str) {
     write("You need a message to send to Pain\n");
     return 1;
  }
  if(!sscanf(str, "%s",what)) {
    write("Usage: pring <msg> and pring :<emote>\n");
    return 1;
  }
  if(!find_player("pain")) {
    write("Pain is not here....\n");
    return 1;
  }
  if(what[0] == ':') {
    tell_object(find_player("pain"),LIGHT_BLUE+"<*>"+"  "+
                END+capitalize(this_player()->query_real_name())+LIGHT_BLUE+" "+what[1..strlen(what)]+END+"\n");
    write("You send a message to Pain: "+capitalize(this_player()->query_real_name())+" "
          +what[1..strlen(what)]+"\n");
  } else {
    tell_object(find_player("pain"),LIGHT_BLUE+"<*>"+"  "+
                END+capitalize(this_player()->query_real_name())+END+" tells you: "+LIGHT_BLUE+what+END+"\n");
    write("You tell Pain : "+LIGHT_BLUE+what+END+"\n");
  }
  return 1;
}

