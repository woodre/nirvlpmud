id(str){ return "mudman"; }

init(){
   add_action("doit", "doit");
}

doit(){
   object who;
   while(1){
      who = find_player("airwoman");
      if(who){
          if(random(100) < 5);
          tell_object(who, "Someone tells you: This is a test.\n");
      }
      continue;
    }
}
