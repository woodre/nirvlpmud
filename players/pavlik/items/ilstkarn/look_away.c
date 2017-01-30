#define EN environment(this_object())

reset(arg){
  if(arg) return;
  call_out("blink", 5);
}

id(str){
  return str == "look_away" || str == "basalisk_look_away";
}

long(){
  write("It is invisible.\n");
  return;
}

short(){
  return;
}

get() {
  return 1;
}

drop() {
  return 1;
}

query_weight() {
  return 0;
}

query_value() {
  return 0;
}

query_save_flag() {
  return 1;
}

blink() {
  object obj;
  int i;

  obj = EN->query_attack();

  if(!obj || obj->query_name() != "Basalisk") {
    destruct(this_object());
    return 1;
  }

  i = random(8);

  if(i == 1)
    write("You watch the Basalisk out of the corner of your eye.\n");
  else if(i == 3)
    write("You swing somewhat blindly at the greater Basalisk.\n");
  else if(i == 5)
    write("You smartly look away from the deadly Basalisk.\n");

  call_out("blink", 5+random(5));
  return 1;
}

