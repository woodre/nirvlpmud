inherit "obj/monster";
#include <ansi.h>

#define TO this_object() 
#define ENV environment

/******************************************************************************
 * Program: red_dragon.c
 * Path: /players/nightshade/mons/
 * Type: Mob
 * Updated: October 2014 by Karash
 *
 * Purpose: An upgrade to the original Nightshade mob named red_dragon.  This upgrade
 *          increases mob stats and adds additional spells, including melee attacks
 *          and breath attacks.  Dragon will also take flight during combat and attack
 *          from the air causing heavy damage to the entire room when attacking from air.
 *         
 *          The dragon also is immune to all fire damage, 50% vulnerable to ice damage,
 *          20% resist to magic.
 *
 *          NOTE: The loot for this mob is located in the treasure room (room c28.c).
 *
 * History:
 *          
 ******************************************************************************/

#define TORCHROOM 200
 

int flt;        /** to track how many flights available - resets at max health **/
string flight;  /** to track when mob is in flight **/
int hbeat;      /** to track heartbeats when mob is in flight **/
string burn;    /** to track if room is burning **/

object *ob;
int h, s;
int plyrpres;   /** to track if players are present **/
 

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("hephaestus");
  SetMultipleIds( ({ "hephaestus the red dragon", "red dragon", "dragon", "wyrm" }) );
  set_short(HIR+"Hephaestus"+NORM+RED+" the Red Dragon"+NORM);
  set_long
   ("Hephaestus is a mighty red dragon many centuries old. He has seen\n"+
      "many battles and devoured even more opponents. His blood red scales\n"+
      "shine and his huge, heaving body swells with each great breath. Nearly\n"+
      "80 feet long, he is by far one of the largest wyrms alive. Best be\n"+
      "careful with this one.\n");
	  
  set_level(28);
  set_hp(1800+random(500));
  set_al(-1000);
  set_wc(58);
  set_ac(26);
  
  set_res(10);  
  set_heal(5,1);
  
  /** Dragon will take flight twice and torch room for 200 fire damage using hit_player **/
  /** At 400 fire dmg and Using an estimated 50 rounds to kill mob, that's 8 dmg/round * 1.25 modifier = 10 **/
  /** Setting WC bonus at 15 for all extra fire damage hitting all attackers (just an estimation) **/
  set_wc_bonus(15);
  
  
  /** 10 resist = 10 AC bonus **/
  /** 30 rounds out of estimated 50 (60% of fight) the Dragon is in flight and no_weapon_attack is       **/
  /** placed on players. With an estimated 50 WC for attacker, let's say avg of (50WC * 60%) 12 AC bonus **/
  /** from no_weapons while in flight.                                                                   **/
  /** 10 bonus + 12 bonus = 22 AC Bonus **/  
  set_ac_bonus(22);
  
   
  /* Immune to Fire */
  set_armor_params("other|fire",0,100,0);
  /* Vulnerable to Cold */
  set_armor_params("other|ice",0,-50,0);
  /* Resistance to Magic */
  set_armor_params("magical",0,20,0);

   
  /** Move spell functions to add_spell and other functions **
   ****************************************************************************************     
   ** set_chance(10);
   ** set_spell_dam(75);
   ** set_spell_mess1("You are almost blinded as Hephastus breaths a huge cone of fire!");
   ** set_spell_mess2("Hephastus inhales deeply and spews a cone of fire at you!");
   ****************************************************************************************/
   
  add_spell("claw_attack",
    "$HR$#MN#$N$ strikes you with his massive $HM$CLAW$N$!\n",
    "$HR$#MN#$N$ strikes #TN# with his massive $HM$CLAW$N$!\n",
    35,"30-50","physical",0);


  add_spell("bite_attack",
    "$HR$#MN#$N$ $HW$BITES$N$ you and his $HW$SHARP TEETH$N$ $HM$rips$N$ into your $Y$FLESH$N$.\n",
    "$HR$#MN#$N$ $HW$BITES$N$ down on #TN# $HM$RIPPING$N$ into #TP# $Y$FLESH$N$.\n",
    20,"60-80","physical",0);


  add_spell("tail_whip",
    "$HR$#MN#$N$ whips his $HM$TAIL THRASHING$N$ you around!\n",
    "$HR$#MN#$N$ whips his $HM$TAIL THRASHING$N$ you around!\n",
    15,"40-60","physical",2);  
   
   
   add_spell("cone_of_fire",
    "You are almost blinded as $HR$#MN#$N$ breathes a $HR$CONE OF FIRE$N$!\n",
    "$HR$#MN#$N$ inhales deeply and spews a $HR$CONE OF FIRE$N$ at #TN#!.\n",
    10,"130-160","other|fire",0); 
   
  flt = 0;
  hbeat = 0;
  flight = "no";
  burn = "no";
  
}


