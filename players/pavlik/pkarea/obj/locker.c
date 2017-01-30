#define EN environment(this_object())

string owner;
string *save_string;
int money;

reset(arg){
  if(arg) return;
  owner = 0;
  money = 0;
  save_string = ({ });
}

id(str){
  if(!owner) return "nooones_locker";
  return str == owner+"_locker";
}

long(){
  write("It is invisible.\n");
  return;
}

short(){
  if(this_player()->query_level() > 20) return owner+"'s Locker (invis)";
  return;
}

get() {
  return 1;
}

drop() {
  return 1;
}

clean_up() {
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

set_owner(str) { owner = str; }
query_owner(){ return owner; }

add_money(i) { money += i; }
query_money() { return money; }

add_save_string(*str) {
  int i;
  for(i=0; i<sizeof(str); i++) {
	save_string += str[i];
  }
}
query_save_string() { return save_string; }

