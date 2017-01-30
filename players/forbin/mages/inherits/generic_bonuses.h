#include "../def.h"

#define MAGEWEPS ({ "knife", "dagger", "stick", "club", "staff", "mace", "morningstar", "hammer", "small", "blunt", })

/* function simulates mages' weakness when it comes to melee battle */
int gen_wc_bonus()
{
  int deduction;
  object weapon;
   
  deduction = 0;
  
  if(!(weapon = (object)environment(this_object())->query_weapon()))
    return deduction;
  
  if(!weapon->id("forbin_mage_staff"))
  {
    deduction -= 7;  /* -7 wc from the start, mages are weak fuckers */
                     /* any weapon but mage staff is lowered */
    
    switch((int)weapon->query_weight())  /* weight lessens ability */
    {
      case 0..1 : break;
      case 2    : deduction -= 1; break;
      case 3    : deduction -= 2; break;
      case 4..5 : deduction -= 3; break;
      case 6..8 : deduction -= 4; break;
      default   : deduction -= 5; break; 
    }

  if(index(MAGEWEPS, (string)weapon->query_type()) < 0) /* mages fight better with */
    deduction -= ((int)weapon->weapon_class() / 6);     /* small or blunt weapons */     
  }
  
  /* casting spell, can't concentrate on hitting something too */
  if(environment(this_object())->query_casting()) 
    deduction -= 2;  

  return deduction; /* deduction in melee */
}

int gen_sp_bonus() /* mages get 30 additional sps per guild level and */
{                  /* 3 additional sps per point of the power attribute */
  int bonus;
  bonus = ((GuildLevel * 30) + (LPOW * 3));
  return bonus;
}

int query_sp_regen()
{
	int bonus;
	bonus = (1 + random(LPOW/15)); 
	return bonus;
}
