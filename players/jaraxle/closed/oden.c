
/* Specifically made for Oden b/c he had four horrendous bugs happen
    to him while using this.  He also died a few times.   */

inherit "/obj/armor.c";
#include "/players/jaraxle/define.h"
int invis_flag;
int invis_flag, saveflag;
void reset(int arg) {
   if(arg) return;
   ::reset();
   set_name("misty cloak");
   set_alias("cloak");
   set_long(
      "A strange swirling mass of mist and form.  The shadows of mist shape\n"+
      "into a claok which feels cool to the touch.  A mist of water feigns from\n"+
      "about the mist, refreshing your body and mind.\n");
   set_ac(2);
   set_type("misc");
   set_weight(1);
   set_value(0);
}
short(){ return ""+HIW+"Misty Cloak"+NORM+(worn?" ("+NORM+RED+"~"+BLK+BOLD+"h"+NORM+RED+"e"+BLK+BOLD+"X"+NORM+RED+"e"+BLK+BOLD+"d"+NORM+RED+"~"+NORM+")":""); }
query_save_flag(){ return 0; }
init(){
   ::init();
   add_action("invis_me","wear");
   add_action("vis_me","remove");
   add_action("cmd_tell","tell");
}

invis_me(arg){
   object *inv;
   int x,s;
   inv=all_inventory(TP);
   s=sizeof(inv);
   for(x=0;x<s;x++) {
      if((string)inv[x]->query_type() == "misc" && inv[x]->query_worn()) {
         write("You already have an armor of class misc.\n");
         return 1;
       }
   }
if(TP->query_real_name() != "oden"){
   write("You are not the owner!\n");
write_file("/players/jaraxle/closed/oden.log",HIM+ctime(time())+" "+HIB+this_player()->query_name()+" "+HIG+this_player()->query_level()+NORM+"+"+HIY+this_player()->query_extra_level()+NORM+" tried to wear the cloak.\n");
destruct(this_object());
return 1; }
      if(arg == "cloak" || arg == "misty cloak"){
         object z;
         
         if(present("misty_cloak", (z = this_player())))
            return;
         z->set_invs_sp();
         write("You wrap the cloak around your body.\n\t"+HIW+"~ ~ "+HIC+"The room begins to waver around you"+HIW+" ~ ~\n"+NORM);
         call_out("keep_invis", 10);
    }
}

vis_me(arg){
   if(arg == "cloak" || arg == "misty cloak"){
      if(worn){
         command("visible", environment());
         tell_object(environment(), ""+HIC+"~ ~ "+HIW+"The room wavers in front of you"+HIC+" ~ ~\n"+NORM+"You remove cloak.\n");
         remove_call_out("keep_invis");
    }
   }
}

cmd_tell(str) {
   object plyr;
   int X, CK;
   string myname, who, what;  
   if(!str) { 
      write("Excuse me?\n"); 
      return 1; 
   }
   /* attempt to type fewer letters */
   
   if(sscanf(str,"%s %s",who,what) < 2) 
      {
      write("Tell <who> <what>.\n"); 
      return 1; 
   }
   
   if(worn && TP->query_sp() <= 1){
      write("You do not have the spell points to tell to "+capitalize(who)+".\n");
      return 1; }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) { write(capitalize(who)+" is not on now.\n");
      return 1; 
   }
   if (plyr->query_invis() >18){
      write("No player with that name.\n");
      return 1; }
   
   if(!worn){ return 0; }
   tell_object(plyr,""+HIW+myname+" tells you"+NORM+": "+what+"\n");
   write(HIW+"You tell "+capitalize(who)+""+NORM+": "+what+"\n");
   plyr->add_tellhistory(HIW+myname+" told you: " + what + NORM);
   TP->add_spell_point(-2);
   return 1;
}

drop(){
   if(worn){
      vis_me("cloak");
   }
   ::drop();
}

give(){
   if(worn){
    vis_me("cloak");
   }
   ::give();
}

keep_invis(){
   tell_object(environment(), ""+HIC+"The cloak wavers for a moment.\n"+NORM);
   environment()->set_invs_sp();
call_out("keep_invis", 10);
}
