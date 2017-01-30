#define EN environment(this_object())

string owner;
int chex;

long() {
  return;
}
reset(arg) {
    if (arg)
 chex = 0;
   return;
}
query_weight() {
    return 0;
}
short() {
   return;
}
id(str) {
  return str == "prayer_obj" || str == "monk_obj";
}
query_value() {
    return 0;
}
get() {
  return;
}
drop() {
 return 1;
}

set_owner(str) { owner = str; }
query_owner() { return owner; }

prayer(){
EN->add_ac(1);
call_out("pray_check", 5);
return 1;
}

pray_check(){
 object ob, obj;
ob = find_player(owner);
if(chex == 15 || !ob || !present(ob, environment(EN))){
 tell_object(EN, "You are no longer under "+capitalize(owner)+
                 "'s Prayer spell.\n");
 EN->add_ac(-1);
 destruct(this_object());
 return 1;    }
if(EN == ob && chex == 15){
 tell_object(EN, "The effects of your Prayer spell wear off.\n");
 EN->add_ac(-1);
 destruct(this_object());
 return 1;    }
chex++;
call_out("pray_check", 20);
return 1;
}
