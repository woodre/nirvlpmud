#include <ansi.h>
id(str){ return str == "tie" || str == "bowtie"; }


get() { 
   return 1; 
} 

drop() { 
   return 1; 
}


short(){
   return (GRY+">"+HIW+"x"+GRY+"<"+NORM+" A silk bowtie");
}

long(){
   write("Duh. It's a silk bowtie. What else did you expect?\n");
}

init(){
   add_action("hhug","hug");
   add_action("skiss","skiss");
}

hhug(str){
object ob;
   if(!str){ write("You need to specify someone.\n"); return 1; }
   if(!present(str, environment(this_player()))){
      if(!find_player(str)){
         write("This player is not in the mud.\n");
         return 1;
      }
      write("You give "+capitalize(str)+" a big hug from afar.\n");
      tell_object(find_player(str), this_player()->query_name()+" gives you a big hug from afar.\n");
      return 1;
   }
   ob = present(str, environment(this_player()));
   write("You give a big hug to "+capitalize(str)+". \n");
   tell_object(ob, this_player()->query_name()+" gives you a big hug.\n");
   say(this_player()->query_name()+" gives a big hug to "+capitalize(str)+". \n");
   return 1;
}

skiss(str){
object ob;
   if(!str){ write("You need to specify someone.\n"); return 1; }
   if(!present(str, environment(this_player()))){
      if(!find_player(str)){
         write("This player is not in the mud.\n");
         return 1;
      }
      write("You give "+capitalize(str)+" a super kiss from afar.\n");
      tell_object(find_player(str), this_player()->query_name()+" pulls you close and kisses you passionately!\n");
      return 1;
   }
   ob = present(str, environment(this_player()));
   write("You give a super kiss to "+capitalize(str)+". \n");
   tell_object(ob, this_player()->query_name()+" pulls you close and kisses you passionately!\n");
   say(this_player()->query_name()+" gives a super kiss to "+capitalize(str)+". \n");
   return 1;
}
