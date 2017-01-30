inherit "room/room";

object diamyo;

reset(arg){
   if(!diamyo || !living(diamyo))   {
         diamyo = clone_object("obj/monster");
         call_other(diamyo, "set_name", "diamyo");
         call_other(diamyo, "set_alias", "thomas");
         call_other(diamyo, "set_level",12);
         call_other(diamyo, "set_short", "Diamyo of Aru");
         call_other(diamyo, "set_wc",13);
         call_other(diamyo, "set_ac",5);
         call_other(diamyo, "set_aggressive", 0);
         call_other(diamyo, "set_move_at_reset");
         call_other(diamyo, "set_whimpy");
         call_other(diamyo, "set_chance",10);
         call_other(diamyo, "set_spell_mess1",
                    "The Diamyo sentances you to death");
         call_other(diamyo, "set_spell_mess2",
                    "You soul has been enslaved by Diamyo!");
         call_other(diamyo, "set_spell_dam",2);
         move_object(diamyo, this_object());
         }
   if(arg)
      return;
   short_desc = "Temple Priest Room";
   long_desc = "Finally, you have found the Diamyo of Aru, the keeper of good in the\n" +
                      "Temple.  He has waited for an Avatar of your skills and cunning for a long\n"  +
                      "time to get the Godsword, and return it to him, to defeat evil.\n\n";
   set_light(1);
   dest_dir = ({ 
               "players/paulasx/temple/temple_entrance", "out",
               "players/paulasx/temple/final_room", "south",
                   });
}
init() {
  ::init();
  add_action("give","give");
}

give(str) {
  string what, who, ob_file, ob_file_name, trash;
  object ob, diamyo;
  if(!str) return;
  if(sscanf(str,"%s to %s",what,who)!=2) return;
  ob=present(what,this_player());
  if(!ob) return;
  ob_file=file_name(ob);
  if(sscanf(ob_file,"%s#%s",ob_file_name,trash)!=2) return;
  if(ob_file_name=="players/paulasx/weapons/godsword") {
    diamyo=present("diamyo",environment(this_player()));
    if(!diamyo) return;
    move_object(ob,diamyo);
        write("Diamyo says: You are truely a great Avatar.  You have defeated the great evils\n" +
               "             of the temple.  You have completed this quest.  I can now defeat\n" +
               "             evil and restore the Temple to its original order.\n\n" +
                "\nYor have fulfilled and solved the terms of this quest, congratulations!!\n\n" +
                "Diamyo says: I thank you and so does all of Legacy!!\n\n"); 
          call_other(this_player(),"set_quest","temple_quest");
          destruct(ob);
        return 1;
       }
}

