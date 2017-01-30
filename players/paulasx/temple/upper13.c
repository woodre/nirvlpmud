inherit "room/room";

object ninja;

reset(arg)
{
   if(!ninja || !living(ninja))
   {
      int i;
      for(i = 3; i; i--)
      {
         ninja = clone_object("obj/monster");
         call_other(ninja, "set_name", "ninja");
         call_other(ninja, "set_alias", "evil ninja");
         call_other(ninja, "set_level",14);
         call_other(ninja, "set_short", "An evil Ninja");
         call_other(ninja, "set_wc",12);
         call_other(ninja, "set_ac",4);
         call_other(ninja, "set_aggressive", 1);
         call_other(ninja, "set_move_at_reset");
         call_other(ninja, "set_whimpy");
         call_other(ninja, "set_chance",30);
         call_other(ninja, "set_spell_mess1",
	            "The Ninja snaps your neck.");
	 call_other(ninja, "set_spell_mess2",
	            "Your neck has been broken by the Ninja!");
	 call_other(ninja, "set_spell_dam",30);
         move_object(ninja, this_object());
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
                   "players/paulasx/temple/upper14", "west",
       	       "players/paulasx/temple/upper12", "east",
                   });
}
