/* Ice Scourge - Legendary Weapon of the Dark Sembraki */
/* Mob Should Be a Long Fight a Ranger Train would be the best way to kill this mob */

inherit "/obj/monster";
#include "/players/jareel/define.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("dark sembrak");
  set_alt_name("sembrak");
  set_gender("demon");
  set_race("chaos");
  set_level(27);  /*Xp Value 531360*/
  set_heal(25,2);
  set_wc(105);
  set_aggressive(1);
  set_hp(2500);  
  set_al(-1000);
  add_money(12500+random(20000));
  set_res(20);
  set_ac_bonus(20); /* Bonus From a 20% Res */ 
  set_ac(25);
  set_multi_cast(1);  /* Xp is Not Increased for Multi-Cast */

            set_armor_params("magical",0,100,"prot_from_magical"); 
            set_armor_params("other|evil",0,100,"protection_from_evil");
            set_armor_params("other|good",0,100,"antiprotection_from_good");
            set_armor_params("other|fire",0,100,"protection_from_fire");
            set_armor_params("other|ice",0,100,"protection_from_ice");
            set_armor_params("other|sonic",0,100,"prot_from_sonic"); 
            set_armor_params("other|mental",0,100,"protection_from_mental");
            set_armor_params("other|electric",0,100,"protection_from_electric");
            set_armor_params("other|wind",0,100,"protection_from_wind");
            set_armor_params("other|earth",0,100,"protection_from_earth");
            set_armor_params("other|dark",0,100,"prot_from_dark"); 
            set_armor_params("other|light",0,100,"protection_from_light");
            set_armor_params("other|water",0,100,"protection_from_water");
            set_armor_params("other|poison",0,100,"protection_from_fire");
            set_armor_params("other|laser",0,100,"protection_from_laser");			
			
			
set_short(
    
	    "The legendary "+HIK+"Dark "+NORM+CYN+"Sembrak"+NORM+" of "+HIC+"Ice"+NORM);

set_long(

        "Among the most feared and deadly creatures in this realm, the Sembrak is one of the\n"+
        "three greater Dark Demons.  It's skin is a black, whale-like, smooth, surface.  Huge\n"+
        "unpleasant horns that curve into each other adorn the demons head.  Bat-like wings\n"+
        "that make no sound as they flap tower from the demons back.  Ugly prehensile paws, and\n"+
        "a barbed tail lash out needlessly and disquietingly. The Sembrak's face, or where it's\n"+
        "face should be, only a suggestive blackness prevails.  With a shield in one hand and a\n"+
        "blood dripping scourge in the other, a death will occur.\n");

		
add_spell(
    "Random ScourgeSlash",
	  "The legendary "+HIK+"Dark "+NORM+CYN+"Sembrak"+NORM+" of "+HIC+"Ice"+NORM+" Scourge sends\n\
      shards of deadly "+HIC+"ice"+NORM+" slashing at #TN#!\n",
      "The legendary "+HIK+"Dark "+NORM+CYN+"Sembrak"+NORM+" of "+HIC+"Ice"+NORM+" scourge sends\n\
      shards of deadly "+HIC+"ice slashing at #TN#!\n",
    20,"8d4","other|ice", 6, "blow_back" ); /* 8 - 32 Damage Random Party Player*/

add_spell(
    "Random Scourgeimp",
	  ""+HIC+"Ice"+NORM+" flies from the Sembraks Scourge impaling #TN#!!!!!\n",
	  ""+HIC+"Ice"+NORM+" flies from the Sembraks Scourge impaling #TN#!!!!!\n",
    20,"8d4","other|ice", 6, "blow_back" ); /* 8 - 32 Damage Random Part Player*/

add_spell(
    "Random Scourgepummel",
	  "The "+HIK+"Dark"+NORM+" Sembrak Pummels #TN# with its Scourge!!!\n",
	  "The "+HIK+"Dark"+NORM+" Sembrak Pummels #TN# with its Scourge!!!\n",
    20,"8d4","other|ice", 6, "blow_back" ); /* 8 - 32 Damage Random Parth Player*/

add_spell(
    "Random Scourgestrike",
	  "The "+HIK+"Dark"+NORM+" Sembrak strikes #TN# with its vicious blow!!!\n",
	  "The "+HIK+"Dark"+NORM+" Sembrak strikes #TN# with its vicious blow!!!\n",
    20,"8d4","other|ice", 6, "blow_back" ); /* 8 - 32 Damage Random Parth Player*/

add_spell(
    "Random Scourgestab",
	  "The "+HIK+"Dark"+NORM+" Sembrak strikes #TN# with its vicious blow!!!\n",
	  "The "+HIK+"Dark"+NORM+" Sembrak strikes #TN# with its vicious blow!!!\n",
    20,"8d4","other|ice", 6, "blow_back" ); /* 8 - 32 Damage Random Parth Player*/
}
		
init() {
    ::init();
      if( this_player() && this_player() == attacker_ob ) {
        tell_room(environment(), HIBLK+"\n\nThe Legendary Dark Sembrak turns to crush "+this_player()->query_name()+" with his Scourge!\n"+NORM);
          this_player()->do_damage( ({random(200) }), ({"other|Jareel"}));
    }
}

blow_back( object target, object room, int damage ) {
  /** Code borrowed from Zeus' Ani Dragnar Master Ninja Cause well it is cool**/
  int ran1, i;
  string str;
  object wall;
  string *the_dirs;
  
  if( room && target && damage - target->query_attrib( "str" ) > 2  ) { /* Damage on Spells is 8 - 32 average Str Stat is 30 gives this a very rare spawn time */
    wall = present( "clan_wall_blocker_obj" );
    
    the_dirs = (room->query_dest_dir());
    ran1 = random(sizeof(the_dirs)-1);
    i = ran1 / 2 * 2;
    str = the_dirs[i+1];
    str += "#";
    str += the_dirs[i];
    tell_room( room, "\n\n"+target->query_name()+" tries to recover but the force of the blow knocks them out of the room!\n" );
    
    if( wall ) {
      destruct( wall );
      tell_room( room, target->query_name()+" flies right through the wall shattering it to pieces!\n" );
      target->hit_player( 50 + random(50) - target->query_attrib( "luc") );
    }
    
    target->move_player(str);
    command( "look", target );
  }
}
