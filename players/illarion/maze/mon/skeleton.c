#include "/players/illarion/dfns.h"
inherit "obj/monster";

#define SOAK 10

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("skeleton");
  set_short("An animated skeleton");
  set_long(
      "There is nothing holding the bones of this skeleton together, and yet\n"+
      "it walks.  This is probably because of the dark energy that seems to\n"+
      "roll off of the dry, bleached bones in waves.\n");
  set_al(-200);
  /* basic vital statistics.  should be customized when cloned */
  set_hp(200);
  set_wc(15);
  set_armor_params("physical",10,0,"bladed_soak");
  set_ac_bonus(SOAK/5);
}

int bladed_soak(object me,int amt) {
  object att;
  object wep;
  string type;
  int reduced;
  att=this_player();
  if(!att || att == me) return 0;
  wep=(object)att->query_name_of_weapon();
  if(!wep) return 0;
  type=(string)wep->query_type();
  if(type=="sword" || type=="knife") {
    tell_object(att,"Your "+type+" doesn't seem very effective...\n");
    if(amt <= SOAK)
      return 10000;
    reduced=amt-SOAK;
    amt=100*reduced/amt;
    return (100-amt)*100;
  }
}
      
