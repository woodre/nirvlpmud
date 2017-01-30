/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

#define IS_POPMAN_DM
#include "definitions.h"
#include "router.h"
#include "/obj/ansi.h"

/* 
 *
 */

/* member variables */
object my_beano;
object my_locker_beano;
object my_prison_beano;
object my_hoth;

string my_available_pawns;
string my_available_rooks;  /* i know, rooks are usually defensive in chess, but not how i play :) */

/* this is ghetto for now. i'll have better population control later. */
object pawn1;
object rook1;


id(str) { return str == "popman-daemon" || str == "server"; }

short() { return "A network server named (popman-daemon)"; }


reset(arg)
{
/*    save_self(); */
    if(arg) return;


    move_object(this_object(), DAEMON_HOME);

    report_message("System online. Function reset(" + arg + ") called.\n");

    call_other(TACTICAL_DM, "???");

/*

    remove_call_out("check_population_beano");
    call_out("check_population_beano", 20);
*/

/*
    remove_call_out("check_population_locker_beano");
    call_out("check_population_locker_beano", 24);

    remove_call_out("check_population_prison_beano");
    call_out("check_population_prison_beano", 28);
*/

/*
    remove_call_out("check_population_offensive_line");
    call_out("check_population_offensive_line", 32);
*/

/*
    remove_call_out("check_population_hoth");
    call_out("check_population_hoth", 40);
*/


    my_available_pawns = ({
        "/players/mizan/mbv3/beasties/afei.c",
        "/players/mizan/mbv3/beasties/fettdog.c",
        "/players/mizan/mbv3/beasties/goliathbeano.c",
        "/players/mizan/mbv3/beasties/knm.c",
        "/players/mizan/mbv3/beasties/clippy.c",
        "/players/mizan/mbv3/beasties/plu-santa.c",
    });

    /*
        "", "/players/mizan/mball/beasties/.c", "ready",
     */

    my_available_rooks = ({
        "/players/mizan/mbv3/beasties/domokun.c",
        "/players/mizan/mbv3/beasties/thorgrim.c",
        "/players/mizan/mbv3/beasties/hydra.c",
    });


}

/* we don't give the Beano any orders, it just wanders around. */
check_population_beano()
{
    if(!my_beano)
    {
        my_beano = clone_object("/players/mizan/mbv3/beasties/beano.c");
        move_object(my_beano, LOCKERS_ROOM);
    }

    remove_call_out("check_population_beano");
    call_out("check_population_beano", 180);
}

/* same with the hoth monster */
check_population_hoth()
{
    if(!my_hoth)
    {
        my_hoth = clone_object("/players/mizan/mbv3/beasties/hoth.c");
        move_object(my_hoth, LOCKERS_ROOM);
        receive_orders(my_hoth, ORDERS_STEALKILLS_NAME, "doolotz", 10000);
    }

    /* don't call this out again. The hoth monster is self contained in its population checking. */
}


check_population_locker_beano()
{
    object room;
    
    if(!my_locker_beano)
    {
        my_locker_beano = clone_object("/players/mizan/mbv3/beasties/beano.c");
        move_object(my_locker_beano, DAEMON_HOME);
    }

    room = environment(my_locker_beano);
    
    if(!room || room != find_object(LOCKERS_ROOM))
    {
        receive_orders(my_locker_beano, ORDERS_HOLD_POSITION, LOCKERS_ROOM, 5000);
    }

    remove_call_out("check_population_locker_beano");
    call_out("check_population_locker_beano", 360);
}



check_population_offensive_line()
{

    if(!pawn1)
        pawn1 = summon_pawn();


    if(!rook1)
        rook1 = summon_rook();

    remove_call_out("check_population_offensive_line");
    call_out("check_population_offensive_line", 360);
}

summon_pawn()
{
    object new_pawn;
    int i;

    i = random(sizeof(my_available_pawns));

    new_pawn = clone_object(my_available_pawns[i]);
    /* todo: set that they have been cloned */

    move_object(new_pawn, LOCKERS_ROOM);

    return new_pawn;
}

summon_rook()
{
    object new_rook;
    int i;

    i = random(sizeof(my_available_rooks));

    new_rook = clone_object(my_available_rooks[i]);
    /* todo: set that they have been cloned */

    move_object(new_rook, LOCKERS_ROOM);

    return new_rook;
}

check_population_prison_beano()
{
    object room;
    
    call_other("room/prison", "???");

    if(!my_prison_beano)
    {
        my_prison_beano = clone_object("/players/mizan/mbv3/beasties/beano.c");
        move_object(my_prison_beano, "/room/prison");
    }

    room = environment(my_prison_beano);
    
    if(!room || room != find_object("room/prison"))
    {
        receive_orders(my_prison_beano, ORDERS_HOLD_POSITION, "room/prison", 5000);
    }

    remove_call_out("check_population_prison_beano");
    call_out("check_population_prison_beano", 360);
}


/* used internally... */
report_message(arg)
{
    object ob;
    object room;
    string message;
    int i;


    message = HIY + ">> " + HIR + "*" + HIY + "System.popman" + NORM + NORM + " reports: " + arg;

    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
        if(present(RADIO_ID, ob[i]))
            tell_object(ob[i], message);
    }
    tell_room(LISTENING_ROOM, message);

}
/* eof */
