#include "/players/mizan/esc.h"
#define GUILD_ID "Mizan-guild-object"
#define MORPH_ID "Mizan-morph-object"
#define HELPFILE "/players/mizan/closed/poly/help/juggernaut"
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

#define ENV environment(this_object())
#define DEATHTIME 3000


id(str) { return str == "sphere" || str == MORPH_ID; }

short() { return "An intense, dark-red sphere"; }

long() {
  write("You look into the sphere and see the reflection\n"+
  "of a man, chiseled of rock and steel. Dark yet vibrant\n"+
  "eyes stare back at you reminding yourself of your warrior\n"+
  "heritage. Yes, you really do feel like a monster truck of a man.\n"+
  "This sphere contains your matrix of regneration for a juggernaut.\n"+
  "Type 'class' to see your new abilities.\n");
}


reset()
{
   call_out("force_return", DEATHTIME);
}

init() {
  add_action("class","class");
  add_action("rtime","rtime");
}

class() {
  cat(HELPFILE);
  return 1;
}


get() { return 1; }
drop() { return 1; }

force_return() {
   if(ENV) tell_object(ENV, ESC + "[1m" + ESC + "[31m" +
         "You feel that the strain of retaining this morph is getting to you\n"+
      "and you will be unable to hold it for much longer...\n" + ESC + "[0m");
   call_out("force_return2", 20);
}

force_return2() {
   if(ENV) {
      if((ENV)->query_dead()) return 0;
      tell_object(ENV, "For no reason whatsoever, you suddenly lose concentration.\n");
      if(environment(ENV))
         call_other(environment(ENV), "revert", ENV);
      MASTER_R->undo_polymorph(ENV);
   }
}

rtime() 
{
  int i;
  int foo;
  string dc_text;
  
  if((i = find_call_out("force_return")) >= 0) 
  {
    dc_text = ("Countdown until forced reversion: ");
    foo=i/60;
    if((i-foo) == 0) dc_text = dc_text + ("(" + foo + " minutes).\n");
    else dc_text = dc_text + ("(" + foo + " minutes, " + (i-(foo * 60)) + " seconds).\n");
    write(dc_text);
    return 1;
  }
  else
  {
    write("Forced reversion is happening very soon!\n");
    return 1;
  }
}

