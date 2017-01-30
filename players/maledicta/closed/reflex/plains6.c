#include "/players/reflex/lib/include/ansi.h"
#define AUTH_CODE "x24mx2x"
#define WAR "/players/maledicta/cont/war/war.c"
#include "security.h" 

inherit "/players/vertebraker/closed/std/room";

reset(arg){
int blah; 
if(WAR->query_goblins(13) > 5){ 
  if(!present("cont_goblin", this_object())){
   for(blah = 0; blah < 5; blah++){
   move_object(clone_object("/players/maledicta/cont/mobs/goblin1.c"), this_object());
   }
  } 
 }

  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"The southwestern corner of the plains borders on a steep hill to\n"+
	"the west and sheer rock cliffs to the south.  To the east and north\n"+
	"the plains continue, and far to the north you can see a heavy fog.\n"+
	"The sound of the waves crashing into the other side of the hill is\n"+
	"very loud here, and the wind whistles through the natural barrier\n"+
	"created by the hill and cliff sides. There is a large cave to the\n"+
   "west.\n");
   add_item("hill","This hill conceals the coastline to the west.");
   add_item("plains","Wide open plains lead out towards the coastline.");
   add_item("grasslands","Scrub grass grows up through the somewhat sandy soil here.");
   add_item("cliffs","These cliffs block off any path south.");
   add_item("cave","A HUGE cave with bones scattered about the ground before it.");
   add_item("bones","Thousands of bones. It is a chilling sight.");
	add_item("fog","The fog is absolutely inpenetrable to the north...");
        
   add_smell("main","The saltwater smell of the sea permeates the air around you.");
	add_smell("wind","The air smells very moist from the sea.");
	
   add_listen("main","Thunder rumbles overhead as the sea storm builds.");
	add_listen("waves","Waves crash violently into the shore in the distance.");
	
   set_chance(10);
   add_msg("Waves crash into the shoreline nearby.");
	add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/plains5","north");
   add_exit("/players/reflex/realms/coastline/plains3","east");
/* add_exit("/players/reflex/realms/coastline/plains7","northwest"); */
/* add_exit("/players/reflex/realms/coastline/plains4","northeast"); */
   add_exit("/players/maledicta/cont/rdragon/rooms/r1","cave");
   add_exit("/players/maledicta/cont/rdragon/rooms/r1","west");
       
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
add_action("nogo", "cave");
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
query_room_num(){ return 13; }
