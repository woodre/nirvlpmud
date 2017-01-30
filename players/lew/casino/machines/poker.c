inherit "obj/treasure";

reset(arg){
   if(!arg){
     set_id("machine"||"machine");
    set_value(0);
     set_weight(1000);
    set_short("A poker machine");
    set_long("This is a poker machine, for a list of payouts type\n"+
             "'payout.'  You may only bet 50 coins at a time.\n");
}
}

init(){

     add_action("payout","payout");
     add_action("bet","bet");
}

payout(){
     write("test function\n");
     return 1;
}

bet(str){
     if(!str){ write("How much?\n");
     return 1;
     }
     if(this_player()->query_money()<str){
          write("You do not have enough, maybe you should slow down.\n");
          return 0;
     }
     write("test amount "+str+"\n");
     return 1;
}
