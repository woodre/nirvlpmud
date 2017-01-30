inherit "/obj/treasure";
#include "/players/illarion/dfns.h"

int wax;
int lit;

void reset(int arg) {
  if(arg) return;
  
  wax=100;
  set_id("candle");
  set_weight(1);
}
string short() {
  if(wax<=0) return "A candle stub";
  return "A scented white wax candlestick"+(lit?" ("+HIY+"lit"+NORM+")":"");
}
void long() {
  if(wax<=0) {
    write(
"The unusable remains of a white scented candle.  A tiny bit of its\n"+
"thick, heady scent still lingers.\n");
    return;
  }
  if(lit)
    write(
"A thick, white candle, burning steadily with a beautiful orange flame.\n"+
"A sweet and heady scent drifts from the flame, filling the room with its\n"+
"pleasant odor.  Like most candles, it can be "+BLD("extinguish")+"ed.\n");
  else
    write(
"A thick white candle, unlit and cold.  A slight smell about it seems to\n"+
"indicate it is scented in some way.  You could probably smell it better\n"+
"if you were to "+BLD("light")+" it.\n");
  switch(wax/20) {
    case 5: write("It hasn't been burned at all.\n"); break;
    case 4: write("It is burned down a little.\n"); break;
    case 3: write("It looks close to half burned.\n"); break;
    case 2: write("It looks a bit more than half burned.\n"); break;
    case 1: write("It looks mostly burned down.\n"); break;
    default: write("It is almost completely gone.\n"); break;
  }
  return;
}
void init() {
  add_action("cmd_light","light");
  add_action("cmd_extinguish","extinguish");
}
int cmd_light(string str) {
  if(!str || str != "candle")
    FAIL("Light what?\n");
  if(lit) {
    write("It's already lit.\n");
    return 1;
  }
  if(wax <=0) {
    write("It's too burned down to light.\n");
    return 1;
  }
  write("You carefully light the candle.  Within moments, the flame is\n"+
        "burning brightly, and a thick, sweet scent fills the air.\n");
  say(TPN+" lights a candle.  Within moments, it is burning brightly,\n"+
      "and a heady scent fills the air.\n");
  lit=1;
  call_out("burn_candle",30);
  return 1;
}
int cmd_extinguish(string str) {
  if(!str || str != "candle")
    FAIL("Extinguish what?\n");
  if(!lit) {
    write("It's not lit.\n");
    return 1;
  }
  write("You extinguish the candle, and the scent from it dwindles.\n");
  say(TPN+" extinguishes a candle, and the scent dies away.\n");
  lit=0;
  remove_call_out("burn_candle");
  return 1;
}
void burn_candle() {
  if(!environment()) return;
  wax--;
  if(wax<=0) {
    tell_room(environment(),"The candle flickers and goes out.\n");
    lit=0;
    return;
  }
  if(random(2)) 
    tell_room(environment(),"The candle"+HIR+" flame "+NORM+"flickers slightly.\n");
  else 
    tell_room(environment(),"The scent from the candle fills your nostrils.\n");
  call_out("burn_candle",30+random(30));
}
