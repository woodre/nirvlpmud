inherit "obj/treasure";
int played;

reset(arg) {
   if(!arg) {
   played=0;
   set_id("pipes");
   set_alias("panpipes");
   set_short("A set of wooden panpipes");
   set_long("The panpipes are made of exquisite wood and the tone is perfect.\n");
   set_value(750);
   set_weight(1);
}
}

init() {
   ::init();
   add_action("play","play");
}
play(str) {
   if((!str) || !id(str)) return 0;
   write("Blowing gently into the pipes produces a haunting, sorrowful melody.\n");
   say(this_player()->query_name()+" plays a sorrowful song on some panpipes.\n");
   if(!played) {
      write("A magical energy makes you feel good...\n");
      if(this_player()->query_alignment() < 1000) {
         this_player()->add_alignment(random(100));
      }
      played=1;
      call_out("pipe_reset",1200);
   }
   return 1;
}

pipe_reset() {
   played=0;
   call_out("pipe_reset",1200);
}