void init()
{
  ::init();
  
  set_heart_beat(1);
  
  /** If Mob is at Max HP and Not Fighting, Reset Flight Counter **/
  if(hit_point == max_hp && !TO->query_attack())
  {
    flt = 0;
	burn = "no";
  }
  
  /** When all players leave room, Dragon will change heal_rate to 100 so players don't just
      leave room when Dragon takes flight.  When any player re-enters room, init will set_ac
      heal_rate back to 5.  (I tried to add_hit_point in heartbeat when players left, but 
      heart_beat would not add_hit_point when no one is in room, so heal_rate works)           **/	  
  if(TO->query_heal_rate() > 10)
  {
  set_heal(5,1);
  }
  
  /* for testing */
  /* tell_room(ENV(TO), "HEAL RATE = "+TO->query_heal_rate()+"\n"); */
    
}


heart_beat()
{
  ::heart_beat();
  
  /* for testing */
  /* tell_room(ENV(TO), "Test Heartbeat 1\n");                */
  /* tell_room(ENV(TO), "HP = "+hit_point+" / "+max_hp+"\n"); */
  
  
  /*************************************************************************************************/
  /** If everyone leaves the room, Mob will set_heal to 100HP each round until a player re-enters **/
  /*************************************************************************************************/
  if(ENV())
  {
    h=0;
    s = sizeof(ob = all_inventory(ENV(TO)));
    plyrpres = 0; 

    while(h < s)
    {
      if(ob[h]->is_player())
      {
        plyrpres++;
	  }
	  h++;
    }
    if(plyrpres == 0)
    {
	  TO->set_heal(100,1);
    }
  }

  /* for testing */
  /* tell_room(ENV(TO)), "PLYRPRES = "+plyrpres+"\n"); */
  
  
  /***********************************************************************************************/
  /** Dragon will take flight twice during combat.  Around 7/10 and 4/10, Dragon will fly into
      the air where Dragon melee attacks will be removed and Players will have no_weapon_attack
	  objects placed on them.  During this time, Dragon will breathe fire into the room and
	  players can use spells, if possible.  After 10 rounds Dragon will land and resume fight as
	  normal (or sooner if players damage Dragon to 5/10 and 2/10 respectively <- did not code 
	  this, but may in future).                                                                 **/
  /***********************************************************************************************/	  
  /** Heartbeat Counter while in Flight **/
  if(flight == "yes")
  {
    hbeat++;
  }
  
  /** Around 7/10, Dragon Takes Flight **/  
  if( (((hit_point - random(200)) * 10 / max_hp) < 8)  &&  (flt < 1) && (flight == "no") )
  {
    flt++;
	flight = "yes";
	
    /* Enter Flight Graphic Here */
	take_flight_graphic();
	
	tell_room(ENV(TO), HIR+"\n\Hephaestus"+NORM+" extends his massive wings and "+HIC+"FLIES INTO THE AIR"+NORM+"!\n\n");
    
	/** Remove Dragon Melee Spells - Keep Cone of Fire on Tank at Increased Rate **/
	no_melee_spells();

	/** Give each creature a no_weapon_attack object **/
	no_melee_objs();

  }  
  
  /** Around 4/10, Dragon Takes Flight **/
  if( (((hit_point - random(200)) * 10 / max_hp) < 5)  &&  (flt < 2) && (flight == "no") )
  {
    flt++;
	flight = "yes";
	
    /* Enter Flight Graphic Here */
	take_flight_graphic();
	
	tell_room(ENV(TO), HIR+"\n\Hephaestus"+NORM+" extends his massive wings and "+HIC+"FLIES INTO THE AIR"+NORM+"!\n\n");
    
	/** Remove Dragon Melee Spells - Keep Cone of Fire on Tank at Increased Rate **/
	no_melee_spells();

	/** Give each creature a no_weapon_attack object **/
	no_melee_objs();
	
  }  
  
  
  /** After 10 rounds in flight, torch room with fire doing lots of fire damage **/
  if( flight == "yes" && hbeat == 10 )
  {
    /* ENTER TORCH ROOM DAMAGE HERE -- 200DMG -- PLUS GRAPHIC -- add to bonus WC */
	torch_graphic();
	tell_room(ENV(TO), HIR+"\n\HEPHAESTUS"+NORM+" takes an "+HIC+"INCREDIBLE BREATH"+NORM+"...\n\
                 ...and spews a "+HIR+"MASSIVE FIREBALL"+NORM+"...\n\
                                    ...that "+HIR+"TORCHES"+NORM+" the "+HIM+"ENTIRE ROOM"+NORM+"!\n\n");
	torch_attackers();

    /** After Dragon torches room, it will continue to burn until Dragon dies, gets max HP, or resets **/
	if(burn == "no")
	{
	  burn = "yes";
	}
	
  }
  
  /* IF I PUT IN CHECK TO LAND EARLY AFTER 20% DAMAGE, PUT IT HERE IN THIS SECTION */
  /** After 15 rounds in flight, dragon will land next to attacker_ob **/
    if( flight == "yes" && hbeat == 15 )
  {
    
	hbeat = 0;
    flight = "no";

	landing_graphic();
	tell_room(ENV(TO), HIR+"\n\Hephaestus"+NORM+" draws in his massive wings and "+HIG+"LANDS NEXT TO "+upper_case(attacker_ob->query_name())+NORM+"!\n\n");
    
	/** Re-Add Melee Spells **/
	melee_spells();
	
	/** the no_weapon_attack objects should destruct automatically **/
	/** if not, then remove them here                          **/
  
  }
  
  
  /** If room is burning, do some fire damage to all in room **/
  if(burn == "yes")
  {
    burn_room();
  }
  
  
}


