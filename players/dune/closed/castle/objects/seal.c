inherit "obj/clean";


id(str) { return str == "seal"; }

get() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }

short() { return "The Seal of Lothlorien"; }

long() { sign_disp(); }

init() { add_action("read","read"); }

read (str)
{
  if(!str || str != "seal") return 0;
  sign_disp();
  return 1;
}

sign_disp()
{
  string file;
  file = "/players/dune/log/QUEST";
  if(file_size(file) >= 0)
  {
    write("The Seal lists those who have solved the Lost Cities quest.\n\n"+
          "&&&&&&&&&&&&&&&&  Champions of Lothlorien  &&&&&&&&&&&&&&&&\n");
    cat(file);
    write("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    return 1;
  }
  return 1;
}
