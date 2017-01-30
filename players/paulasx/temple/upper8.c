inherit "room/room";

object reaper;

reset(arg)
{
   if(!reaper || !living(reaper))
   {
      int i;
      for(i = 1; i; i--)
      {
         reaper = clone_object("obj/monster");
         call_other(reaper, "set_name", "reaper");
         call_other(reaper, "set_alias", "grim reaper");
         call_other(reaper, "set_level",19);
         call_other(reaper, "set_short", "The Grim Reaper");
         call_other(reaper, "set_wc",16);
         call_other(reaper, "set_ac",7);
         call_other(reaper, "set_aggressive", 1);
         call_other(reaper, "set_move_at_reset");
         call_other(reaper, "set_whimpy");
         call_other(reaper, "set_chance",30);
         call_other(reaper, "set_spell_mess1",
	            "The reaper sells your soul to Satan.");
	 call_other(reaper, "set_spell_mess2",
	            "Your soul is sold to Satan!");
	 call_other(reaper, "set_spell_dam",30);
         move_object(reaper, this_object());
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
                   "players/paulasx/temple/upper9", "east",
       	       "players/paulasx/temple/upper7", "south",
                   });
}

