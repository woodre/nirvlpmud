/*****************************************************************************
 *      File:                   block.c
 *      Function:               A terrain block object
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 6/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/
inherit "/obj/monster.c";


reset(int arg)
{
    if(arg) return;
    set_race("block");
    set_alias("block");
    set_al(0);
    set_wc(3);
    ::reset(arg);

}

heart_beat()
{

}

attack_object(object ob)
{

}

long() 
{
    write (long_desc);
    if (hit_point < max_hp/10) {
        write(cap_name + " is in very bad shape.\n");
        return;
    }
    if (hit_point < max_hp/5) {
        write(cap_name + " is badly damaged.\n");
        return;
    }
    if (hit_point < max_hp/2) {
        write(cap_name + " is somewhat damaged.\n");
        return;
    }
    if (hit_point < max_hp - 20) {
        write(cap_name + " is slightly damaged.\n");
        return;
    }
    write(cap_name+" is in good condition.\n");
}

/* we don't carry anything */
can_put_and_get() { return 0; }

/* We don't wimpy.  */
run_away() { return 0; }
wimpy_out() { return 0; }

/* we don't leave a corpse behind */
second_life()
{
    object ob;
    if(!environment(this_object())) return;
    say(query_name() + " is destroyed!\n");

    ob = present("corpse", environment(this_object()));
    if(ob) destruct(ob);
    destruct(this_object());
}

is_block() { return 1; }
