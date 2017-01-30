inherit "room/room";

object demon;

reset(arg)
{
   if(!demon || !living(demon))
   {
      int i;
      for(i = 7; i; i--)
      {
         demon = clone_object("obj/monster");
         call_other(demon, "set_name", "demon");
         call_other(demon, "set_alias", "mad demon");
         call_other(demon, "set_level",16);
         call_other(demon, "set_short", "A hellish demon");
         call_other(demon, "set_wc",13);
         call_other(demon, "set_ac",5);
         call_other(demon, "set_aggressive", 1);
         call_other(demon, "set_move_at_reset");
         call_other(demon, "set_whimpy");
         call_other(demon, "set_chance",30);
         call_other(demon, "set_spell_mess1",
	            "The demon burns you with his tail.");
	 call_other(demon, "set_spell_mess2",
	            "You are hit by the fiery tail");
	 call_other(demon, "set_spell_dam",30);
         move_object(demon, this_object());
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
                   "players/paulasx/temple/upper4", "north",
       	       "players/paulasx/temple/upper2", "west",
                   });
}
