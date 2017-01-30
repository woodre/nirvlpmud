inherit "room/room";

object zombie;

reset(arg)
{
   if(!zombie || !living(zombie))
   {
      int i;
      for(i = 4; i; i--)
      {
         zombie = clone_object("obj/monster");
         call_other(zombie, "set_name", "zombie");
         call_other(zombie, "set_alias", "dead zombie");
         call_other(zombie, "set_level",11);
         call_other(zombie, "set_short", "A dead zombie");
         call_other(zombie, "set_wc",10);
         call_other(zombie, "set_ac",4);
         call_other(zombie, "set_aggressive", 1);
         call_other(zombie, "set_move_at_reset");
         call_other(zombie, "set_whimpy");
         call_other(zombie, "set_chance",30);
         call_other(zombie, "set_spell_mess1",
	            "The zombie slaps you around.");
	 call_other(zombie, "set_spell_mess2",
	            "You are hit by the zombie's hand");
	 call_other(zombie, "set_spell_dam",30);
         move_object(zombie, this_object());
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
                   "players/paulasx/temple/upper3", "north",
       	       "players/paulasx/temple/upper1", "west",
                   });
}
