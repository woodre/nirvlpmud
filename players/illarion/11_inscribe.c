#include "/players/guilds/bards/def.h"

/*

Runes taken from Saber's plans for Bards 3.0

Dark              crysea    other|dark defense/offense
Lit/Light         soli      other|light defense/offense
Earth             japa      other|earth    "
Fire              jamo      other|fire     "
Water             jako      other|water    "
Lightning         libuske   other|electric "
Wind              yajika    other|wind     "
Disease           jusoli    other|poison   "
Shield            cry       physical defense (only works on armor)
Strike/Hit        juwe      physical offense (only works on weapons)
Knowledge         nojuko    not sure what this should do yet
Fight/Battle      ru        very small chance of extra hit/counterattack
Die/Drop          da        armor: heal based on current hp  weapon: tiny chance of instant death for weakened monster
*/

status main(string str) {
  string what,runes;
  object ob;
  
  status weapon;
  
  string type;
  int amt;
  string spec_func;
  int hits;

  if (spell(-200, 11, 100) == -1)
    return 0;
  if(!str || sscanf(str,"%s with %s",what,runes)!=2) 
    FAIL("Syntax: inscribe <object> with <rune>\n");
  ob=present(what,TP);
  if(!ob)
    FAIL("You must be holding the object you wish to inscribe runes upon.\n");
  if(!(weapon=(status)ob->query_weapon()) && !ob->query_armor())
    FAIL("You may only inscribe runes upon weapons and armor.\n");
  if(ob->query_enchantment("bard_runes"))
    FAIL("The item already has bardic runes inscribed upon it.\n");
/*  if(!GOB->check_rune(runes))
    FAIL("You do not know how to form that rune.\n"); */
  type="physical";
  amt=1+(BLVL)/3;
  hits=50+10*(BLVL);
  spec_func=0;
  switch(runes) {
    case "crysea":
      type="other|dark";
      break;
    case "soli":
      type="other|light";
      break;
    case "japa":
      type="other|earth";
      break;
    case "jamo":
      type="other|fire";
      break;
    case "jako":
      type="other|water";
      break;
    case "libsuke":
      type="other|electric";
      break;
    case "yajika":
      type="other|wind";
      break;
    case "jusoli":
      type="other|poison";
      break;
    case "cry":
      /* no effect if not armor */
      if(weapon) amt=0;
      break;
    case "juwe":
      /* no effect if not weapon */
      if(!weapon) amt=0;
      break;
    case "nojuko":
      amt=0;
      spec_func="knowledge_func";
      break;
    case "ru":
      amt=0;
      spec_func="battle_func";
      break;
    case "da":
      amt=0;
      spec_func="die_func";
      break;
    default:  /* nonsense runes don't do anything, but can still be inscribed */
      amt=0;
      break;
  }
  ob->add_enchantment("bard_runes","["+HIM+runes+NORM+"]",
  "Bardic Runes have been inscribed upon this item",weapon?amt:0,type,0,hits,
  spec_func,this_object(),weapon?0:amt);
  write("You inscribe the runes upon "+NAME(ob)+".\n");
  say(NAME(TP)+" inscribes some runes upon "+POSS(TP)+" "+NAME(ob)+"\n");
  return 1;
}
