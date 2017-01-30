
 /* A spell to paralyze a player with fear */

int count;

id(str)  {  return str == "ice";  }

long()  {  return "A thin layer of ice.\n";  }

short() { return 0; }

freeze()  {
  count = time();
        }

init()  {  add_action("iced");  add_xverb("");  }

init_arg(str)  {  sscanf(str, "%d", count);  }

iced()  {
  if(time() < count + 10)  {
    say(this_player()->query_name()+" is paralyzed with fear.\n");
     write("You're paralyzed with fear!\n");
    return 1;  }
  else  {
    write("blah\n");
    return 0;
        }
        }

drop()  { return 1; }
get()   { return 1;  }
