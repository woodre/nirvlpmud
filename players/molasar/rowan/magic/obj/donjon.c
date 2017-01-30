

/* 
 * DONJON (1/24/94)
 * Prison where players who use deck.c are moved to.
 */

#define SENTENCE 1200    /* 20 minute sentence */

int start_time;

reset(arg) {
   if(arg)
     return;
   start_time = 0;
}

set_start_time(t) { if(t == 1) start_time = time(); }

short() { return "DONJON"; }

long() {
   write("You are trapped in an immaterial plane of existence.\n");
   write("You may perform no actions till your sentence has expired.\n");
   write("Time left: "+((start_time+SENTENCE)-time())+"\n");
}

init() {
#ifndef __LDMUD__
     add_action("no_do"); add_xverb("");
#else
     add_action("no_do", "", 3);
#endif
}

no_do() {
  if((time() < start_time + SENTENCE) && 
         this_player()->query_level() < 20) {
   write("You are imprisoned.  You may not perform any actions\n");
   write("until you're sentence is over.\n");
   write("Time left: ");
   when();
   write("\n");
   return 1;
  }
  write("Your sentence is over.\n");
  move_object(this_player(), "/room/church");
  this_player()->look();
  return 1;
}

when() {
   int i, j;
   i = (start_time + SENTENCE) - time();
   j = i/60/60/24;
   if(j == 1)
      write("1 day ");
   else if(j > 0)
          write(j+" days ");
   i -= j*60*60*24;
   j = i/60/60;
   if(j == 1)
      write("1 hour ");
   else if(j > 0)
          write(j+" hours ");
   i -=j*60*60;
   j = i/60;
   if(j == 1)
     write("1 minute ");
   else if(j > 0)
          write(j+" minutes ");
   i -= j*60;
   if(i == 1)
     write("1 second");
   else if(i > 0)
          write(i+" seconds");
   return 1;
}
