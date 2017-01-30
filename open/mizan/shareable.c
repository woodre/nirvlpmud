id(str) 
{
    return str == "ball"; 
}

short()
{
    return "A broken bowling ball"; 
}

long() 
{
  write("Eep. These things are very hard to break. Nonetheless, this indeed\n"+
	"is a _broken_ bowling ball. Pretty useless, eh? Possibly, but this is\n"+
    "is a special bowling ball that you can share with another person.\n"+
    "Use the command 'cloneball <player>'.\n");
}

init()
{
    add_action("on_cloneball","cloneball");
}

get() { return 1; }

on_cloneball(arg)
{
    object newball;
    object person;
    object room;

    /* no arg, no service */
    if(!arg) 
    {
        write("Buh?\n");
        return 1;
    }

    /* grab the person... */
    person = find_player(arg);

    /* it is important to check for invis, and also make the player not know
     * the difference between someone invis and someone who isnt logged in */
    if(!person || person->query_invis() >= this_player()->query_level())
    {
        write("There is no such person logged in. The bowling ball is sad.\n");
        return 1;
    }

    room = environment(person);

    /* this shouldnt happen */
    if(!room) return 0;

    if(environment(this_player()) && /* a sanity check */
       environment(this_player()) != room)
    {
        write("You must be in the same room as the person in order to do this...\n");
        return 1;
    }

    /* check if they have one already */
    if(present("ball", person))
    {
        write("Homeslice already has a ball.\n");
        return 1;
    }

    newball = clone_object("/open/mizan/shareable.c");
    
    /* should not happen either */
    if(!newball) return 0;

    move_object(newball, person);
    write("The bowling ball magically clones itself and a copy flies into " + person->query_name() + "'s inventory! Oof!\n");
    say(person->query_name() + " is given a broken bowling ball... LOOPYLICIOUS!\n");
    return 1;

}