/* master.c - master guild daemon for the bards
 *            created by illarion 6/2004
 */
 
/*
#include <ansi.h>
*/
#include "/players/guilds/bards/def.h"
 
string get_colored_instrument_name(string instr) {
  switch(lower_case(instr)) {
    case "cello": 
      return GRN+"Cello"+NORM;
    case "kazoo":
      return RED+"Kazoo"+NORM;
    case "harp": default:
      return HIR+"Harp"+NORM;
    case "flute":
      return HIG+"Flute"+NORM;
    case "fiddle":
      return HIY+"Fiddle"+NORM;
    case "lyre":
      return HIB+"Lyre"+NORM;
    case "horn":
      return HIM+"Horn"+NORM;
    case "mandolin":
      return HIC+"Mandolin"+NORM;
    case "lute":
      return HIW+"Lute"+NORM;
    case "violin":
      return HIR+"Violin"+NORM;
    case "bagpipes":
      return HIG+"Bagpipes"+NORM;
    case "recorder":
      return HIY+"Recorder"+NORM;
    case "guitar":
      return HIB+"Guitar"+NORM;
    case "drum":
      return HIM+"Drum"+NORM;
    case "pan pipes":
      return HIC+"Pan Pipes"+NORM;
    case "trumpet":
      return HIW+"Trumpet"+NORM;
    case "harpsicord":
      return HIR+"Harpsicord"+NORM;
    case "saxophone":
      return HIG+"Saxophone"+NORM;
    case "cowbell":
      return YEL+"Cowbell"+NORM;
    case "air guitar":
      return BOLD+"Air Guitar"+NORM;
  }
  return "broken instrument";
}

int check_spell(int cutoff_ali, int min_level, int sp_cost) {
  if(GOB->query_locked()) { 
    notify_fail("Your powers are frozen.\n");
    return -1;
  }
  if(TP->query_ghost()) {
    notify_fail("You must be alive to do that.\n");
    return -1;
  }
  if(ALI<cutoff_ali) {
    notify_fail(NOT_GOOD);
    return -1;
  }
  if(BLVL<min_level) {
    notify_fail(NOT_LEVEL); 
    return -1;
  }
  if(SPELL<sp_cost) {
    notify_fail(NOT_SP);
    return -1;
  }
  if((string)environment(TP)->realm() == "NM") { 
    notify_fail("Your power is gone here.\n");
    return -1;
  }
  return 1;
}

int check_attack_spell(int cutoff_ali, int min_level, int sp_cost, object ob) {
  if(check_spell(cutoff_ali, min_level, sp_cost) == -1)
    return -1;
  if(!ob) {
    notify_fail("That is not here.\n");
    return -1;
  }
  if(!living(ob)) {
    notify_fail("Your target must be alive.\n");
    return -1;
  }
  if(ob->is_player() && !(present("bard_obj", this_player())->query_pk_defense())) {
    notify_fail(NO_PK); 
    return -1;
  }
  return 1;
}
