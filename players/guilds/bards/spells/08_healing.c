#include "/players/guilds/bards/def.h"

status main(string str) {
  object targ;
  if (spell(-100, 8, 50) == -1) return 0;

  if(!str){
    targ=TP;
  } else {
    targ=present(str,environment(TP));
  }
  if(!targ)
    FAIL("Your target must be present for you to syng the Hymn of Healing.\n");
    
  targ->add_hit_point(40);
  write("You play the Hymn of Healing, and a halo of light surrounds you.\n"
       +"You faintly hear a choir of angels singing in accompaniment to your "
       + INST + ".\n");
  say(tp + " plays a hymn, and a halo of light surrounds "+OBJE(TP)+".\n"+
      "You faintly hear a choir of angles singing in accompniment to the "
      + INST + " music.\n");
  tell_object(targ,"A beam of healing light strikes you from above!\n"+
    "Your wounds close at an amazing rate.\n");
  tell_room(environment(TP),"A beam of healing light strikes "+NAME(targ)+
    " from above!\n",({targ}));
  call_other(TP, "add_spell_point", -50);
  return 1;
}
