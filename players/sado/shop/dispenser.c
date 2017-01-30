#define DRUNK "/players/sado/shop/drunk.c"

inherit "/obj/treasure.c";

reset(arg)
{
   if(!arg)
      {
      set_id("dispenser");
      set_long("This is a dispenser for the distribution of Sado's patented drunken speech\n"+
         "slurrer.  Type 'help drunk' for info on the device.\n"+
         "Or press the button to receive your very own device.\n");
      set_short("A drunken-device dispenser");
   }
}

init()
{
   ::init();
   add_action("press","press");
   add_action("press","push");
   add_action("help","help");
}

help(str)
{
   if(str!="drunk") return 0;
   cat("/players/sado/shop/drunk_help");
   return 1;
}

press(str)
{
   if(str!="button") return 0;
   if(present("drunk",this_player()))
      {
      write("You already have a drunken device!\n");
      return 1;
   }
   write("As you press the button, a little demon runs out of a flap, jumps onto your hand\n");
   write("and climbs up your arm, into your ear.  You feel some hammering inside your\n");
   write("skull, then an odd sense of confusion, and the demon comes running back out of\n");
   write("your ear.  He turns to face you, salutes, and says:\n");
   write("Device installed as per request!\n");
   write("He then runs back into the dispenser through his little flap, and disappears.\n");
   move_object(clone_object(DRUNK),this_player());
   log_file("sado.drunk",ctime()+" "+this_player()->query_real_name()+"\n");
   return 1;
}

get() {return 0;}
