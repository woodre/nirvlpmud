#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

void
RangerInit()
{
   if(previous_object()->QuerySkillLevel("armor") >= 2){
      previous_object()->AHiddenSkill("lamp","beck");
   }
   if(previous_object()->QuerySkillLevel("armor") >= 5){
     previous_object()->AHiddenSkill("marmor","beck",7);
     previous_object()->AHiddenSkill("rwear","beck");     
   }
}

void
RangerPower(string str, string Align) { }

int
QMax() { return 20; }

status
QRangerInfo() { return 1; }

status
RangerInfo(string str)
{
  write( "Armor is your physical protection against your enemy.\n\n\
Armor skills:\n\n\
  Suit                        1   (Your basic suit)\n"+
BOLD+RED+"  Lamp"+OFF+"                        2\n\
  Metallic Armor ("+BOLD+RED+"Marmor"+OFF+")     5\n"+
BOLD+RED+"  Rwear"+OFF+"                       5 (Type Scarf.)\n"+
BOLD+RED+"  Rwear"+OFF+"                       8 (Type Orb.)\n\
  Mega Battle Armor           9\n"+
BOLD+RED+"  Rwear"+OFF+"                      10 (Type Misc.)\n\
  Battle Warrior Armor       13\n"+
BOLD+RED+"  Rwear"+OFF+"                      15 (Type Amulet, Cloak.)\n\
  Animarium Armor            17\n\
  Battlizer Armor            20\n"+
BOLD+RED+"  Rwear"+OFF+"                      20 (Type Ring, Bracelet.)\n\n\
Prestige:\n"+
BOLD+RED+"  Rwear"+OFF+"                      20 (Type Belt.)\n\n\
Additional armor types are in the works.\n\n");
  return 1;
}

int
DefSkill(int level)
{
  level = (int) previous_object()->QuerySkillLevel("armor");
  return (1+(level/5));
}