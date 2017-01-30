/*
#define TP     this_player()
*/
#define IPTP   present("shadow-mark", TP)
#define TRN    capitalize((string)TP->query_real_name())


status return_from_shadow(string str)
{
  TP->visible();
  IPTP->set_shadows(0);
  IPTP->save_me();
  write("You return to normal from a shadowy form.\n");
  return 1;
}
