inherit "room/room";

object lord;

reset(arg)
{
   if(!lord || !living(lord))
   {
      int i;
      for(i = 1; i; i--)
      {
         lord = clone_object("obj/monster");
         call_other(lord, "set_name", "lord");
         call_other(lord, "set_alias", "dark lord");
         call_other(lord, "set_level",17);
         call_other(lord, "set_short", "A dark lord");
         call_other(lord, "set_wc",15);
         call_other(lord, "set_ac",6);
         call_other(lord, "set_aggressive", 1);
         call_other(lord, "set_move_at_reset");
         call_other(lord, "set_whimpy");
         call_other(lord, "set_chance",30);
         call_other(lord, "set_spell_mess1",
	            "The lord steals your soul.");
	 call_other(lord, "set_spell_mess2",
	            "Your soul is absorbed by the dark lord");
	 call_other(lord, "set_spell_dam",30);
         move_object(lord, this_object());
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
                   "players/paulasx/temple/upper7", "north",
       	       "players/paulasx/temple/upper5", "east",
                   });
}

