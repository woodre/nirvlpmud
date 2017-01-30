inherit "room/room";

object shukenja;

reset(arg)
{
   if(!shukenja || !living(shukenja))
   {
      int i;
      for(i = 3; i; i--)
      {
         shukenja = clone_object("obj/monster");
         call_other(shukenja, "set_name", "shukenja");
         call_other(shukenja, "set_alias", "Matsoto shukenja");
         call_other(shukenja, "set_level",18);
         call_other(shukenja, "set_short", "A Matsoto shukenja");
         call_other(shukenja, "set_wc",16);
         call_other(shukenja, "set_ac",7);
         call_other(shukenja, "set_aggressive", 1);
         call_other(shukenja, "set_move_at_reset");
         call_other(shukenja, "set_whimpy");
         call_other(shukenja, "set_chance",30);
         call_other(shukenja, "set_spell_mess1",
	            "The Shukenja slices your arm off.");
	 call_other(shukenja, "set_spell_mess2",
	            "Your arm has been cut off by the Shukenja!");
	 call_other(shukenja, "set_spell_dam",30);
         move_object(shukenja, this_object());
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
                   "players/paulasx/temple/upper12", "north",
       	       "players/paulasx/temple/upper10", "south",
                   });
}
