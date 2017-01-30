#include "/players/wocket/mages/def.h"
#include "/obj/user/one_chan.c"

#define FREEZE "/players/feldegast/obj/freeze.c"
#define CORPSE "/players/feldegast/mages/obj/sw_corpse.c"

inherit PAGE;

void reset(int arg) {
  if(arg) return;
  spell="spiritwalk";
  spell_short="Spiritwalk";
  spell_desc=
"  The spiritwalk spell is dangerous even by the reckoning of\n\
many accomplished sorcerors.  Too many stories abound about\n\
intrepid necromancers stepping across the threshold of death,\n\
never to be heard from again.  But for the truly accomplished,\n\
the spiritwalk spell can be a valuable reconaissance tool, and\n\
perhaps an intriguing glimpse at what will happen to us all\n\
eventually.  Note: The caster may step back into his or her\n\
corpse at any time by simply reincarnating.\n";
  time=3;
  size=8;
  spcost=200;
  hpcost=200;
  type = "necro";
}
int check_spell(object mage, string str) {
  return 1;
}
int cast_spell(object mage,string str) {

  tell_object(mage,
"You carefully slit your left wrist and let your blood drain out\n\
of your body.  You feel your life slowly draining away...\n");
  mage->remote_say(
mage->query_name()+" carefully slits "+mage->query_possessive()+" left wrist and slowly lets "+mage->query_possessive()+" blood drain\n\
out of "+mage->query_possessive()+" body.\n");
  move_object(FREEZE,mage);  
  call_out("spiritwalk1",4,mage);
}
void spiritwalk0(object mage) {
  chan_msg("Storm clouds gather and lightning flashes in the distance.\n","junk");
  call_out("spiritwalk1",3,mage);
}
void spiritwalk1(object mage) {
  object corpse;
  corpse=clone_object(CORPSE);
  corpse->set_name(mage->query_real_name());
  corpse->set_corpse_level(mage->query_level());
  mage->transfer_all_to(corpse);
  move_object(corpse,environment(mage));
  tell_object(mage,"You feel disoriented.\n");
  mage->second_life(1);
  mage->set_dead(2);
  call_out("spiritwalk2",4,mage);
}
void spiritwalk2(object mage) {
  destruct(present("freeze",mage));
  tell_object(mage,"You step up and look around.\n");
  command("look",mage);
  move_object(FREEZE,mage);  
  call_out("spiritwalk3",3,mage);
}
void spiritwalk3(object mage) {
  tell_object(mage,"\nYou have passed through death's door and into a state\n"+
                   "of pure spirit.\n");
  destruct(present("freeze",mage));
}
