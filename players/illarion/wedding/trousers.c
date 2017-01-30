inherit "/players/illarion/obj/clothes";

void reset(status arg) {
  if(arg) return;

  set_id("trousers");
  set_short("A pair of `BLACK`matte black`off` wool trousers");
  set_long(
    "A pair of wool trousers so soft they hardly seem like wool at all,\n"+
    "and so black they appear to consume the light.\n");
  set_wear_mess("wear_room","&NAME& slips &POSS& legs into a pair of black trousers, and "+
                "buttons them");
  set_wear_mess("wear_self","You slip your legs into the trousers, and button them.\n");
  set_wear_mess("remove_room","&NAME& unbuttons &POSS& pants and slips them off.\n");
  set_wear_mess("remove_self","You unbutton the pants and slip them off.\n");
}
