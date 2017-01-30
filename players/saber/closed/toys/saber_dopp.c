id(str)  { return str == "saber" || str == "saber_dopp"; }

short()  {  return
"Can you see the sparkle in the eyes of Saber the Bardic One (Flamboyant)";
        }

long()  {
  write(
"Can you see the sparkle in the eyes of Saber the Bardic One (Flamboyant)"+
      "\n");
  write("Saber is cloaked in illusion.\n"+
        "You gain no more than a faint image of a blue sparkling eyes.\n");
        }

init()  {
#ifndef __LDMUD__
   add_action("remote_me"); add_xverb("");
#else
  add_action("remote_me","",3);
#endif
        }

remote_me(str)  {
  if(find_player("saber"))  {
    tell_object(find_player("saber"),
      "*]"+this_player()->query_name()+":"+query_verb()+" "+str+"\n");
      return 0;
   }
}

query_gender()      { return "male"; }
query_level()       { return 200; }
query_guild_name()  { return "bard"; }
query_objective()   { return "him"; }
query_possessive()  { return "his"; }
query_pronoun()     { return "he"; }
is_living()         { return 1; }
is_player()         { return 1; }
query_interactive() { return 1; }
