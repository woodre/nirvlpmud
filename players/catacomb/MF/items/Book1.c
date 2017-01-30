inherit "obj/treasure";
#define TPN this_player()->query_name()

reset(arg){
    if(arg) return;
    set_id("book");
    set_value(500);
    set_weight(1);
    set_short("The legend of Yeroc");
    set_long(
      "A leather backed book that has been in the village for\n"+
      "several decades.  This is the writing of the legend of\n"+
      "Yeroc, the nomad.  You can read the legend with these\n"+
      "commands: 'read <1-2>'.\n");
}
init() 
{
    ::init();
    add_action("READ","read"); 
}


READ(str)
{
    if (!str)
    {
       write("Read which page?\n");
       return 1;
    }
    if (str == "1") 
    {
        READ_PAGE1();
        return 1;
    }
    if (str == "2")
    {
        READ_PAGE2();
        return 1;
    }
}

READ_PAGE1()
{
   say(TPN+" reads the first page of the book.\n");
   write("You begin reading The Legend of Yeroc, the Nomad.\n\n");
   write("            The story of Mesirer Forest\n");
   write("                and Yeroc, the nomad\n\n");
   write("  Known as the forgotten forest, Mesirer forest is a forest of \n");
   write("isolation.  The forest is forever clouded in despair.  The rays\n");
   write("of sunshine that peak through the clouds are only a false light\n");
   write("of hope.  The willow trees show the sadness of this place, \n");
   write("drooping to the ground.  The grass on the ground strives to be \n");
   write("seen but to no avail.  The atmosphere prevents the grass from \n");
   write("ever showing it's true beauty.  Deep within the forest there is\n");
   write("rumored to be a sanctuary from the gloomy surroundings. The elves\n");
   write("from the city of Shamot never tread into the forest for fear of \n");
   write("becoming lost in the mists of isolation.\n");
   return 1;
}

READ_PAGE2()
{
   say(TPN+" starts reading the second page.\n");
   write("          The Legend of Yeroc, the Nomad    \n\n");
   write("  Yeroc was always seen as different.  He found his isolation to be\n");
   write("his only sanctuary.  Yeroc did not see the point of going through \n");
   write("the meaningless chit-chat, pointless violence, and obsessive greed.\n");
   write("He believed that all creatures were put on the land for one reason.\n");
   write("One night many years ago he entered the Mesirer Forest in search of\n");
   write("his reason to never be seen again.  The night that he entered into \n");
   write("the forest a dark cloud devoured the forest.  The cloud is there at\n");
   write("all times but once a year when a ray of sunshine can be seen shining \n");
   write("through the darkness.\n");
   return 1;
}
