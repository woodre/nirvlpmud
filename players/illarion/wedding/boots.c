inherit "/players/illarion/obj/clothes";

void reset(status arg) {
  if(arg) return;

  set_id("boots");
  set_short("A pair of knee-high `BLACK`midnight `blue`blue`off` boots");
  set_long(
    "A comfortable pair of supple, knee-high leather boots, dyed a deep midnight blue.\n");
  set_wear_mess("wear_room","&NAME& pulls on a pair of dark blue boots.\n");
  set_wear_mess("wear_self","You pull the boots onto your feet.\n");
  set_wear_mess("remove_room","&NAME& kicks off &POSS& boots.\n");
  set_wear_mess("remove_self","You kick the boots off your feet.\n");
}
