inherit "room/room";

object prison_guard;

reset(arg)
{
   if(!prison_guard || !living(prison_guard))
   {
      int i;
      for(i = 5; i; i--)
      {
         prison_guard = clone_object("obj/monster");
         call_other(prison_guard, "set_name", "guard");
         call_other(prison_guard, "set_alias", "prison guard");
/* Changed from lev. 14 to 12  -Snow */
         call_other(prison_guard, "set_level",12);
         call_other(prison_guard, "set_short", "A prison guard");
         call_other(prison_guard, "set_wc",14);
         call_other(prison_guard, "set_ac",5);
         call_other(prison_guard, "set_aggressive", 1);
         call_other(prison_guard, "set_move_at_reset");
         call_other(prison_guard, "set_whimpy");
         call_other(prison_guard, "set_chance",30);
         call_other(prison_guard, "set_spell_mess1",
                    "The guard burns you with his eyes.");
         call_other(prison_guard, "set_spell_mess2",
                    "You are hit by the fiery beam");
         call_other(prison_guard, "set_spell_dam",30);
            call_other(prison_guard, "add_money", 50*random(10));
         move_object(prison_guard, this_object());
      }
   }
   if(arg)
      return;
   short_desc = "Prison Hallway";
   long_desc = "You are in the basement of the Temple.  It is used as a prison for\n" +
                      "avatars like yourself.  If you are captured by the Benju, you will be put\n"  +
                      "into a cell until execution time.  You only hope is to destroy the guards!\n\n";
   set_light(1);
   dest_dir =
   ({
       "players/paulasx/prison/cellhall3", "east",
       "players/paulasx/prison/cell5", "west",
          });
}
