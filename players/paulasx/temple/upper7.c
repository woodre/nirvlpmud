inherit "room/room";

object warrior;

reset(arg)
{
   if(!warrior || !living(warrior))
   {
      int i;
      for(i = 10; i; i--)
      {
         warrior = clone_object("obj/monster");
         call_other(warrior, "set_name", "warrior");
         call_other(warrior, "set_alias", "battle warrior");
         call_other(warrior, "set_level",15);
         call_other(warrior, "set_short", "A battle warrior");
         call_other(warrior, "set_wc",12);
         call_other(warrior, "set_ac",4);
         call_other(warrior, "set_aggressive", 1);
         call_other(warrior, "set_move_at_reset");
         call_other(warrior, "set_whimpy");
         call_other(warrior, "set_chance",30);
         call_other(warrior, "set_spell_mess1",
	            "The warrior crushes your head.");
	 call_other(warrior, "set_spell_mess2",
	            "Your head is crushed by the warrior");
	 call_other(warrior, "set_spell_dam",30);
         move_object(warrior, this_object());
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
                   "players/paulasx/temple/upper8", "north",
       	       "players/paulasx/temple/upper6", "south",
                   });
}
