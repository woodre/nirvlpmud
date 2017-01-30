#include "/players/puppy/define.h"
inherit "room/room";

reset(arg) {
   if(arg) return;
   
   set_short("Murky Liquid");
   set_long(
      "A thick liquid substance that makes moving almost impossible.\n"+
      "It feels like it is eating away at your skin.  What have you\n"+
      "gotten yourself into now?  You'd better get out of here quick.\n"+
      "Maybe you could go into the 'forest'.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "There is a nasty smell to this liquid.");
   items = ({
         "thick liquid substance", "A murky fluid that makes movement hard",
         "liquid substance", "A murky fluid that makes movement hard",
         "liquid", "A murky fluid that makes movement hard",
		 "forest", "Thick trees covering a small path into an unknown land",
         "substance", "A murky fluid that makes movement hard",
         "thick substance", "A murky fluid that makes movement hard"});
   dest_dir = ({
         "/room/farmroad2.c", "out"});
   return 1; }

init(){
   ::init();
   add_action("noforest", "forest");
}
noforest(string str) {
   if (!str || str != "forest"){
      notify_fail("Where are you trying to go?\n");
      write("You squeeze through the trees\n");
      say(this_player()->query_name()+" squeezes through the trees.\n");
      move_object(this_player(),"/players/puppy/s/rm/1.c");
      tell_room("players/puppy/s/rm/1.c",
         this_player()->query_name()+" arrives.\n");
      write_file("/players/puppy/logs/smurf",
         this_player()->query_real_name()+"   "+ ctime()[4..15]+"\n");
      command("look",this_player());
      return 1;}
}
