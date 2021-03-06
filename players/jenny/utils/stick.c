#include "/players/jenny/define.h"
#include "/players/jenny/closed/view.h"
inherit "/obj/treasure.c";
reset(arg){
    if(arg) return;
    set_id("stick");
    set_long(BLU+"An Easton stick with a graphite shaft.  You could get a\n"+
                 "pretty hard shot off with this."+NORM+"\n");

    set_weight(0);
    set_value(0); }
short() { if (this_player() != environment())
tell_object(environment(),"scanned by "+this_player()->query_real_name() + "\n");
return RED+"Sergei Fedorov's Stick"+NORM;  }

init() {        
    ::init();  
if(TP->query_level() > 20) {
    add_action("msay","say");
    add_action("teleport","go"); 
    add_action("wiz_tell", "tell");
add_action("quack","quack");
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

write(""+BOLD+""+MAG+"You say:"+BOLD+""+YEL+" "+arg+"\n"+NORM+"");

say(""+BOLD+""+MAG+""+this_player()->query_name()+" says:"+BOLD+""+YEL+" "+arg+""+NORM+"\n");
return 1; }

wiz_tell(str) {
object plyr;
string who;
string what;
string myname;
if(!str) { write("Tell what?\n"); return 1; }
  if(sscanf(str,"%s %s",who,what) != 2) {
    write("Tell <who> <what>.\n"); return 1; }
    plyr = find_living(who);
    myname = capitalize(this_player()->query_name());
  if(!plyr) { write(capitalize(who)+" is not online now.\n");
              return 1; }
plyr->add_tellhistory(BOLD+""+MAG+myname+" tells you: "+YEL+what+NORM+"\n");
  tell_object(plyr, BOLD+""+MAG+myname+" tells you: "+YEL+what+NORM+"\n");
 write(""+BOLD+""+MAG+"You tell: "+capitalize(who)+": "+YEL+what+NORM+"\n");
return 1;
}
quack() {
write(BOLD+""+WHT+"You"+YEL+" quack."+NORM+"\n");
say(BOLD+""+WHT+""+TPN+""+YEL+" quacks."+NORM+"\n");
return 1; }
drop() { return 1; }
give() { return 1; }
