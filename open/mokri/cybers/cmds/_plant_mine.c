main()
{
   
   object gobj;
   int this_timer;
   
   if(!this_player()->query_pl_k())
      {
      write("You must be PK to use this.\n");
      return 1;
   }
   
   if(this_player()->query_ghost())
      {
      write("You're dead. Please lie still.\n");
      return 1;
   }
   
   gobj = present("guild_implants",this_player());
   
   if(!gobj)
      {
      write("Error. No CyberNinja Implants present.\n");
      return 1;
   }
   
   if(gobj->guild_lev() < 8)
      {
      write("Your neural implants are not sufficient to allow this action.\n");
      return 1;
   }
   
   if(this_player()->query_sp() < 150)
      {
      write("You are too drained to attempt this.\n");
      return 1;
   }
   
   if(present("cyberninja_landmine",environment(this_player())))
      {
      write("There is already a landmine planted here.\n");
      return 1;
   }
   
   this_player()->add_sp(-150);
   gobj = clone_object("/open/mokri/cybers/obj/landmine");
   gobj->set_owner(this_player()->query_real_name());
   this_timer = random(3) + 1;
   gobj->set_timer(this_timer);
   move_object(gobj,environment(this_player()));
   write("Landmine set with a " + this_timer + " second delay.\n");
   return 1;
}
