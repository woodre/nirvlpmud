inherit "room/room";

object hell_hound;

reset(arg)
{
   if(!hell_hound || !living(hell_hound))
   {
      int i;
      for(i = 7; i; i--)
      {
         hell_hound = clone_object("obj/monster");
         call_other(hell_hound, "set_name", "hound");
         call_other(hell_hound, "set_alias", "hell hound");
         call_other(hell_hound, "set_level",14);
         call_other(hell_hound, "set_short", "A hell hound");
         call_other(hell_hound, "set_wc",14);
         call_other(hell_hound, "set_ac",5);
         call_other(hell_hound, "set_aggressive", 1);
         call_other(hell_hound, "set_move_at_reset");
         call_other(hell_hound, "set_whimpy");
         call_other(hell_hound, "set_chance",30);
         call_other(hell_hound, "set_spell_mess1",
	            "The hound burns you with his tongue.");
	 call_other(hell_hound, "set_spell_mess2",
	            "You are hit by the fiery tongue");
	 call_other(hell_hound, "set_spell_dam",30);
         move_object(hell_hound, this_object());
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
                   "players/paulasx/temple/upper2", "east",
       	       "players/paulasx/temple/stairway_top", "south",
                   });
}
