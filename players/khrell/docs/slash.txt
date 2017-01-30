#include "/players/eurale/defs.h"
#include <ansi.h>


attack_slash(str) {
int success_chance, random_nbr, spell_damage, spell_cost;
object target_obj;
string spell_name, caster_msg, target_msg, room_msg;
string msg1, msg2, msg3;

if(TP->query_spell_dam()) return 1;

if (TP->query_ghost()) {
  write("You can't cast spells, you're dead...\n");
  return 1; }

if (str == TPRN) {
  write("You cannot attack this one...\n");
  return 1; }


if(!str && !TP->query_attack())
{
  write("Use: slash [<who>]\n");
  return 1;
}

if(!str)
  target_obj = TP->query_attack();

if(!target_obj)
  target_obj = present(str, ROOM);

if(!target_obj && !present(str, ROOM))
{
  write("You don't see "+str+" here.\n");
  return 1;
}

if(TPXL < 5 || TPGEXP < 670 ||

  TP->query_attrib("cha") < 20 || TP->query_attrib("dex") < 20 ||
  TP->query_attrib("sta") < 20 || TP->query_attrib("mag") < 20 ||
  TP->query_attrib("str") < 20 || TP->query_attrib("wil") < 20 ||
  TP->query_attrib("luc") < 20 || TP->query_attrib("ste") < 20 ||
  TP->query_attrib("pie") < 20 || TP->query_attrib("int") < 20) {
  write("You lack the skills necessary to use that ability.\n");
  return 1; }

if(TPBPTS < 2) {
  write("You lack the blood energy to attack in this manner.\n");
  return 1; }

PFANGS->add_BLOODPTS(-2);
  /* new code to switch over to spell_object */
spell_name = "slash";
spell_damage = random(33) + 12;
spell_cost = 25;

switch(spell_damage)
  {
    case 42..44: 
      msg1 = HIR+"SUNDER "+NORM;  
      msg2 = HIR+" SUNDERS "+NORM;
      break;
    case 38..41: 
      msg1 = HIR+"slash "+NORM;   
      msg2 = HIR+" slashes "+NORM;
      break;
    case 32..37: 
      msg1 = RED+"carve "+NORM;    
      msg2 = RED+" carves "+NORM;
      break;
    case 20..31: 
      msg1 = "cleave ";               
      msg2 = " cleaves ";
      break;
    case 14..19: 
      msg1 = "cut ";                  
      msg2 = " cuts ";
      break;
    case 12..13: 
      msg1 = "gash ";               
      msg2 = " gashes ";
      break;
  }

  switch(random(4))
  {
    case 0:
      msg3="chest, spraying"+RED+" blood"+NORM+" across the room ";
      break;
    case 1:
      msg3="arm, spinning them about";
      break;
    case 2:
      msg3="leg, knocking them to the ground";
      break;
    case 3:
      msg3="neck, leaving them coughing up"+RED+" blood"+NORM+";
      break;
  }
  
  
  tell_object(TP,
    "With vampiric speed you "+msg1+target_obj->query_name()+NORM+"'s "+msg3+".\n");

  tell_object(target_obj,
    "With vampiric speed "+TP->query_name()+msg2+"your "+msg3+".\n");

  tell_room(environment(TP),
    "With vampiric speed ""+TP->query_name()+msg2+target_obj->query_name()+NORM+"'s "+msg3+".\n"), ({ TP, target_obj }));
    

  TP->spell_object(target_obj, "slash", spell_damage, spell_cost,0,0,0); /*Got rid of msgs within spell_object()*/

  TP->set_spell_dtype("other|evil");
  return 1;     
}
