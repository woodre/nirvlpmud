
int worn;
id(str){ return str == "headphones"; }
query_tuned(){ return worn; }

query_value(){ return 10; }
get(){ return 1; }
short(){
     if(worn == 1) return "A pair of headphones (worn)";
     else return "A pair of headphones";
}
long(){
     write("These are headphones tuned into the Nirvana Mud\n");
     write("Shopping Network.  To listen to the auctions and\n");
     write("sales going on through this channel, 'wear headphones'.\n");
     write("To stop listening to the sales chatter, 'unwear headphones'.\n");
     write("To speak through this network, 'net <message>'.\n");
}

init(){
     add_action("wear", "wear");
     add_action("unwear", "unwear");
     add_action("talk", "net");
}

wear(str){
     if(str == "headphones"){
       write("You put on your Nirvana Mud Shopping Network headphones.\n");
    say(this_player()->query_name()+" puts on some headphones.\n");
       worn = 1;
       return 1;
     }
}

unwear(str){
     if(str == "headphones"){
       write("You take off your headphones.\n");
       say(this_player()->query_name()+" takes off some headphones.\n");
       worn = 0;
       return 1;
      }
}
talk(str){
      object list, headphones;
      int i;
      if(worn == 0){
        write("You are not wearing your headphones.\n");
        return 1;
      }
     list = users();
     for(i=1;i<sizeof(list);i++){
       headphones = present("headphones", list[i]);
       if(headphones && headphones->query_tuned() == 1){
         tell_object(list[i], this_player()->query_name()+
           "[shopping network] "+str+"\n");
       }
     }
return 1;
}
