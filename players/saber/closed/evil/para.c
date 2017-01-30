
 /* A spell to paralyze a player with fear */

int count;

id(str)  {  return str == "ice";  }

long()  {  return "A thin layer of ice.\n";  }

short() { return 0; }

freeze()  {
  count = time();
        }

init () {
#ifndef __LDMUD__
  add_action("iced"); add_xverb("");
#else
  add_action("iced", "".3);
#endif
}

init_arg(str)  {  sscanf(str, "%d", count);  }

iced()  {
  if(time() < count + 10)  {
    say(this_player()->query_name()+" is paralyzed with fear.\n");
     write("You're paralyzed with fear!\n");
    return 1;  }
  else  {
    say(this_player()->query_name()+" is paralyzed with fear.\n");
     write("You're paralyzed with fear!\n");
    destruct(this_object());
return 1;
/* This cannot happen or heartbeat error if command is called from heartbeat - like wimpy
    return 0;
*/
        }
        }

drop()  { return 1; }
get()   { return 1;  }
