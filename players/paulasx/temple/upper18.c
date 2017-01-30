inherit "room/room";

object dragon;

reset(arg)
{
   if(!dragon || !living(dragon))
   {
      int i;
      for(i = 9; i; i--)
      {
         dragon = clone_object("obj/monster");
         call_other(dragon, "set_name", "dragon");
         call_other(dragon, "set_alias", "evil dragon");
         call_other(dragon, "set_level",16);
         call_other(dragon, "set_short", "An evil Dragon");
         call_other(dragon, "set_wc",14);
         call_other(dragon, "set_ac",6);
         call_other(dragon, "set_aggressive", 1);
         call_other(dragon, "set_move_at_reset");
         call_other(dragon, "set_whimpy");
         call_other(dragon, "set_chance",30);
         call_other(dragon, "set_spell_mess1",
	            "The Dragon snaps your neck.");
	 call_other(dragon, "set_spell_mess2",
	            "Your neck has been broken by the Dragon!");
	 call_other(dragon, "set_spell_dam",30);
         move_object(dragon, this_object());
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
                   "players/paulasx/temple/final_room", "north",
       	       "players/paulasx/temple/upper17", "south",
                   });
}
init() {
  ::init();
  add_action("north","north");}

north() {
    if(present("dragon",this_object())) {
        write("The dragon bars the way.\n");
        return 1;
   }
    call_other(this_player(), "move_player", "north#players/paulasx/temple/upper19");
    return 1;
}
