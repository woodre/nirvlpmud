inherit "room/room";

object bushi;

reset(arg)
{
   if(!bushi || !living(bushi))
   {
      int i;
      for(i = 8; i; i--)
      {
         bushi = clone_object("obj/monster");
         call_other(bushi, "set_name", "bushi");
         call_other(bushi, "set_alias", "evil bushi");
         call_other(bushi, "set_level",15);
         call_other(bushi, "set_short", "An evil Bushi");
         call_other(bushi, "set_wc",13);
         call_other(bushi, "set_ac",6);
         call_other(bushi, "set_aggressive", 1);
         call_other(bushi, "set_move_at_reset");
         call_other(bushi, "set_whimpy");
         call_other(bushi, "set_chance",30);
         call_other(bushi, "set_spell_mess1",
	            "The Bushi snaps your neck.");
	 call_other(bushi, "set_spell_mess2",
	            "Your neck has been broken by the Bushi!");
	 call_other(bushi, "set_spell_dam",30);
         move_object(bushi, this_object());
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
                   "players/paulasx/temple/upper17", "east",
       	       "players/paulasx/temple/upper15", "south",
                   });
}
init() {
  ::init();
  add_action("east","east");}

east() {
    if(present("bushi",this_object())) {
        write("The bushi bars the way.\n");
        return 1;
   }
    call_other(this_player(), "move_player", "east#players/paulasx/temple/upper17");
    return 1;
}
