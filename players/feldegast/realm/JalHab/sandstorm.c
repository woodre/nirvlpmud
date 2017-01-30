#include "defs.h"

int dx, dy;
int x, y;

id(str) {
  return str=="sandstorm";
}

reset(arg) {
  dx=random(6) - 3;
  dy=random(6) - 3;
  if(arg) return;
  move_object(clone_object(MON_PATH+"wing_dem.c"),this_object());
  enable_commands();
  call_out("random_move",20+random(80));
}

short() {
  return BOLD+BLK+"Sandstorm"+NORM;
}

long() {
  if(environment(TP) == environment(this_object()))
  write(
    "  The sandstorm spreads across the horizon, a billowing, black cloud\n"+
    "of darkness.  The storm's edge roils violently, sometimes apearing to\n"+
    "be a clawed hand or a demon's learing face.\n");
  else {
    write(RED+"In the heart of the storm, sand flies about, borne by demonic winds.\n");
    write(BOLD+BLK);
    environment()->long();
    write(NORM);
  }
}

init() {
  if(this_player() && this_player()->is_player()) {
  while(remove_call_out("wind") != -1);
  call_out("wind",5+random(10),this_player());
 }
  if(environment(TP)==this_object()) {
    add_action("cmd_leave","north");
    add_action("cmd_leave","west");
    add_action("cmd_leave","east");
    add_action("cmd_leave","south");
  }
}

get() { return 0; }

wind(targ) {
  if(!targ || !targ->is_player() || targ->query_ghost()) return;
  
  if(environment(targ)==environment(this_object())) {
    if(!random(5)) {
      tell_object(targ, BOLD+"You are swept up in the sandstorm!\n"+NORM);
      move_object(targ, this_object());
    }
    call_out("wind",5+random(20),targ);
  }
  if(environment(targ)==this_object()) {
    switch(random(3)) {
      case 0: tell_object(targ, HIY+"The wind scours your flesh with sand!\n"+NORM);
              break;
      case 1: tell_object(targ, YEL+"You are blinded by the sand!\n"+NORM);
              break;
      case 2: tell_object(targ, HIR+"The wind buffets you with sand!\n"+NORM);
              break;
    }
    call_out("wind",4+random(16),targ);
    targ->hit_player(random(10));
  }
}

cmd_leave(str) {
  if(!random(8)) {
    write("You fight your way free of the sandstorm!\n");
    TP->remote_say(TPN+" fights "+TP->query_possessive()+" way free of the storm!\n");
    move_object(this_player(),environment());
    TP->remote_say(TPN+" fights "+TP->query_possessive()+" way free of the storm!\n");
    command("look",TP);
    return 1;
  }
  switch(random(2)) {
    case 0: write("The wind buffets you to the ground!\n");
            break;
    case 1: write("You get lost in the storm!\n");
            break;
  }
  return 1;
}

random_move() {
  string dir;
  int *loc;
  if(!environment(this_object()))  return 1;
  loc=environment()->query_coords();
  x+=dx;
  y+=dy;
  dir="";
  if(y > 10) {
    loc[1]+=1;
    y=0;
    dir+="north";
  }
  if(y < -10) {
    loc[1]-=1;
    y=0;
    dir+="south";
  }
  if(x < -10) {
    loc[0]-=1;
    x=0;
    dir+="west";
  }
  if(x > 10) {
    loc[0]+=1;
    x=0;
    dir+="east";
  }

/* Begin Cludge */
  if(loc[0] < 0) loc[0]=0;
  if(loc[1] < 0) loc[1]=0;
  if(loc[0] >= WIDTH) loc[0]=WIDTH-1;
  if(loc[1] >= LENGTH) loc[1]=LENGTH-1;
/* End cludge */
  say("The Sandstorm blows "+dir+"\n");
  move_object(this_object(),MAP->query_location(loc[0],loc[1]));
  call_out("random_move",20+random(80));
}
