#include "/players/jaraxle/define.h"
inherit "obj/armor";

set_type(string str){
    type = str;
}
object ob;
int tmp, num;

reset(arg) {
   ::reset(arg);
   set_name("orb");
   set_alias("void");
   set_long(

      "This is a floating orb.  It creates a deep dark space around it which\n"+
      "seems to be absorbing the light.\n"+
       "The orb can be used by "+BLK+BOLD+"activating"+NORM+" and"+BLK+BOLD+" deactivating"+NORM+" it.\n");

   
   set_ac(0);
   set_type("orb");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
    set_value(2500+random(10000));
}

short(){ return "Orb of the "+BOLD+""+BLK+"void"+NORM+""+(worn_by?" ("+BOLD+""+BLK+"floating nearby"+NORM+")":""); }

id(str) {
  if(worn) return str == "void" || str == "orb" || str == "orb of the void" || str == "dark_sight_object";
  else return str == "void" || str == "orb" || str == "orb of the void";
}

query_worn() { return worn; }
query_type() { return type; }
init(){
   ::init();
   
   add_action("wear","activate");
   add_action("remove","deactivate");
   add_action("remove","unwear");
   
}
wear(str)
{   
   if( environment() && environment(environment()) ){
      if(!creator(environment(environment()))){ 
         write("You cannot wear that here.\n");
         return 1; }
   }
   
   if (!id(str))
      return 0;
   
   if (environment() != this_player()) {
      write("You must get the orb first!\n");
      return 1;
   }
   if(present("notarmor",this_player())) {
      write("For some reason you are unable to use the orb.\n");
      return 1;
   }
   if (worn) {
      write("You are already using the orb!\n");
      return 1;
   }
   
if(environment()->is_kid()){
object kid, room;
/* added by verte : guess this was supposed to be here */
kid=environment();
room=environment(kid);
/* end verte */
kid->hit_player(10000);
tell_room(room,"The orb smothers the child to death with darkness!\n");
return 1; }

   next = 0;
   if(!protect)
      protect = "physical";
   set_params(protect,ac,res,special);
   ob = call_other(this_player(), "wear", this_object(), silently, type, params);
   if(ob) {
      write("You hold the orb out and it gently rises.\nThe orb floats nearby silently.\n");
      write("\n\t"+HIW+". . . Darkness . . ."+NORM+"\n");
 tell_room(environment(environment()), "The orb releases a burst of "+BOLD+""+BLK+"darkness"+NORM+" with an ear shattering clap!\n");
      set_arm_light(-1);
this_player()->hit_player(10+random(11), "other|dark");
      set_heart_beat(1);
      worn_by = this_player();
      worn = 1;
      return 1;
   }
   write("You are already using an item of class " + type + ".\n");
   return 1;
}



remove(str) {
   if (!id(str))
      return 0;
   if (!worn) {
      write("You are not currently using the orb!\n");
      return 1;
   }
   call_other(worn_by, "stop_wearing",this_object(), type, silently);
   write("You hold your hand out and the orb settles itself into your palm.\n");
   write("\n\t"+HIY+". . . Recession . . ."+NORM+"\n");
   set_heart_beat(0);
   set_arm_light(1);
   worn_by = 0;
   worn = 0;
   return 1;
}
  
do_damage(){
      object room, item;
      if(!environment() || !environment(environment())) return;
      room = environment(environment());
      item = first_inventory(room); 
 tell_room(environment(environment()), "The orb releases a burst of "+BOLD+""+BLK+"darkness"+NORM+" with an ear shattering clap!\n");
      while(item){
         if(living(item) && item->is_player())
{
if(item == environment()) item->hit_player(10+random(40), "other|dark");
else item->hit_player(5+random(10));
}
         item = next_inventory(item);
    }
}
void heart_beat(){
   if(!random(500)) do_damage();
   if( environment() && environment(environment()) ){
      if(!creator(environment(environment()))){ 
         if(worn){ 
            command("remove orb of the void",environment()); }
      }
   }
}
do_special(owner) {
num = random(12);
if(num == 6){
     tell_object(owner, "The orb pulses with "+BLK+BOLD+"dark energy"+NORM+".\n");
return -3; }
return 0; }

give(){
remove("orb of the void");
return 0; }

drop() {
remove("orb of the void");
return 0; }
