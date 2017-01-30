inherit "obj/treasure";
int x;
object who,room;
reset(arg){
   if(arg){return;}
   set_value(150);
}
init(){
   add_action("hit","jizz");
}
id(str){return (str == "sperm");}
short() {return "The Sperminator";}
long() {write("This is the Sperminator.\n"+
      "It looks like you could really Jizz someone in the face with it.\n");
}
get(){return 1;}
hit(arg){
   if(!find_player(arg)){
      write("That player is not on the mud.\n"); return 1;}
   if(x > 15){
      write("Sorry, only 15 times.\n");
      return 1;
   }
   x++;
   who=find_player(arg);
   if(who->query_level() > 50){
        write("I don't think it'd be wise to Jizz a wizard.\n");
      return 1;
   }
   room=environment(who);
  
tell_object(who,this_player()->query_name()+" just Jizzes in yo face mutha fucka!!!\n");
   write("You just Jizzed in thier face!!!\n");
   if(x > 15){
      write("Your stick just broke, i suggest gettin a new one.\n");
   }
   return 1;
}
