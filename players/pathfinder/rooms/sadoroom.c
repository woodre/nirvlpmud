/*
* * This is a my workroom. *
* 
* Sado, May 20 1993
*/
#define tp this_player()
#define tpname this_player()->query_real_name()
#define throwout_room "/room/church"
#define owner "sado"

inherit "room/room";

int shields;
string descr;

init()
{
   object me;
   
   ::init();
   add_action("toggle_shields","shields");
   if(shields)
      if(tpname != owner)
      {
      write("Sorry.  The fumes in there are too dangerous just at the moment.\n" +
         "Sado had a bit of an accident with a bottle of some nasty green\n" +
         "chemotoxin.  Best try again later.\n");
      move_object(tp,throwout_room);
      if(me=find_player(owner))
         tell_object(me,capitalize(tpname)+" tried to get in.\n");
   }
}

reset(arg)
{
   if (!arg) {
      set_light(1);
      shields=0;
      short_desc = "Sado's laboratory";
      descr     = "This is a large lab, with bubbling glass containers everywhere.\n" +
      "You can tell that whoever works here is very much into chemicals\n" +
      "and chemistry, but you sense a difference between this setup and\n" +
      "your average, everyday chem lab setup.  There are more twisted\n" +
      "glass dodads and flanges, and lots of thin pipes, and more green\n" +
      "liquids than in your average lab, with more dry ice vapor filling\n" +
      "the room.  In fact, you'd probably think you were being fooled into\n" +
      "believing that a very very powerful alchemist worked here, if you\n" +
      "didn't know Sado.\n";
      long_desc = descr+"The shields are DOWN.\n";
      no_castle_flag = 0;
      dest_dir =
      ({
            "room/church", "church",
       });
      items =
      ({
            "workroom", "Very cluttered with books, scrolls, and glass dodads.",
            "shields", "A method by which Sado floods the room with noxious gases.",
       });
   }
}

toggle_shields(str)
{
   if(str=="on") shields=1;
   else if(str=="off") shields=0;
   else if(str=="stat")
      if(shields) write("The shields are on.\n");
   else write("The shields are down.\n");
   else write("The syntax is: shields <on|off|stat>\n");
   if(shields) long_desc=descr+"The shields are UP.\n";
   else long_desc=descr+"The shields are DOWN.\n";
   return 1;
}
