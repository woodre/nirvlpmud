inherit "/players/illarion/obj/clothes";

void reset(status arg) {
  if(arg) return;

  set_id("shirt");
  set_short("A loose-fitting `BLACK`black silk`off` poet shirt");
  set_long(
    "A loose-fitting poet shirt of the softest black silk, with laces at\n"+
    "the neck and the wrists.  The neck falls open in a V-shape, laces\n"+
    "hanging loose from their bindings.  The wrists of the voluminous\n"+
    "sleeves are tightly bound, wrapped in layers of silken strands.\n");
  set_wear_mess("wear_room",
    "&NAME& pulls on a black poet shirt and laces the sleeves.\n");
  set_wear_mess("wear_self",
    "You pull on the shirt and lace up the sleeves.\n");
  set_wear_mess("remove_room",
    "&NAME& unlaces &POSS& sleeves and removes &POSS& shirt.\n");
  set_wear_mess("remove_self",
    "You unlace the sleeves and remove your shirt.\n");
}
