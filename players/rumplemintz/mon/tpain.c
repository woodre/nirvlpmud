/*
 * T-Pain for I'm on a boat
 */

inherit "/obj/monster";

void reset(int arg){
  ::reset(arg);
  if(arg) return;
  set_name("T-Pain");
  set_race("human");
  set_alias("tpain");
  set_alt_name("t-pain");
  set_short("T-Pain");
  set_long("\
Faheem Rasheen Najm, better known by his stage name T-Pain, is an American \n\
hip hop and R&B singer-songwriter, and producer.  He began his career as \n\
a rapper in the group Nappy Headz.  In 2005, his debut album Rappa Ternt \n\
Sanga was released and spawned the hits I'm Sprung and I'm N Luv (Wit A \n\
Stripper).  Since the release of that album, T-Pain has produced numerous \n\
hits of his own and for other rappers and R&B singers.  T-Pain has also had \n\
over 10 top ten singles on the Billboard Hot 100.  In 2008, he won a Grammy \n\
with rapper Kanye West for the single Good Life.  He was rated #34 of the \n\
most influential people in the world on the 2009 Time 100 List.\n");
  set_level(11);
  set_al(-500);
}

