inherit "room/room";
object t2, temp, onion, onion2, bowl, bowl2;
reset(arg)
{
   if (arg) return;
   set_light(1);
   short_desc = "HEAVEN CANT WAIT\n";
   long_desc = "You have reached the highest point of the\n"+
               "mountain.  Looking above you see wave of light\n"+
                "by wave of light flooding through the sky...\n"+

"\n\n"+
                "The only way down is to bungi JUMP (without \n"+
                "a cord of course!\n";  
}
 
   init() 
 {
    add_action("peel_onion", "peel");
    add_action("raise_onion", "raise");
    add_action("jump", "jump");
    ::init();
 }
 
jump()
   {    write("YOU jump...!   Falling at 9.8m/s^2!(not counting air"+
              " resistance of course....\n");
        write("\n\n\n\n");
        write("AHHH FREE.....wwwhHHHEEEEee....\n\n\n\n");
        write("Falling....lower...and...lower....\n\n\n");
        write("Falling.....\n\n\n\n");
        write("AHHHHHHHHHHHHHHH......\n\n\n\n\n");
        if(present("bowl2", this_player())){
        this_player()->move_player( 
       "falls....#/players/airwoman/quest/bboyroom");
        return 1;
	}
	this_player()->move_player("falls...#/players/airwoman/fields/tower1");
	return 1;
     }
  
peel_onion(str)
{
     onion = clone_object("players/airwoman/onion"); 
     if(str=="onion")
     {
     if(!present("onion", this_player()))
     { write("You cannot peel that.\n");
       return 1;
     }
       if(present("onion", this_player()))
        { 
        write("You peel the magical onion.  An exotic\n"+
        "aroma begins to emmanate from the onion.\n");
        temp =(present("onion", this_player()));
        destruct(temp);
   move_object(clone_object("/players/airwoman/onion2"), this_player());
        return 1;
        }
    } /*of if str == onion*/
 } /*of peel_onion (str)*/
 
 
raise_onion(str)
       {
        onion2=clone_object("players/airwoman/onion2");
        if(str == "onion")
        {
        if(!present("onion2", this_player()))
         {
           if(present("onion", this_player()))
                {write("You must peel the onion first!\n");
                  return 1;} 
        write("You cannot raise that\n");
                                            
          return 1;
         }
         if (present("onion2", this_player()))
        {
           write("You raise the peeled onion to the heavens"+ 
   "above\n");
        write("Tears seem to stream from the heavens...\n");
	temp = present ("onion2", this_player());
        destruct(temp);
        bowl = clone_object("players/airwoman/bowl");
	if (present("bowl", this_player()))
        {write("You collect the tears into your magical bowl.\n"); 
	t2 = present ("bowl", this_player());
        destruct(t2);
        bowl2 = clone_object("players/airwoman/bowl2");
        move_object(bowl2, this_player());
         return 1;}
        write("The tears fall to the ground because you do not.\n"+
        "possess the magical bowl to collect it.\n");
        
	return 1;
        }
    
 }
}
