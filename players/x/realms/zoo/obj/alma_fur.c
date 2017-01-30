#include <ansi.h>

inherit "/obj/treasure";

int barter_value;

void reset(int x){
  if(x) return;
  
  set_id("alma fur");
  set_alias("fur");
 
  set_weight(2);
  set_value(666 + random(333));
}

void set_short(string sd){ short_desc = sd; }

void set_size(string x){
  switch(x){
    case "baby":
      set_short("a baby");
      barter_value = (int)query_value();
      set_long("\
A small, tattered fur from the body of a small baby alma. The\n\
tufts of fur are soft to the touch and feel warm.\n");
      set_weight(1);
      break;
    case "juvenile":
      set_short("a juvenile");
      barter_value = 2500+random(2000);
      set_long("\
A brown and black fur from the body of a juvenile alma. Small\n\
jagged claws protrude from the extremities. Blood soaks the\n\
back and innards.\n");
      break;
    case "adult":
      set_short("an adult");
      barter_value = 4000+random(4000);
      set_long("\
A large black fur with brief whisps of greyish-white hair;\n\
adult alma furs are reknowned for being warm and cozy.\n"); 
      break;
    case "elder":
      set_short("an elder");
      barter_value = 5000 + random(5000);
      set_long("\
A sheer white fur with occasional puffs of grey. The elder\n\
alma fur is the rarest of all alma furs and is worth the\n\
most on the black market.\n");
      break;
  }
  set_short(short()+" "+YEL+"alma "+HIK+"fur"+NORM);
  if(x=="elder")
    set_short("an "+HIW+"elder alma fur"+NORM);
}

int query_verte_barter(){
  return barter_value;
}
