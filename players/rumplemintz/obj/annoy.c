inherit "obj/treasure";
int x;
object who,room;
reset(arg){
   if(arg){return;}
   set_value(0);
}
init(){
   add_action("hit","annoy");
}
id(str){return (str == "stick");}
short() {return "The Annoying Stick";}
long() {write("This is the Annoying Stick.\n"+
      "It looks like you could really annoy someone with it.\n");
}
get(){return 1;}
hit(arg){
   if(!find_player(arg)){
      write("That player is not on the mud.\n"); return 1;}
   if(x > 15){
      write("Your stick is broken.\n");
      return 1;
   }
   x++;
   who=find_player(arg);
/*
   if(who->query_level() > 21){
        write("I don't think it'd be wise to smack a wizard.\n");
      return 1;
   }
*/
   room=environment(who);
   tell_object(who,"ANNOYING!!!\n\nANNOYING!!!\n\nANNOYING!!!\n\nANNOYING!!!\n\nANNOYING!!!\n\nGOD DAMN, THIS IS ANNOYING ISN'T IT!!!\n\nANNOYING!!!\n\n\n\n\nP.S.\n\nANNOYING!!!\n");
   write("You just annoyed the hell out of "+capitalize(arg)+"\n");
   if(x > 15){
      write("Your stick is broken, no more annoying.\n");
   }
   return 1;
}
