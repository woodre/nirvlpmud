#include "../def.h"

object weapon, gob;
#define MAGEWEPS = ({ "knife", "dagger", "stick", "club", "staff", "mace", "morningstar", "hammer", "small", "blunt", });

int bonusing; /* verte */

set_mage_weapon_shadow(object obj)
{
  weapon = obj;
  gob = present("forbin_mage_object", environment(weapon));
  if(!environment(mage))
  {
    write("Error: User not defined.\n");
    return;
  }
  if(!gob)
  {
    write("Error: Guild object not found.\n");
    return;
  }
  shadow(weapon, 1);
}

remove_mage_weapon_shadow()
{
  weapon->unshadow();
  destruct(this_object());
  return 1;
}

wield(str)
{
  if(this_player()->query_weapon() == weapon)
    return 1;
  if(weapon->wield(str))
  {
    if(this_player()->query_guild_name() != "Mages" && 
      this_player()->query_level() < 21)
      {
        remove_mage_weapon_shadow(); 
        return 1;
      }
    if(!(gob = present("forbin_mage_object", this_player())))
    rm_bloodfist_wep_shadow();
    return 1; 
  }
}

/* function simulates mages' weakness when it comes to melee battle */
get_deduction()
{
  int deduction;
  
  deduction = 0;
  
  if(!weapon->id("forbin_mage_staff"))
    deduction -= 7;  /* -7 wc from the start, mages are weak fuckers */
                     /* any weapon by mage staff is lowered */
    
  switch(weapon->query_weight())  /* weight lessens mages ability */
  {
    case 0..1  : deduction -= 0; break;
    case 2     : deduction -= 1; break;
    case 3     : deduction -= 2; break;
    case 4..5  : deduction -= 3; break;
    case 6..10 : deduction -= 4; break;
    default    : deduction -= 5; break; 
  }

  if(weapon->id("forbin_mage_staff"))
    deduction += 2;  /* add back weight deduction if mage staff, no penalty */   
  
  /* casting spell, can't concentrate on hitting something too */
  if(environment(weapon)->query_casting()) 
    deduction -= 1;  

  if(index(MAGEWEPS, weapon->query_type()) < 0)  /* mages fight better with */
    deduction -= (weapon->weapon_class() / 6);   /* small or blunt weapons */   

  return deduction; /* deduction to return */
}

stopwield()
{
  if(environment(weapon) != this_player()) return 0;
  bonusing = 0;
  return weapon->stopwield();
}

drop(silently)
{
  if(environment(weapon) != this_player()) return 0;
  return weapon->drop(silently);
}

xfer_special()
{
  call_other(environment(weapon), "stop_wielding");
  weapon->set_wielded(0);
  weapon->set_wielded_by(0);
  return 1;
}

hit(target) 
{
  
  int deduction;  
  
  if(!environment(weapon)->is_player()) return 0;
  if(!gob)
    gob = present("forbin_mage_object", environment(weapon));
  if(!gob)
  {
    write("Weapon error: Contact Forbin.\n");
    return 0;
  }

  deduction = get_deduction();

  if(weapon->query_hit_func())
    return (base + deduction + 
            call_other(weapon->query_hit_func(), "weapon_hit", target));

  return (base + deduction);
}

query_guild_bonus() { return "ForbinMageGuildWeaponBonus"; }

add_guild_bonus() 
{
  bonusing = 1;
}

remove_guild_bonus() 
{
 if(bonusing)
  stopwield();
}