take_flight_graphic()
{

tell_room(ENV(TO),"  \n"); 
tell_room(ENV(TO),HIR+"                                                  ,888b.                \n"+NORM);
tell_room(ENV(TO),HIR+"                                                 88b."+NORM+RED+"*                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                               ,d88'"+NORM+RED+"**                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                             ,d88'"+NORM+RED+"****                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                           ,d88'"+NORM+RED+"******                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                         ,d88'"+NORM+RED+"*********                 \n"+NORM);
tell_room(ENV(TO),HIR+"                                        ,d8'"+NORM+RED+"************                \n"+NORM);
tell_room(ENV(TO),HIR+"                                      ,d8"+NORM+RED+"****************               \n"+NORM);
tell_room(ENV(TO),HIR+"                                    ,d88"+NORM+RED+"**************"+NORM+HIR+"..d**'            \n"+NORM);
tell_room(ENV(TO),HIR+"                                  ,d88'"+NORM+RED+"*********"+NORM+HIR+"..d8*'"+NORM+RED+"****              \n"+NORM);
tell_room(ENV(TO),HIR+"                                ,d888'"+NORM+RED+"****"+NORM+HIR+"..d8P*'"+NORM+RED+"********               \n"+NORM);
tell_room(ENV(TO),HIR+"                        .     ,d8888*8888*'"+NORM+RED+"*************                \n"+NORM);
tell_room(ENV(TO),HIR+"                      ,*     ,88888*8P"+NORM+RED+"*****************                 \n"+NORM);
tell_room(ENV(TO),HIR+"                    ,*      d888888*8b."+NORM+RED+"****************                 \n"+NORM);
tell_room(ENV(TO),HIR+"                  ,P       dP  *888.*888b."+NORM+RED+"**************                \n"+NORM);
tell_room(ENV(TO),HIR+"                ,8*        8    *888*8'"+NORM+RED+"**"+NORM+HIR+"88888b."+NORM+RED+"*********               \n"+NORM);
tell_room(ENV(TO),HIR+"              ,dP                *88 8b."+NORM+RED+"*******"+NORM+HIR+"88b."+NORM+RED+"******               \n"+NORM);
tell_room(ENV(TO),HIR+"             d8'                  *8b 8b."+NORM+RED+"***********"+NORM+HIR+"8b."+NORM+RED+"***              \n"+NORM);
tell_room(ENV(TO),HIR+"           ,d8'                    *8. 8b."+NORM+RED+"**************"+NORM+HIR+"88b.            \n"+NORM);
tell_room(ENV(TO),HIR+"          d8P                       88. 8b."+NORM+RED+"***************              \n"+NORM);
tell_room(ENV(TO),HIR+"        ,88P                        888  8b."+NORM+RED+"************                \n"+NORM);
tell_room(ENV(TO),HIR+"       d888*       .d88P            888   8b."+NORM+RED+"*********                  \n"+NORM);
tell_room(ENV(TO),HIR+"      d8888b..d888888*              888    8b."+NORM+RED+"*******        "+NORM+HIR+"*          \n"+NORM);
tell_room(ENV(TO),HIR+"    ,888888888888888b.              888     8b."+NORM+RED+"*****         "+NORM+HIR+"8          \n"+NORM);
tell_room(ENV(TO),HIR+"   ,8*;88888P*****788888888ba.      888      8b."+NORM+RED+"****         "+NORM+HIR+"8'         \n"+NORM);
tell_room(ENV(TO),HIR+"  ,8;,8888*        '88888*         d88*       8b."+NORM+RED+"***        "+NORM+HIR+"8'          \n"+NORM);
tell_room(ENV(TO),HIR+"  )8e888*          ,88888be.       888         8b."+NORM+RED+"**      "+NORM+HIR+",8'           \n"+NORM);
tell_room(ENV(TO),HIR+" ,d888            ,8888888***     d888          88b."+NORM+RED+"*    "+NORM+HIR+"d8'            \n"+NORM);
tell_room(ENV(TO),HIR+",d88P            ,8888888Pb.     d888'           888b.  d8'             \n"+NORM);
tell_room(ENV(TO),HIR+"888*            ,88888888**   .d8888*                   d8'             \n"+NORM);
tell_room(ENV(TO),HIR+"'88            ,888888888    .d88888b                  d88'             \n"+NORM);
tell_room(ENV(TO),HIR+" 'P           ,8888888888bd888888*                     d88'             \n"+NORM);
tell_room(ENV(TO),HIR+"              d888888888888d888*                       d88'             \n"+NORM);
tell_room(ENV(TO),HIR+"              8888888888888888b.                        d88'            \n"+NORM);
tell_room(ENV(TO),HIR+"              88*. *88888888888b.        .db             d888'          \n"+NORM);
tell_room(ENV(TO),HIR+"              '888b.'8888888888888b. .d8888P               d888'        \n"+NORM);
tell_room(ENV(TO),HIR+"               **88b.'*8888888888888888888888b...            d888'      \n"+NORM);
tell_room(ENV(TO),HIR+"                *888b.'*8888888888P***7888888888888e.          d888'    \n"+NORM);
tell_room(ENV(TO),HIR+"                 88888b.'********.d8888b**  '88888P*            d888'   \n"+NORM);
tell_room(ENV(TO),HIR+"                 '888888b     .d88888888888**  '8888.            d888'  \n"+NORM);
tell_room(ENV(TO),HIR+"                  )888888.   d888888888888P      '8888888b.       d8888'\n"+NORM);
tell_room(ENV(TO),HIR+"                 ,88888*    d88888888888**'        '8888b          d888'\n"+NORM);
tell_room(ENV(TO),HIR+"                ,8888*    .8888888888P'              '888b.        d888'\n"+NORM);
tell_room(ENV(TO),HIR+"               ,888*      888888888b...                '88P88b.  d8888' \n"+NORM);
tell_room(ENV(TO),HIR+"      .db.   ,d88*        88888888888888b                '88888888888   \n"+NORM);
tell_room(ENV(TO),HIR+"  ,d888888b.8888'         '*888888888888888888P'              ******    \n"+NORM);
tell_room(ENV(TO),RED+" /"+NORM+HIR+"*****8888b**'              '***8888P*''8888'                          \n"+NORM);
tell_room(ENV(TO),RED+"  /"+NORM+HIR+"**88'                    ,d888888b.8888'                             \n"+NORM);
tell_room(ENV(TO),RED+"                       /"+NORM+HIR+"*****8888b**'                                   \n"+NORM);
tell_room(ENV(TO),RED+"                         /"+NORM+HIR+"**88'                                         \n"+NORM);
tell_room(ENV(TO),"  \n");
tell_room(ENV(TO),CYAN+" ^   ^   "+NORM+HIR+"____                                 "+NORM+HIC+"_____ _ _            "+NORM+CYAN+" ^   ^ \n"+NORM);
tell_room(ENV(TO),CYAN+"/|\\ /|\\ "+NORM+HIR+"|  _ \\ _ __ __ _  __ _  ___  _ __  "+NORM+HIC+"  |  ___| (_) ___  ___  "+NORM+CYAN+"/|\\ /|\\\n"+NORM);
tell_room(ENV(TO),CYAN+" |   |  "+NORM+HIR+"| | | | '__/ _` |/ _` |/ _ \\| '_ \\  "+NORM+HIC+" | |_  | | |/ _ \\/ __| "+NORM+CYAN+" |   | \n"+NORM);
tell_room(ENV(TO),CYAN+" |   |  "+NORM+HIR+"| |_| | | | (_| | (_| | (_) | | | |  "+NORM+HIC+"|  _| | | |  __/\\__ \\  "+NORM+CYAN+"|   | \n"+NORM);
tell_room(ENV(TO),CYAN+" |   |  "+NORM+HIR+"|____/|_|  \\__,_|\\__, |\\___/|_| |_|"+NORM+HIC+"  |_|   |_|_|\\___||___/"+NORM+CYAN+"  |   | \n"+NORM);
tell_room(ENV(TO),CYAN+" |   |  "+NORM+HIR+"                 |___/                "+NORM+HIC+"                      "+NORM+CYAN+"|   | \n"+NORM);
tell_room(ENV(TO),"  \n");

}

