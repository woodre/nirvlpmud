string state;

id(str){ return str == "poison"; }
get(){ return 1; }
reset(arg){
    if(!arg){
      state = "bottle";
    }
}


set_state(s){ state = s; }
short(){
     if(state == "liquid") return "Liquid"; 
      if(state == "bottle") return "A bottle of poison (blindness)"; 
      else return 0;
}

init(){
    /*
    if(!present("license", this_player())){
      write("The poison flows into the ground due to mishandling.\n");
      destruct(this_object());
      return 1;
    }
   */
    if(!state){
      add_action("dark", "look", 1);
    }
}

effect(){
    call_out("wear_off", 110);
    return 1;
}

wear_off(){
    write("Slowly, your vision returns to you.\n");
    destruct(this_object());
    return 1;
}

dark(){
    write("It is too dark.\n");
    return 1;
}
