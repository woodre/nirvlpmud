inherit "room/room";

object dog;

reset(arg)
{
   if(!dog || !living(dog))
   {
      int i;
      for(i = 1; i; i--)
      {
         dog = clone_object("obj/monster");
         call_other(dog, "set_name", "hound");
         call_other(dog, "set_alias", "hell hound");
         call_other(dog, "set_level",15);
         call_other(dog, "set_short", "A hell hound");
         call_other(dog, "set_wc",14);
         call_other(dog, "set_ac",6);
         call_other(dog, "set_aggressive", 1);
         call_other(dog, "set_move_at_reset");
         call_other(dog, "set_whimpy");
         call_other(dog, "set_chance",30);
         call_other(dog, "set_spell_mess1",
	            "The dog burns you with his tongue.");
	 call_other(dog, "set_spell_mess2",
	            "You are hit by the fiery fire");
	 call_other(dog, "set_spell_dam",30);
         move_object(dog, this_object());
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
                   "players/paulasx/temple/upper6", "west",
       	       "players/paulasx/temple/upper4", "east",
                   });
}
