/*** Missile spell spam Does around 112 points of damage around it is magical damage
if 'Magical is mitigated by normal armour I should change the damage type  ****/


inherit "/obj/monster";
#include "/players/jareel/define.h"
#define TO this_object()

object target;
int arrows;
int V;
int sword;
int necklace;
int sword;
int armor;
int stuff; 

  reset(arg)  { 
    stuff = random(32); 
    ::reset(arg);
  if (arg) return;
  set_name("Solaris");
  set_alias("solaris");
  set_alt_name("mage");
  set_race("human");
  set_al(-1000);
  set_level(23);

  set_aggressive(0);
  set_hp(2000);
  set_ac(1);
  set_wc(1);
  set_multi_cast(1); 
  set_gender("male");
  add_money(2000+random(1000));
  set_dead_ob(this_object());
  
if(stuff == 0) { /* Main Armor */ 
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageArmor.c"),this_object());
  set_armor_params("magical",0,75,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(60); /* Reflects the 10% res this armor adds when worn also this armor when worn by an arch mage of the Order provides the above 
                  additional protection/reflection */
  set_ac_bonus(30); /* Physical Resistance */				  
  }

if(stuff == 1){ /* Amulet */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageAmulet.c"),this_object());
  set_armor_params("magical",0,100,"prot_from_magical"); 
  set_armor_params("other|evil",0,-25,"protection_from_evil");
  set_armor_params("other|good",0,25,"protection_from_good"); /* counter to the other|evil praram */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); /* Reflects the res to Physical the Crater Maker Mages Possess */
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 2){ /* Belt */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageBelt.c"),this_object());
  set_armor_params("magical",0,25,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,25,"reflect_evil_attack");
  set_armor_params("other|good",0,50,"protection_from_good"); /* counter to the other|evil praram. */
  set_armor_params("other|fire",0,10,"protection_from_ice");
  set_armor_params("other|ice",0,10,"protection_from_fire");
  set_res(50);
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 3){ /* Boots */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageBoots.c"),this_object());
  set_armor_params("magical",0,100,"prot_from_magical"); 
  set_armor_params("other|evil",0,-10,"antiprotection_from_evil");
  set_armor_params("other|good",0,10,"antiprotection_from_good"); /* counter to the other|evil praram */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */  
  }

if(stuff == 4){ /* Bracelet */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageBracelet.c"),this_object());
  set_armor_params("magical",0,50,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,-25,"antiprotection_from_evil");
  set_armor_params("other|good",0,25,"protection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50);
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 5){ /* Bracer */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageBracer.c"),this_object());
  set_armor_params("magical",0,5,"prot_from_magical"); 
  set_armor_params("other|evil",0,100,"protection_from_evil");
  set_armor_params("other|good",0,-100,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */  
  }

if(stuff == 6){ /* Chest */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageChest.c"),this_object());
  set_armor_params("magical",0,75,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 7){ /* Cloak */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());    MOCO("/players/jareel/armor/mondar_armor.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageCloak.c"),this_object());
  set_armor_params("magical",0,75,"prot_from_magical"); 
  set_armor_params("other|evil",0,15,"protection_from_evil");
  set_armor_params("other|good",0,-15,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50);
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 8) { /* Earring */ 
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageEarring.c"),this_object());
  set_armor_params("magical",0,50,"prot_from_magical"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50);
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 9){ /* Gloves */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageGloves.c"),this_object());
  set_armor_params("magical",0,50,"prot_from_magical"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 10){ /* Misc */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageMisc.c"),this_object());
  set_armor_params("magical",0,50,"prot_from_magical"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 11){ /* Necklace */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageNecklace.c"),this_object());
  set_armor_params("magical",0,100,"prot_from_magical"); 
  set_armor_params("other|evil",0,-25,"antiprotection_from_evil");
  set_armor_params("other|good",0,25,"protection_from_good"); /* counter to the other|evil praram */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */  
  }

if(stuff == 12){ /* Pants */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMagePants.c"),this_object());
  set_armor_params("magical",0,50,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50);
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 13){ /* Ring */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing.c"),this_object());
  set_armor_params("magical",0,100,"prot_from_magical"); 
  set_armor_params("other|evil",0,-25,"antiprotection_from_evil");
  set_armor_params("other|good",0,25,"protection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50);
  set_ac_bonus(25); /* Physical Resistance */  
  }

if(stuff == 14){ /* Ring2 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing2.c"),this_object());
  set_armor_params("magical",0,50,"prot_from_magical"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 15){ /* Ring3 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing3.c"),this_object());
  set_armor_params("magical",0,100,"prot_from_magical"); 
  set_armor_params("other|evil",0,-25,"protection_from_evil");
  set_armor_params("other|good",0,25,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 16) { /* Ring4 */ 
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing4.c"),this_object());
  set_armor_params("magical",0,50,"prot_from_magical"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 17){ /* Ring5 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing5.c"),this_object());
  set_armor_params("magical",0,75,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,25,"protection_from_evil");
  set_armor_params("other|good",0,-25,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 18){ /* Ring5 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing5.c"),this_object());
  set_armor_params("magical",0,90,"prot_from_magical"); 
  set_armor_params("other|evil",0,10,"protection_from_evil");
  set_armor_params("other|good",0,-10,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 19){ /* Ring6 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing6.c"),this_object());
  set_armor_params("magical",0,50,"prot_from_magical"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 20){ /* Ring6 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing6.c"),this_object());
  set_armor_params("magical",0,50,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50);
  set_ac_bonus(25); /* Physical Resistance */  
  }

if(stuff == 21){ /* Ring7 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing7.c"),this_object());
  set_armor_params("magical",0,50,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50);
  set_ac_bonus(25); /* Physical Resistance */  
  }

if(stuff == 22){ /* Ring7 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing7.c"),this_object());
  set_armor_params("magical",0,100,"prot_from_magical"); 
  set_armor_params("other|evil",0,-25,"antiprotection_from_evil");
  set_armor_params("other|good",0,25,"protection_from_good"); /* counter to the other|evil praram */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */  
  }

if(stuff == 23){ /* Ring8 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing8.c"),this_object());
  set_armor_params("magical",0,5,"prot_from_magical"); 
  set_armor_params("other|evil",0,100,"protection_from_evil");
  set_armor_params("other|good",0,-100,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */  
  }

if(stuff == 24) { /* Ring8 */ 
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing8.c"),this_object());
  set_armor_params("magical",0,50,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50);
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 25){ /* Ring9 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing9.c"),this_object());
  set_armor_params("magical",0,75,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 26){ /* Ring9 */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageRing9.c"),this_object());
  set_armor_params("magical",0,50,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,-25,"antiprotection_from_evil");
  set_armor_params("other|good",0,25,"protection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50);
  set_ac_bonus(25); /* Physical Resistance */   
  }

if(stuff == 27){ /* Underware */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageUnderware.c"),this_object());
  set_armor_params("magical",0,75,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_evil");
  set_armor_params("other|ice",0,10,"protection_from_evil");
  set_res(60); /* Reflects the 10% res this armor adds when worn also this armor when worn by an arch mage of the Order provides the above 
                  additional protection/reflection */
  set_ac_bonus(30); /* Physical Resistance */  
  }

if(stuff == 28){ /* NotoxHeals */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageArmor.c"),this_object());
  set_armor_params("magical",0,5,"prot_from_magical"); 
  set_armor_params("other|evil",0,100,"protection_from_evil");
  set_armor_params("other|good",0,-100,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_fire");
  set_armor_params("other|ice",0,10,"protection_from_ice");
  set_res(50); 
  set_ac_bonus(25); /* Physical Resistance */  
  }

if(stuff == 29){ /* Staff */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageArmor.c"),this_object());
            
		set_armor_params("magical",0,50,"magic_deflect"); 
        set_armor_params("other|evil",0,50,"evil_deflect");
        set_armor_params("other|good",0,50,"good_deflect");
        set_armor_params("other|fire",0,50,"fire_deflect");
        set_armor_params("other|ice",0,50,"ice_deflect");
        set_armor_params("other|sonic",0,50,"sonic_deflect"); 
        set_armor_params("other|mental",0,50,"mental_deflect");
        set_armor_params("other|electric",0,50,"electric_deflect");
        set_armor_params("other|wind",0,50,"wind_deflect");
        set_armor_params("other|earth",0,50,"earth_deflect");
        set_armor_params("other|dark",0,50,"dark_deflect"); 
        set_armor_params("other|light",0,50,"light_deflect");
        set_armor_params("other|water",0,50,"water_deflect");
        set_armor_params("other|poison",0,50,"poison_deflect");
        set_armor_params("other|laser",0,50,"laser_deflect");
        set_res(50); 
        set_ac_bonus(25); /* Physical Resistance */  
    }

if(stuff == 30){ /*  */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageArmor.c"),this_object());
  set_armor_params("magical",0,75,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_evil");
  set_armor_params("other|ice",0,10,"protection_from_evil");
  set_res(60); /* Reflects the 10% res this armor adds when worn also this armor when worn by an arch mage of the Order provides the above 
                  additional protection/reflection */
  set_ac_bonus(30); /* Physical Resistance */   
  }

if(stuff == 31){ /*  */
  MOCO("/players/jareel/heals/LUNAR/cratermaker/solaris/bag2.c"),this_object());
  MOCO("/players/jareel/armor/cratermaker/solaris/ArchMageArmor.c"),this_object());
  set_armor_params("magical",0,75,"reflect_magic_attack"); 
  set_armor_params("other|evil",0,50,"protection_from_evil");
  set_armor_params("other|good",0,-50,"antiprotection_from_good"); /* counter to the other|evil praram...however is more an fu to mages */
  set_armor_params("other|fire",0,10,"protection_from_evil");
  set_armor_params("other|ice",0,10,"protection_from_evil");
  set_res(60); /* Reflects the 10% res this armor adds when worn also this armor when worn by an arch mage of the Order provides the above 
                  additional protection/reflection */
  set_ac_bonus(30); /* Physical Resistance */  
  }

  set_short("Solaris - "+RED+"["+NORM+BOLD+"Arch Mage"+NORM+RED+"] "+BOLD+HIK+"Order of the "+NORM+RED+"Crater Makers"+NORM+" (Black Knight) ");
  set_long(
      "Solaris is an old silver-haired, wrinkled, weathered warrior.  His powerful aura has\n"+
      "has been slashed and empowered by lunar and demonic energy emanating from his soul.  Evil\n"+
      "haunting death rid-in soulless eyes pierce through your soul as his gaze catches you \n"+
      "looking at him.  Engaging this mere mortal may not be the wisest move one has ever made.\n");

add_spell(
    "Meteor Storm",
	"\nSolaris "+HIC+"channels"+NORM+" a beam of energy up into the sky....\n",
    "\nSolaris "+HIC+"channels"+NORM+" a beam of energy up into the sky....\n\n",
    100,"1d2","magic");	  
	
   add_spell(
    "light hit",
	"\nLightning flashes across the sky and deadly bolts of energy leap\n\
    from Solaris's fingertips and streak through the air at #TN#!\n",
    "\nLightning flashes across the sky and deadly bolts of energy leap\n\
    from Solaris's fingertips and streak through the air at #TN#!\n",
    100,"1d4","magic",6);

   add_spell(
    "missile one",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    100,"5d4","magic",6);
  
   add_spell(
    "missile two",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    90,"3d4","magic",6);
  

  
   add_spell(
    "missile five",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    60,"5d4","magic",6);
  
   add_spell(
    "missile six",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    50,"3d4","magic",6);
  
   add_spell(
    "missile seven",
	"Solaris's missile "+HIC+"grazes"+NORM+" #TN#.\n",
    "Solaris's missile "+HIC+"grazes"+NORM+" #TN#.\n",
    45,"1d2","magic",6);

  
   add_spell(
    "missile nine",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    30,"5d4","magic",6);
  
   add_spell(
    "missile ten",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    30,"3d4","magic",6);
  
   add_spell(
    "missile eleven",
	"Solaris's missile "+HIC+"grazes"+NORM+" #TN#.\n",
    "Solaris's missile "+HIC+"grazes"+NORM+" #TN#.\n",
    25,"1d2","magic",6);
  
   add_spell(
    "missile thirteen",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    100,"5d4","magic",6);
  
   add_spell(
    "missile fourteen",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    10,"3d4","magic",6);
  
   add_spell(
    "missile fifteen",
	"Solaris's missile "+HIC+"grazes"+NORM+" #TN#.\n",
    "Solaris's missile "+HIC+"grazes"+NORM+" #TN#.\n",
    35,"1d2","magic",6);

   add_spell(
    "missile seventeen",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    70,"5d4","magic",6);
  
   add_spell(
    "missile eighteen",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    5,"3d4","other|magical",6);
  
   add_spell(
    "missile nineteen",
	"Solaris's missile "+HIC+"grazes"+NORM+" #TN#.\n",
    "Solaris's missile "+HIC+"grazes"+NORM+" #TN#.\n",
    45,"1d2","other|magical",6);


   add_spell(
    "missile twentyone",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    35,"5d4","other|magical",6);
  
   add_spell(
    "missile twentyonetwo",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    25,"3d4","other|magical",6);
  
 	
	   add_spell(
    "light hittwo",
	"\nLightning flashes across the sky and deadly bolts of energy leap\n\
    from Solaris's fingertips and streak through the air at #TN#!\n",
    "\nLightning flashes across the sky and deadly bolts of energy leap\n\
    from Solaris's fingertips and streak through the air at #TN#!\n",
    100,"1d4","other|magical",6);

   add_spell(
    "missile onetwo",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    100,"5d6","other|magical",6);
  
   add_spell(
    "missile twotwo",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    90,"3d6","other|magical",6);
  
   add_spell(
    "missile threetwo",
	"Solaris's missile "+HIC+"grazes"+NORM+" #TN#.\n",
    "Solaris's missile "+HIC+"grazes"+NORM+" #TN#.\n",
    85,"1d16","other|magical",6);
  
   add_spell(
    "missile onetwo",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    60,"5d6","other|magical",6);
  
   add_spell(
    "missile twotwo",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    50,"3d6","other|magical",6);
  

  
   add_spell(
    "missile onetwo",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    30,"5d6","other|magical",6);
  
   add_spell(
    "missile twotwotwo",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    30,"3d6","other|magical",6);
  
  
   add_spell(
    "missile twotwoone",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    100,"5d6","other|magical",6);
  
   add_spell(
    "missiletwo two",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    10,"3d6","other|magical",6);
  
	
   add_spell(
    "missiletwotwo one",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    20,"5d4","other|magical",6);
  
   add_spell(
    "missiletwotwo two",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    35,"3d6","other|magical",6);
  

   add_spell(
    "missile onefour",
	"Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    "Solaris's missile flies straight into #TN#. , a "+RED+"direct"+NORM+" hit!\n",
    33,"5d4","other|magical",6);
  
   add_spell(
    "missile twofour",
	"Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    "Solaris's magic missile "+HIR+"hits"+NORM+" #TN#.\n",
    5,"3d6","other|magical",6);
  

	
   add_spell(
    "Greater Crater",YEL+"\n\t                  ____ (  (    )   )  ___\n\
                         ("+RED+"(  "+NORM+"( "+BOLD+" )   _  "+NORM+YEL+" "+RED+" )) "+NORM+" )"+BOLD+"   )\n\
                      "+NORM+YEL+" ("+NORM+"(     (   "+BOLD+")(   "+RED+" )  )   "+NORM+"(   )"+NORM+YEL+"  )\n\
    Meteors impact    ((  ( _(   )   (   _) ) "+NORM+"( "+RED+" ("+BOLD+") ) "+NORM+YEL+" )\n\
                    ( (  ( (_)   ((    (   )   ((_ )    )_\n\
                   ( (  )    (      (  )    )   )   ) (   )\n\
                  (  "+NORM+"(   ( "+BOLD+"(   ) (  _ "+NORM+YEL+" ( _) ).  )  0 ) ) ( )\n\
                  ( (  (   ) ( "+RED+" )   ( "+NORM+" ))  "+NORM+YEL+"   ) _)(   "+NORM+")  "+BOLD+")  "+NORM+YEL+")\n\
                 ( "+NORM+"(  ( "+BOLD+"\ ) (    (_  ( ) "+NORM+YEL+"( )  )   ) )  )) ( )\n\
                  (  (   (  (   (_ ( ) ( _    )  ) ( "+NORM+" ) "+BOLD+" )  "+NORM+YEL+" )\n\
                 ( "+RED+"( "+NORM+" ( ( "+BOLD+" (  )     "+NORM+YEL+"(_ "+NORM+")  )"+BOLD+" )  _)   ) "+RED+"_( ("+NORM+YEL+" )\n\
                  ((  (   )(    (     _    )   _) _(_ (  (_ )\n\
                   (_((__(_"+RED+"(__(( ( "+NORM+"( | "+BOLD+" ) ) )"+NORM+YEL+" )_))_"+NORM+"_)"+BOLD+")_)__"+NORM+YEL+"_)\n\
                   ((__)         ||lll|l||   )            _))\n\
                             (   (  (  )  ) )    )\n\
                            (  ( ( ( | | ) ) )    )\n\
                       oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOo \n"+NORM,
	
    YEL+"\nMeteors Impact the Earth"+NORM+"\n",
    33,"60-90+60","other|earth",1); /* The Spell that Makes the Man */
	
      load_chat("Solaris says:  I shall find the real '"+HIK+"Cacodeamon"+NORM+"' on the '"+HIR+"HeroPlane"+NORM+"' before Morgus and harness his power for the "+RED+"Red Godess"+NORM+"!\n");
      load_chat("Solaris says:  We will ride the "+RED+"Crimson"+NORM+" Bat into battle and destroy the Orlanthi!\n");
  }

status players_attacking_me(object ob) {
  return ob->is_player() && (object)ob->query_attack()==this_object();
}

mixed get_random_attacker() {
  int s;
  object *targets;
#ifndef __LDMUD__ 
    targets=filter_array(all_inventory(environment()),"players_attacking_me",this_object());
#else
    targets = filter(all_inventory(environment()), "players_attacking_me", this_object());
#endif
  s = sizeof(targets);
  tell_room( environment(), "Size of attackers is: "+s+"\n");
  if( s < 1 )
    return 0;

  return targets[ random(s) ];
}

reflect_magic_attack(object who, int dam){   
  object target;

  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"magic"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"Energy"+NORM+" shield.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's Energy shield!!!\n");
      target->hit_player( dam, "magical" ); 
    }
  }
  return 1;
} 

magic_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"magic"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's magic block!!!\n");
	this_player()->hit_player( dam, "magical" ); 
    }
  }
  return 1;
} 

evil_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"evil attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|evil" ); 
    }
  }
  return 1;
} 

