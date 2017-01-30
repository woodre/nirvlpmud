
 /*  A spell to keep players from moving.  */

int count;

id(str)  {  return str == "stone";  }

long()  { return "A thin layer of stone.\n";  }

short() { return 0; }

freeze()  {
  count = time();
        }

init()  {
  freeze();
  add_action("iced","north");
  add_action("iced","east");
  add_action("iced","west");
  add_action("iced","south");
  add_action("iced","northeast");
  add_action("iced","northwest");
  add_action("iced","southeast");
  add_action("iced","southwest");
  add_action("iced","up");
  add_action("iced","down");
        }

init_arg(str)  {  sscanf(str, "%d", count);  }

iced()  {
if(time() < count + random(80))  {
  say(this_player()->query_name()+" tries to move, but has been turned to stone.\n");
  write("You have been turned to stone!\n");
  return 1;
        }
 else  {
  write("You break free of the thin layer of stone!\n");
    destruct(this_object());
    return 1;
        }
        }

drop()  { return 1; }
get()   { return 1;  }
