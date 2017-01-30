inherit "/obj/treasure";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(arg) return;
  
  set_id("gem");
  set_short("A "+CYN+"glowing"+NORM+" gem");
  set_long(
"This gem has an internal glow that washes strangely over your hands.  Almost\n"+
"too slowly to notice, it brigtens and dims from some inside souce that seems\n"+
"much to deep for this small gem.  To activate the magic invested in it, use\n"+
BLD("poem")+".\n");
  set_value(0);
  set_weight(1);
}
init() {
  ::init();
  if(TP->query_real_name()=="catwoman" || TP->query_real_name()=="illarion");
    add_action("cmd_poem","poem");
}
int cmd_poem() {
  write("The gem glows brightly, and words come into your mind.\n");
  write(CYN+"\
I was drifting aimlessly, and you chose me out of the blue,\n\
Startled but intrigued, I let you tell me what you knew.\n\
If you wanted me, I was willing to wait and find,\n\
If what ever touched your heart would also affect mine.\n");
  write(NORM+"The glow of them gem dims.\n");
  call_out("poem2",5,this_player());
  return 1;
}
poem2(object ob) {
  if(!ob) return;
  tell_object(ob,"The gem glows again, and you feel more words.\n");
  tell_object(ob,CYN+"\
As time marched it's way, and you told me how you feel,\n\
I found I too hoped that what we had could become real.\n\
Someone in my life who needs what I can give,\n\
Is what I need to make myself get up and really live.\n");
  tell_object(ob,NORM+"The glow from the gem dims again.\n");
  call_out("poem3",5,ob);
}
poem3(object ob) {
  if(!ob) return;
  tell_object(ob,
"Them gem glows brigtly once again, sending more words to your mind.\n");
  tell_object(ob,CYN+"\
Two things on my mind that I wasn't sure I liked,\n\
Yet I never dreamed those things would end in a relationship spiked.\n\
Your thoughts and feelings all too oft I could not see,\n\
And my already messed up schooling put unrelated stress on me.\n");
  tell_object(ob,NORM+"The glow in the gem dims for nearly the last time.\n");
  call_out("poem4",5,ob);
}
poem4(object ob) {
  if(!ob) return;
  tell_object(ob,"The gem glows a final time, and more words come to you.\n");
  tell_object(ob,CYN+"\
But I didn't know that those two things would end in love broken\n\
I wanted long perhaps forever before \"goodbye\" was spoken\n\
And if there's any way I you'll let me try again,\n\
You only need to tell me how and where and when.\n");
  tell_object(ob,NORM+"The gem goes dark, then vanishes.\n");
  destruct(this_object());
}
