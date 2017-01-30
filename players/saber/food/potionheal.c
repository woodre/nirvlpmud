#define tp this_player()->query_name()
id(str)     {
  return str == "potion";
            }
reset()     {}

long()      {
  write("A potion filled with elixer of healing.\n"+
     "To drink it type <drink potion>\n");
             }

short()     {
  return "A potion of healing";
             }

init()       {
  add_action("drink","drink");
             }

drink(str)   {
  if(str != "potion") return 0;
  write("You drink a potion of healing.\n"+
     "You feel much better.\n");
  say(tp+" drinks a potion.\n");
  call_other(this_player(),"heal_self",100);
  write("You throw away the empty potion bottle.\n");
  destruct(this_object());
  return 1;
             }

get()        {
  return 1;
             }

query_weight() { return 0; }

query_value() { return 3500; }
