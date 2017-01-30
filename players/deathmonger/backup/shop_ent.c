
id(str){
   return str == "shop" || str == "k-mart" || str== "K-mart" ||
          str == "kmart";
}
short(){ return "There is a large K-mart to the north"; }
long(){
    write("Well, it's K-mart.\n");
    write("It is a large run-down retail store. Not exactly the place\n"+
     "one is likely to find high quality goods.\n");
}

init(){ 
     add_action("north", "north");
}

reset(arg){
    if(!arg){
/*
     if(!find_living("van")){
      move_object(clone_object("players/deathmonger/MAGIC/sal"), "room/shop");
      }
   */
      move_object(this_object(), "room/northroad3");
   }
}
   
north(){
    call_other(this_player(), "move_player",
       "north#players/deathmonger/CASTLE/kmart");
     return 1;
}

is_castle() { return 1; }
