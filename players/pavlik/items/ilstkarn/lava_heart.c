#include <ansi.h>
#define ME capitalize(this_player()->query_name())
#define PO this_player()->query_possessive()

int eaten;
int count;

id(str) {
  if(!eaten)  {
    return str == "heart" || str == "dragon heart" || str == "lava heart" ||
    str == "dragon's heart" || str == "dragons heart";
  }
  return str == "eaten_heart";
}

short() { 
  if(!eaten) { return RED+"Lava Dragon's Heart"+NORM; }
  return 0;
}

long() {  
  if(!eaten) {
    write(
    "The heart of a slain Lava Dragon.  The heart is no longer beating,\n"+
    "yet it still feels very warm to the touch.\n");
    return;
  }
  return;
}

get() { return 1; }
query_weight() { return 1; }
query_value(){ if(!eaten) return 1200; else return 0; }
query_save_flag(){ return 1; }

drop() { 
  if(!eaten) return 0;
  return 1;
}

reset(arg){
  if(arg) return;
  eaten = 0;
  count = 0;
}

init(){
  add_action("eat_heart","eat");
}

eat_heart(str){
  if(id(str)) {

    if(eaten) {
      return 0;
    }
    if(present("eaten_heart", this_player())){
      write("It would not be a good idea to eat this right now.\n");
      return 1;
    }
    write(
    "You close your eyes and stuff the Dragon's Heart into your mouth.\n"+
    "The soft muscle tastes hot and bitter on your tongue and you swallow\n"+
    "it quickly!\n");
    write("The "+RED+"Lava Dragon's Heart"+NORM+" burns in your stomach.\n");

    say(
    ME+" closes "+PO+" eyes and stuffs a Dragon's Heart into "+PO+" mouth.\n"+
    ME+" grimaces slightly as "+this_player()->query_pronoun()+
    " swallows it down.\n");

    eaten = 1;
    count = 0;
    this_player()->add_stuffed(-10);
    this_player()->add_soaked(-10);
    this_player()->add_intoxination(-10);
    call_out("dragon_heart", 60+random(60));
    return 1;
  }
}

dragon_heart() {
  object obj;

  obj = environment(this_object());

  if(!obj || !living(obj)) {
    destruct(this_object());
    return 1;
  }

  tell_object(obj,
  "The "+RED+"Lava Dragon's Heart"+NORM+" burns in your stomach.\n");

  obj->add_stuffed(-10);
  obj->add_soaked(-10);
  obj->add_intoxination(-10);
  count++;

  if(count >= 3) {
    tell_object(obj,
    "The "+RED+"burning"+NORM+" sensation in your stomach disappears.\n");
    obj->add_weight(-1);
    destruct(this_object());
    return 1;
  }

  call_out("dragon_heart", 120);
  return 1;
}

