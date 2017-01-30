inherit "room/room";

object damian, godsword;

reset(arg){
   if(!damian || !living(damian))   {

         damian = clone_object("obj/monster");
         call_other(damian, "set_name", "damian");
         call_other(damian, "set_alias", "damian");
         call_other(damian, "set_level",20);
         call_other(damian, "set_short", "Damian, son of Satan");
         call_other(damian, "set_hp",500);
         call_other(damian, "set_wc",30);
         call_other(damian, "set_ac",17);
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
   long_desc = "You have stepped into the Lair of Damian, son of Satan.  He posses the\n" +
                      "sword that you need to defeat Benju, but you must kill him first to get it.\n"  +
                      "Your only hope of escape is <prayer> but it probably wont work!!!.\n\n";
   set_light(1);
   dest_dir = ({ 
               "players/paulasx/hell/hell17", "south",
                   });
}
init() {
  ::init();
  add_action("pray","pray");}

pray() {
    if(present("damian",this_object())) {
        write("Damian blocks any help from your God!!\n");
        return 1;
   }
    call_other(this_player(), "move_player", "pray#players/paulasx/temple/temple_center");
    return 1;
}

