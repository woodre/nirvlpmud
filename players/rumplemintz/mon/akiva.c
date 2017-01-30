/*
 * Akiva Schaffer for I'm on a boat
 */

inherit "/obj/monster";

void reset(int arg){
  ::reset(arg);
  if(arg) return;
  set_name("Akiva");
  set_alias("akiva");
  set_alt_name("akiva schaffer");
  set_race("human");
  set_short("Akiva Schaffer");
  set_long("\
Akiva is an American writer for Saturday Night Live, a fild director, an \n\
Emmy-winning songwriter, and a member of The Lonely Island, a sketch- \n\
comedy troupe that originated on the Internet, which includes SNL cast \n\
member Andy Samberg and SNL writer Jorma Taccone.  He majored in film at \n\
UC Santa Cruz.\n");
  set_level(11);
  set_al(-500);
}
