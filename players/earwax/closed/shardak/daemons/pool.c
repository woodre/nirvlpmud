/*
 * Pool is (c) Balowski, December 16th 1995.
 *      This is a permanent power storage. Power builds up slowly.
 *      If power was only added by users then there would be no prob..
 *      But when do I save this object if this object is swapped out.
 *      If swapped reset isn't called. That means power doesn't build
 *      and there is no way I can save the object.
 * Change log:
 */
#pragma strict_types
#define INTERVAL 300            /* every 5 minutes */
#define RATE 3
#define SAVEFILE "players/earwax/closed/shardak/daemons/pool"

static void build();
int     power;
int     lasttime;

void
reset(int arg)
{
    if (!arg) {
	restore_object(SAVEFILE);
	lasttime = (int) "/room/church"->query_reboot_time();
    }
    /*
     * 3.1.2-DR rules:
     * Wizard creations can only save to wizard's dir
     * Objects from /obj, /room, and /std to save to anywhere. 
     * All other attempts will fail
     */
    else {
	build();
	save_object(SAVEFILE);
    }
}

static void
build()
{
    int p;

    p = time() - lasttime;
    if (p > INTERVAL) {
	p = p/INTERVAL;         /* add RATE every INTERVAL seconds */
	power += RATE*p;

	lasttime += p*INTERVAL; /* update lasttime accordingly */
    }
}

int
query_power()
{
    build();
    return power;
}

status
add_power(int x)
{
    power += x;
}
