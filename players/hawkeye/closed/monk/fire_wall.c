#define EN environment(this_object())
#define ME find_player(owner)

string owner;
int enwc, limit, x;

reset(arg){
 if(arg)
 x = 0;
  return;
}

short(){ return; }
long(){ return; }
query_weight(){ return 0; }
query_value(){ return 0; }
get(){ return 1; }
drop(){ return 1; }
id(str){ return str == "fire_wall" || str == "monk_obj"; }
set_owner(str) { owner = str; }

fire_wall(){
enwc = EN->query_wc();
EN->set_wc("GRABBED");
limit = 5 + random(5);
call_out("fire", 2);
return 1;
}

fire(){
 if(!present(ME, environment(EN))) destruct(this_object());
 if(EN->query_hp() < 10) destruct(this_object());
tell_room(environment(EN), capitalize(EN->query_name())+
 " is trapped inside "+capitalize(ME->query_name())+
 "'s Firewall.\n");
EN->hit_player(random(6));
x++;
if(x > limit)
  gone();
else
  call_out("fire", 3);
return 1;
}

gone(){
 tell_room(environment(EN), capitalize(ME->query_name())+
  "'s Firewall spell ends and the flames around "+
  capitalize(EN->query_name())+" disappear.\n");
EN->set_wc(enwc);
EN->attack_object(ME);
move_object(this_object(), "room/void");
destruct(this_object());
return 1;
}
