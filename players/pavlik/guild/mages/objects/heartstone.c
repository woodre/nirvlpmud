string summon;

reset(arg){
  if(arg) return;
  summon = "none";
}

long(){
  write("A mystical heartstone.\n");
}

short(){ return "A Heartstone"; }

query_weight(){ return 3; }

query_value(){ return 1000; }

id(str){
  return str == "stone" || str == "heartstone";
}

get(){
  if(summon == "none") return 1;
  write("You cannot enter the summoning circle while a spell is being cast!\n");
  return;
}

set_summon(str){ summon = str; }
query_summon(){ return summon; }

