 inherit "obj/container.c";
 reset(arg) {
    ::reset();
    if (arg) return;
    set_name("chest");
   set_short("A small treasure chest");
   set_long("A small locked treasure chest.\n"+
        "Something is shifting inside of it.\n");
    set_weight(4);
    set_value(50);
    set_max_weight(12);
}

init()  {
  ::init();
  add_action("get_check","get");
  add_action("put_check","put");
        }

put_check(str)  {
string temp, temp1;
  sscanf(str, "%s in %s",temp, temp1);
  if(temp1 == "chest")  {
  if(!present("steel key", this_player()))  {
   write("You need a key to open the chest.\n");
  return 1;
        }
        }
        }

get_check(str)  {
string temp, temp1;
  sscanf(str, "%s from %s", temp, temp1);
  if(temp1 == "chest")  {
  if(!present("steel key", this_player()))  {
   write("You need a key to open the chest.\n");
   return 1;
        }
        }
        }
