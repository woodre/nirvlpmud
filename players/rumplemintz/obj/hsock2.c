inherit "obj/treasure";
int x;
object who,room;
reset(arg){
   if(arg){return;}
   set_value(150);
}
init(){
   add_action("hit","bonk");
}
id(str){return (str == "sock");}
short() {return "A Homey Sock";}
long() {write("A Homey D Clown patended Bonking Sock!\n"+
      "If you think someone needs an 'I Don't play Dat' just\n"+
        "type 'bonk <person>' and it'll do the trick for ya!\n");
}
get(){return 1;}
hit(arg){
   if(!find_player(arg)){
        write("You can't bonk someone who isn't playin, stupid!\n"); return 1;}
   who=find_player(arg);
   room=environment(who);
   tell_room(room,capitalize(this_player()->query_real_name())+" says: "+capitalize(this_player()->query_real_name())+" don't play Dat!\n");
   tell_room(room,capitalize(this_player()->query_real_name())+" bonks "+capitalize(who->query_real_name())+" on the head with the sock!\n");
   tell_object(who,"Damn!, I think "+capitalize(this_player()->query_real_name()
)+" don't play Dat!\n");
    write("You just bonked "+capitalize(arg)+" with a swift '"+capitalize(this_player()->query_real_name())+" don't play Dat!'\n");
   return 1;
}
