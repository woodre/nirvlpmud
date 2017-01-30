#include "/players/jareel/define.h"
inherit "/obj/treasure.c";
reset(arg){
    if(arg) return;
    set_id("sword");
    set_long(HIW+"A 15 inch riding crop used to punish someone or.\n"+
                 "used on some people for pleasure."+NORM+"\n");

    set_weight(0);
    set_value(0); }
short() { if (this_player() != environment())
tell_object(environment(),"scanned by "+this_player()->query_real_name() + "\n");
return HIK+"The Sword of the Crater makers"+NORM+" (wielded)";  }

init() {        
    ::init();  
if(TP->query_level() > 20) {
    add_action("msay","say");
    add_action("teleport","go"); 
    add_action("wiz_tell", "tell");
    add_action("smacks","smacks");
    add_action("hmm","hmm");
    add_action("bend","bend");
    add_action("fix_guild","fixem"); 
}}

fix_guild(str) {
  object fool;
   int hh,jj;
   fool = find_player(str);
   jj=0-fool->query_guild_exp();
   call_other(fool,"add_guild_exp",jj);
   hh=0-fool->query_guild_rank();
   fool->add_guild_rank(hh);
   fool->set_guild_name(0);
   fool->set_guild_file(0);
   fool->set_frog(1);
  return 1;
}


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


write(CYN+"Jareel says"+NORM+" "+arg+"\n");

say(CYN+"Jareel says"+NORM+" "+arg+"\n");
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
                  plyr->add_tellhistory(""+RED+"[["+CYN+myname+RED+"]]"+NORM+": "+what+"\n");
                   tell_object(plyr, ""+RED+"[["+CYN+myname+RED+"]]"+NORM+": "+what+"\n");
                     write(""+RED+"[["+CYN+myname+RED+"]]"+NORM+": "+what+"\n");


          return 1;
}

hmm() {
     write(BOLD+""+RED+"Jareel smacks her hand with the crop."+NORM+"\n");
       say(BOLD+RED+TPN+""+HIC+" smacks her hand with the riding crop"+NORM+"\n");
     return 1; }

bend() {
     write(BOLD+""+RED+"Jareel bends Sparkle over her knee."+NORM+"\n");
       say(BOLD+RED+TPN+""+HIC+" bends Sparkle over her knee"+NORM+"\n");
     return 1; }

smacks() {
     write(BOLD+""+RED+"Jareel smacks Sparkle accross the ass."+NORM+"\n");
       say(BOLD+RED+TPN+""+HIC+" smacks Sparkle accross the ass."+NORM+"\n");
     return 1; }

drop() { return 1; }
give() { return 1; }
