inherit "/obj/monster.c";
#include <ansi.h>
/******************************************************************************
 * Program: leonardo.c
 * Path: /players/wicket/ninja_turtles/mobs
 * Type: Mob
 * Created: August 19, 2014 by Wicket/Dragnar
 *
 * Purpose: A high level quest mob who wanders the sewers of Nirvana
 *
 * Special Abilities:
 *  1. Multi cast with high damage / high % spells
 *  2. Random location (controled by Gnar's castle)
 *  3. Disarm attacker
 *  4. Forces attacker to remove armor
 *     - Chance of breaking armor
 *  5. Offwielded weapon = dual hit full WC
 *
 * History:
 *          08/19/2014 - Wicket
 *            Created
 *          08/24/2014 - Gnar
 *            Added disarm spell, updated wander.
 *          09/23/2014 - Rumplemintz
 *            Added quest drop
 *          09/26/2014 - Gnar
 *            Beefed up stats to meet requirements for level 30 quest mob.
 ******************************************************************************/
#define tpn this_player()->query_name()

#if 1 /* 0 to disable drop, 1 to enable - Rumplemintz */
#define NINJA_TURTLE_QUEST
#endif

object katana;

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  move_object(clone_object("/players/wicket/ninja_turtles/weapons/lkatana.c"),
        this_object());
  command("wield");
        katana=clone_object("/players/wicket/ninja_turtles/weapons/lkatana.c"),
        move_object(katana, this_object());
  katana->offwield( this_object() );
  set_name("leonardo");
  set_alt_name("turtle");
  set_alias("leo");
  set_race("mutant_turtle");
  set_short(HIB+"Leonardo"+NORM+", One of the"+HIR+" Legendary"+NORM+" "+GRN+"Ninja Turtles"+NORM);
  set_long(
    "  An ancient ninja turtle, he is one of four that make up the team\n"+
    "of the ninja turtles. He is very well fit in strength and stamina\n"+
    "and is a force to be reckon with if ever attacked. He stays forever\n"+
    "defending the good and honorable in this realm.\n");
  add_money(10000+random(13000));
  set_level(30);
  set_hp(3000+random(400));
  set_al(-800);
  set_dead_ob(this_object());
    set_chat_chance(4);
  load_chat("Leonardo says: 'C O W A B U N G A    DUDE!!!!'\n");
  load_chat("Leonardo says: 'Wow when is the pizza delivery guy gonna get here?!'\n");
  load_chat("Leonardo says: 'Have you seen Master Splinter? \n");
  load_chat("Leonardo says: 'I wonder where my brothers have gone now!'\n");
  set_ac(32+random(9));
  set_wc(80);
  set_heal(50,4);
  set_multi_cast(1);
  add_spell("katana_slash",
  "$HR$Screams$N$ echo from $HB$Leonardo$N$ as he slashes you with inner strength!\n"+
  "$HR$                SSS                                 $N$\n"+
  "$HR$                   LLL                              $N$\n"+
  "$HR$                      AAA                           $N$\n"+ 
  "$HR$                         SSS                        $N$\n"+
  "$HR$                            HHH                     $N$\n",
  "#MN# screams as he grabs his katana slashing with a deep inner strength!\n",
   40,100,0,0);
   add_spell("shell_shock", 
   "$HB$ #MN#$N$ lundges forward and$HR$ G R A B S$N$ You!\n"+
   "$HY$       Stunning $N$ You....\n"+
   "       You $HK$stumble$N$ around $HR$Dazed$N$ and $HG$Confused$N$!\n",
   "Room Message\n",
   40,100,0,0);
   add_spell("disarm", 0, 0, 20, 0, 0, 6, "disarm_attacker");
   call_out("random_move", 5+random(10) );
   enable_commands();

}

status filter_armor( object ob ) {
  return (status) ob->query_worn();
}

void disarm_attacker( object target, object room, int damage) {
  int siz;
  object *arm;
  object wep, armor;

  if( !target )
    return;
  
  wep = (object) target->query_weapon();

  if( wep ) {

    target->stop_wielding();
    wep->set_wielded(0);
    wep->set_wielded_by(0);
    if( wep->query_guild_bonus() )
      wep->remove_guild_bonus();

    tell_room( room, "\n\n\t\tLeonardo's attack forces "+target->query_name()+" to fumble their weapon!\n");
  }
  else {
#ifndef __LDMUD__
  arm = filter_array( all_inventory(target), "filter_armor", this_object() );
#else
  arm = filter( all_inventory(target), "filter_armor", this_object() );
#endif
    siz = sizeof(arm );
    if( siz > 0 ) {
      armor = arm[ random(siz) ];
      if(!random(25) ) {
        armor->armor_breaks();
      }
      else {
        tell_room( room, "\n\n\t\tLeonardo's attack forces "+target->query_name()+" to stumble!\n");
        target->stop_wearing( armor, armor->query_type() , 1);
        armor->take_off();
      }
    }
  }
}

monster_died() {
  object corpse;
#ifdef NINJA_TURTLE_QUEST /* Rumplemintz */
  object mask;

  mask = clone_object("/players/wicket/ninja_turtles/quest/turtle_mask");
  mask->set_color("blue");
  move_object(mask, this_object());
#endif
  move_object(clone_object("/players/wicket/ninja_turtles/obj/remains.c"), this_object());
  corpse = present("corpse", environment() );
  if( corpse )
    destruct(corpse);
  return 1;
}

status random_move() {
  if( !attacker_ob || !present( attacker_ob, environment()) )
    wander();

  call_out("random_move",5+random(60));
  return 1;
}
