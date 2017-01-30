inherit "obj/treasure";

void reset(int arg){
   if(arg) return;
   ::reset(arg);
   set_name("sock");
   set_short("A Homey Sock");
   set_long("A Homey D Clown patented Bonking Sock!\n"+
      "If you think someone needs an \" I Don't play Dat \" just \n"+
      "type \"bonk <who>\" and it'll do the trick for ya!\n");
   set_alias("homey sock");
   set_value(150);
}

int hit(string who){
   if(!find_player(who)){
      notify_fail("You can't bonk someone who isn't playin, stupid!\n");
      return 0;
   }
   tell_room(environment(find_player(who)), this_player()->query_name()+" don't play Dat!\n");
   tell_room(environment(find_player(who)), this_player()->query_name()+" bonks "+find_player(who)->query_name()+" on the head with a sock!\n");
   tell_object(find_player(who), "Damn! I think "+this_player()->query_name()+" don't play Dat!\n");
   write("You just bonked "+find_player(who)->query_name()+" with a swift \""+this_player()->query_name()+" don't play Dat!\"\n");
   return 1;
}

void init(){
   ::init();
   add_action("hit", "bonk");
}

int get(){ return 1; }
