#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
   
   if(!arg) {
      set_light(1);
      set_short("A place to remember");
      set_long(
         "The floor has been slightly damaged from the attacks.  The\n"+
         "pedestal that once rested on the floor has fallen and been\n"+
         "cracked down the center.  A scroll has fallen to the ground\n"+
         "under a sign hanging from one of the walls.\n");
      items = ({
            "floor", "A once polished floor covered with wreckage and dust",
            "pedestal", "A cracked piece of artwork that once held a scroll for people to read",
            "scroll", "A small piece of parchment that people used to come to read",
            "ground", "A once polished floor covered with wreckage and dust",
            "walls", "A neurtal colered white wall holding a slightly crooked sign",
            "sign", "A small sign hanging from one of the walls that  you might be able to read"});
      
      dest_dir = ({
            "/players/puppy/mem/2.c", "out"});
      return 1;
   }
}

init() {
   if(!present("donate",this_player())) 
      move_object(clone_object("/players/puppy/mem/donate.c"),this_player());
   add_action("blah","read");
   add_action("info","info");
}

blah(string str) {
   if(str == "sign")
{
   write("You are reading the sign\n");
return 1;
}
   else if(str == "scroll")
{
   write("You are reading the scroll\n");
   return 1;
}
}

exit() {
   object don;
   if(this_player()) if(don = present("donate",this_player())) destruct(don);
}

info(){
   write("This will be your own personal memorial to\n");
   write("remember someone of your choosing.  You\n");
   write("will be able to create the room any way you\n");
   write("choose as long it follows the mud rules, No\n");
   write("shrines or to Puppy (though you may worship\n");
   write("me if you choose to do so.)\n");
   write("-Once your balance is 80,000 mail Puppy.\n");
   write("\n");
   write("Rules:\n");
   write("-Donations are NOT refundable!\n");
   write("-The ROOM you create will be available to all.\n");
   write("-One room allowed per player!\n");
   write("-All rooms are subject to Puppy's approval.\n");
   write("-Puppy reserves the right to change the rules.\n");
   write("\n");
   write("Commands:\n");
   write("rules - balance\n");
   return 1;
}
