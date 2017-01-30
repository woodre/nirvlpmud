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
      add_listen("main", "You hear nothing special.\n");
      add_smell("main", "An ashy odor fills the air.\n");
      add_property("NF");
      items = ({
            "floor", "A once polished floor covered with wreckage and dust",
            "pedestal", "A cracked piece of artwork that once held a scroll you can read",
            "scroll", "A small piece of parchment that people used to come to read",
            "ground", "A once polished floor covered with wreckage and dust",
            "walls", "A neutral colered white wall holding a slightly crooked sign",
            "sign", "A small sign hanging from one of the walls that you might be able to read"});
      
      dest_dir = ({
"/players/puppy/mem/2.c", "out"});
   }
}

init() {
   ::init() ;
   if(!present("donate",this_player())) 
      move_object(clone_object("/players/puppy/mem/donate.c"),this_player());
   add_action("blah","read");
   add_action("info","info");
}

blah(string str) {
   if(str == "sign")
      {
      write("You may create your very own memorial to someone\n");
      write("you may type 'info' to find out to find out more.\n");
      return 1;
   }
   else if(str == "scroll")
      {
      write("There are two days in every week about which we should not\n");
      write("worry.  Two days which should be kept from apprehension.\n");
      write("\n");
      write("One of these days is yesterday with it's mistakes and cares,\n");
      write("it's faults and blemishes, it's aches and pains.  Yesterday has\n");
      write("passed forever and is beyond our control.  All the money in the\n");
      write("world cannot bring back yesterday.  We can not erase a single\n");
      write("word we said.  Yesterday is gone.\n");
      write("\n");
      write("The other day we should not worry about is tomorrow with it's\n");
      write("possible adversities, it's blunders, it's large promises, and\n");
      write("poor performance.  Tomorrow is also beyond our immediate control.\n");
      write("Tomorrow sun will rise either in splendor or behind a mask of\n");
      write("clouds-but it will rise.  Until it does, we have no stake in\n");
      write("tomorrow, for it is yet unborn.\n");
      write("\n");
      write("This leaves only one day, Today.  Any person can fight the battles\n");
      write("of just one day.  It is only when you and I add the burden of those\n");
      write("two awful alternatives Yesterday and Tomorrow that we break down.\n");
      write("\n");
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
   write("shrines to Puppy (though you may worship me\n");
   write("if you choose to do so.)\n");
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
   write("balance\n");
   return 1;
}
