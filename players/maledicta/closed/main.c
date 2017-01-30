#include "/players/reflex/lib/lib.h"
#include "/players/reflex/lib/include/ansi.h"
#define AUTH_CODE "x24mx2x"
#define WAR "/players/maledicta/cont/war/war.c"
#include "security.h" 

inherit ROOM;

void create() {
::create();
    set_short("Western Coastal Plains");
    set_long(
	"Fog is so thick here that you cannot see more than a foot in front\n"+
	"of your face.  You know there are mountains to the north, but\n"+
	"beyond that you do not know a thing.  The ground under your feet is\n"+
	"soft and sandy, and the wind howls around you, screaming in protest\n"+
	"at the rock walls along the mountains.\n");
    set_items(([ "fog" : "A dense fog restricts the range of your vision.\n", ]));
    set_smells(([
	"default" :
	"The saltwater smell of the sea permeates the air around you\n",
	"wind" :
	"The air smells very moist from the sea.\n",
	]));
    set_sounds(([
	"default" :
	"Thunder rumbles overhead as the sea storm builds.\n",
	"waves" :
	"Waves crash violently into the shore to the west.\n",
	]));
    set_chat_frequency(80);
    load_chats(({
	"You hear a whistling noise as the winds whip through the"+
	" grasslands.\n",
	"Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...\n",
	}));
    set_exits(([
        "west" : "/players/reflex/realms/coastline/plains9",
        "east" : "/players/reflex/realms/coastline/plains8",
        "south" : "/players/reflex/realms/coastline/plains5",
        "southwest" : "/players/reflex/realms/coastline/plains7",
        "southeast" : "/players/reflex/realms/coastline/plains4",
        ]));
    set_light(0);
    replace_program(ROOM);
}

void
reset(int arg){
int blah;
  ::reset(arg);

/* if(WAR->query_goblins(1) > 5){ */
   for(blah = 0; blah < 5; blah++){
   move_object(clone_object("/players/maledicta/cont/mobs/goblin1.c"), this_object());
   }
 /* } */
}  

goblinz(arg)
{
    return (arg->query_goblin() == AUTH_CODE);
}

lonely(arg)
{
    return (arg->is_player() && !arg->query_attack());
}

zazoo(arg)
{
    return (arg->is_player());
}       

init()
{

 object x;
 ::init();
   
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
query_room_num(){ return 2; }
