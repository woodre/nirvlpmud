
int state;
id(str){ return str == "poison"; }
get(){
/*
    if(present("license")){
      return 1;
    }
    write("The poison flows into the ground due to mishandling.\n");
    destruct(this_object());
    return;
*/
return 1;
}
short(){
    if(state == 1){ return "Poison"; }
    if(state == 2){ return 0; }
    else return "A bottle of poison (blindness)"; }
set_state(i){ state = i; }
long(){ 
    write("This poison causes blindness in its victims.\n");
}

init(){
/*
     if(!present("license", environment(this_object()))){
       write("The poison flows to the ground due to mishandling.\n");
       destruct(this_object());
     }
*/
}

effect(){
     environment(this_object())->set_light(0);
     write("Suddenly the world goes black.  You are blind!\n");
     call_out("heal", 50);
     return 1;
}

heal(){
     environment(this_object())->set_light(1);
     write("Slowly light penetrates the darkness....\n");
     write("You can see again.\n");
     destruct(this_object());
     return 1;
}
