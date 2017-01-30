#include "../../defs.h"

int flower;
int air;
int dig;
int occup;
object who;

id(str) { 
  if(!occup) return str == "grave_heal" || str == "grave"; 
  else
   return str == "mound" || str == "dirt";
}

short(){ 
  if(occup){
    if(flower){
      return "A mound of dirt with a single "+HIY+"flower"+OFF+" growing out of it";
    }
    return "A mound of dirt";
  }
  else return "A recently opened grave"; 
}

long() {
  if(environment(tp) != to){
    if(occup){ 
     write("A mound of freshly turned soil.  A single yellow flower grows from the ground\n"+
           "hanging with a slight limp.\n");
     return 1;
    }
    else{
      write("A recently opened grave.  The dirt around is fresh with some ashes lining the bottom.\n");
      if(GOB){
        write(ROD+"You have a strange desire to 'enter' the grave.\n");
      }
    }
  }
  else{
    write("Dirt surrounds you inside this grave.  Perhaps you could 'dig' your way up\n"+
          "through the soft dirt.\n");
    return 1;
  }
}

reset(arg) {
  if(arg) return;
  occup = 0;
  who = 0;
}

init() {
  if(GOB){
    if(environment(tp) == this_object()){
      add_action("leave_grave","dig");
    } 
    else if(environment(tp) == environment(this_object())){
      add_action("enter_grave","enter");
    }
  }
}

enter_grave(str) {
  if(!str || str != "grave"){
    notify_fail("What would you like to enter?\n");
    return 0; 
  }
  if(id(str)) {
    if(!GOB){
      write("You move to enter the grave but the are overwhelmed with dread.\n");
      return 1; 
    }
    if(occup){
      write("You move to enter the grave, but realize it is already filled in.\n"); 
      return 1;
    }
    if(GOB->query_skin() < 3){
    write("You move to enter the grave, but realize how cold it would be without\n"+
          "some warm corpse skin to wrap around you.\n");
    return 1;
    }
  say(tp->query_name()+" enters the recently opened gravesite.  Dirt falls in around "+tp->query_objective()+".\n");
  call_out("flower",5);
  write("You wrap some skin tightly around your body to keep you warm\n"+
        "and slide into the grave.  As you enter, dirt from above falls down\n"+
        "on top of you, burying you "+BOLD+"ALIVE"+OFF+"!\n");
  move_object(tp,this_object());
  GOB->add_skin(-3);
  who = tp;
  occup = 1;
  dig = random(4);
  air = 50+random(100);
  set_heart_beat(1);
return 1;
}
}

flower(){
  tell_room(environment(to),"A small flower pops out of the mound of dirt.\n");
  flower = 1;
}

leave_grave() {
  if(dig > 0){
    write("You claw up towards the surface as dirt falls around you.\n");
    write("You remained buried.\n");
    dig--;
    return 1;
  }
    tell_room(environment(to),tpn+" claws "+tpp+" way out from the underneath the mound of dirt.\n");
    write("You break through the surface and gasp for a deep breath of air.\n");
    write("Slowly you climb out of the hole and brush yourself off.\n");
    move_object(tp,environment(to));
    occup = 0;
    return 1;
}

heart_beat() {
string msg;
int amount;
  if(who && environment(who) == to){
    if(air > 0){
      amount = random(2);
      switch(random(50)){
        case 0:   msg = ROD+"The realm of death is pleased with your communion with the dead.\n";
                  amount = 5; break;
        case 1:   msg = ROD+"You feel at home against the maggots and the bones.\n";
                  amount = 3; break;
        case 2:   msg = ROD+"The realm of death holds you closer.\n";
                  amount = 5; break;
        case 3:   msg = ROD+"You wrap the skins around you tighter.\n"; 
                  amount= 3; break;
        case 4:   msg = ROD+"The sweet stench of death fills the dry air.\n";
                  amount = 4; break;
        case 5:   msg = "";
                  break;
        case 6:   msg = "";
                  break;
        case 7:   msg = "";
                  break;
        case 8:   msg = "";
                  break;
        case 9:   msg = ROD+"Small bugs crawl across your body and down your leg.\n";
                  amount = 2; break;
        default:  msg = ""; break; 
      } 
      who->heal_self(amount);
      tell_object(who,msg);
      air--;
      return 1;
    }     
    else{
      tell_object(who,"You begin to gasp for air!\n");
      who->add_hit_point(-30);
      return 1;   
    }
  }
  else{
    who = 0;
    flower = 0;
    air = 0;
    occup = 0;
    set_heart_beat(0);
  }
}

exit() { flower = 0; air = 0; occup = 0; who = 0; set_heart_beat(0); }
realm() {return "NT";}

