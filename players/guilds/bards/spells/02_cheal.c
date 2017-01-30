#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;

  if (spell(0, 2, 15) == -1)
    return 0;
  if(!str)
    ob = TP;
  else
    ob=present(str,environment(TP));    
  if(!ob)
    FAIL("You can't heal someone who's not there.\n");
  ob->add_hit_point(12);
  
  write("You chant the song of healing.\n" +
      "You dance around in a circle.\n");
  say(tp + " chants a strangely soothing chant.\n"+
      tp + " dances around in a circle.\n");
  tell_room(environment(TP),
    NAME(ob)+ " is surrounded by a shining white aura.\n",({ob}));
  tell_object(ob,"A shining white aura surrounds you, and you feel better.\n");
  
  call_other(TP, "add_spell_point", -15);
  return 1;
}
