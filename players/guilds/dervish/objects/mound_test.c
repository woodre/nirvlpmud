#include "../defs.h"
#include <ansi.h>

#define MAXSIZE 20
#define TESTCHAR_D "/obj/user/testchar-d"
/** Max heal is based off 25% rate of intox healing **/
#define MAXHEAL 120

/******************************************************************************
 * Program: mound.c
 * Path: /players/snow/dervish/
 * Type: Object
 * Created: 2013 by Dragnar
 *
 * Purpose: Keeps a "top player" list for the Dervish guild based on sand points.
 *          Sand points are given to the player by sacrificing a corpse to the
 *          sands. This object reads the dervish member files and then sorts
 *          them based on the sand points. Does some validation to ensure
 *          player is active, is not a wiz, not a test character, and the
 *          current guild is dervish.
 * History:
 *          12/12/2013 - Dragnar
 *            Created.
 *          01/06/2014 - Dragnar
 *            Updated to heal players that are on the list and present.
 *            Approved by Fred.
 ******************************************************************************/

int sand_points;
int level;
string name;
string guild_name;

static mixed *unsorted;

id(string str) {
  return str == "mound" || str == "sand" || str == "mound of sand"; 
}

short() { 
  return "A swirling mound of "+YEL+"Sand"+NORM;
}

long() {
  int i;
  
write("The mound of sand swirls and shifts and starts to form words in\n\
the side of the mound. You realize the sands are transcribing the\n\
Dervish that have been most dedicated to giving "+HIR+"blood"+NORM+" to the "+YEL+"Sands"+NORM+".\n\n");

  PrintList();
  
  if(this_player()->query_level() > 90) 
    write("\nAs a wizard you also have the ability to 'resetmound'\n");

}

init() {
   add_action("DoSort","sort");
   if(this_player()->query_level() > 90) 
     add_action("ResetMound", "resetmound");
      
}
reset(arg){
  if(arg) return;
  
}

mound_effect() {
  object myenv;
  string play_name;
  int index;
  
  myenv = environment();
  
  if(!myenv)
    return 0;
  
  if(!unsorted || sizeof(unsorted) == 0)
    DoSort();
    
  if(unsorted && sizeof(unsorted) > 0) {
  
    index = random(sizeof(unsorted));
    if( index > 20 )
      index = random(MAXSIZE);
      
    play_name = capitalize(unsorted[index][0]);
  
    switch( random(5) ) {
    case 0:
      tell_room(myenv, "The "+YEL+"Sands"+NORM+" in the mound shift and writhe.\n");
      break;
    case 1:
      tell_room(myenv, "The "+YEL+"Sands"+NORM+" rise up and form into the face of "+HIR+play_name+NORM+"!\n");
      call_out( "heal_players", 2, play_name );
      break;
    case 2:
      tell_room(myenv, "The "+YEL+"Sands"+NORM+" swirl up into the sky forming a great Vortex.\n");
      break;
    case 3:
      tell_room(myenv, "The "+YEL+"Sands"+NORM+" whip about the room and then cascade back into the mound.\n");
      break;
    default:
      tell_room(myenv, "The "+YEL+"Sands"+NORM+" scatter through the room and form the name: "+HIR+play_name+NORM+"!\n");
      call_out( "heal_players", 2, play_name );
      break;
    }
  }
  
  call_out("heal_players", 5 + random(10) );
  
  call_out("mound_effect", 200 + random(200) );
}

heal_players( string name ) {
  int i, amt;
  object env;
  object target;
  
  env = environment();
  
  if( !name && unsorted && env )
  {
    for( i = 0; i < sizeof(unsorted) && i < MAXSIZE; i++ ) {
      target = present( unsorted[i][0], env );
      if( target ) {
        switch( i ) {
          case 0..7:
            amt = MAXHEAL;
            break;
          case 8..15:
            amt = MAXHEAL / 2;
            break;
          default:
            amt = MAXHEAL / 3;
            break;
         }
        target->heal_self( amt );
        tell_room(env, capitalize(unsorted[i][0])+ "'s" +HIR+ " wounds"+NORM+" are healed by the sands.\n" );
      }
    }
  }
  
  if( name ) {
    target = present( lower_case( name ), env );

    if( target) {
      target->heal_self( MAXHEAL * 2 );
      tell_room(env, capitalize(name)+ " is "+HIR+ "blessed"+NORM+" by the sands.\n" );  
    }
  }
  
}

ResetMound() {
  unsorted = ({ } );
  
  DoSort();
  write("Mound reset.\n");
  return 1;
}

PrintList() {
  int i, max, cols;
  
  if(!unsorted || sizeof(unsorted) == 0)
    DoSort();
    
  if(unsorted)
  {
    max = unsorted[0][1];
      
    for( i = 0; i < sizeof(unsorted) && i < MAXSIZE; i++ ) {
      cols = unsorted[i][1] * 100 / max;
      /** Adjust to a line limit of 57 **/
      cols = cols * 57 / 100;
      
      write( pad(capitalize(unsorted[i][0]),12, ' ')  +" " );
      
      write( HIR + pad("", cols, '#') );
      write( NORM+"\n" );
    }
  }
}

DoSort() {
  int x;
  int i;
  int siz;
  string dir, who, junk;
  
  dir = get_dir(MEMPATH+"/"+"*" );
  x = 0;
  
  siz = sizeof(dir);
  
  unsorted = ({ } );
  
  while( x < siz ) 
  {

    if(sscanf(dir[x],"%s.o",who)) 
    {
      if(restore_object(MEMPATH+"/"+who))
      {
        if(Verify(who) == 1 && sand_points > 500 && guild_name == "dervish" )
        {
          if( level > 19 )
            sand_points = 0;
          if(junk = (string)TESTCHAR_D->query_owner(name))
            sand_points = 0;
          unsorted += ({ ({ who, sand_points }) });
        }
      }
    }
    x++;
  } /* end while */
  
  unsorted = sort_array(unsorted, "sp_sort", this_object());

  if( find_call_out("mound_effect") == -1 )
    call_out("mound_effect", 1 + random(20) );
  
  return 1;
}

int sp_sort(mixed *a, mixed *b) {
  return ( a[1]  < b[1] );
}


Verify(str) {
  /* Taken from Boltars /boltar/templar/verif.c and modified */

#ifndef __LDMUD__
  if(restore_object("pfiles/" + extract(str,0,0) + "/" + str)) return 1;
#else
  if (restore_object("pfiles/" + str[0] + "/" + str)) return 1;
#endif
  if(restore_object("players/inactive_saved/" + str)) return 2;
  return 0;
}

get() { return 0; }
drop() { return 1; }
query_weight() { return 1000; }
query_value() { return 0; }

