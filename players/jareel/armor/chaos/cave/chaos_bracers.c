#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())
#define NAME HIK+"Dark "+NORM+RED+"Cha"+HIR+"os "+HIK+"Greaves"+NORM
#define CCC HIK+"<("+HIR+"*"+HIK+")>"+NORM

string *Armor_pieces;
status Ghetto; /* Ghetto fix, based on speed bracers */
object Owner;

void
init()
{
  ::init();
  add_action("ghetto_it","ghetto_it");

  if (environment(this_object()) && this_player() == environment(this_object())) {

    Owner = this_player();
    call_out("do_shit", 1 + random(10));
  }
}
  
void
reset(status arg)
{

  ::reset(arg);
  if (arg)
    return;

  set_name("greaves");
  set_ac(0);
  set_value(1200);
  set_weight(1);
  set_type("bracelet");
  set_short(NAME);
  set_long(
    "\n"+
    "\n"+
    "\n"+
    "\n");

  /* Put the id's for your special armors required in here */

  Armor_pieces = ({ "chaos_armor", "chaos_amulet", "chaos_helm", "chaos_boots", "chaos_gloves", "chaos_chest", "chaos_shield", "chaos_misc", "chaos_pants", "chaos_ring", "chaos_underwear", "chaos_earring", "chaos_bracers", "chaos_necklace", "chaos_cloak", "chaos_belt" });
  }

status id(string arg) { return ( ::id(arg) || arg == "chaos_bracers" || arg == "greaves" || arg == "bracelet" || arg == "chaos greaves"); }

status check_full_set() {
  int i;

  if(!USER) return 0; /* verte, damn noobs, heh */
  i = sizeof(Armor_pieces);

  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);

    if (!t || !((status)t->query_worn()))
      return 0;
  }
  return 1;
}

string short() {

  if (check_full_set())
    return (NAME+"   ("+NORM+HIG+"Set of Chaos"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(NAME+"(worn)");

  return NAME;
}
void do_shit() {
  object hh;

    if(!environment(this_object())) return;

    while(remove_call_out("do_shit") != -1);
    call_out("do_shit",4+random(4));

    hh = environment(environment(this_object()));

    if (!check_full_set()) return;

    if (!((object)Owner->query_attack())) return;

    if(!hh) return;

    Ghetto = 1;
      command("ghetto_it", Owner);
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
 CCC+HIK+" With great speed your actions blur "+CCC+"\n");
  return 1;
}