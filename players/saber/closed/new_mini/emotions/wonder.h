wonder(str)  {
 if(!str)  {
  write("You wonder...\n");
  say(tp+" wonders...\n");
  return 1;
     }
  write("You wonder "+str+"?\n");
  say(tp+" wonders "+str+"?\n");
  return 1;
        }
