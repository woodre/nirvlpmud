/*  10/08/06 - Rumplemintz
      Moved inherit above #include, changed invis_flag to only define once
      Changed give() function to return 0 instead of ::give();
*/

inherit "/obj/armor.c";
#include "/players/jaraxle/define.h"
int invis_flag, saveflag;
void reset(int arg) {
   if(arg) return;
   ::reset();
   set_name("misty cloak");
   set_alias("cloak");
   set_short(HIW+"Misty Cloak"+NORM);
   set_long(
      "A strange swirling mass of mist and form.  The shadows of mist shape\n"+
      "into a claok which feels cool to the touch.  A mist of water feigns from\n"+
      "about the mist, refreshing your body and mind.\n");
   set_ac(2);
   set_type("misc");
   set_weight(0);
   set_value(10000+random(10000));
}
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
      /* Added check for this_object() to prevent bug when using ready command - Beck 3/21/2002 */
      if((string)inv[x]->query_type() == "misc" && inv[x]->query_worn() && inv[x] != this_object()) {
         write("You already have an armor of class misc.\n");
         return 1;
       }
   }
   if(arg == "cloak" || arg == "misty cloak"){
      object z;
      
      if(present("misty_cloak", (z = this_player())))
         return;
      z->set_invs_sp();
      write("You wrap the cloak around your body.\n\t"+HIW+"~ ~ "+HIC+"The room begins to waver around you"+HIW+" ~ ~\n"+NORM);
      call_out("keep_invis", 10);
      worn = 1;
      return 1; }
   return 0; }

vis_me(arg){
   if(arg == "cloak" || arg == "misty cloak"){
      if(worn){
         command("visible", environment());
         tell_object(environment(), ""+HIC+"~ ~ "+HIW+"The room wavers in front of you"+HIC+" ~ ~\n"+NORM+"You remove cloak.\n");
         remove_call_out("keep_invis");
         worn = 0;
         return 1; }
      return 0; }
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
   TP->add_spell_point(-1);
   return 1;
}

drop(){
   if(worn){
      vis_me("misty cloak");
   }
   ::drop();
}
give(){
   if(worn){
      vis_me("misty cloak");
   }
    return 0;
}

keep_invis(){
   switch(random(3)){
      case 0: tell_object(environment(), ""+HIC+"The cloak wavers for a moment.\n"+NORM);
      break;
      case 1: tell_object(environment(), HIC+"The rooms seems to quickly spin.\n"+NORM);
      break;
      case 2: tell_object(environment(), HIC+"You feel a cold chill from inside the cloak.\n"+NORM);
      break;
   }
   environment()->set_invs_sp();
   remove_call_out("keep_invis");
   call_out("keep_invis", 10);
}

do_special(owner){
   if(!random(6)){
      tell_object(owner,  HIC+"\tThe air around you shakes as the cloak protects you.\n"+NORM);
      if(this_player() && this_player()!=owner)
         write("The air around "+owner->query_name()+" seems to waver.\n");
      return 2+random(9);
   }
}

status
query_worn()
{
   return worn;
}
