#define SHLEVEL         8
/*
#define TP     this_player()
*/
#ifndef IPTP
#define IPTP   present("shadow-mark", TP)
#endif
#ifndef TRN
#define TRN    capitalize((string)TP->query_real_name())
#endif
#define TPN    capitalize((string)TP->query_name())

/* version of cyber's hide-in-shadows for the shadow guild */


turn_to_shadow(string str)
{
  /* command to hide in shadows */
  object ob;
  if (!level_check(SHLEVEL)) {
     write("Your Shadow level is not high enough.\n");
     return 1;
  }
  if (TP->query_invis() && IPTP->query_shadows())
  {
    write("You are already in a shadowy form.\n");
    return 1;
  }
  if (TP->query_attack())
  {
    write("You cannot change successfully while fighting.\n");
    return 1;
  } 
  if (!less_pts(40)) return 1;
  TP->set_invs_sp();
  IPTP->set_shadows(1);
  IPTP->save_me();
  say(TPN + " becomes shadowy, disappearing into the shadows.\n");
  write("You take on a shadowy form.\n");
  return 1;
}
