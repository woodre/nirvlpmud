/*
* * This is a my workroom. *
* 
* Sado, May 20 1993
*/

inherit "/players/sado/rooms/mansion.c";

short()
{
   object r;
   if(!this_player()) return "Sado's laboratory";
   r = present("wedding ring",this_player());
   if(r) return capitalize(r->query_spouse())+"'s hotel room";
   return capitalize(this_player()->query_real_name())+"'s hotel room";
}

reset(arg)
{
   if (!arg) {
      set_long("This is a large lab, with bubbling glass containers everywhere.\n" +
         "You can tell that whoever works here is very much into chemicals\n" +
         "and chemistry, but you sense a difference between this setup and\n" +
         "your average, everyday chem lab setup.  There are more twisted\n" +
         "glass dodads and flanges, and lots of thin pipes, and more green\n" +
         "liquids than in your average lab, with more dry ice vapor filling\n" +
         "the room.  In fact, you'd probably think you were being fooled into\n" +
         "believing that a very very powerful alchemist worked here, if you\n" +
         "didn't know Sado.\n");
      set_dest_dir(
         ({
               "room/church", "church",
               "/players/quicksilver/workroom.c","quick",
               "/players/sado/rooms/bedroom.c","bed",
               "/players/sado/rooms/garden.c","garden",
               "/players/sado/rooms/games.c","games",
          }));
      set_items(
         ({
               "workroom", "Very cluttered with books, scrolls, and glass dodads.",
          }));
      set_light(1);
   }
}
