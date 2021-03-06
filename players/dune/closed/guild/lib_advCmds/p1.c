#include "../DEFS.h"
#define LEVEL  2
#define DRAIN 10


status main(string str) { return 0; }


/* this function should have no return type in its declaration */
static_main(string str)
{
  object meat;
  int dmg;
  string name;

  if (!gotrank(TP, LEVEL))
  {
    write("Your neural processor does not support this feature.\n");
    return 1;
  }

  if ((string)IPTP->query_wepsync())
  {
    write("You have synchronized your weapon.\n"+
          "Thus, this command cannot be used independently.\n");
    return 1;
  }

  if(TP->query_spell_dam())
  {
    IPTP->add_spellscast();
    write("You are already powering.\n");
    return 1;
  }

  if (!gotsp(TP, DRAIN)) return 1;

  if (str)
  {
    meat = present(str, environment(TP));
    name = capitalize(str);
    if(!meat)
    {
      write("You cannot see [ "+str+" ] here.\n");
      return 1; 
    }
  }

  if (!str)
  {
    if(!TP->query_attack())
    {
      write("What do you want to power?\n");
      return 1; 
    }
    meat = (object)TP->query_attack();
    name = MEAN;
  }

  if (!meat || !present(meat, environment(TP)))
  {
    write("Your opponent is not here to fight.\n");
    return 1; 
  }

/* added by wocket */
  if(meat == TP)
  {
    write("It isn't wise to attack yourself\n");
    return 1;
  }

/* Spell damage.
   -2 for Renegade
   -5 for defense mode
   +1 for attack mode 
*/
  dmg = random(15) + 5;
  if(IPTP->query_nohonor()) dmg -= 2;
  if(IPTP->query_attack_mode() == 2) dmg -= 10;
  if(IPTP->query_attack_mode() == 1) dmg += 1;
  if(dmg < 0) dmg = 0;

  dmg *= 5; dmg /= 4;
  TP->add_sp(-10);
  TP->spell_object(meat, "Power Wield", dmg, 0,
    "A laser beam shoots from one of your eyes and cuts into "+name+".\n",
    "A laser beam shoots from one of "+TPN+
    "'s eyes and cuts into you!\n",
    "A laser beam shoots from one of "+TPN+
    "'s eyes and cuts into "+name+".\n");
  TP->set_spell_dtype("other|laser");

  return 1;
}
