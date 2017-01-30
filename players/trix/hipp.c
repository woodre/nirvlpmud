inherit "room/room";
reset(arg){
if(arg) return;
set_light(0);
short_desc="You ever heard of SEX_BRAINS??";
long_desc="These are the sex-brains. It is a place where Hippo's\n"+
   "sexual feelings and thoughts are translated into more fysical\n"+
   "behaviour. Making advances and having erections etc have their\n"+
   "origin in this place. Examine this area thoroughly to understand\n"+
   "the behaviour of a lot of male people...\n";
dest_dir=
({
   "/players/hippo/quest_1/willosi","up"
});
}
init() {
::init();
   add_action("have","have");
}

have(str)
{
   if(str!="erection")
   {write("Hey, man! Hippo can do a lot, but not what you want here!\n");
      return 1;
   }
   write("You see strange pictures and make an erection...");
   move_object(this_player(),"/players/hippo/quest_2/er_penis.c");
   command("look",this_player());
   return 1;
}
