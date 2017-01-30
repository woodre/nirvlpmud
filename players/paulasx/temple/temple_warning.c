inherit "room/room";

object deacon;

reset(arg)
{
   if(!deacon || !living(deacon))
   {
         deacon = clone_object("obj/monster");
         call_other(deacon, "set_name", "deacon");
         call_other(deacon, "set_alias", "thomas");
         call_other(deacon, "set_level",4);
         call_other(deacon, "set_short", "Deacon Thomas");
         call_other(deacon, "set_wc",3);
         call_other(deacon, "set_ac",2);
         call_other(deacon, "set_aggressive", 0);
         call_other(deacon, "set_move_at_reset");
         call_other(deacon, "set_whimpy");
         call_other(deacon, "set_chance",10);
         call_other(deacon, "set_spell_mess1",
                    "The Deacon spits at you");
         call_other(deacon, "set_spell_mess2",
                    "Your have been slapped by Deacon Thomas!");
         call_other(deacon, "set_spell_dam",2);
         move_object(deacon, this_object());
   }
   if(arg)
      return;
   short_desc = "Temple Gathering Area";
   long_desc = "You are in a rather large gathering area, where the congregation used \n" +
                      "to meet before services.  There is a strange and fluttered man in front\n"  +
                      "of you that might have an important message...\n\n";
   set_light(1);
   dest_dir = ({ 
                   "players/paulasx/temple/temple_dogs1", "north",
               "players/paulasx/temple/temple2", "south",
                   });
}
init() {
  ::init();
  add_action("ask_benju","ask");}

ask_benju() {
    if(present("deacon",this_object())) {
        write("Deacon Thomas says: Finally, someone that can help me! I hope you can help me!!\n\n" +
                "Deacon Thomas says: Benju Matsutomo has taken over the Temple and has placed\n" +
                "              evil all around.. the only hope is to find the missing Godsword\n" +
		"             and return it to the Diamyo.\n\n"+
                "Deacon Thomas says: Please hurry!! we need your help!! Please!!\n\n");
        return 1;
       }
}
