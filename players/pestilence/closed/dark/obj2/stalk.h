object stalkee;
int stalk;
string stalkee_name;

set_stalkee(ob, str, i){
   if(ob){
      stalkee = ob;
      stalkee_name = str;
      stalk = i;
   }
   return 1;
}
stalk(str){
   object assassin, victim;
   if(!str){ notify_fail("Usage: stalk <who>\n"); }
   if(str == "off"){
      write("You are no longer stalking "+stalkee->query_name()+".\n");
      set_heart_beat(0);
      stalk = 0;
      return 1;
   }
   stalkee = find_player(str);
   if(!present(str, environment(this_player()))){
      write("That is not here.\n");
      return 1;
   }
   if(stalkee->query_level() > 20){
      write("You can't stalk wizards.\n");
      return 1;
   }
   if(!str){
      write("Stalk who?\n");
      return 1;
   }
   if(this_player()->query_spell_point() < 15){
      write("You are too low on power to stalk.\n");
      return 1;
   }
   if(!str){
      write("Usage: stalk <who> or stalk off\n");
      return 1;
   }
   if(stalk == 1){
      write("You are already stalking someone.\n");
      return 1;
   }
   else {
      write("You begin stalking "+stalkee->query_name()+".\n");
      stalk = 1;
      this_player()->add_spell_point(-15);
      set_heart_beat(1);
      return 1;
   }
}

my_heart_beat(){
   if(stalk == 1){
      if(environment(stalkee) != environment(environment(this_object()))){
         move_object(environment(this_object()), environment(stalkee));
         tell_object(environment(this_object()),
            "You continue stalking "+stalkee->query_name()+".\n");
         command("look", environment(this_object()));
      }
      return 1;
   }
   return 1;
}
