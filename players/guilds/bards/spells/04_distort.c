#include "/players/guilds/bards/def.h"

status main(string str) {
  object targ;
  object ob;
  int acboost;

  if (spell(-111, 4, 40) == -1)
    return 0;
  
  if(!str)
    targ=TP;
  else
    targ = present(str, environment(TP));
    
  if(!targ)
    FAIL("You must specify a target to protect.\n");
  if(!living(targ))
    FAIL("Your target must be alive.\n");
  if(!targ->is_player())
    FAIL("The Chord of Distortion will only protect players.\n");
  if(present("bard_defend_spell", targ))
    FAIL(NAME(targ)+" is already protected by the Chord of Distortion.\n");

  switch(BLVL){
    case 10..10000: acboost = 4; break;
    case 8..9:      acboost = 3; break;
    case 6..7:      acboost = 2; break;
    case 1..5:      acboost = 1; break;
    default:        acboost = 0; break;
  } 
  ob = clone_object(OBJ+"bard_defend");
  move_object(ob, targ);
  ob->start(targ, acboost, BLVL * 600, TP);
   
  write("You play the Chord of Distortion upon your " + INST + ".\n");
  say(tp + " plays a single, obviously magical chord on " + POSS(TP) +
    " " + INST + ".\n");
  tell_object(targ,
    "You fear a faint humming sound, which fades into a distortion in\n"+
    "the air surrounding you.  You feel protected.\n");
  tell_room(environment(TP),
    "A distortion appears in the air around "+NAME(targ)+".\n",
    ({targ}));

  call_other(TP, "add_spell_point", -40);
  return 1;
}
