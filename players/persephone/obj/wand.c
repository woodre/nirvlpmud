object owner;
string ownerset, nflag;

id(str) { return str == "wand"; }

short() { return (capitalize(environment(this_object())->query_real_name())) + "'s coding wand"; }

long() { }

get() { if (call_other(this_player(), "query_level") > 20) return 1; else return 0; }

drop() { return 1; }

query_value() { return 0; }

query_npc () { return 1;}

reset(arg) { enable_commands(); }

init()
{
    if (ownerset != "yes")  /* Set the owner the first time only!! */
    {
        owner = this_player();
        ownerset = "yes";
    }

    if (call_other(this_player(), "query_level") > 20)
    {
        add_action("do_reset","Reset");
        add_action("nuke","Nuke");
        add_action("do_get","Get");
        add_action("do_drop","Drop");
        add_action("describe","Look");
        add_action("exa_obj","Exa");
        add_action("go_in","Enter");
        add_action("go_out","Out");
        add_action("clone_obj","Clone");
        add_action("remove","Remove");
        add_action("reload","Reload");
        add_action("moreerr","Error");
        add_action("patch","Patch");
        add_action("do_help","Help");
        add_action("notify", "Notify");
   }
}

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
/* Get any object                                                          */
do_get(str)
{
    object ob;
    if (!str)
    {
        write("Give object name as argument.\n");
        return 1;
    }
    ob = present(str, environment(this_player()));
    if (!ob)
    {
        return 0;
    }
    else
    {
        write("Got: " + call_other(ob, "short") + ".\n");
        move_object(ob, this_player());
        return 1;
    }
}
/***************************************************************************/
/* Drop any object                                                         */
do_drop(str)
{
    object ob;
    if (!str)
    {
        write("Give object name as argument.\n");
        return 1;
    }
    ob = present(str, this_player());
    if (!ob)
    {
        return 0;
    }
    else
    {
        write("Dropped: " + call_other(ob, "short") + ".\n");
        move_object(ob, environment(this_player()));
        return 1;
    }
}
/***************************************************************************/
/* Look at room and ALL objects in the room                                */
describe()
{
    object ob;
    ob = environment(this_player());
    write(ob);
    write("\n");
    call_other(ob, "long", 0);
    ob = first_inventory(ob);

    while(ob)
    {
        if (ob != this_player())
        {
            write(call_other(ob, "short", 0) + ".\t\t");
            write(ob);
            write("\n");
        }
        ob = next_inventory(ob);
    }
    return 1;
}
/***************************************************************************/
/* Enter ANY object                                                        */
go_in(str)
{
    object ob;
    if (!str)
    {
        write("Give object name as argument.\n");
        return 1;
    }
    ob = present(str, environment(this_player()));
    if (!ob) {
        write("Object not present!\n");
        return 1;
    }
    write("Entered: " + call_other(ob, "short") + ".\t\t");
    move_object(this_player(), ob);
    describe();
    return 1;
}
/***************************************************************************/
/* Leave ANY object                                                        */
go_out()
{
    object ob, ob2;
    ob = environment(this_player());
    if (!ob) {
        write("You aren't in an object! This should not happen !\n");
        return 1;
    }
    ob2 = environment(ob);
    if (!ob2) {
        write("You can't go out of this object!\n");
        return 1;
    }
    write("Left: " + call_other(ob, "short") + ".\t\t");
    move_object(this_player(), ob2);
    describe();
    return 1;
}
/***************************************************************************/
/* Look at object and all objects in the player                            */
exa_obj(str)
{
    object ob;

    if (!str) return 0;

    ob = present(str, environment(this_player()));
    write(ob);
    write("\n");
    call_other(ob, "long", 0);
    ob = first_inventory(ob);

    while(ob)
    {
        if (ob != this_player())
        {
            write(call_other(ob, "short", 0) + ".\t\t");
            write(ob);
            write("\n");
        }
        ob = next_inventory(ob);
    }
    return 1;
}

