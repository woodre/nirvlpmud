id(str){ return str == "sample_object" || str == "sample"; }

short(){
   return "A short description";
}

long(){
   write("A long desc.\n");
}

init(){
   add_action("hug_function","hug");
}

hug_function(str){
object ob;
   if(!str){ write("You need to specify someone.\n"); return 1; }
   if(!present(str, environment(this_player()))){
      if(!find_player(str)){
         write("This player is not in the mud.\n");
         return 1;
      }
      write("You hug "+capitalize(str));
      tell_object(find_player(str), this_player()->query_name()+" gives you a big hug.\n");
      return 1;
   }
   ob = present(str, environment(this_player()));
   write("You hug "+capitalize(str));
   tell_object(ob, this_player()->query_name()+" gives you a big hug.\n");
   say(this_player()->query_name()+" gives a big hug to "+capitalize(str));
   return 1;
}
