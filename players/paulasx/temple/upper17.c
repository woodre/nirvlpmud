inherit "room/room";

object buntaro;

reset(arg)
{
   if(!buntaro || !living(buntaro))
   {
      int i;
      for(i = 3; i; i--)
      {
         buntaro = clone_object("obj/monster");
         call_other(buntaro, "set_name", "buntaro");
         call_other(buntaro, "set_alias", "evil buntaro");
         call_other(buntaro, "set_level",13);
         call_other(buntaro, "set_short", "An evil Buntaro");
         call_other(buntaro, "set_wc",10);
         call_other(buntaro, "set_ac",4);
         call_other(buntaro, "set_aggressive", 1);
         call_other(buntaro, "set_move_at_reset");
         call_other(buntaro, "set_whimpy");
         call_other(buntaro, "set_chance",30);
         call_other(buntaro, "set_spell_mess1",
	            "The Buntaro snaps your neck.");
	 call_other(buntaro, "set_spell_mess2",
	            "Your neck has been broken by the Buntaro!");
	 call_other(buntaro, "set_spell_dam",30);
         move_object(buntaro, this_object());
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
                   "players/paulasx/temple/upper18", "north",
       	       "players/paulasx/temple/upper16", "west",
                   });
}
init() {
  ::init();
  add_action("north","north");}

north() {
    if(present("buntaro",this_object())) {
        write("The buntaro bars the way.\n");
        return 1;
   }
    call_other(this_player(), "move_player", "north#players/paulasx/temple/upper18");
    return 1;
}
