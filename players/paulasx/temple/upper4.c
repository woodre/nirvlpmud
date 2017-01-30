inherit "room/room";

object devil;

reset(arg)
{
   if(!devil || !living(devil))
   {
      int i;
      for(i = 5; i; i--)
      {
         devil = clone_object("obj/monster");
         call_other(devil, "set_name", "devil");
         call_other(devil, "set_alias", "red devil");
         call_other(devil, "set_level",11);
         call_other(devil, "set_short", "A red devil");
         call_other(devil, "set_wc",10);
         call_other(devil, "set_ac",4);
         call_other(devil, "set_aggressive", 1);
         call_other(devil, "set_move_at_reset");
         call_other(devil, "set_whimpy");
         call_other(devil, "set_chance",30);
         call_other(devil, "set_spell_mess1",
	            "The devil burns you with his tongue.");
	 call_other(devil, "set_spell_mess2",
	            "You are hit by the fiery fire");
	 call_other(devil, "set_spell_dam",30);
         move_object(devil, this_object());
      }
   }
   if(arg)
      return;
   short_desc = "3rd Floor Hallway";
   long_desc = "You are on a long hallway on the second floor.  All that you can see to \n" +
                      "the north is hell hounds.  They are obviously protecting something, but \n"  +
                      "what?  You see a strange area about 250 feet ahead.\n\n";
   set_light(1);
   dest_dir = ({ 
                   "players/paulasx/temple/upper5", "west",
       	       "players/paulasx/temple/upper3", "south",
                   });
}