landing_graphic()
{

tell_room(ENV(TO),"  \n");  
tell_room(ENV(TO),HIR+"                                                  ,888b.                \n"+NORM);
tell_room(ENV(TO),HIR+"                                                 88b."+NORM+RED+"*                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                               ,d88'"+NORM+RED+"**                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                             ,d88'"+NORM+RED+"****                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                           ,d88'"+NORM+RED+"******                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                         ,d88'"+NORM+RED+"*********                 \n"+NORM);
tell_room(ENV(TO),HIR+"                                        ,d8'"+NORM+RED+"************                \n"+NORM);
tell_room(ENV(TO),HIR+"                                      ,d8"+NORM+RED+"****************               \n"+NORM);
tell_room(ENV(TO),HIR+"                                    ,d88"+NORM+RED+"**************"+NORM+HIR+"..d**'            \n"+NORM);
tell_room(ENV(TO),HIR+"                                  ,d88'"+NORM+RED+"*********"+NORM+HIR+"..d8*'"+NORM+RED+"****              \n"+NORM);
tell_room(ENV(TO),HIR+"                                ,d888'"+NORM+RED+"****"+NORM+HIR+"..d8P*'"+NORM+RED+"********               \n"+NORM);
tell_room(ENV(TO),HIR+"                        .     ,d8888*8888*'"+NORM+RED+"*************                \n"+NORM);
tell_room(ENV(TO),HIR+"                      ,*     ,88888*8P"+NORM+RED+"*****************                 \n"+NORM);
tell_room(ENV(TO),HIR+"                    ,*      d888888*8b."+NORM+RED+"****************                 \n"+NORM);
tell_room(ENV(TO),HIR+"                  ,P       dP  *888.*888b."+NORM+RED+"**************                \n"+NORM);
tell_room(ENV(TO),HIR+"                ,8*        8    *888*8'"+NORM+RED+"**"+NORM+HIR+"88888b."+NORM+RED+"*********               \n"+NORM);
tell_room(ENV(TO),HIR+"              ,dP                *88 8b."+NORM+RED+"*******"+NORM+HIR+"88b."+NORM+RED+"******               \n"+NORM);
tell_room(ENV(TO),HIR+"             d8'                  *8b 8b."+NORM+RED+"***********"+NORM+HIR+"8b."+NORM+RED+"***              \n"+NORM);
tell_room(ENV(TO),HIR+"           ,d8'                    *8. 8b."+NORM+RED+"**************"+NORM+HIR+"88b.            \n"+NORM);
tell_room(ENV(TO),HIR+"          d8P                       88. 8b."+NORM+RED+"***************              \n"+NORM);
tell_room(ENV(TO),HIR+"        ,88P                        888  8b."+NORM+RED+"************                \n"+NORM);
tell_room(ENV(TO),HIR+"       d888*       .d88P            888   8b."+NORM+RED+"*********                  \n"+NORM);
tell_room(ENV(TO),HIR+"      d8888b..d888888*              888    8b."+NORM+RED+"*******        "+NORM+HIR+"*          \n"+NORM);
tell_room(ENV(TO),HIR+"    ,888888888888888b.              888     8b."+NORM+RED+"*****         "+NORM+HIR+"8          \n"+NORM);
tell_room(ENV(TO),HIR+"   ,8*;88888P*****788888888ba.      888      8b."+NORM+RED+"****         "+NORM+HIR+"8'         \n"+NORM);
tell_room(ENV(TO),HIR+"  ,8;,8888*        '88888*         d88*       8b."+NORM+RED+"***        "+NORM+HIR+"8'          \n"+NORM);
tell_room(ENV(TO),HIR+"  )8e888*          ,88888be.       888         8b."+NORM+RED+"**      "+NORM+HIR+",8'           \n"+NORM);
tell_room(ENV(TO),HIR+" ,d888            ,8888888***     d888          88b."+NORM+RED+"*    "+NORM+HIR+"d8'            \n"+NORM);
tell_room(ENV(TO),HIR+",d88P            ,8888888Pb.     d888'           888b.  d8'             \n"+NORM);
tell_room(ENV(TO),HIR+"888*            ,88888888**   .d8888*                   d8'             \n"+NORM);
tell_room(ENV(TO),HIR+"'88            ,888888888    .d88888b                  d88'             \n"+NORM);
tell_room(ENV(TO),HIR+" 'P           ,8888888888bd888888*                     d88'             \n"+NORM);
tell_room(ENV(TO),HIR+"              d888888888888d888*                       d88'             \n"+NORM);
tell_room(ENV(TO),HIR+"              8888888888888888b.                        d88'            \n"+NORM);
tell_room(ENV(TO),HIR+"              88*. *88888888888b.        .db             d888'          \n"+NORM);
tell_room(ENV(TO),HIR+"              '888b.'8888888888888b. .d8888P               d888'        \n"+NORM);
tell_room(ENV(TO),HIR+"               **88b.'*8888888888888888888888b...            d888'      \n"+NORM);
tell_room(ENV(TO),HIR+"                *888b.'*8888888888P***7888888888888e.          d888'    \n"+NORM);
tell_room(ENV(TO),HIR+"                 88888b.'********.d8888b**  '88888P*            d888'   \n"+NORM);
tell_room(ENV(TO),HIR+"                 '888888b     .d88888888888**  '8888.            d888'  \n"+NORM);
tell_room(ENV(TO),HIR+"                  )888888.   d888888888888P      '8888888b.       d8888'\n"+NORM);
tell_room(ENV(TO),HIR+"                 ,88888*    d88888888888**'        '8888b          d888'\n"+NORM);
tell_room(ENV(TO),HIR+"                ,8888*    .8888888888P'              '888b.        d888'\n"+NORM);
tell_room(ENV(TO),HIR+"               ,888*      888888888b...                '88P88b.  d8888' \n"+NORM);
tell_room(ENV(TO),HIR+"      .db.   ,d88*        88888888888888b                '88888888888   \n"+NORM);
tell_room(ENV(TO),HIR+"  ,d888888b.8888'         '*888888888888888888P'              ******    \n"+NORM);
tell_room(ENV(TO),RED+" /"+NORM+HIR+"*****8888b**'              '***8888P*''8888'                          \n"+NORM);
tell_room(ENV(TO),RED+"  /"+NORM+HIR+"**88'                    ,d888888b.8888'                             \n"+NORM);
tell_room(ENV(TO),RED+"                       /"+NORM+HIR+"*****8888b**'                                   \n"+NORM);
tell_room(ENV(TO),RED+"                         /"+NORM+HIR+"**88'                                         \n"+NORM);
tell_room(ENV(TO),"  \n");
tell_room(ENV(TO),RED+" |  "+NORM+HIR+" ____                                "+NORM+HIG+" _                    _      "+NORM+RED+" | \n"+NORM);
tell_room(ENV(TO),RED+" |  "+NORM+HIR+"|  _ \\ _ __ __ _  __ _  ___  _ __  "+NORM+HIG+"  | |    __ _ _ __   __| |___ "+NORM+RED+"  | \n"+NORM);
tell_room(ENV(TO),RED+" |  "+NORM+HIR+"| | | | '__/ _` |/ _` |/ _ \\| '_ \\  "+NORM+HIG+" | |   / _` | '_ \\ / _` / __|"+NORM+RED+"  | \n"+NORM);
tell_room(ENV(TO),RED+" |  "+NORM+HIR+"| |_| | | | (_| | (_| | (_) | | | |  "+NORM+HIG+"| |__| (_| | | | | (_| \\__ \\"+NORM+RED+"  | \n"+NORM);
tell_room(ENV(TO),RED+"\\|/ "+NORM+HIR+"|____/|_|  \\__,_|\\__, |\\___/|_| |_|"+NORM+HIG+"  |_____\\__,_|_| |_|\\__,_|___/"+NORM+RED+" \\|/\n"+NORM);
tell_room(ENV(TO),RED+" V  "+NORM+HIR+"                 |___/                "+NORM+HIG+"                            "+NORM+RED+" V \n"+NORM);
tell_room(ENV(TO),"  \n");

}

