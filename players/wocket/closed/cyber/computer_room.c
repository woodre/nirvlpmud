#include "/players/wocket/closed/ansi.h"
inherit "room/room";

reset(arg){
    set_light(1);
    short_desc = "CyberNinja Terminal Room";
    long_desc = "not done yet...\n";
}
init(){
  add_action("register","register");
}

int register(){
write("Services available:\n\n");
write("reboot computer...........reboots the cybernet\n");
write("tend computer.............prevents computer from crashing\n");
write("diags.....................shows current data of computer\n");
return 1;
}
