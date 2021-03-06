inherit "/obj/monster.c";
#include <ansi.h>
/******************************************************************************
 * Program: mikey.c
 * Path: /players/wicket/ninja_turtles/mobs
 * Type: Mob
 * Created: August 19, 2014 by Wicket/Dragnar
 *
 * Special Abilities:
 *  1. Multi cast with high damage / high % spells
 *  2. Random location (controled by Gnar's castle)
 *  3. Steals heals from the player 
 *     - Uses the heal to heal itself
 *  4. Offwield weapon = dual attacks
 *
 * Purpose: A high level mob who wanders the sewers of Nirvana
 * History:
 *          08/19/2014 - Wicket
 *            Created
 *          08/25/2014 - Gnar
 *            Added spell to steal heals, addef fake intox funcs,  
 *            updated wander.
 *          09/23/2013 - Rumplemintz
 *            Added quest drop
 *          09/26/2014 - Gnar
 *            Beefed up stats to meet requirements for level 30 quest mob.
 ******************************************************************************/

#if 1 /* 0 to disable drop, 1 to enable - Rumplemintz */
#define NINJA_TURTLE_QUEST
#endif

#define tpn this_player()->query_name()
object katana;

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  move_object(clone_object("/players/wicket/ninja_turtles/weapons/mikeywep.c"),
        this_object());
  katana=clone_object("/players/wicket/ninja_turtles/weapons/mikeywep.c"),
  move_object(katana, this_object());
  katana->offwield( this_object() );

  set_name("michelangelo");
  set_alt_name("turtle");
  set_alias("mikey");
  set_race("mutant_turtle");
  set_short(YEL+"Michelangelo"+NORM+", One of the"+HIR+" Legendary"+NORM+" "+GRN+"Ninja Turtles"+NORM);
  set_long(
    "  An ancient ninja turtle, he is one of four that make up the team\n"+
    "of the ninja turtles. He is very well fit in strength and stamina\n"+
    "and is a force to be reckon with if ever attacked. He stays forever\n"+
    "defending the good and honorable in this realm.\n");
  add_money(10000+random(13000));
  set_level(30);
  set_hp(3000+random(500));
  set_al(-800);
  set_dead_ob(this_object());
    set_chat_chance(4);
  load_chat("Michelangelo says: 'C O W A B U N G A    DUDE!!!!'\n");
  load_chat("Michelangelo says: 'Lets go shred up the sewers!'\n");
  load_chat("Michelangelo says: 'Where is Master Splinter? \n");
  load_chat("Michelangelo says: 'I wonder where my hot headed brothers are now!'\n");
  set_ac(32+random(9));
  set_wc(80);
  set_heal(50,3);
  set_multi_cast(1);

  add_spell("sai_stab",
  "$HR$Screams$N$ echo from $Y$Michelangelo$N$ as he bashes you with inner strength!\n"+
  "$HR$                >>>                                 $N$\n"+
  "$HR$                   >>>                              $N$\n"+
  "$HR$         >>>Blood Sprays Everywhere<<<              $N$\n"+ 
  "$HR$                         <<<                        $N$\n"+
  "$HR$                            <<<                     $N$\n",
  "#MN# screams as he grabs his nunchakus pound with a deep inner strength!\n",
40,100,0,0);

   add_spell("shell_shock", 
   "$HB$ #MN#$N$ lundges forward and$HR$ G R A B S$N$ You!\n"+
   "$HY$       Stunning $N$ You....\n"+
   "       You $HK$stumble$N$ around $HR$Dazed$N$ and $HG$Confused$N$!\n",
   "Room Message\n",
40,100,0,0);

   add_spell("theif", 0, 0, 55, 0, 0, 6, "steal_heal");
   call_out("random_move", 5+random(10) );
   enable_commands();
}

status filter_heals( object ob ) {
  return (status) ob->is_heal() || 
    ob->id( "heal") || ob->id("potion") || ob->id("bottle") || ob->id("ice sphere");
}

void steal_heal(object target, object room, int damage) {
  int i, s, charges;
  object heal;
  object *heals;
  string *cmds;

  if( !target || !room )
    return;
#ifndef __LDMUD__
  heals = filter_array(all_inventory(target),"filter_heals",this_object());
#else
  heals = filter(all_inventory(target), "filter_heals", this_object());
#endif

  if( !heals )
    return;

  s = sizeof( heals );

  if( !s )
    return;

  /** Steal the heal **/
  heal = heals[ random(s) ];
  if(heal->queryKept());
    heal->deShadow();
  move_object( heal, this_object() );
  tell_room( room, "\n\n\t\tMikey steals a "+heal->short()+"!!!!\n");

  /** now use up the heal **/
  if( heal->is_heal() ) {
    cmds = (string *) heal->query_cmds();
    if( sizeof( cmds ) > 0 ) {
      charges = (int) heal->query_charges();
      for( i=charges; i > 0; i-- ) {
        set_hp_bonus( query_hp_bonus() + heal->query_hp_heal());
        command(cmds[0]+ " " + heal->query_name());
      }
    }
  }
  command("heal");
  command("drink potion");
  command("pop pill");
  command("pop pill");
  command("pop pill");
  command("apply sphere");
  command("apply sphere");
  command("apply sphere");
}

monster_died() {
  object corpse;
#ifdef NINJA_TURTLE_QUEST /* Rumplemintz */
  object mask;

  mask = clone_object("/players/wicket/ninja_turtles/quest/turtle_mask");
  mask->set_color("orange");
  move_object(mask, this_object());
#endif

  move_object(clone_object("/players/wicket/ninja_turtles/obj/remains.c"), this_object());
  corpse = present("corpse", environment() );
  if( corpse )
    destruct(corpse);
  return 1;
}

status random_move() {
  if(!environment()) return 0;
  if( !attacker_ob || !present( attacker_ob, environment()) )
    wander();

  call_out("random_move",5+random(60));
  return 1;
}

/** fake intox funcs **/
query_soaked() { return 1; }
int drink_soft(int i ) { return 1; }
query_stuffed() { return 1; }
eat_food( int i ) { return 1; }
query_intoxination() { return 1; }
drink_alcohol( int i ) { return 1; }
int query_max_intox() { return 1000; }
int query_max_soak() { return 1000; }
int query_max_stuff() { return 1000; }

