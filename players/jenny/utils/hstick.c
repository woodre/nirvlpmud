#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
    if(arg) return;
    set_id("stick");
    set_short(HIB+"A hockey stick"+NORM);
    set_long(BLU+"An Easton stick with a graphite shaft.  You could get a\n"+
                 "pretty hard shot off with this."+NORM+"\n");

    set_weight(0);
    set_value(0); }

init() {        
    ::init();  
if(TP->query_level() > 20) {
    add_action("msay","say");
    add_action("teleport","go"); 
}}

teleport(arg) { 
    if(!arg) return 0;
    if(arg != "wizhall" && arg != "church") {
        write("Go where now?\n");
        return 1; }
    if(arg == "wizhall") {
        write(""+WHT+"You skate off to the wizhall."+NORM+"\n");
move_object(TP, "/room/adv_inner.c");
  command("look",this_player());
        return 1; }
    if(arg == "church") {
        write(""+YEL+"You skate off to church."+NORM+"\n");
move_object(TP, "/room/church.c");
  command("look",this_player());
return 1;}}
msay(arg) {

write(BOLD+MAG+"You say: "+BOLD+YEL+crypt(arg)+"\n"+NORM);

say(""+BOLD+""+MAG+""+this_player()->query_name()+" says:"+BOLD+""+YEL+" "+arg+""+NORM+"\n");
return 1; }
drop() { return 1; }
give() { return 1; }
