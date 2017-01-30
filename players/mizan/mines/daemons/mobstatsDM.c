#include "../definitions.h"
#include "/obj/ansi.h"

string *my_stats; 
int *offset_stats;
int *my_stats;

get() { return 0; }
short() { return "A server named (mobcalc)"; }
id(str) { return str == "mobcalc" || str == "server"; }

reset(arg)
{
	move_object(this_object(), DAEMON_HOME);
	if(arg) return;

	offset_stats = ({ 500,     2,    2,   5000,     15 });

	/*                  HP     WC   AC    GOLD   SPDAM */
	/* my_stats += ({      10,    4,    3,     10,      4 }); */

	my_stats = allocate(5);


	/* HP */
	my_stats[0] = ({
	10, 20, 30, 40, 50,
	60, 70, 80, 90, 100,
	110, 120, 130, 140, 150,
	160, 170, 180, 190, 200,
	});

	/* wc */
	my_stats[1] = ({
	1, 2, 3, 4, 5,
	6, 7, 8, 9, 10,
	11, 12, 13, 14, 15, 
	16, 17, 18, 19, 20,
	});

	/* AC */
        my_stats[2] = ({
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20,
        });

	/* gold */
        my_stats[3] = ({
	100, 200, 300, 400, 500,
	600, 700, 800, 900, 1000,
	1100, 1200, 1300, 1400, 1500,
	1600, 1700, 1800, 1900, 2000,
        });

	/* spell damage */
        my_stats[4] = ({
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20,
        });

}

get_hp(arg)
{
	return fetch_stats(arg, 0);
}

get_wc(arg)
{
	return fetch_stats(arg, 1);
}

get_ac(arg)
{
	return fetch_stats(arg, 2);
}

get_gold(arg)
{
	return fetch_stats(arg, 3);
}

get_spell_damage(arg)
{
	return fetch_stats(arg, 4);
}

fetch_stats(arg, i)
{
	int counter;
	int level;
	int type;
	int extra_offset;
	int *result;

	result = allocate(5);

	if(!arg || arg < 1) level = 1;
	else level = arg;

	if(level > 20) 
	{
		extra_offset = arg - 20;
		level = 20;
	}
	else extra_offset = 0;

	if(i < 0 || i > 4) type = 1;
	else type = i;

	result = ({ 
		my_stats[0][level - 1],
		my_stats[1][level - 1],
		my_stats[2][level - 1],
		my_stats[3][level - 1],
		my_stats[4][level - 1],
		});

	/* HP WC AC GOLD SPDAM */
	if(extra_offset > 0)
	{
		result[0] = result[0] + (offset_stats[0] * extra_offset);
		result[1] = result[1] + (offset_stats[1] * extra_offset);
		result[2] = result[2] + (offset_stats[2] * extra_offset);
		result[3] = result[3] + (offset_stats[3] * extra_offset);
		result[4] = result[4] + (offset_stats[4] * extra_offset);
	}
/*
	for(counter = 0; counter < sizeof(offset_stats); counter ++)
	{
		write("Item: " + result[counter] + "\n");
	}
 */
	return result[type];
}
