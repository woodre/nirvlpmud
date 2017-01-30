/* Master object to keep track of players' faction within the
 * crystal area.  Faction will affect aggro rate and access to
 * each of the races cities.
 */

#pragma strict_types

#define PATH "players/llew/Bcrystal/"

#include "/players/llew/Bcrystal/factions.h"

/* MAPPING TOOLS */
inherit "/players/llew/Bcrystal/tools/maptools";
 
/***********/
/* Globals */
/***********/

/* Holds every player that has killed something in the area. */
mapping faction_list;
/* Temp mixed array to enable saving of mapping. */
mixed *savemap;


/*************************/
/* Function Declarations */
/*************************/

void reset(int arg);
void add_faction(string name, int value);
int query_faction(string name);
void save_faction();


/************************/
/* Function Definitions */
/************************/

void reset(int arg)
{
   if (arg) 
   {
      save_faction();
      return;
   }

	/* Restore the list of factions. */
   savemap = ({});
	restore_object(PATH + "factions");
   faction_list = mixed_to_mapping(savemap);
}

/* Function: add_faction
 * In:       string name     The player to add or subtract faction for.
 *           int value       How much to change the faction.
 * Desc:     Change the faction amount of a player in the crystal area.
 */
void add_faction(string name, int value)
{
   if (!name) return;

	/* Check if the player is listed in the faction map. */
	if (!faction_list[name])
	/* If not, add him to the faction map. */
		faction_list += ([name: 0]);

	/* Adjust the faction accordingly, and check if it is 
	 * in the bounds of the faction range.
	 */
	 faction_list[name] += value;
	 if (faction_list[name] > FACTION_MAX) faction_list[name] = FACTION_MAX; 
	 if (faction_list[name] < FACTION_MIN) faction_list[name] = FACTION_MIN; 

	/* Save the adjusted faction map. */
   save_faction();
}

/* Function: query_faction
 * In:       string name     Which player to check faction for.
 * Return:   The player's current faction rating.
 * Desc:     Check a player's faction.
 */
int query_faction(string name)
{
	if (!name) return 0;

	/* If the player is not in the faction list, return will be 0,
	 * the default for never killing anything.
	 */
	return faction_list[name];
}

/* Function: save_faction
 * Desc:     Converts the mapping to a mixed array and saves.
 */
void save_faction()
{
   savemap = mapping_to_mixed(faction_list);
   save_object(PATH + "factions");
}
