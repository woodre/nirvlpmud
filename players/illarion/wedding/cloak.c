inherit "/players/illarion/obj/clothes";

void reset(status arg) {
  if(arg) return;

  set_id("cloak");
  set_short("A `BLACK`midnight `blue`blue`off` cloak shot through with `WHITE`s`white`i`BLACK`lv`white`e`WHITE`r`off` threads");
  set_long("A floor-length cloak of deepest midnight blue velvet, shot \n"+
           "through with silver strands that catch the light.  The lining is\n"+
           "a lighter blue, made of shimmering satin that plays with the\n"+
           "light like a rippling pond.\n");
  set_wear_mess("wear_room","&NAME& fastens a long midnight blue cloak around &POSS& neck.");
  set_wear_mess("remove_room","&NAME& unfastens the cloak from around &POSS& neck, and removes it.");
  set_move_emote("self","As you move, the silver threading of your cloak "+
                        "catches and throws the light.\n");
  set_move_emote("room","A bit of light glints into your eye, reflected from "+
                        "&NAME&'s cloak.\n");
}
