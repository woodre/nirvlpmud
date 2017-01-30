bet(str){
     if(!str){
          say("How much?\n";
          return;  
     }
     if(str>this_player()->query_money()){
          write("You don't have enough money.");
          return;
     }
     return 1;
}
