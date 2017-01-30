#include "/players/reflex/lib/include/ansi.h"
#define AUTH_CODE "x24mx2x"
#define WAR "/players/maledicta/cont/war/war.c"
#include "security.h" 

inherit "/players/vertebraker/closed/std/room";

reset(arg){
int blah;
  if(WAR->query_goblins(9) > 5){ 
   if(!present("cont_goblin", this_object())){
    for(blah = 0; blah < 5; blah++){
    move_object(clone_object("/players/maledicta/cont/mobs/goblin1.c"), this_object());
   }
  } 
 }

 if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"The western edge of the plains is open in all directions except for\n"+
	"the mountains to the southwest.  The ocean surf rages to the west\n"+
	"and you can see a sandy beach in that direction.  The grasslands\n"+
	"continue in all other directions, but a heavy fog to the north\n"+
	"obscures your view.  The wind is at full strength here as it tears\n"+
	"across the plains.\n");
   add_item("beach","The surf crashes into the coastline to the west.");
   add_item("plains","Wide open plains lead out towards the coastline.");
   add_item("grasslands","Scrub grass grows up through the somewhat sandy soil here.");
   add_item("beach","The water whips across the beach, tearing at anything there.");
	add_item("fog","The fog is absolutely inpenetrable to the north...");
       
   add_smell("main","The saltwater smell of the sea permeates the air around you.");
	add_smell("wind","The air smells very moist from the sea.");

   add_listen("main","Thunder rumbles overhead as the sea storm builds.");
	add_listen("waves","Waves crash violently into the shore in the distance.");
	
   set_chance(10);
   add_msg("Waves crash into the shoreline nearby.");
	add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/plains7","west");
   add_exit("/players/reflex/realms/coastline/main","north");
   add_exit("/players/reflex/realms/coastline/plains4","east");
   add_exit("/players/reflex/realms/coastline/plains6","south");
/* add_exit("/players/reflex/realms/coastline/plains9","northwest"); */
/* add_exit("/players/reflex/realms/coastline/plains8","northeast"); */
/* add_exit("/players/reflex/realms/coastline/plains3","southeast"); */

   set_light(1);
   }


  

nogo(){
  if(present("cont_goblin", this_object())){
   write("The army of goblins blocks your way!\n");
   return 1;
   }
  return;
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
    add_action("nogo", "north", 1);
    add_action("nogo", "east", 1);
    add_action("nogo", "west", 1);
    if((x = this_player()) && (x->is_player()) &&
       (x->query_level() < 20))
    {
 object *i; 
      FightClub(filter_array((i = all_inventory(this_object())), "goblinz", this_object()),
                filter_array(i, "lonely", this_object()),
                filter_array(i, "zazoo", this_object()));
    }
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
query_room_num(){ return 9; }

