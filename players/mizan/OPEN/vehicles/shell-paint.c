
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
   return "An 88mm howitzer shell (filled with dye)"; 
}

long() 
{
   write("This is an 88mm howitzer shell, but it is filled with dye instead\n"+
         "of an incindiary explosive warhead.\n");
}

query_save_flag()
{
   return 1;
}

query_value() 
{
   return 100; 
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
    if(!arg)
    {
        return 0;
    }

    tell_room(environment(), boom());
    tell_room(environment(), arg->query_name() + " is blasted by an 88mm anti-tank shell!\n");

    tell_room(environment(), "Luckily, it is only filled with green dye.\n");

    move_object(clone_object("/players/mizan/closed/stuff/vehicles/shell-residue.c"), environment());
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
