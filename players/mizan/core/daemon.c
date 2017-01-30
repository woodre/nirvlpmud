inherit "/players/mizan/core/object.c";

string my_homeroom;

reset(arg)
{
    ::reset();
    if(arg) return 0;

    /* important! */
/*    set_no_clean(1); */

    remove_call_out("extra_reset");
    call_out("extra_reset", 1);
}

extra_reset()
{
    if(!my_homeroom)
        move_object(this_object(), "/players/mizan/workroom.c");
    else
        move_object(this_object(), my_homeroom);
}

query_homeroom() { return my_homeroom; }

set_homeroom(arg) { my_homeroom = arg; }

/* eof */