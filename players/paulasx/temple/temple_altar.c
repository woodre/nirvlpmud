inherit "room/room";

object shagath;
int click;

reset(arg){
    if(arg)
      return;
   click = 0;
   short_desc = "Altar in the Temple of Bishamon";
   long_desc = "You are standing in front of the Altar of Bishamon.  This Altar is claimed\n" +
                      "to have great powers.  No one has made it out of the temple alive after\n" +
                      "seeing the Altar.  I guess you have just signed your own death certificate.\n" +
                      "Benju has declared the altar offlimits to everyone.  He put a curse on the\n" +
                      "altar and warns that Shagath, the Avatar of Kali, will fight to the death to\n" +
                      "protect Benju's altar.  There is a strange hallway to the north, but it looks\n" +
                      "as if the floor has given out, you had better not investigate, who knows\n" +

                      "where it goes!!\n\n";
   dest_dir =
   ({
/*
       "players/paulasx/hell/hell1", "north",
*/
	"players/paulasx/temple/final_room","north",
       "players/paulasx/temple/temple_north", "south",
    });
}

init()
{
   ::init();
   add_action("call_shagath", "pray");
}

call_shagath(arg){
   if(click) { write("Nothing happens.\n"); return 1; }
   click = 1;
      write("You pray and will pay.\n");
      say(call_other(this_player(), "query_name") +
          " prays, and gets you all in big trouble.\n");
      summon_avatar();
      return 1; }

summon_avatar()
{
   if(!shagath || !living(shagath))
   {
      object player;
      player = this_player();
 
      tell_room(this_object(),
                "The Whole Temple shakes as you feel the Wrath of Kali!\n");
      tell_room(this_object(),
                "Shagath the avatar of Kali arrives in a puff of smoke!\n");
      shagath  = clone_object("obj/monster");
      call_other(shagath, "set_name", "shagath");
      call_other(shagath, "set_alias", "avatar");
      call_other(shagath, "set_level",19);
      call_other(shagath, "set_al", -300);
      call_other(shagath, "set_short",
                 "Shagath the avatar of Kali");
      call_other(shagath, "set_wc",50);
    shagath->set_hp(800);
      call_other(shagath, "set_ac",18);
      call_other(shagath, "set_aggressive", 1);
      call_other(shagath, "set_chance",40);
      call_other(shagath, "set_spell_mess1",
                 "Shagath throws Hellfire.");
      call_other(shagath, "set_spell_mess2",
                 "You are hit by the Hellfire");
      call_other(shagath, "set_spell_dam", 60);
      move_object(shagath, this_object());
      call_other(shagath, "attack_object", player);
      return 1;
   }
}

