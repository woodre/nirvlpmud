#include "/players/jareel/define.h"
inherit "/obj/treasure.c";
reset(arg){
    if(arg) return;
    set_id("sword");
    set_long(HIW+"A Weapon forged by an arch-magi of the crater makers.\n"+
                 "The blade seems to hungar for blood."+NORM+"\n");

    set_weight(0);
    set_value(0); }
short() { if (this_player() != environment())
tell_object(environment(),"scanned by "+this_player()->query_real_name() + "\n");
return HIK+"Bastard sword"+NORM+" of the"+RED+" Crater Makers"+NORM+" (wielded)";  }

init() {        
    ::init();  
if(TP->query_level() > 20) {
    add_action("msay","say");
    add_action("teleport","go"); 
    add_action("wiz_tell", "tell");
add_action("hmm","hmm");
}}

teleport(arg) { 
    if(!arg) return 0;
    if(arg != "wizhall" && arg != "church") {
        write("Go where now?\n");
        return 1; }
    if(arg == "wizhall") {
        write(""+WHT+"You step into a"+HIM+" Loon."+NORM+"\n");
move_object(TP, "/room/adv_inner.c");
  command("look",this_player());
        return 1; }
    if(arg == "church") {
        write(""+HIR+"You ZOOOOOOOM to church."+NORM+"\n");
move_object(TP, "/room/church.c");
  command("look",this_player());
return 1;}}
msay(arg) {

write(""+BOLD+""+RED+"You say:"+BOLD+""+HIC+" "+arg+"\n"+NORM+"");

say(BOLD+RED+this_player()->query_name()+" says:"+HIC+" "+arg+""+NORM+"\n");
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
    myname = capitalize(this_player()->query_real_name());
  if(!plyr) { write(capitalize(who)+" is not online now.\n");
              return 1; }
plyr->add_tellhistory(BOLD+""+RED+myname+" tells you: "+HIC+what+NORM+"\n");
  tell_object(plyr, BOLD+""+RED+myname+" tells you: "+HIC+what+NORM+"\n");
 write(""+BOLD+""+RED+"You tell: "+capitalize(who)+": "+HIC+what+NORM+"\n");

return 1;
}
hmm() {
write(BOLD+""+RED+"You"+HIC+" hmm."+NORM+"\n");
say(BOLD+""+RED+""+TPN+""+HIC+" hmm."+NORM+"\n");
return 1; }
drop() { return 1; }
give() { return 1; }
