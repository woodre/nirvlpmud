#define ME capitalize(this_player()->query_name())

int quaffed;

id(str) {
  if(!quaffed)  {
    return str == "vial" || str == "potion" || str == "clear" ||
    str == "clear potion";
  }
  return str == "empty_potion" || str == "water_breath";
}

short() { 
  if(!quaffed) { return "A clear potion"; }
  return 0;
}

long() {  
  if(!quaffed) {
    write("A vial of clear liquid\n");
    return;
  }
  return;
}

get() { return 1; }
query_weight() { return 1; }
query_value(){ if(!quaffed) return 700; else return 0; }
query_save_flag(){ return 1; }

extra_look() {
  if(quaffed)
     return capitalize(environment(this_object())->query_pronoun())+" has Gills for breathing underwater!";
}

drop() { 
  if(!quaffed) return 0;
  return 1;
}

reset(arg){
  if(arg) return;
  quaffed = 0;
}

init(){
  add_action("drink_potion","drink");
}

drink_potion(str){
  if(id(str)) {

    if(quaffed) {
      return 0;
    }
    if(present("empty_potion", this_player())){
      write("It would not be a good idea to drink another potion right now.\n");
      return 1;
    }
    write(
    "You tip the bottle to your lips and down the clear liquid.\n"+
    "You feel instantly strange ...\n"+
    "Something wierd is happening to you ...\n"+
    "Gills appear on your neck!\n");
    say(ME+" drinks a clear potion.\n");
    quaffed = 1;
    call_out("end_gills", 300+random(300));
    return 1;
  }
}

end_gills() {
  tell_object(environment(this_object()),
  "You feel an itching sensation in your neck...\n"+
  "Your gills disappear.\n");
  environment(this_object())->add_weight(-1);
  destruct(this_object());
  return 1;
}

