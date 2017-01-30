decorpse() {
  object blah;
   object corpse;
   string i;
   corpse = present("corpse", environment(TP));
if(this_player()->query_guild_rank() < 2){ write("You can't use this skill yet.\n"); return 1; }
   if (!corpse) {

      write("No corpse present.\n");
      return 1;
      }
   write("You jab a needle into the "+corpse->short()+" sucking out its vital DNA.\n"+
             "You then inject the needle into your arm, making you feel energized.\n");
   say(TP->query_name() + " jabs a needle into the "+ corpse->short()+" sucking out its vital DNA.\n"+
           TP->query_name() + " then injects the needle into "+TP->query_possessive()+" arm.\n");
   if (sscanf(file_name(corpse),"obj/corpse%s",i)!=1) return 1;
   TP->heal_self(corpse->heal_value());
   destruct(corpse);
   return 1;
   }
