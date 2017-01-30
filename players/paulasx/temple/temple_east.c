inherit "room/room";

object evil_monk;

reset(arg)
{
   if(!evil_monk || !living(evil_monk))
   {
      int i;
      for(i = 2; i; i--)
      {
         evil_monk = clone_object("obj/monster");
         call_other(evil_monk, "set_name", "monk");
         call_other(evil_monk, "set_alias", "evil monk");
         call_other(evil_monk, "set_level",14);
         call_other(evil_monk, "set_short", "An evil monk");
         call_other(evil_monk, "set_wc",14);
         call_other(evil_monk, "set_ac",5);
         call_other(evil_monk, "set_aggressive", 1);
         call_other(evil_monk, "set_move_at_reset");
         call_other(evil_monk, "set_whimpy");
         call_other(evil_monk, "set_chance",30);
         call_other(evil_monk, "set_spell_mess1",
                    "The evil monk lashes out with his tongue.");
         call_other(evil_monk, "set_spell_mess2",
                    "You are hit by the fiery tongue");
         call_other(evil_monk, "set_spell_dam",30);
         call_other(evil_monk,"add_money",500+random(300));
         move_object(evil_monk, this_object());
      }
   }
   if(arg)
      return;
   short_desc = "Temple Arena";
   long_desc = "You are in the east end of the arena.  There is an evil monk here.\n" +
                      "waiting to explain why you shouldn't be in here.  His tongue appears\n"  +
                      "to be flaming, and his tolerance for you is nonexistant.  RUN LIKE HELL!\n\n";
   set_light(1);
   dest_dir =
   ({
       "players/paulasx/temple/temple_ne", "north",
       "players/paulasx/temple/temple_se", "south",
       "players/paulasx/temple/temple_center", "west",
          });
}