good_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"good attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|good" ); 
    }
  }
  return 1;
} 

fire_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"fire attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|fire" ); 
    }
  }
  return 1;
}

ice_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"ice attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|ice" ); 
    }
  }
  return 1;
}  

sonic_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"sonic attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|sonic" ); 
    }
  }
  return 1;
} 

mental_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"mental attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|mental" ); 
    }
  }
  return 1;
} 

electric_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"electric attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|electric" ); 
    }
  }
  return 1;
} 

wind_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"wind attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|wind" ); 
    }
  }
  return 1;
} 

earth_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"earth attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|earth" ); 
    }
  }
  return 1;
} 

dark_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"dark attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|dark" ); 
    }
  }
  return 1;
} 

light_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"light attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|light" ); 
    }
  }
  return 1;
} 

water_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"water attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|water" ); 
    }
  }
  return 1;
} 

poison_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"poison attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|poison" ); 
    }
  }
  return 1;
} 

laser_deflect(object who, int dam){   
   object target;
   
  if( this_player() ) {
    tell_room( environment(TO), this_player()->query_name()+"'s "+HIM+"laser attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
    target = get_random_attacker();
    if( target ) {
      tell_room( environment(TO), "            "+target->query_name()+" is jolted by the flashback off of Solaris's spinning staff block!!!\n");
	this_player()->hit_player( dam, "other|laser" ); 
    }
  }
  return 1;
} 

  prot_from_magical(){
    tell_room(environment(TO),attacker_ob->query_name()+"'s "+HIM+"magical attack"+NORM+BOLD+BLINK+" sparks"+NORM+" off Solaris's "+BLU+"Energy"+NORM+" shield.\n"+NORM);
  return 1;
}

  antiprotection_from_evil(){
    tell_room(environment(TO),attacker_ob->query_name()+"'s "+HIK+"evil"+NORM+BOLD+" spell"+NORM+" rips into Solaris, tearing apart his soul.\n"+NORM);
   return 1;
}

  antiprotection_from_good(){
    tell_room(environment(TO),attacker_ob->query_name()+"'s "+HIK+"evil"+NORM+BOLD+" spell"+NORM+" rips into Solaris, tearing apart his soul.\n"+NORM);
   return 1;
}

  protection_from_evil(){
    tell_room(environment(TO),attacker_ob->query_name()+"'s "+HIK+"evil"+NORM+BOLD+" spell"+NORM+" absorbs into Solaris body empowering his soul.\n"+NORM);
   return 1;
}

  protection_from_good(){
    tell_room(environment(TO),attacker_ob->query_name()+"'s "+HIK+"evil"+NORM+BOLD+" spell"+NORM+" absorbs into Solaris body empowering his soul.\n"+NORM);
   return 1;
}



init() {
  ::init();
  if( this_player() && this_player() == attacker_ob ) {
    tell_room(environment(), HIBLK+"\n\n\n\nSolaris turns to attack "+this_player()->query_name()+"!\n"+NORM);
    this_player()->do_damage( ({random(250) }), ({"magical"}));
  }
}

heart_beat() {
    
  ::heart_beat();
  
  if( attacker_ob ) {
    if( !target || target != attacker_ob )
      arrows = 14 + random(4);
    target = attacker_ob;
  }
  
  if( target && arrows > 0 && find_call_out("range_attack") == -1 ) {
    range_attack();
  }
}

/******************************************************************************
 * Func:    do_range_damage
 * Created: June 9th, 2013 by Dragnar Adjusted by Jareel For Wimpy Players
 *
 * Purpose: Called by the rage_attack function.  Sets the messages and 
 *          determines damage done by ranged arrows.  Damage is based on luck,
 *          higher luck means less chance of a more vital area being hit, and
 *          also the severity of the hit.
 ******************************************************************************/
do_range_damage() {
  string msg, msg1;
  int dam, luck;
  
  if( !target || !environment(target) )
    return;
    
  luck = target->query_attrib( "luc" );
  
  switch( random(luck/4) ) {
    case 0:
      msg = HIM+"eye"+NORM;
      dam = 65;
      break;
    case 1:
      msg = HIY+"neck"+NORM;
      dam = 55;
      break;
    case 2:
      msg = HIC+"chest"+NORM;
      dam = 45;
      break;
    case 3:
      msg = HIB+"thigh"+NORM;
      dam = 40;
      break;
    case 4:
      msg = YEL+"shoulder"+NORM;
      dam = 25;
      break;
    default:
      msg = GRY+"foot"+NORM;
      dam = 20;
      break;
  }
  
  switch( random(luck/4) ) {
    case 0:
      msg1 = HIR+"flies straight"+NORM+" to the"+NORM;
      dam += 35;
      break;
    case 1:
      msg1 = HIR+"hits"+NORM;
      dam += 30;
      break;
    case 2:
      msg1 = HIR+"hits penetrating "+NORM+NORM;
      dam += 25;
      break;
    case 3:
      msg1 = HIR+"punctures"+NORM+" deep to"+NORM;
      dam += 20;
      break;
    case 4:
      msg1 = RED+"penetrates"+NORM+" deep to"+NORM;
      dam += 15;
      break;
    case 5:
      msg1 = RED+"hits"+NORM;
      dam += 10;
    default:
      msg1 = "grazes";
      dam += 5;
      break;
  }
  
  tell_object( target, "Solaris magic missile "+msg1+" the "+msg+"!!!\n");
  tell_room(environment(target), target->query_name()+" magic missile "+msg1+" in the "+msg+" by an magic missile fired by Solaris!\n", ({target}) );
  target->hit_player( dam, "magical" ); 
}

/******************************************************************************
 * Func:    range_attack
 * Created: June 9th, 2013 by Dragnar
 *
 * Purpose: Initially called by HB, then call_out as long as mob still has 
 *          arrows to fire.  This attack will do damage to a player that has
 *          attacked this mob, but now is in an adjoining room.  This can happen
 *          if the player runs or wimpies, but also the "range_attack" spell
 *          will cause mob to "wander" and move out of the room.  Attack is 
 *          deadly because of the massive damage arrows can do as well as the
 *          high heal rate of this mob.  If the player moves 2 rooms away the
 *          range attacks will stop.
 ******************************************************************************/
range_attack() {
  int idx;
  object targ, my_env;
  string room_path;
  string *dest_dir;
  
  if( !target ) {
    return;
  }
  
  my_env = environment();
  
  if( my_env && target &&  !present(target) && arrows > 0 ) {
    targ = environment( target );
    dest_dir = my_env->query_dest_dir();
    
    if( targ )
      room_path = file_name( targ );

    /** Ensure sure room_path is absolute **/
    if( room_path[0..0] != "/" )
      room_path = "/" + room_path;
    
    if( room_path && ( idx = member_array(room_path, dest_dir) ) >= 0 ) {
    
      tell_room(my_env, "Solaris fires a magic missile "+dest_dir[idx+1]+" at "+capitalize(target->query_name())+".\n");
      
      /** Ghost check **/
      if( target->query_ghost() ) {
        tell_object( target, "A magic missile passes right through your incorporeal form!\n");
        target = 0;
      }
      else {
        do_range_damage();
      }
      
      arrows -= 1;
      if( arrows < 1 ) {
        tell_room(my_env, "Lightning jumps off of Solaris's finger tips as missiles fly from his hands.\n" );
        target = 0;
      }
    }
    else {
      tell_object( target, "Solaris fires another missile at you but you are just out of range.\n");
      target = 0;
    }
  }
  if( target ) {
    call_out("range_attack", 3+random(3));
  }
}
