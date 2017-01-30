inherit "room/room";

object samurai;

reset(arg)
{
   if(!samurai || !living(samurai))
   {
      int i;
      for(i = 5; i; i--)
      {
         samurai = clone_object("obj/monster");
         call_other(samurai, "set_name", "samurai");
         call_other(samurai, "set_alias", "Benju samurai");
         call_other(samurai, "set_level",16);
         call_other(samurai, "set_short", "A Benju samurai");
         call_other(samurai, "set_wc",13);
         call_other(samurai, "set_ac",5);
         call_other(samurai, "set_aggressive", 1);
         call_other(samurai, "set_move_at_reset");
         call_other(samurai, "set_whimpy");
         call_other(samurai, "set_chance",30);
         call_other(samurai, "set_spell_mess1",
	            "The samurai stabs you.");
	 call_other(samurai, "set_spell_mess2",
	            "You have been stabbed by the samurai!");
	 call_other(samurai, "set_spell_dam",30);
         move_object(samurai, this_object());
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
                   "players/paulasx/temple/upper11", "north",
       	       "players/paulasx/temple/upper9", "west",
                   });
}
