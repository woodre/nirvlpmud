inherit "obj/treasure";
#include "/players/zeus/closed/all.h"
int hp, sp;
string msg, flame;

reset(arg){
  if (arg) return;

  flame = 0;
  set_weight(1);
  set_value(12000);
  call_out("trpsprngr", 45);
}

short(){ if(flame) return BOLD+BLK+"The Heart of the Shadowninja"+
                          NORM+" ["+flame+"]";
         else return BOLD+BLK+"The Heart of the Shadowninja"+NORM;
}

long(){
  write(
    "This is a mystical black gem.  It is treasured amongst the\n"+
    "Shadowninja as a sacred and mystical stone.  Looking deep\n"+
    "within the gem a small flame is visible that dances back\n"+
    "and forth.  The color of the flame changes as you gaze into\n"+
    "the gem, from red to blue to white.\n");
  if(!random(30))
    write("polish, gaze, lick, eat, hold, toss, admire, stroke, suck\n");
}

id(str){ return str == "gem" || str == "heart"; }

query_save_flag(){  return 0; }

init(){
  ::init();
  add_action("polish_gem", "polish");
  add_action("gaze_gem", "gaze");
  add_action("lick_gem", "lick");
  add_action("eat_gem", "eat");
  add_action("hold_gem", "hold");
  add_action("toss_gem", "toss");
  add_action("admire_gem", "admire");
  add_action("stroke_gem", "stroke");
  add_action("suck_gem", "suck");
}

polish_gem(str){
  if((!str) || !id(str) || !present(this_object(), this_player())) return 0;
  write("You polish the gem.\n");
  say(TP->QN+" polishes a gem.\n");
  return 1;
}

gaze_gem(str){
  if((!str) || !id(str) || !present(this_object(), this_player())) return 0;
  write("You gaze at the mystical flame within the gem.\n");
  say(TP->QN+" gazes into a gem.\n");
  return 1;
}

lick_gem(str){
  if((!str) || !id(str) || !present(this_object(), this_player())) return 0;
  write("You slowly drag your tongue along the gem.\n");
  say(TP->QN+" drags "+TP->POS+" tongue along a gem.\n");
  return 1;
}

eat_gem(str){
  if((!str) || !id(str) || !present(this_object(), this_player())) return 0;
  write("You stick the gem in your mouth and try to eat it...\n"+
    "You chew the gem....\n"+
    "You spit the gem back out unhappy with its nutritional value.\n");
  say(TP->QN+" sticks a gem in "+TP->POS+" mouth then spits it back out.\n");
  return 1;
}

hold_gem(str){
  if((!str) || !id(str) || !present(this_object(), this_player())) return 0;
  write("You hold the gem and can feel a warmth within it.\n");
  say(TP->QN+" holds a gem for a moment then releases it.\n");
  return 1;
}

toss_gem(str){
  if((!str) || !id(str) || !present(this_object(), this_player())) return 0;
  write("You toss the gem high into the air"+
    " only to catch it a moment later.\n");
  say(TP->QN+" tosses a gem high into the air only to catch it a"+
    " moment later.\n");
  return 1;
}

admire_gem(str){
  if((!str) || !id(str) || !present(this_object(), this_player())) return 0;
  write("You hold your gem up and admire it lovingly.\n");
  say(TP->QN+" holds a gem up and admires it lovingly.\n");
  return 1;
}

stroke_gem(str){
  if((!str) || !id(str) || !present(this_object(), this_player())) return 0;
  write("You lovingly stroke the gem with your hand.\n");
  say(TP->QN+" lovingly strokes a gem with "+TP->POS+" hand.\n");
  return 1;
}

suck_gem(str){
  if((!str) || !id(str) || !present(this_object(), this_player())) return 0;
  write("You pop the gem into your mouth, suck on it, then spit it out.\n");
  say(TP->QN+" pops a gem into "+TP->POS+
    "mouth, sucks on it, then spits it out.\n");
  return 1;
}

trpsprngr(){
  if(!environment()) return;
  if(environment()->is_player()){
    hp = ((ENV->query_hp() * 100) / ENV->query_mhp());
    sp = ((ENV->query_sp() * 100) / ENV->query_msp());
    if(!random(10)){
      flame = BOLD+BLK+"black"+NORM;
      ENV->heal_self(-10);
    }
    else if(hp < sp){
      flame = BLU+"blue"+NORM;
      ENV->add_hit_point(hp / 10);
    }
    else if(hp > sp){
      flame = RED+"red"+NORM;
      ENV->add_spell_point(sp / 10);
    }
    else if(hp == sp){
      flame = HIW+"white"+NORM;
      ENV->heal_self((hp + sp) / 10);
    }
    tell_object(ENV, "The gem glows "+flame+" for a moment then dims.\n");
  }
  call_out("trpsprngr", 45);
}

