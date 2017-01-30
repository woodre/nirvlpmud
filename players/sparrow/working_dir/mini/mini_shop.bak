int is_succubus, is_larn, is_gypsy, is_kender, is_blade, is_gothic, is_canine, is_feline;
int time, mini_status;
string QUOTE;
#define tp this_player()->query_name()

id(str)  { return str == "guard"; }
short()  { return "A guard dressed in white";  }
long()  {
   write(
      "City guard (white knight) (male)\n"+
      "You see a guard dressed all in white, wearing chainmail and carrying\n"+
      "a longsword.  You would guess that he belongs to the city guard of Ryllian.\n"+
      "\nThis guard can help you with your mini guilds.\n"+
      "   If you type <restore> all of your mini guilds which\n"+
      "   you have lost will be restored.  If by some chance\n"+
      "   you have too many mini guilds, type <nix> <guildname>\n"+
      "   to remove yourself from it.  Use one of the following\n"+
      "   as nix names: larn, gypsy, kender, blade, goth, feline.\n"+
      "   canine or succubus.\n"+
      "   If you are a Ring Master, type <ring>.\n"+
      "\n"+
      "City guard is in good shape.\n"+
      "       City guard is carrying:\n"+
      "A suit of chainmail (worn).\n"+
      "A longsword (wielded).\n"+
      "\n");
}

init()  {
   add_action("restore","restore");
   add_action("nix","nix");
   add_action("kill","kill");
   add_action("ring","ring");
}

restore()  {
   object ob, item;
   object temp;
   int count;
   
   if(!restore_object("players/saber/closed/new_mini/stats/"+this_player()->query_real_name()))  {
      write("You are not in any mini guilds.\n");
      return 1;
   }
   
   if(is_succubus)  { count = count + 1;  }
   if(is_larn)      { count = count + 1;  }
   if(is_gypsy)     { count = count + 1;  }
   if(is_kender)    { count = count + 1;  }
   if(is_blade)     { count = count + 1;  }
   if(is_gothic)      { count = count + 1;  }
   if(is_canine)    { count = count + 1;  }
   if(is_feline)    { count = count + 1;  }
   
   if(count > 2)  {
      write("You are in more than 2 mini guilds.\n"+
         "You must <nix> yourself down to 2.\n");
      return 1;
   }
   
   command("break_knife");
   command("i_am_no_feline");
   command("i_am_no_canine");
   command("i_am_no_succubus");
   command("abandon_larn");
   command("i_am_no_kender");
   command("i_am_no_goth");
   command("i_am_no_gypsy");
   
   if(is_succubus && !present("succubus_obj", this_player())) move_object(clone_object("/players/saber/closed/new_mini/succubus.c"), this_player());
   if(is_larn && !present("larn_obj", this_player())) move_object(clone_object("/players/saber/closed/new_mini/larn.c"), this_player());
   if(is_gypsy && !present("gypsy_obj", this_player())) move_object(clone_object("/players/saber/closed/new_mini/gypsy.c"), this_player());
   if(is_kender && !present("kender_obj", this_player())) move_object(clone_object("/players/saber/closed/new_mini/kender.c"), this_player());
   if(is_blade && !present("blade_obj", this_player())) move_object(clone_object("/players/saber/closed/new_mini/blade.c"), this_player());
   if(is_gothic && !present("gothic_obj", this_player())) move_object(clone_object("/players/saber/closed/new_mini/gothic.c"), this_player());
   if(is_canine && !present("canine_obj", this_player())) move_object(clone_object("/players/saber/closed/new_mini/canine.c"), this_player());
   if(is_feline && !present("feline_obj", this_player())) move_object(clone_object("/players/saber/closed/new_mini/feline.c"), this_player());
   
   write("Your mini guild item(s) has returned!\n");
   return 1;
}

nix(str)  {
   
   if(!str)  {
      write("What mini guild do you want to nix?\n");
      return 1;
   }
   
   if(str != "succubus" && str != "gypsy" && str != "kender" && str != "blade" && str != "goth" && str != "feline" && str != "canine" && str != "larn")  {
      write("That was not a valid choice.\n");
      return 1;
   }
   
   restore_object("players/saber/closed/new_mini/stats/"+this_player()->query_real_name());
   
   if(str == "succubus") is_succubus = 0;
   if(str == "gypsy")    is_gypsy = 0;
   if(str == "kender")   is_kender = 0;
   if(str == "larn")     is_larn = 0;
   if(str == "blade")    is_blade = 0;
   if(str == "goth")     is_gothic = 0;
   if(str == "canine")   is_canine = 0;
   if(str == "feline")   is_feline = 0;
   
   save_object("players/saber/closed/new_mini/stats/"+this_player()->query_real_name());
   write("You are no longer "+capitalize(str)+".\n");
   return 1;
}

ring()  {
   if(tp == "Saber" ||
         tp == "Puppy" ||
      tp == "Stone" ||
      tp == "Nikki"  ||
      tp == "Snowfire"  ||
      tp == "Galadriel"  ||
      tp == "Daranath")  {
      move_object(clone_object("/players/saber/closed/master.c"),this_player());
      write("You recover your master ring.\n");
      return 1;
   }
}

kill(str)  {
   if(str == "guard")  {
      write("The guard dodges your blow.\n");
      say(this_player()->query_name()+" attack the guard.\n"+
         "The guard steps out of the way.\n");
      return 1;
   }
}

get()  { return 0; }
