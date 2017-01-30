#include "/players/wocket/closed/ansi.h"
int time;
id(str){ return str == "fire" || str == "w_fire" || str == "campfire"; }
short(){ return "A "+HIR+"blazing"+OFF+" campfire"; }
long(){ 
  write("This is a small campfire made of branches.  It is very warm\n"+
        "and cozy.  Being near it seems to help heal any wounds.  If\n"+
        "the fire starts to get dim one might want to 'add' more branches\n"+
        "to it.\n"+
        "The fire is "+get_time()+".\n");
}

get_time(){
 switch(time){
  case 0..15: return "dieing down";
    break;
  case 16..30: return "fading fast";
    break;
  case 31..50: return "getting dim";
    break;
  case 51..100: return "burning well";
    break;
  case 101..150: return "burning strong";
  default:  return "blazing away";
 }
}
get(){ return 0; }
reset(){
 time = 30+random(150); 
 set_heart_beat(1);
}

set_time(x){
  if(time)
    time = time + x;
  else
    time = x;
}

put_out(){
  tell_room(environment(this_object()),HIR+"The fi"+OFF+RED+"re die"+OFF+"s out...\n");
  destruct(this_object());
}

heart_beat(){
object *everything;
int i,a;
  everything = all_inventory(environment(this_object()));
  for(i=0,a=sizeof(everything);i<a;i++){
    everything[i]->heal_self(1);
  }
  if(!random(20)){
    tell_room(environment(this_object()),"The "+HIR+"fire"+OFF+" blazes.\n");
  }
time--;
if(!time) put_out();
}

init(){
  add_action("adding","add");
}

adding(str){
  if(str != "branch"){
    notify_fail("What would you like to add to the fire?\n");
    return 0;
  }
  if(!present("branch",this_player())){
    write("You do not have a branch to add to the fire.\n");
    return 1;
  }
  destruct(present("branch",this_player()));
  write("You add a branch to the fire.\nThe fire flares slightly.\n");
  say(this_player()->query_name()+" adds a branch to the fire.\n");
  set_time(10+random(50));
  return 1;
}