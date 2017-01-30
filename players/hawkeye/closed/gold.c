midas() {
   
    int amt;
   object body;
   
   body = present("corpse",environment(this_player()));
   if(!body) {
      write("You can't perform the midas touch without the proper material.\n");
      return 1;
   }
   if(this_player()->query_attrib("int") < 12) {
      write("The Shade tells you:  You need to be more intelligent to perform this spell.\n");
      return 1;
   }
   
     amt=random(50) + 50;
   if(this_player()->query_spell_point() < 5) {
      write("You need more spell points to perform the midas touch.\n");
      return 1;
   }
   
write("You perform the midas touch on a corpse, and pocket "+amt+" coins.\n");
   say(capitalize(this_player()->query_real_name())+" turns a corpse into gold pieces and pockets the coins.\n");
   
   destruct(body);
this_player()->add_spell_point(-5);
this_player()->add_money(amt);
   return 1;
}
