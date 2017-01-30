inherit "room/room";

object henchmen;

reset(arg)
{
   if(!henchmen || !living(henchmen))
   {
      int i;
      for(i = 3; i; i--)
      {
         henchmen = clone_object("obj/monster");
         call_other(henchmen, "set_name", "henchmen");
         call_other(henchmen, "set_alias", "evil henchmen");
         call_other(henchmen, "set_level",14);
         call_other(henchmen, "set_short", "An evil Henchmen");
         call_other(henchmen, "set_wc",12);
         call_other(henchmen, "set_ac",4);
         call_other(henchmen, "set_aggressive", 1);
         call_other(henchmen, "set_move_at_reset");
         call_other(henchmen, "set_whimpy");
         call_other(henchmen, "set_chance",30);
         call_other(henchmen, "set_spell_mess1",
	            "The Henchmen snaps your neck.");
	 call_other(henchmen, "set_spell_mess2",
	            "Your neck has been broken by the Henchmen!");
	 call_other(henchmen, "set_spell_dam",30);
         move_object(henchmen, this_object());
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
                   "players/paulasx/temple/upper16", "north",
       	       "players/paulasx/temple/upper14", "south",
                   });
}
init() {
  ::init();
  add_action("north","north");}

north() {
    if(present("henchmen",this_object())) {
        write("The henchmen bars the way.\n");
        return 1;
   }
    call_other(this_player(), "move_player", "north#players/paulasx/temple/upper16");
    return 1;
}
