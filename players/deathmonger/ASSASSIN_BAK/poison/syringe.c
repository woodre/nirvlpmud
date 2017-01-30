
object poison;
id(str){ return str == "syringe"; }
get(){ return 1; }
short(){ return "A hypodermic syringe"; }
long(){ 
    write("Hmmm...looks like it's used for injecting liquids into things.\n");
}

init(){
     poison = present("poison", environment(this_object()));
     add_action("inject", "inject");
      add_action("fill", "fill");
}

inject(str){
     object victim;
     victim = present(str, environment(this_player()));
     if(!victim){
       write("No "+str+" here.\n");
       return 1;
     }
     move_object(poison, victim);
     write("You inject "+capitalize(str)+" with the syringe and the poison\n");
     write("flows into your victim's bloodstream.\n");
     poison->effect();
}

fill(str){
     if(str == "syringe"){
       if(!present("poison")){
         write("You don't have anything to fill it with.\n");
         return 1;
       }
       move_object(poison, this_object());
       poison->set_state(0);
       write("You fill the syringe with poison.\n");
       return 1;
      }
}
