inherit "/obj/monster.c";
#include <ansi.h>
inherit "/players/wicket/ninja_turtles/include/mon_funcs.c";/*Skills of darkness and disarm added thanks to Sparrow */
#if 1 /* 0 to disable drop, 1 to enable - Rumplemintz */
#endif

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
   set_name("shredder");
  set_alt_name("shredder");
  set_alias("shredder");
  set_race("human");
  set_short(HIK+"Shredder"+NORM+", The "+HIK+"Evil Warlord "+NORM+"of the"+HIR+" Footclan"+NORM);
  set_long(
    "  An ancient ninja master, he is one of the fearless enemies of the ninja\n"+
    "turtles. He is very well fit in strength and stamina and covered from head\n"+
    "to toe in armor with blades that can penetrate almost anything. He is litteraly\n"+
    "a walking tin can. But do not let his apperance be deceiving.\n");
  add_money(20000+random(13000));
  set_level(30);
  set_hp(6000+random(500));
  set_al(-800);
  set_dead_ob(this_object());
    set_chat_chance(4);
  load_chat("Shredder says: 'Find and KILL those turtles!!!!'\n");
  load_chat("Shredder says: 'You Idiot What are you standing around and waiting for bring me their heads.'\n");
  load_chat("Shredder says: 'Bring me the hide of Splinter! I want him DEAD! \n");
  set_ac(32+random(9));
  set_wc(80);
  set_heal(75,2);
  set_multi_cast(2);

  add_spell("backhand",
  "$HR$Laughs$N$ echo from $HK$Shedder$N$ as he backhands you with his spiked bracers!\n"+
  "$HR$  \\ \\ \\ \\                                            $N$\n"+
  "$HR$   \\ \\ \\ \\                                           $N$\n"+
  "$HR$    \\ \\ \\ \\                                          $N$\n"+ 
  "$HR$                >>>Flesh and Blood Fly<<<             $N$\n"+
  "$HR$                                           \\ \\ \\ \\  $N$\n"+
  "$HR$                                            \\ \\ \\ \\  $N$\n"+
  "$HR$                                             \\ \\ \\ \\ $N$\n",
  "#MN# screams as he grabs his spike bracers tear through flesh and bone!\n",
40,100,0,0);

   add_spell("impale", 
   "$HK$ #MN#$N$ lundges forward and$HR$ impales $N$ You!\n"+
   "$HR$       Blood$N$ Gushes freely from you $N$ You....\n"+
   "              You $HK$stumble$N$ around in $HR$agony$N$ and $HY$pain$N$!\n",
   "Room Message\n",
40,100,0,0);
/*Skills of darkness and disarm added thanks to Sparrow */
    add_spell("disarm",
    "$HR$****$N$$R$#CMN# spins inside of your defenses and smashing your arms wide open!$HR$****\n$N$",
    "$HR$****$N$$R$#CMN# spins inside of #CTN#'s defenses and smashing #TP#'s arms wide open!$HR$****\n$N$",
    12,"2d10",0,0,"disarm");
     
    add_spell("smoke_bomb",
    "$HR$****$HK$#CMN# slams down a smoke bomb, you stumble about trying to regain vision!$HR$****\n$N$",
    "$HR$****$HK$#CMN# slams down a smoke bomb, you stumble about trying to regain vision!$HR$****\n$N$",
    10,5,"other|dark",0,"smoke_bomb");
  
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

  /** Steal the heal thanks to dragnar's code**/
  heal = heals[ random(s) ];
  if(heal->queryKept());
    heal->deShadow();
  move_object( heal, this_object() );
  tell_room( room, "\n\n\t\tShredder steals a "+heal->short()+"!!!!\n");

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

