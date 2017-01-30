/* Viable option for Warpstone, Shin Pads, BoS so not everyone has same gear */



#include "/players/jareel/define.h"
inherit "/obj/armor.c";
#define ATT USER->query_attack()
#define USER environment(this_object())
#define THUNDER HIY+"T"+HIB+"*"+HIY+"H"+HIB+"*"+HIY+"U"+HIB+"*"+HIY+"N"+HIB+"*"+HIY+"D"+HIB+"*"+HIY+"E"+HIB+"*"+HIY+"R"+NORM 

/* Global Variables */
string *Armor_pieces;
status Ghetto; /* Ghetto fix, based on speed bracers */
object Owner;

void
init()
{
  ::init();
  add_action("ghetto_it","ghetto_it");
}
  
void
reset(status arg)
{

  if (arg)
    return;

  ::reset(arg);

  set_name("orlanth bracers");
  set_ac(0);
  set_value(200);
  set_weight(1);
  set_type("bracelet");
  set_short(HIB+"Bracers"+NORM+" of "+THUNDER);
  set_long(
    "                      "+HIG+"Set of the Wind"+NORM+"\n"+
    "A swirling blue and white bracers shine with an eerie glow.  The \n"+
    "bracers fit over your forearm snuggly.  The bracers feel like they\n"+
    "would enable you to move very quickly.\n");

  /* Put the id's for special armors required here */
  Armor_pieces = ({ "orlanth_plate", "orlanth_bracers", "orlanth_vambraces" });

     }

status id(string arg) { return ( ::id(arg) || arg == "orlanth_bracers" || arg == "bracers" || arg == "thunder" || arg == "bracers of thunder"); }

status check_full_set() {
  int i;

  if(!USER) return 0;
  i = sizeof(Armor_pieces);

  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);

    if (!t || !((status)t->query_worn())) return 0;
  }
  return 1;
}

string short() {

  if (check_full_set())

    return (HIB+"Bracers"+NORM+" of "+THUNDER+NORM+BOLD+" ("+NORM+HIG+"Set of "+THUNDER+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())

    return(HIB+"Bracers"+NORM+" of "+THUNDER+NORM+" (worn)");

    return HIB+"Bracers"+NORM+" of "+THUNDER+NORM;
}

int do_special(object owner) {
  int i;
  object hh;

  i = random(15);

  if (!check_full_set()) return 0;

  if (i > 1) return 0;

  Ghetto = 1;

  command("ghetto_it", owner);
 
  return 1;
}

int ghetto_it() {
  object wep, att, me;

  if (!Ghetto)
    return 1;

  Ghetto = 0;

  me = this_player();
  att = (object)me->query_attack();
  wep = (object)me->query_weapon();

  if (!att)
    return 1;

  me->toggle_already_fight(1);
  me->attack();

  if (wep)
    wep->hit(att);

tell_room(environment(me), 
 ""+BOLD+" <"+BLU+"<>"+NORM+BOLD+">"+BLU+" Rushing wind surounds "+me->query_name()+"'s body "+NORM+BOLD+" <"+BLU+"<>"+NORM+BOLD+">\n"+NORM);
  return 1;
}
