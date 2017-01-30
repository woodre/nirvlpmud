#define ROSE "rose.c"
#define OREO "oreo.c"
#define CHOCS "chocolate.c"
#define DOGGIE "doggie.c"
#define SHOPDIR "/players/sado/shop/"

inherit "room/room.c";

make(name_of_item)
{
   object ob;
   if (!call_other(this_player(), "add_weight",call_other(name_of_item, "query_weight"))) {
      write("You can't carry that much.\n");
      return 0;
   }
   else
      {
      move_object(ob=clone_object(name_of_item), this_player());
      return ob;
   }
}


reset(arg) {
   if (arg) return;
   long_desc="You are in Sado's trinkets shoppie.\n"+
   "We sell doggies, roses and chocolates.\n"+
   "\n"+
   "Pet dogs cost 500 coins.\n"+
   "A beautiful freshly picked red rose costs 100 coins.\n"+
   "Sado's latest product, a box of oreos will cost 250 coins.\n"+
   "And I was lying.  we don't sell chocolates.\n";
   long_desc = long_desc + "The previous line is a lie.\n";
   dest_dir=({"/room/lanceroad2","exit"});
   set_light( 1);
   move_object(clone_object("/players/sado/shop/dispenser.c"),this_object());
}

short() {
   return "A small trinkets shoppie";
}

init() {
   ::init();
   add_action("buy","buy");
   add_action("garden","garden");
}

garden(str)
{
write("This command has been deactivated until its legality is checked.\n");
return 1;
   if(present("sadoengagementring",this_player()))
   {
      write("As you approach the door, your engagement ring warms slightly, and you hear a click.\n");
      write("The gate swings open in front of you as you approach, allowing you, and only you into\n");
      write("your secret garden.\n");
      this_player()->move_player("to her secret garden#/players/sado/rooms/garden.c");
      return 1;
   }
   else
   {
      write("I'm afraid only Esoterica is allowed into her secret garden through this gate.\n");
      return 1;
   }
}

buy(str)
{
   object ob;
   if(str=="doggie" || str=="dog") {
      if(present("dog",environment(this_player())))
         if(present("dog",environment(this_player()))->query_master()==this_player())
         {
         write("You buy a new dog, but as soon as your old dog see it, he attacks furiously.\n");
         write("Chihuahuas are savagely territorial, and jealous, and brutal fighters.\n");
         write("Your existing dog has soon shredded the new one, and a hatch pops open\n");
         write("in one of the walls of the room.  A little demon appears with a broom and\n");
         write("dustpan, and he calmly but quickly collects the remains of the poor pooch,\n");
         write("and carries them back into his hatch, where the remains will be recylced, and\n");
         write("turned into oreo cookies, which you can buy here.\n");
         return 1;
      }
      ob=clone_object(SHOPDIR+DOGGIE);
      ob->set_master(this_player()); /* added in by verte 6.15.01 .. hmm. */
      move_object(ob, environment(this_player()));
   } else if(str=="rose") {
      ob=make(SHOPDIR+ROSE);
   } else if(str=="chocolates" || str=="chocolate") {
      ob=make(SHOPDIR+CHOCS);
   } else if(str=="oreos" || str=="oreo" || str=="cookies") {
      ob=make(SHOPDIR+OREO);
   } else {
      return 0;
   }
   if(this_player()->query_money()<ob->query_price())
      {
      write("Yeah, like you can afford that!\n");
      destruct(ob);
   }
   else
      {
      write("You have purchased: "+ob->short()+"\n");
      this_player()->add_money(0-ob->query_price());
      say(this_player()->query_name()+" buys "+ob->short()+"\n");
   }
   return 1;
}
