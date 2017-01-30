/*
  this is the shadow flyer, for distribution by guild commanders. 
*/

#define HELPPATH "/players/pathfinder/closed/shadow/help/"
inherit "/obj/treasure";

id(str) 
{
  return str == "flyer" ||
         str == "shadow_flyer";
}

short()
{
  return "Shadow Guild flyer";
}

long()
{
  write("This is the Shadow Guild flyer.  It contains information on the\n" +
        "Shadow guild.  There is a 'list' of topics on there which you can\n" +
        "get help on.\n");
  return 1;
}

reset(arg)
{
  if(arg) return;
}

init()
{
  add_action("do_info", "shinfo");
  add_action("list_topics", "list");
}

list_topics()
{
  write("\nThe topics upon which you can receive help for the \n");
  write("Shadow Guild are:\n");
  write("====================================================\n");
  write("shinfo sh   - List of abilities available to everyone\n");  
  write("shinfo sh1  - List of powers/abilities avail to rank 1\n");
  write("shinfo sh2  - List of powers/abilities avail to rank 2\n");
  write("shinfo sh3  - List of powers/abilities avail to rank 3\n");
  write("shinfo sh4  - List of powers/abilities avail to rank 4\n");
  write("shinfo sh5  - List of powers/abilities avail to rank 5\n");
  write("shinfo sh6  - List of powers/abilities avail to rank 6\n");
  write("shinfo sh7  - List of powers/abilities avail to rank 7\n");
  write("shinfo sh8  - List of powers/abilities avail to rank 8\n");
  write("\n");
  return 1;
}

do_info(str)
{
   int lines, dummy;
   object me, mark;
   string file;
   me = this_player();
   mark = present("shadow-mark",me);
   if(!sscanf(str, "sh%d", dummy) == 1)
   {
     write("Usage: shinfo sh<level>\n");
     return 1;
   }
   file = HELPPATH + str;
   if(!read_file(file)) {
      write("No info on '" + str + "'.\n");
      return 1;
   }
   lines = sizeof(explode(read_file(file), "\n"));
   if(!lines) {
      write("No info found on " + str + ".\n");
      return 1;
   }
   write(read_file(file, 1, lines) + "\n");
   return 1;
}
  
  
