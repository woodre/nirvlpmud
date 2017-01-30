#define NAME "Puppy"
#define DEST "room/farmroad2"
#include "/players/puppy/define.h"

id(str) { return (str == "puppy" || str == "a puppy" || str == "memorial" || str == "a memorial"); }

short() {
   return "A puppy.\n"+
   "A memorial";
}

long(str) {
   if(str == "puppy" || str == "a puppy")
      write("A cute little puppy that enjoys it when people 'pet' him.\n");
   else {
      write("A small memorial erected to remember our lost souls.\n");
      write("To honor the victims one needs only to 'enter' memorial.\n");
   }
}

init() {
  add_action("enter", "enter");
   add_action("ppuppy","pet");
add_action("ffind","find");
   add_action("pupy","kill");
}

pupy(str) {
   if(str == "puppy") {
      write("The puppy is just too cute to harm.\n");
      return 1; }
   write("Kill what?\n");
   return 1; }

ffind(str) {
if(str == "puppy") {
tell_object(find_player("puppy"), this_player()->query_name()+" is RINGING you!!!!!\n");
}
write("OK.\n");
return 1; }

ppuppy(arg) {
if(!arg){ notify_fail("What cute furry creature would you like to pet?\n"); return 0; }
   if(!arg) { return 0;}
   if(arg == "puppy" || arg == "a puppy" || arg == "the puppy") {
      write("The puppy jumps up on you.\n\tYou start to feel a little funny.\n\t\tYour body starts to disolve into the ground.\n");
      say("The puppy jumps up on "+this_player()->query_name()+" and slobbers all over "+this_player()->query_objective()+".\n");
      say(this_player()->query_name()+" is disolved by all the slobber.\n");
      move_object(this_player(),"/players/puppy/areaentrance.c");
      tell_room("players/puppy/areaentrance.c", this_player()->query_name()+" arrives.\n");
      write_file("/players/puppy/logs/area",
         this_player()->query_real_name()+"   "+ ctime()[4..15]+"\n");
      command("look",this_player());
      return 1;}}
/*
memorial(arg) {
   if(!arg) {return 0;}
   if(arg == "memorial" || arg == "at memorial") {
      write("A small memorial erected to remember our lost souls.\n"+
         write("To honor the victims one needs only to 'enter' the memorial.\n");
         return 1;}
*/
enter(string str) {
   if (!str || str != "memorial"){
      notify_fail("What would you like to enter?\n");
      return 0;
   }
   
write("A chill runs through your body as you step into the memorial.\n");
   say(this_player()->query_name()+" steps into the memorial.\n");
   move_object(this_player(),"/players/puppy/mem/1.c");
tell_room("players/puppy/mem/1.c", this_player()->query_name()+" arrives.\n");
   write_file("/players/puppy/logs/memorial",
      this_player()->query_real_name()+"   "+ ctime()[4..15]+"\n");
   command("look",this_player());
   return 1;
}

reset(arg) {
   move_object(this_object(),DEST);
   if(arg) return;
call_other("/players/puppy/mem/ribbon.c","???");
}

is_castle(){return 1;}
