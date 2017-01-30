#include "/players/beck/rangers/Defs.h"
id(str){
   return str == "pool" || str == "golds_gym_pool";
}
short(){ return "Golds Gym Pool"; }
is_pool(){return 1;}
long(){ 
   write("This is the pool at the Golds Gym facilities.\n"+
   "You can do your swimming and water running workouts here,\n"+
   "or you can just lounge around and play if you want.\n"+
   "");
   if(!present(this_player(),this_object())){ 
      write("You can dive into the pool by 'dive into pool'.\n");
      write("You can climb into the pool by 'climb into pool'.\n");
      write("You can throw a person in by 'throw <person>'.\n");
   }
   if(present(this_player(),this_object())){
      write("To begin your workout type 'workout'.\n");
      write("To get out just 'climb out'.\n");
   }
}
init(){
   if(!present(this_player(),this_object())){
      add_action("throw","throw");
      add_action("dive","dive");
      add_action("climb_in","climb");
   }
   if(present(this_player(),this_object())){
      add_action("workout","workout");
      add_action("climb_out","climb");
      add_action("splash","splash");
   }
}
workout(){
COMM->workout();
   return 1;
}
dive(str){
   if(!str){ write("Where do you want to dive?\n"); return 1; }
   if(str != "into pool"){
      write("You can only dive into the pool.\n");
      return 1;
   }
   write("You dive headfirst into the pool.\n");
   say(this_player()->query_name()+" dives headfirst into the pool.\n");
   tell_room(this_object(),this_player()->query_name()+" dives into the pool.\n"); 
   move_object(this_player(), this_object());
command("look",this_player());
   return 1;
}
climb_in(str){
   if(!str){ write("Where do you want to climb?\n"); return 1; }
   if(str != "into pool"){
      write("You can only climb into the pool.\n");
      return 1;
   }
   write("You climb slowly into the pool.\n");
   say(this_player()->query_name()+" climbes into the pool.\n");
   tell_room(this_object(),this_player()->query_name()+" climbes into the pool.\n");
   move_object(this_player(), this_object());
command("look",this_player());
   return 1;
}
climb_out(str){
   if(!str){ write("Where do you want to climb?\n"); return 1; }
   if(str != "out"){
      write("You can only climb out.\n");
      return 1;
   }
   write("You climb out of the pool.\n");
   say(this_player()->query_name()+" climbes out of the pool.\n");
   tell_room(environment(this_object()),this_player()->query_name()+" climbes out of the pool.\n"); 
   move_object(this_player(), environment(this_object()));
command("look",this_player());
   return 1;
}
throw(str){
   object sucker;
   if(!str){ write("Who do you want to throw in the pool?\n"); return 1; }
   if(!present(str, environment(this_player()))){
      write("That person is not here.\n");
      return 1;
   }
   sucker = present(str, environment(this_player()));
   if(present("RangerCommunicator",sucker)->QNoThrow() == 1){
      write("You can't throw a person in while they are working out.\n");
      return 1;
   }
   write("You throw "+sucker->query_name()+
   " into the pool.\n");
   say(this_player()->query_name()+" throws "+sucker->query_name()+
   " into the pool.\n");
    tell_room(this_object(),this_player()->query_name()+" throws "+
    sucker->query_name()+" into the pool.\n");   
    move_object(sucker, this_object());
    return 1;
}
splash(str){
   if(!str){ write("Who do you want to throw in the pool?\n"); return 1; }
   if(!present(str, environment(this_player()))){
      write("That person is not here.\n");
      return 1;
   }
   write("You splash "+present(str, environment(this_player()))->query_name()+
   " in the face.\n");
   say(this_player()->query_name()+" slashes "+present(str, environment(this_player()))->query_name()+
   " in the face.\n");
   return 1;
}
realm(){ return "NT"; }
query_no_fight(){ return 1; }