/***************************************************************************/
/* Finds an object which *identifies* with str and LOADs, UPDATEs and      */
/* CLONEs object to this_player's inventory                                */
clone_obj(str)
{
    object ob;
    string fname;
    if (!str)
    {
    write("Error: File name as argument!\n");
    return 1;
    }

    fname = "/" + call_other(this_player(), "query_path", 0) + "/" + str + ".c";
    if (file_size(fname) <= 0)
    {
        write("Invalid file name: " + fname + "\n");
        return 1;
    }

    /* We just call a non existing function in the object, and that way
     * force it to be loaded.
     */
    call_other(fname, "???");

    /* Update here; so I am toading the FULL NAME! */
    ob = find_object(fname);
    if (ob) { destruct(ob); }

    /* Nuke all ocurrances of the thing in my inv and env */
    ob = present(str, environment(this_player()));
    while (ob)
    {
        destruct(ob);  
        ob = present(str, environment(this_player()));
    }
    ob = present(str, this_player());
    while (ob)
    {
        destruct(ob);  
        ob = present(str, this_player());
    }

    /* and clone the new copy of it */
    ob = clone_object(fname);
    move_object(ob, this_player());
    write("Fetched: " + call_other(ob, "short") + " to inv.\n");
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

    /* move player back to workroom */
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
/***************************************************************************/
/* The patch command from lars' wand                                       */
patch(str) {
    string name, with, what;
    int iwhat;
    object ob;

    if (!str)
        return 0;
    if (sscanf(str, "%s %s %d", name, with, what) == 3)
        iwhat = 1;
    else if (sscanf(str, "%s %s %s", name, with, what) != 3) {
    if (sscanf(str, "%s %s", name, with) == 2)
        iwhat = 0;
    else
        return 0;
    }
    if (name == "here")
    ob = environment(this_player());
    else
    ob = present(name, environment(this_player()));
    if (what == "me")
    what = this_player();
    if (!ob)
    ob = find_living(name);
    if (!ob) {
        write("No such object here.\n");
    return 1;
    }
    write("Output: "); write(call_other(ob, with, what)); write("\n");
    say(call_other(this_player(), "query_name") +
    " patched the internals of " + call_other(ob, "short") + ".\n");
    return 1;
}
/***************************************************************************/
/* Notify on/off                                                           */
notify(str)
{
    if (str == "on") { nflag = "on"; write("Notify: ON!\n"); return 1; }
    if (str == "off") { nflag = "off"; write("Notify: OFF!\n"); return 1; }
}
catch_tell(str) { if (nflag == "on") tell_object(owner, "Wand: " + str); }
/***************************************************************************/
/* Some help                                                               */
do_help() {
    write("Reset : resets your current environment.\n" +
          "Nuke  : Destroys all objects in the room you are in be careful as\n" +
          "        this function is indescriminate.\n" +
          "Get   : This enables you to get any objec even if on a mortal use this\n" +
          "        wisely or else trouble may arise.\n" +
          "Drop  : This enables you to drop any object in your inventory\n" +
          "        even non dropable ones.\n" +
          "Enter : this function allows you to enter any monster, ojbect or player\n" +
          "        use carefully as entering players is frowned on\n" +
          "Out   : This is the command for leaving players, objects, and monsters\n" +
          "Clone : This allows you to clone an object onto your inventory\n" +
          "Remove: Removes the environment you are in and moves you to the church\n" +
          "Reload: Reloads and updates the environment your are in and returns\n" +
          "        you to the same environment if no coding errors else places\n" +
          "        you in the church\n" +
          "Error : Does a cat of your log file and then removes it\n" +
          "Patch : This is the patch code from lars wand it allows you to\n" +
          "        raise or lower your statistics, change sex etc\n" +
          "Notify: A switchable command that can either be toggled on or off.\n" +
          "        If toggled on it catches all say functions in rooms\n" +
          "        a great function for debugging\n");


    return 1;
}
