#include "/players/reflex/lib/include/ansi.h"
#define AUTH_CODE "x24mx2x"
#define WAR "/players/maledicta/cont/war/war.c"
#include "security.h" 

inherit "/players/vertebraker/closed/std/room";

reset(arg){
 int blah;
 if(WAR->query_goblins(1) > 5){ 
  if(!present("cont_goblin", this_object())){
   for(blah = 0; blah < 5; blah++){
   move_object(clone_object("/players/maledicta/cont/mobs/goblin1.c"), this_object());
   }
  }
 } 
  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"This is the northwestern edge of the coastline.  Mountains block\n"+
	"any passage north, and the ocean opens up to the west.  Waves crash\n"+
	"violently into the shore, and the wind almost takes you off your\n"+
	"feet.  Any movement is a battle for footing, and you feel that if\n"+
	"you slip it will not be easy to get back up.  There is a heavy fog\n"+
	"here that gets inpenetrable to the east.\n");
 
    add_item("mountains", "Tall mountains block the coastline to the north.");
    add_item("ocean", "The ocean storms violently to the west.");
    add_item("waves", "Huge waves crash into the shoreline, devouring it slowly.");
    add_item("shore", "This is a sandy beach in the midst of a storm.");
	 add_item("fog", "The fog is absolutely impenetrable to the east..");
    add_smell("main","The saltwater smell of the sea permeates the air around you.");
	 add_smell("wind","The air smells very moist from the sea.");
 
    add_listen(
	 "main","Thunder rumbles overhead as the sea storm builds.");
	 add_listen(
    "waves","Waves crash violently into the shore.");
	
   
   set_chance(10);
   add_msg("Waves crash into the shoreline.");
	add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/main","east");
   add_exit("/players/reflex/realms/coastline/plains7","south");
/* add_exit("/players/reflex/realms/coastline/plains5","southeast"); */
   set_light(1);
   }


  

goblinz(arg)
{
    return (arg->query_goblin() == AUTH_CODE);
}

lonely(arg)
{
return (arg->is_player() && !arg->query_attack() && (arg->query_level() < APPRENTICE));
}

zazoo(arg)
{
    return (arg->is_player() && (arg->query_level() < APPRENTICE));
}       

init()
{

 object x;
 ::init();
    add_action("nogo", "east", 1);
    if((x = this_player()) && (x->is_player()) &&
       (x->query_level() < 20))
    {
 object *i; 
      FightClub(filter_array((i = all_inventory(this_object())), "goblinz", this_object()),
                filter_array(i, "lonely", this_object()),
                filter_array(i, "zazoo", this_object()));
    }
}

nogo(){
  if(present("cont_goblin", this_object())){
   write("The army of goblins blocks your way!\n");
   return 1;
   }
  return;
  }


doitanyway(){
 object *i;
 FightClub(filter_array((i = all_inventory(this_object())), "goblinz", this_object()),
                filter_array(i, "lonely", this_object()),
                filter_array(i, "zazoo", this_object()));
 }

/*
 * Rule #23434 of Fight Club:
 * Don't code while watching Fight Club.
 */

FightClub(x, y, z)
{
    int s, s2, s3, indice;
    object poof, me;

    if(!(s = sizeof(x)) || !(s3 = sizeof(z)))
      return;

    s2 = sizeof(y);

    while(s --)
    {
      if(s2)
      {
        poof = y[indice = random(s2)];
        y -= ({ y[indice] });
        s2 = sizeof(y);
      }
      else
        poof = z[random(s3)];

      if(objectp(poof))
        x[s]->attack_object(poof);
    }
}

query_auth_code() { return AUTH_CODE; }
query_room_num(){ return 1; }
