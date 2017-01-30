/*
 * Monster generator daemon/population control. Balowski@Nirvana
 * 
 * Data is stored in a mapping with
 * 	(string) ident : (object *) monsters
 * pairs.
 * ident will default to the monster basename,
 * but can be used for controlling a population across rooms (in an area)
 * "orcs in gloomy grottos" is an example
 * If no ident is given to the clone_monster function, the filename is
 * used for ident.. (is this good? it's a rather restrictive default.. )
 * 
 * Should there be a way of setting a multiple population control areas?
 * e.g. "orcs","orcs is frozen wastes" (frenzy!)
 * 
 * As filenames are not necessarily stored, debugging could become difficult
 * The reasons (I can think of) for storing an array of monster obs
 * is for debugging (can detect empty slots) and synchronizing (cleanup)
 */
#include "/players/guilds/bards/bard_lib/lib.h"
#pragma strict_types
private mapping Monsters;
inherit BASE;

void create()
{
    Monsters = ([ ]);
    set_light(1);
}

void long()
{
    string *ks;
    object *mons;
    int i, j;
    
    write("Monsters registered:\n");
    ks = m_indices(Monsters);
    i = sizeof(ks);
    while (i--) {
	write("  " + ks[i] + ":\n");
	mons = Monsters[ks[i]];
	j = sizeof(mons);
	while (j--) {
	    write("    " + file_name(mons[j]) +
		  " - " + file_name(environment(mons[j])) + "\n");
	}
    }
}
    
int query_population(string ident)
{
    return sizeof(Monsters[ident]);
}

void add_monster(string ident, object ob)
{
    if (Monsters[ident]) {
	Monsters[ident] += ({ ob });
    }
    else {
	Monsters[ident] = ({ ob	});
    }
}

object clone_monster(string ident, string file)
{
    object ob;

    /* do I really want to do this? */
    /* for encapsulation it's fine, but what about permissions? */
    if (!ident) ident = file;
    ob = clone_object(file);
    ob->set_property("ident", ident);

    add_monster(ident, ob);
    return ob;
}

int remove_monster(object ob)
{
    string ident;
    object *mons;
    
    ident = (mixed)ob->query_property("ident");
    if (!(mons = Monsters[ident])) {
	log_file("balowski.md",
		 "No monsters for ident: '" + ident + "'\n");
	return 1;
    }
    if (member_array(ob, mons) < 0) {
	log_file("balowski.md",
		 "Monster not found in array for ident: '" + ident + "'\n");
	return 2;
    }
    Monsters[ident] = (mons - ({ ob }));
}

void clean_daemon()
{
    string *ks;
    object *mons;
    int i;

    ks = m_indices(Monsters);
    i = sizeof(ks);
    while (i--) {
	mons = Monsters[ks[i]];
	if (member_array(0, mons) >= 0) {
	    log_file("balowski.md",
		     "Blank entry found for ident: '" + ks[i] + "'\n");
	    Monsters[ks[i]] -= ({ 0 });
	}
    }
}

mixed query_monsters()
{
    return Monsters;
}
