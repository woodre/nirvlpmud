/*
 *      File:                   /daemons/combat.c
 *      Function:               Tracks damage dealt/taken and time in combat
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2007 David Halek
 *                                      All Rights Reserved.
 *      Source:                 07/13/2007
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

inherit "/players/earwax/lib/waxfuns.c";

#define DEALT 0
#define TAKEN 1
#define TTIME 2
#define TANKT 3

/* Global Variables */
mapping AllInfo; /* ([ who: ({ dealt, taken, time }) ]) */

void twax(string arg) {
  object ob;

  ob = find_player("earwax");

  if (ob) tell_object(ob, HIC+"COMBATD: "+arg+NORM+"\n");
}

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

void add_entry(string name, int dealt, int taken, int ttime, int tankt)
{
  if (!AllInfo)
    AllInfo = ([name : ({ dealt, taken, ttime, tankt }) ]);
  else if (!member(AllInfo, name))
    AllInfo[name] = ({ dealt, taken, ttime, tankt });
  else
  {
    if (dealt) AllInfo[name][DEALT] += dealt;
    if (taken) AllInfo[name][TAKEN] += taken;
    if (ttime) AllInfo[name][TTIME] += ttime;
    if (tankt) AllInfo[name][TANKT] += tankt;    
  }
/*
  twax("add_entry... "+name+", dealt: "+dealt+", took: "+taken);
  twax(name + "/"+AllInfo[name][0]+"/"+AllInfo[name][1]);
*/
}

void add_combat_time(string who)
{
  add_entry(who, 0, 0, 1, 0);
}

/* 
 * Function name: do_damage
 * Description:   tracks damage dealt 
 * Arguments:     who it's from, who it's to, amount
 */

void do_damage(object obfrom, object obto, int amount)
{
  string from, to;
  
  from = (obfrom && (int)obfrom->is_player() ? (string)obfrom->query_real_name() : 0);
  to = (obto && (int)obto->is_player() ? (string)obto->query_real_name() : 0);
  if (from) add_entry(from, amount, 0, 0, 0);
  if (to) add_entry(to, 0, amount, 0, 0);
}

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

string divide(int num, int denom)
{
  string result;
  if (!denom) return "";

  result = ((num * 100) / denom) + "";
#ifndef __LDMUD__ /* Rumplemintz */
  return result[0..-3] + "." + result[-2..-1];
#else
  return result[0..<3] + "." + result[<2..<1];
#endif
}

string get_rating(int dealt, int taken, int hbs)
{
  string result;
  if (!taken || !hbs) return "";

  dealt -= taken;
  return divide(dealt, hbs);
}

mapping query_info() { return (AllInfo ? AllInfo : 0); }

void dump_info() {
  string *names;
  int i;

  if (!AllInfo) {
    write("No information to report at this time.\n");
    return;
  }
  names = m_indices(AllInfo);
  write("Format is Damage/Hbs, Damage/Taken,   Dealt/Taken/HBs in combat.\n");
  i = sizeof(names);
  while(i--) {
    write(pad(capitalize(names[i]), 13)
      + ralign(divide(AllInfo[names[i]][0], AllInfo[names[i]][2]), 6) /* DPHB */
      + ralign(divide(AllInfo[names[i]][0], AllInfo[names[i]][1]), 10) /* DPTaken */
      + ralign(get_rating(AllInfo[names[i]][0], AllInfo[names[i]][i], AllInfo[names[i]][2]), 10)
      + " ... "
      + AllInfo[names[i]][0]+"/"+AllInfo[names[i]][1]+"/"+AllInfo[names[i]][2]+"\n");
  }
}
