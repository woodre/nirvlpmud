
 /* A spell to freeze a player solid */

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
  if(time() < count + 300)  {
    say(this_player()->query_name()+" twitches a little.\n");
    write("You can't move!\n");
    return 1;  }
  else  {
    destruct(this_object());
    return 0;
        }
        }

drop()  { return 1; }
get()   { return 1;  }
