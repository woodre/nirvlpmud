#define ME capitalize(this_player()->query_name())
#define IT capitalize(obj->query_name())
int quaffed,num;

id(str) {
  if(!quaffed)  {
    return str == "vial" || str == "potion" || str == "blue" ||
    str == "blue potion";
  }
  return str == "empty_potion";
}

short() { 
  if(!quaffed) { return "A blue potion"; }
  return 0;
}

long() {  
  if(!quaffed) {
    write("A vial of blue liquid\n");
    return;
  }
  return;
}

get() { return 1; }
query_weight() { return 1; }
query_value(){ if(!quaffed) return 700; else return 0; }
query_save_flag(){ return 1; }

drop() { 
  if(!quaffed) return 0;
  return 1;
}

reset(arg){
  if(arg) return;
  quaffed = 0;
  num = 0;
}

init(){
  add_action("drink_potion","drink");
  add_action("fire_breath","breathe");
}

fire_breath(str){
  object obj;

  if(!quaffed) {
    return 0;
  }
  if(!str) {
    return 0;
  }

  obj = present(str, environment(this_player()));

  if(!obj || !living(obj)) {
    return 0;
  }
  if(!obj == this_player()->query_attack()){
    tell_room(environment(this_player()),
    ME+" spits a tiny spray of flame and lights "+IT+"'s arse on fire!\n"+
    IT+" yelps and hops around in panic!\n");
    return 1;
  }
  write("\n"+
  "You draw in a deep breath and then exhale a tumeltous spray of flames!\n"+
  IT+" is engulfed in a blazing inferno!!!\n\n");
  say("\n"+
  ME+" takes a deep breath and then spits forth a tumeltous spray of flames!\n"+
  IT+" is engulfed in a blazing inferno!!!\n\n");
  obj->hit_player(20+random(30));
  num++;

  if(num > 2){
    write("You feel a twitch inside and know that your potion has worn off.\n");
    this_player()->add_weight(-1);
    destruct(this_object());
    return 1;
  }

  return 1;
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
    "You tip the bottle to your lips and drink the bluish liquid.  You squeeze\n"+
    "your tearing eyes tight at the sweet taste.  You finish of the entire bottle\n"+
    "and smash it to the ground!\n"+
    "BURP!\n"+
    "A blast of fire escapes your lips!\n"+
    "You wonder what would happen now if you 'breathe' on someone!\n");
    say(
    ME+" tips his head back and chugs a bottle of strange blue liquid.\n"+
    "BURP!\n"+
    ME+" belches up a fireball that almost burns your head off!!!\n");
    quaffed = 1;
    return 1;
  }
}

