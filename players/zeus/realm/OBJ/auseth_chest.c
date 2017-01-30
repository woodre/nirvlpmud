inherit "/obj/treasure.c";
int closed;

reset(arg){

  closed = 1;
  set_weight(40000);
}

short(){ return 0; }

long(){
  write(
"This is a fairly exquisite looking treasure chest.  It is made of gold\n"+
"and has numerous jewels fastened to the case.");
  if(closed)
    write("  It is closed.\n");
  else
    write("  It is open.\n");
  if(present("coins") && !closed)
    write("It looks like there is something in it.\n");
}

get(){ return 0; }

id(str){ return str == "t_chest" || str == "chest" 
             || str == "treasure chest"; }

void init(){
    ::init();
  add_action("open_cmd", "open");
  add_action("close_cmd", "close");
  add_action("search_cmd", "search");
}

open_cmd(x){
  if(x != "chest") return 0;
  if(closed){
    write("You open the treasure chest.\n");
    closed = 0;
  }
  else
    write("The treasure chest is already open.\n");
  return 1;
}

close_cmd(x){
  if(x != "chest") return 0;
  if(!closed){
    write("You close the treasure chest.\n");
    closed = 1;
  }
  else
    write("The treasure chest is already closed.\n");
  return 1;
}

search_cmd(x){
  int y,z;
  if(x != "chest") return 0;
  if(present("coins"))
  {
    write("You find some treasure.\n");
    move_object(present("coins"), environment(this_player()));
  }
  else
    write("You search the treasure chest and find nothing.\n");
  return 1;
}