torch_graphic()
{

tell_room(ENV(TO),"  \n");  
tell_room(ENV(TO),HIR+"                                                 .                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                                `s                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                                o/                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                                d-                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                               `M:                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                           .,  `Ms                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                           `y` `mh                         \n"+NORM);
tell_room(ENV(TO),HIR+"                ``                          yo  yM-                        \n"+NORM);
tell_room(ENV(TO),HIR+"                `o.                         dh  :Mh`     '                 \n"+NORM);
tell_room(ENV(TO),HIR+"                 :m.                       -Mh  `dMs    `/`                \n"+NORM);
tell_room(ENV(TO),HIR+"                 -Nd   -           ,      `dM/   :MMs    -y`               \n"+NORM);
tell_room(ENV(TO),HIR+"       ,         -MM: -o           o      +Md     yMM+    hy               \n"+NORM);
tell_room(ENV(TO),HIR+"       o`        /MM: /d           m      mMy     .NMN:   oN.  :           \n"+NORM);
tell_room(ENV(TO),HIR+"      .N         yMm  :M/          N.    -NMd      hMMm   hN- `o           \n"+NORM);
tell_room(ENV(TO),HIR+"      /N        -NM+   yN/`     /` No    .NMMo`   -NMMM: `Nm   m-          \n"+NORM);
tell_room(ENV(TO),HIR+"  `   +M       `dMm`   `sNh:    +o oN-    hMMMdsshNMMMM+ oMo   om+`        \n"+NORM);
tell_room(ENV(TO),HIR+"  .o` /M/      yMMy      :mMs`  -d `dm:   .NMMMMMMMMMMM+.NM.    /Nd.       \n"+NORM);
tell_room(ENV(TO),HIR+"   No `mm-    -MMMo       /MMo  /h  .dNs`  :NMMMMMMMMMM.-MM`     hMd`      \n"+NORM);
tell_room(ENV(TO),HIR+"   Nm  /Nm/   /MMMy       .MMN.`m/   `mMd.  -dMMMMMMMMy -MMy-```.mMM: .+   \n"+NORM);
tell_room(ENV(TO),HIR+"  :My   +MN/  /MMMNo.`  `.yMMM-yM:    yMMm.  .hMMMMMMm. `dMMMmhhNMMN. d+   \n"+NORM);
tell_room(ENV(TO),HIR+"  hM+    dMN. .NMMMMNdhydNMMMM.NMs` `-NMMMs   `dMMMMN-   :MMMMMMMMM+ :M+   \n"+NORM);
tell_room(ENV(TO),HIR+" +MM+    hMM+  yMMMMMMMMMMMMNs hMMdyhNMMMMd    -MMMMo     hMMMMMMN/  .Nd`  \n"+NORM);
tell_room(ENV(TO),HIR+" MMMy` `/NMM+  `dMMMMMMMMMMN/  -mMMMMMMMMM+    `MMMM:     +MMMMMN:    +Mh` \n"+NORM);
tell_room(ENV(TO),HIR+" \MMMdydMMMN.   -NMMMMMMMMM-    .hMMMMMMN+     oMMMMo     yMMMMMd      oMd`\n"+NORM);
tell_room(ENV(TO),HIR+" -MMMMMMMMM+     hMMMMMMMMy      :MMMMMMm`    /MMMMMNs/-/yMMMMMMd      :MMh\n"+NORM);
tell_room(ENV(TO),HIR+"  hMMMMMMMM-    `dMMMMMMMMh`     sMMMMMMMmo:/hMMMMMMMMMMMMMMMMMMMo`   .dMMM\n"+NORM);
tell_room(ENV(TO),HIR+"  :MMMMMMMMm+..:hMMMMMMMMMMh:../hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdddMMMMM\n"+NORM);
tell_room(ENV(TO),HIR+"` /MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"+NORM);
tell_room(ENV(TO),HIR+"MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm\n"+NORM);
tell_room(ENV(TO),HIR+"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss.\n"+NORM);
tell_room(ENV(TO),"  \n");

}




