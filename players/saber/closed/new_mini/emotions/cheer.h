cheer(str)  {
 if(!str)  {
  write("You cheer wildly.\n");
  say(tp+" cheers wildly.\n");
  return 1;
     }
  str = CAP;
  write("You cheer wildly for "+str+".\n");
  say(tp+" cheers wildly for "+str+".\n");
  return 1;
        }
