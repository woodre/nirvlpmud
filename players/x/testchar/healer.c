status id(string str){
  return (str=="healer");
}

void init(){
  if(this_player() && this_player()->is_testchar())
  add_action("cmd_heal", "heal");
}

string short(){
  return "Portable Healer";
}

void long(){
  write("Type 'heal'.\n");
}

int cmd_heal(string str){
  if(str) return 0;

  this_player()->heal_self(100000);
  write("You have been fully healed.\n");
  return 1;
}

int drop(){ return 1; }
