inherit "room/room";
reset(arg)
{
   
   if(!arg)
      {
      set_light(-1);
      short_desc="A Gloomy Tunnel";
      long_desc=
      "A gloomy tunnel\n"+
      "opressive in its darkness.\n";
      
      items=({
            "steps", "Though they are worn, the steps seem to be dry, sure footing.",
            "door","The door is of metal bound wood planks, it would take \n"+
            "something heavy to 'batter' the door down.",
            });
      
      dest_dir=({
            "/players/arrina/grounds/high0.c","west",
	});
   }
}


init()

{
   ::init();
   flicker();
}

flicker()
{
   int delay; /* can't declare and do a = in the same go :( */
      string null, null2; /* these were missing */
      delay = 180;
      if(present("torch",this_player()))
         {
         delay=20;
         if(sscanf(present("torch",this_player())->short(),"%slit%s",null,null2))
            {
            delay=180;
            if (random(5)>1)
               {   
               if (!present("shadow 2",this_object()))
                  {
                  write("Your torch flickers.\n");
                  say( (this_player()->query_name()) + "'s torch flickers.\n");
                  move_object(clone_object("/obj/bag"),this_object());
                  delay=180;
                  return 1;
                }
            }
         }
         call_out("flicker",delay); 
         return 1;
}
      return 0;
   }
