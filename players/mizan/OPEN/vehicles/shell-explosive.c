
id(str)
{
   return str == "88mm-shells" || 
          str == "shell";
}

reset(arg)
{
   if(arg) return;
}

short()
{
   return "An 88mm howitzer shell (high explosive)"; 
}

long() 
{
   write("This is an 88mm howitzer shell of the high explosive variety.\n"+
         "The warhead tip is tungsten carbide, and the innards are filled\n"+
         "with a compressed high explosive of some sort. Don't drop this\n"+
         "shell, as it would be a bad thing.\n");
}

query_save_flag()
{
   return 1;
}

query_value() 
{
   return 1000; 
}

get() 
{
   return 1; 
}

query_weight() 
{
   return 5; 
}


/** AMMO SPECIFIC FUNCTIONS **/

detonate(arg)
{
    object ob;

    if(!arg)
        return 0;

    tell_room(environment(), boom());
    tell_room(environment(), arg->query_name() + " is blasted by a HIGH EXPLOSIVE 88mm anti-tank shell!\n");

    arg->hit_player(random(75));

    ob = first_inventory(environment());

    while(ob)
    {
        if(ob != arg && living(ob) && ob != environment())
        {
            tell_object(ob, "You are thrown clear by the blast!\n");
            ob->run_away();
            tell_room(environment(), ob->query_name() + " is thrown clear by the blast!\n");
        }
        ob = next_inventory(ob);
    }

    destruct(this_object());
    return 1;
}


boom()
{
    string result;
    result = 
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MMM   MMM  !!  !!\n"+
      "\tBBBBBBB   OO    OO  OO    OO  MM MMM MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MM  M  MM  \n"+
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n\n";

    return result;

}
/* end function boom() */
