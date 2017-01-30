object ob,ob2,ob3,ob4,ob5,ob6,ob7,ob8,ob9,ob10;

reset(arg) 
{
    move_object(this_object(), "/players/mizan/workroom");

    /* This is used by the http://nirvana.beanos.com website */
    call_other("players/mizan/services/mudwho.c", "???");

    call_other("players/mizan/ent", "???");
    call_other("players/mizan/etheriel/subrealms/alchcave/castle.c", "???");
    call_other("players/mizan/etheriel/subrealms/watchlar/castle.c", "???");
/* 07/04/06 Earwax: replaced this with /obj/objtracker.c */
/*
   call_other("players/mizan/closed/sDM", "???");
*/

    /* i put this in because nobody has fixed Moe yet. */
/* I fixed moe 2 years ago - earwax 11/15/05
    call_other("players/mizan/closed/moe_pacemaker", "???");
*/

   call_other("players/mizan/closed/planter2.c", "???");

    /* this is my ghetto snoop object. */
   call_other("players/mizan/closed/makadra","???");

   call_other("players/mizan/opl/items/opl-champ-belt.c", "???");
   call_other("players/mizan/opl/items/tripod_card.c", "???");
    /* monster's guild stuff */
/*
    call_other("players/mizan/mbv2/popmanDM", "???");
    call_other("players/mizan/mbv2/tacticalDM", "???");
    call_other("players/mizan/mbv2/waypointDM", "???");
    call_other("players/mizan/mbv2/nexusDM", "???");
    call_other("players/mizan/mbv2/entrance", "???");
*/
    
    /* guild stuff */
    call_other("players/mizan/etheriel/ROOMS/linna", "???");
    call_other("players/mizan/etheriel/ROOMS/spuck","???");

    /* from if !ob */
    if(!present("machine", find_object("/players/mizan/etheriel/ROOMS/linna")))
    {
        ob=clone_object("players/mizan/etheriel/environs/wz-pinball.c");
        move_object(ob, "players/mizan/etheriel/ROOMS/linna");
    }
 
   if(!ob5) 
    {
        ob5=clone_object("players/mizan/closed/sbox.c");
        move_object(ob5, "/room/vill_green");
    }

    /* to prevent polys from using the advance guild for attribs */
    if(!ob6)
    {
        ob6 = clone_object("/players/mizan/closed/poly/block.c");
        move_object(ob6, "/room/adv_guild");
    }

    /* from ob8 verte */
    if(!present("box", find_object("/players/mizan/etheriel/ROOMS/linna")))
    {
        ob8 = clone_object("/players/mizan/closed/poly/catapult-box.c");
        move_object(ob8, "players/mizan/etheriel/ROOMS/linna");
    }
    /* changed from if(!ob9) */
    if(!present("catapult", find_object("/players/mizan/etheriel/ROOMS/linna")))
    {
        ob9 = clone_object("/players/mizan/closed/poly/guild-catapult.c");
        move_object(ob9, "players/mizan/etheriel/ROOMS/linna");
    }
    remove_call_out("load_opl_entrance");
    call_out("load_opl_entrance", 600);
}

load_opl_entrance()
{
    call_other("/players/mizan/opl/arrow.c", "???");
}


id(str) { return str == "tombstone" || str == "stone"; }
is_castle() { return 1; }
short() { return "A tombstone"; }

long() 
{
    write("Here lies the flying rooster.\n");
}
