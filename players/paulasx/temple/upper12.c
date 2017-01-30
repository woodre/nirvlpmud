inherit "room/room";

object yakuza;

reset(arg)
{
   if(!yakuza || !living(yakuza))
   {
      int i;
      for(i = 3; i; i--)
      {
         yakuza = clone_object("obj/monster");
         call_other(yakuza, "set_name", "yakuza");
         call_other(yakuza, "set_alias", "wu jen yakuza");
         call_other(yakuza, "set_level",18);
         call_other(yakuza, "set_short", "A Wu Jen Yakuza");
         call_other(yakuza, "set_wc",16);
         call_other(yakuza, "set_ac",7);
         call_other(yakuza, "set_aggressive", 1);
         call_other(yakuza, "set_move_at_reset");
         call_other(yakuza, "set_whimpy");
         call_other(yakuza, "set_chance",30);
         call_other(yakuza, "set_spell_mess1",
	            "The Yakuza breaks your legs.");
	 call_other(yakuza, "set_spell_mess2",
	            "Your legs have been broken by the Yakuza!");
	 call_other(yakuza, "set_spell_dam",30);
         move_object(yakuza, this_object());
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
                   "players/paulasx/temple/upper13", "west",
       	       "players/paulasx/temple/upper11", "south",
                   });
}

