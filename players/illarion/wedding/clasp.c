inherit "/players/illarion/obj/clothes";

void reset(status arg) {
  if(arg) return;

  set_id("clasp");
  set_short("A `WHITE`s`white`i`BLACK`lv`white`e`WHITE`r`off` dragon cloak clasp");
  set_long(
    "A brilliant silver cloak fastening in the shape of an attacking dragon.  An occasional\n"+
    "tiny lick of flame from its mouth sets the whole clasp glittering brightly.\n");
  set_wear_mess("wear_room","&NAME& fastens &POSS& cloak with a clasp in the shape of a silver "+
                            "dragon.");
  set_wear_mess("wear_self","You fasten your cloak with the clasp.\n");
  set_wear_mess("remove_room","&NAME& unfastens &POSS& cloak clasp.\n");
  set_wear_mess("remove_self","You unfasten your cloak clasp.\n");
}
