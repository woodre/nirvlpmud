inherit "room/room";

object barbarian;

reset(arg)
{
   if(!barbarian || !living(barbarian))
   {
      int i;
      for(i = 5; i; i--)
      {
         barbarian = clone_object("obj/monster");
         call_other(barbarian, "set_name", "barbarian");
         call_other(barbarian, "set_alias", "large barbarian");
         call_other(barbarian, "set_level",15);
         call_other(barbarian, "set_short", "A large barbarian");
         call_other(barbarian, "set_wc",10);
         call_other(barbarian, "set_ac",4);
         call_other(barbarian, "set_aggressive", 1);
         call_other(barbarian, "set_move_at_reset");
         call_other(barbarian, "set_whimpy");
         call_other(barbarian, "set_chance",30);
         call_other(barbarian, "set_spell_mess1",
	            "The barbarian rapes you.");
	 call_other(barbarian, "set_spell_mess2",
	            "You have been raped by the barbarian!");
	 call_other(barbarian, "set_spell_dam",30);
         move_object(barbarian, this_object());
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
                   "players/paulasx/temple/upper10", "east",
       	       "players/paulasx/temple/upper8", "west",
                   });
}