no_melee_spells()
{
  remove_spell("claw_attack");
  remove_spell("bite_attack");  
  remove_spell("tail_whip");
  remove_spell("cone_of_fire");

   add_spell("cone_of_fire",
    "You are almost blinded as $HR$#MN#$N$ breaths a huge $HR$CONE OF FIRE$N$!\n",
    "$HR$#MN#$N$ inhales deeply and spews a $HR$CONE OF FIRE$N$ at #TN#!.\n",
    50,"130-160","other|fire",0);   

}


no_melee_objs()
{
  object noweap;
  object *obb;
  int xx, sz;
  sz = sizeof(obb = all_inventory(environment(this_object())));
 
  while(xx < sz)
  {
    if(living(obb[xx]))
    {
      /* PATH UPDATED */
      noweap = "/players/nightshade/misc/nomelee_obj_new.c";
      if(!present("no_melee", obb[xx]))
	  {  
        move_object(clone_object(noweap), obb[xx]);
      }	
    }
  xx++;
  }
}


melee_spells()
{

  remove_spell("cone_of_fire");

  add_spell("claw_attack",
    "$HR$#MN#$N$ strikes you with his massive $HM$CLAW$N$!\n",
    "$HR$#MN#$N$ strikes #TN# with his massive $HM$CLAW$N$!\n",
    35,"30-50","physical",0);


  add_spell("bite_attack",
    "$HR$#MN#$N$ $HW$BITES$N$ you and his $HW$SHARP TEETH$N$ $HM$rips$N$ into your $Y$FLESH$N$.\n",
    "$HR$#MN#$N$ $HW$BITES$N$ down on #TN# $HM$RIPPING$N$ into #TP# $Y$FLESH$N$.\n",
    20,"60-80","physical",0);


  add_spell("tail_whip",
    "$HR$#MN#$N$ whips his $HM$TAIL$N$ THRASHING the back of the room!\n",
    "$HR$#MN#$N$ whips his $HM$TAIL$N$ THRASHING the back of the room!\n",
    15,"40-60","physical",2);  
   
   
   add_spell("cone_of_fire",
    "You are almost blinded as $HR$#MN#$N$ breathes a $HR$CONE OF FIRE$N$!\n",
    "$HR$#MN#$N$ inhales deeply and spews a $HR$CONE OF FIRE$N$ at #TN#!.\n",
    10,"130-160","other|fire",0); 


}

