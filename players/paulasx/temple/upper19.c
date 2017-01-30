inherit "room/room";

object damian, godsword;

reset(arg){
   if(!damian || !living(damian))   {

         damian = clone_object("obj/monster");
         call_other(damian, "set_name", "damian");
         call_other(damian, "set_alias", "damian");
         call_other(damian, "set_level",18);
         call_other(damian, "set_short", "Damian, son of Satan");
         call_other(damian, "set_hp",350);
         call_other(damian, "set_wc",20);
         call_other(damian, "set_ac",12);
         call_other(damian, "set_aggressive", 1);
         call_other(damian, "set_move_at_reset");
         call_other(damian, "set_whimpy");
         call_other(damian, "set_chance",50);
         call_other(damian, "set_spell_mess1",
	            "Damian blows fire at you!!");
	 call_other(damian, "set_spell_mess2",
	            "Damian roasts your ass!!!");
	 call_other(damian, "set_spell_dam",40);
        godsword = clone_object ("players/paulasx/weapons/godsword.c");
        move_object (damian, this_object());
        move_object (godsword, damian);

         }
   if(arg)
      return;
   short_desc = "Damian's Lair";
   long_desc = "You have stepped into the Lair of Damian, son of Satan.  He possesses the\n" +
                      "sword that you need to defeat Benju, but you must kill him first to get it.\n"  +
                      "Your only hope of escape is <prayer> but it probably won't work!!!.\n\n";
   set_light(1);
dest_dir = ({
                   "players/paulasx/temple/final_room", "north",
       	       "players/paulasx/temple/upper18", "south",
                   });
}
init() {
  ::init();
  add_action("north","north");}

north() {
if(present("damian")) {
  write("Damian bars the way!\n"); return 1; }
else {
  this_player()->move_player("north#players/paulasx/hell/hell1.c");
  return 1; }
}
