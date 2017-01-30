inherit "room/room";

object demon;

reset(arg)
{
   if(!demon || !living(demon))
   {
      demon = clone_object("obj/monster");
      call_other(demon, "set_name", "demon");
      call_other(demon, "set_short", "A bastard demon");
      call_other(demon, "set_aggressive", 1);
      call_other(demon, "set_level",12);
      call_other(demon, "set_wc", 15);
      call_other(demon, "set_ac", 2);
      call_other(demon, "set_chance",20);
      call_other(demon, "set_spell_mess1",
                "The demon utters a wailing scream.");
      call_other(demon, "set_spell_mess2",
                "The scream hurts you bad.");
      call_other(demon, "set_spell_dam",40);
      move_object(demon, this_object());
   }
   if(arg)
      return;
   short_desc = "Bottom of stairway";
   long_desc = "You are at the bottom of the stairway.\n" +
               "The stairway goes up and you can go further\n" +
               "into the prison to the west.\n";
   set_light(0);
   dest_dir =
   ({
       "players/paulasx/temple/stairway", "up",
       "players/paulasx/prison/cellhall1", "west",
       "players/paulasx/prison/cellhall2", "east"
    });
}

init()
{
   ::init();
   add_action("west","west");
   add_action("east","east");
}

west()
{
   if(call_other(this_player(), "query_level", 0) < 20)
   {
      if(demon && present("demon"))
      {
         write("The demon is in the way!\n");
         return 1;
      }
   }
}

east()
{
   if(call_other(this_player(), "query_level", 0) < 20)
   {
      if(demon && present("demon"))
      {
         write("The demon is in the way!\n");
         return 1;
      }
   }
}
