/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     Random mob creation for miscellaneous mobs in area
//  Create Date:  2004.01.26
//  Last Edit:    2004.07.30 -Forbin
//  Notes:        Adapted from: 
//                  /players/vertebraker/swamp/NPC/beast.c
//                  Orignal Copyright (c) 2000 Vertebraker@Nirvana
//  Notable Changes:  
//    2004.07.27 -changed ratios of mob cloning
//    2004.07.30 -added id of ff_mob          
*/ 

#include "/players/forbin/realms/flame_forest/ffdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

int Destruct_Corpse;  /* Does corpes destruct or not */
int Thermal_Wraith;   /* Is the mob a Thermal Wraith */
string Death_Chat;    /* Room emote at mob death */
string Prize;         /* Reward object */

id(str) { return (::id(str) || str == "ff_mob"); }
   
reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_gender("creature");
  set_al(random(2001)-1000);   
  if(!random(3)) set_wander((30+random(60)), (!random(4) ? 1 : 0), ({}));
  set_heart_beat(2);
  set_chat_chance(5);
  set_a_chat_chance(10);
  Thermal_Wraith = 0;
  switch(random(8)) {
    case 0..1: "/players/forbin/realms/flame_forest/NPC/forestmobbase.c"->smallmob(); break;
    case 2..3: "/players/forbin/realms/flame_forest/NPC/forestmobbase.c"->mediummob(); break;
    case 4..7: "/players/forbin/realms/flame_forest/NPC/forestmobbase.c"->largemob(); break; 
  }
  set_dead_ob(this_object()); 
}

/* 
 *  ***********************************************************************
 *  Function:    set_destruct_corpse
 *  Description: sets corpse destructing
 *  Arguments:   int 0 for no, 1 for yes
 *  ***********************************************************************
 */

set_destruct_corpse(int num) {
  Destruct_Corpse = num;
}

/* 
 *  ***********************************************************************
 *  Function:    set_thermal_wraith
 *  Description: sets whether or not mob is thermal wraith for special item
 *  Arguments:   int 0 for no, 1 for yes
 *  ***********************************************************************
 */

set_thermal_wraith(int num) {
  Thermal_Wraith = num;
}

/* 
 *  ***********************************************************************
 *  Function:    set_death_chat
 *  Description: sets corpse destructing
 *  Arguments:   string dc, where dc is the message upon monster_died()
 *  ***********************************************************************
 */

set_death_chat(string dc) {
  Death_Chat = dc;
}

/* 
 *  ***********************************************************************
 *  Function:    set_prize
 *  Description: sets monster_died() reward
 *  Arguments:   string p, where p is the path for item to be cloned
 *  ***********************************************************************
 */

set_prize(string p) {
  Prize = p; 
}

monster_died() {
  if(Death_Chat) tell_room(environment(),Death_Chat+"\n");
  if(Prize) move_object(clone_object(Prize),environment());
  if(Thermal_Wraith) {
    if(!random(2)) 
      move_object(clone_object(OBJ+"bone_shard.c"), environment());
    if(!random(4))   
      move_object(clone_object(OBJ+"bone_shard.c"), environment());
  }
  if(Destruct_Corpse) destruct(present("corpse",environment()));
    return 1; 
}

special_defense() {
  if(!random(5)) {
      return 3001;
  }
}
