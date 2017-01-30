inherit "/obj/monster";

#include <ansi.h>

mapping tot_damage;
mapping hb_damage;
int rounds, max_dam, dam2, max_dam2;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  
  tot_damage = ([ ]);
  hb_damage = ([ ]);
  
  SetMultipleIds( ({ "man", "trainer" }) );
  
  set_name("old man");
  set_race("human");
  set_short("An Old Man");
set_long("The man carries himself like he is very strong...Perhaps attacking\n"+
"him would be unwise.  As he looks at you his eyes seem to burn\n"+
"right through you.  Maybe he could help you train, fight him and\n"+
"when you have had enough, type 'totals.'\n");

  set_gender("male");
  set_level(20);
  set_wc(3);
  
  set_aggressive(0);
  set_al(-1);
  
}

init() {
  ::init();
	add_action("totals","totals");
	add_action("clear","clear");
}


heart_beat() {
  int i, dam;
  string *dtypes;
  
  ::heart_beat();
  if( query_attack() ) {
    rounds++;
    
    dtypes = m_indices( hb_damage );
    for( i = 0; i < sizeof(dtypes); i++) {
      tell_room( environment(), dtypes[i] + " : " + hb_damage[ dtypes[i] ] + "\n");
      dam += hb_damage[ dtypes[i] ];
        
      if( !tot_damage[ dtypes[i] ] )
        tot_damage += ([ dtypes[i] : hb_damage[ dtypes[i] ] ]);
      else
        tot_damage[ dtypes[i] ] += hb_damage[ dtypes[i] ];
    }
    tell_room( environment(), "Total damage for round "+rounds+": " +dam+ "\n");
     if( dam > max_dam )
        max_dam = dam;
  }
  clear( 1 );
  
  /** Real Damage **/
  dam = query_mhp() - query_hp();
  if( dam > 0 ) {
    dam2 += query_mhp() - query_hp();
    if( dam > max_dam2 )
      max_dam2 = dam;
    add_hp( dam );
    tell_room( environment(), "Total real damage for round "+rounds+": " +dam+ "\n");
  }
}

do_damage(int *damage, string *method){
  int i, dam;
  string dtype;
  object target;
  
  for( i=0; i < sizeof(damage); i++) {
    if( damage[i] > 0 ) {
      dtype = method[i] ? method[i] : "physical";
      tell_room( environment(), "\t\tdtype: " +dtype+" dam: "+damage[i]+"\n");
      if( !hb_damage[ dtype ] )
        hb_damage += ([ dtype : damage[i] ]);
      else
        hb_damage[ dtype ] += damage[i];
    }
  }
  return ::do_damage( damage, method );
}

totals() {
  int i, dam;
  string *dtypes;
  
	if(rounds < 1) {
	  write("The old man says: You have to fight me first foolish one.\n");
		return 1; 
  }
  write("Totals are as follows:\n");
  dtypes = m_indices( tot_damage );
    for( i = 0; i < sizeof(dtypes); i++) {
      tell_room( environment(), pad(dtypes[i],20) + " : " + tot_damage[ dtypes[i] ] + " | " + tot_damage[ dtypes[i] ]/rounds + "\n");
      dam += tot_damage[ dtypes[i] ];
    }
    tell_room( environment(), "Tot Damage   : " +dam+ "\n");
    tell_room( environment(), "Real Damage  : " +dam2+ "\n");
    tell_room( environment(), "Rounds       : " +rounds+ "\n");
    tell_room( environment(), "Avg Damage   : " +dam/rounds+ "\n");
    tell_room( environment(), "Avg Real Dmg : " +dam2/rounds+ "\n");
    tell_room( environment(), "Max Damage   : " +max_dam+ "\n");
    tell_room( environment(), "Max Real Dmg : " +max_dam2+ "\n");
	write("\nType 'clear' to reset the variables back to 0.\n");
  return 1;
}

clear( int hb_flag ) {
	
  if( !hb_flag ) {
	  rounds = 0;
    max_dam = 0;
    max_dam2 = 0;
    dam2 = 0;
    tot_damage = ([ ]);
  }
  else
    write("The old man says: Resetting all variables.\n");
    
  hb_damage = ([ ]);
	return 1; 
}