/** Each time Dragon flies, it will torch the room for 200 fire damage **/
torch_attackers()
{

  int yy, si;
  object *att;
  
  att = all_inventory(ENV(TO));
  for( yy=0, si = sizeof(att); yy < si; yy++ )
  {
    if(living(att[yy]))
    {
      if( !att[yy]->id("hephaestus") )
      {
	    att[yy]->hit_player(TORCHROOM,"other|fire");
	  }
	}
  }	 

}


/** Once Dragon torches room, it will continue to burn and do a small amount of fire damage **/
/** to each object in room every round (which is why I didn't use add_spell)                **/
burn_room()
{

  int i, siz;
  object *mobs;
  
  mobs = all_inventory(ENV(TO));
  for( i=0, siz = sizeof(mobs); i < siz; i++ )
  {
    if(living(mobs[i]))
    {
      if( !mobs[i]->id("hephaestus") )
      {
	    tell_object(mobs[i], MAG+"You are "+NORM+HIR+"singed"+NORM+MAG+" by the "+NORM+HIR+"fire"+NORM+MAG+" that continues to "+NORM+HIR+"burn"+NORM+MAG+" around you.\n"+NORM);
        mobs[i]->hit_player(random(10)+15,"other|fire");
	  }
	}
  }	  

}


move_player(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

move_object(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

run_away(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to run but is compelled to stay...\n");}

movement(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}


