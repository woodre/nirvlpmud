#pragma strict_types

#include "/players/llew/closed/ansi.h"

inherit "room/room";

/* List of monsters for this room. */
/* example ({ MONSTER_PATH + "rat", 2, MONSTER_PATH + "spider", 1 }); 
   would have two rats and one spider in the room. */
mixed *npcs;

/* What section we are in.  This will determine what monsters go here. */
int section;

/*************/
/* Functions */
/*************/
void reset(int arg);
void npc_reset();
int query_section();
void init();

/************************************/
void reset(int arg)
{
   if (!arg)
   {
      set_light(1);
   }
   npc_reset();
}

/* Function: npc_reset
 * Desc:     Reload any monsters that were killed in the room.
 */
void npc_reset()
{
   int i;
   int size;
   object *room_inv;
   int count,j;
   string npcname;
   
   for (i = 0, size = sizeof(npcs); i < size; i += 2)
   {
      count = 0;
      npcname = (string)npcs[i]->query_name();

      for(j = 0, room_inv = all_inventory(this_object()); j < sizeof(room_inv); j++) {
         if ((string)room_inv[j]->query_name() == npcname) count++;
      }
      while(count < npcs[i + 1]) {
         move_object(clone_object((string)npcs[i]), this_object());
         count++;
      }
   }
}

/* Function: query_section
 * Return:   What section of the crystal this room is part of.
 */
int query_section()
{
   return section;
}

string realm() { return "NT"; }

int okay_follow() { return 1; }

int no_quit()
{
   if (this_player()->query_attack())
   {
      write(BOLD + "You cannot quit during combat here.\n" + NORM);
      return 1;
   }
}

void init()
{
   ::init();
   add_action("no_quit", "quit");
}
