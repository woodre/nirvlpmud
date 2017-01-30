/* special advantage multi-cast, steals heals, steals armors, also makes monsters out of said items/heals  4 total special advantages.*/

inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("lucious");
  set_alias("vampire");
  set_race("demon");
  set_short("Lucious "+HIG+"("+HIK+"Mid Boss"+HIG+")"+NORM+"");
  set_long(
    " A sinister looking vampire stands here clad in a dark cloak and a\n"+
    " Golden ankh worn around his neck. A Golden ring shimmers from his\n"+
	" right hand. Lucious is one of the 3 servants of Vlad the impaler.\n");
	move_object(clone_object("/players/sami/area/GPO/obj/necklace.c"),this_object());
init_command("wear necklace");
move_object(clone_object("/players/sami/area/GPO/obj/vsword.c"),this_object());
init_command("wield sword");
move_object(clone_object("/players/sami/area/GPO/obj/pants.c"),this_object());
init_command("wear pants");
move_object(clone_object("/players/sami/closed/cube.c"),this_object());
move_object(clone_object("/players/sami/closed/cube.c"),this_object());

  set_level(29);
  set_hp(1900+random(250));
  add_money(14000+random(4000));
  set_armor_params("other|evil",0,25,0);
  set_armor_params("other|dark",0,25,0);
  set_armor_params("other|magical",0,25,0);
  set_armor_params("other|good",0,-50,0);
  set_al(-800);
  set_heal(20,1);
  set_ac(45+random(8));
  set_wc(60+random(12));
  set_wc_bonus(50);
  set_gender("male");
  
  set_aggressive(0);
 set_multi_cast(1);
 
 add_spell("claw_swipe",
  ""+HIK+"#MN#'s"+NORM+" claws flays you with "+HIY+"burt"+HIB+" of speed"+NORM+".\n",
  ""+HIK+"#MN#"+NORM+" tears into #TN#'s "+HIY+"flesh"+NORM+" with his jagged claws.\n",
  35,80,"physical");

  add_spell("roundhouse_kick", 
   ""+HIK+"#MN# "+NORM+" delivers a deadly"+HIB+" roundhouse"+NORM+" to your "+HIR+" abdomen"+NORM+".\n",
  ""+HIK+"#MN# "+NORM+" delivers a deadly"+HIB+" roundhouse"+NORM+" to #TN#'s "+HIR+" abdomen"+NORM+".\n",
  35,60,"physical");
  
  add_spell("ring_pulse", 
   ""+HIK+"#MN#'s"+NORM+" necklace radiates"+HIB+" POWER "+NORM+" that pierces your "+HIR+" mind"+NORM+".\n",
  ""+HIK+"#MN#'s"+NORM+" necklace radiates"+HIB+" POWER "+NORM+" that pierces #TN#'s "+HIR+" mind"+NORM+".\n",
  35,50,"other|evil");
 
 add_spell("thief", "\t\t#MN# steals your stuff!", "\t\t#MN# steals #TN#'s stuff!", 55, 0, 0, 6, "steal_heal"),
   enable_commands();
}
  
  status filter_heals( object ob ) {
  return (status) ob->is_heal() || 
    ob->id( "heal") || ob->id("potion") || ob->id("bottle") || ob->id("ice sphere") || (int) ob->is_armor();
}

void steal_heal(object target, object room, int damage) {
  int i, s, charges;
  object heal,mob;
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
  tell_room( room, "\n\n\t\tLucious steals a "+heal->short()+"!!!!\n");

  /** create mob from heal **/
  mob = clone_object( "/players/sami/area/GPO/npc/healmob.c" );
  move_object( mob, environment() );
  mob->set_short( heal->short() );
  mob->set_name( ( (string) heal->query_name() ? (string) heal->query_name() : (string) heal->short()) );
  mob->attacked_by(target);
  tell_room( environment(), target->query_name()+"'s "+heal->short()+" has been brought to life!\n", ({target}) );
  tell_object( target, "Your "+heal->short()+" has been brought to life!\n");
}

