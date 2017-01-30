/*
 * Monster generator. Balowski@Nirvana
 */
#include "/players/guilds/bards/bard_lib/lib.h"
#include "/players/guilds/bards/bard_lib/daemons.h"
#pragma strict_types
#pragma save_types
private mixed *Monsters;
private int CloneFreq;

void set_monsters(mixed *m)
{
    Monsters = m;
}

varargs void add_monster(string file, int maxpop, int group)
{
    if (!group) group = 1;
    if (!Monsters) {
	Monsters = order_alist(({ file }), ({ maxpop }), ({ group }));
    }
    else {
	Monsters = insert_alist(file, maxpop, group, Monsters);
    }
}

mixed query_monsters()
{
    return Monsters;
}

void set_monster_frequency(int x)
{
    CloneFreq = x;
}

/* the following functions are control funcs */
varargs void StartGenerator(int delay)
{
    if (delay < 1) {
	if (!CloneFreq) return;
	delay = (CloneFreq >> 1) + random(CloneFreq);
    }
    call_out("MonsterAppears", delay);
}

int StopGenerator()
{
    return remove_call_out("MonsterAppears");
}

void MonsterAppears()
{
    int i, j, size;
    string ident, file;
    
    if (Monsters) {
	i = size = sizeof(Monsters[0]);
	for (j = random(i); i--; j--) {
	    int maxpop, pop, group;
	    
	    file = ident = Monsters[0][j];
	    pop = (int) POPULATIOND->query_population(ident);
	    maxpop = Monsters[1][j];
	    group = Monsters[2][j];
	    
	    if ((maxpop - pop) >= group) {
		object ob;
		while (group--) {
		    ob = (object) POPULATIOND->clone_monster(ident, file);
		    /* hmm.. to this? what about appear msgs? */
		    ob->move_player(this_object());
		}
		break;
	    }
	    if (j <= 0) j = size;
	}
    }
    call_out("MonsterAppears", (CloneFreq >> 1) + random(CloneFreq));
}
