      add_action("nuke","Nuke");
       add_action("reload","Reload");
/***************************************************************************/
/* reset() : reset current environment                                     */
do_reset()
{
    call_other(environment(this_player()), "reset", 0);
    write("Environment reset.\n");
    return 1;
}
/***************************************************************************/
/* nuke() : destruct everything in the room apart from me                  */
nuke()
{
    int num_nuked;
    object ob, ob2;

    num_nuked = 69;
    while (num_nuked > 0)
    {
        num_nuked = 0;
        ob = first_inventory(environment(this_player()));
        while(ob)
        {
            if (ob == this_player())
            {
                ob = next_inventory(ob);
            }
            else 
            {
                write("Nuked: " + call_other(ob, "short") + ".\n");
                ob2 = ob;
                ob = next_inventory(ob);
                num_nuked = num_nuked + 1;
                destruct(ob2);
            }
        }
    }
    return 1;
}
/***************************************************************************/
/* Removes the room i'm in + puts this_player() to workroom                */
remove()
{
    object ob;
    ob = environment(this_player());
    if (!ob)
    {
        write("Error: No environment!\n");
        return 1;
    }
    this_player()->move_player("X#room/church");
    write("Removed: Your environment.\n");
    destruct(ob);
    return 1;
}
/***************************************************************************/
/* Removes the env, loads, updates and puts me back there                  */
reload()
{
    object ob;
    string fname;
    ob = environment(this_player());
    if (!ob)
    {
        write("Error: No environment!\n");
        return 1;
    }
    fname = ("/" + file_name(ob));

    if (file_size(fname + ".c") <= 0)
    {
        write("Invalid file name: " + fname + "\n");
        return 1;
    }

    move_object(this_player(), ("room/church"));

    /* We just call a non existing function in the object, and that way
     * force it to be loaded.
     */
    call_other(fname, "???");

    /* Update here */
    ob = find_object(fname);
    if (ob) { destruct(ob); }

    /* Move me to the new room! */
    write("Reloaded: " + fname + ".c; ");

    move_object(this_player(), fname);
    describe();
    return 1;
}
