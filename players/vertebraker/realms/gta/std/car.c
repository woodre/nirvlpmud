#include <ansi.h>

inherit "/obj/living";


static string dir;
void reset(status arg)
{
  if(arg) return;

  enable_commands();
}

string query_carType() {
  return "Car";
}

status is_ok()
{
  return (string)this_player()->query_real_name()=="vertebraker";
}

status inside()
{
  return environment(this_player())==this_object();
}

status outside()
{
  return !inside();
}


varargs void long(string str)
{
  if(inside())
  {
    write("\n\t"+BOLD+"Inside a "+query_carType()+"\n\n");
    write(NORM);
    environment()->long(str);
  }

}
status id(string str)
{
  return str=="car" || str=="auto" || str == "automobile";
}

void init()
{
  if(!is_ok()) return;
  if(inside())
  {
    add_action("cmd_drive", "drive");
    add_action("cmd_brake", "brake");
    add_action("cmd_exit", "exit");
    add_action("cmd_horn", "horn");
    add_action("cmd_reverse", "reverse");
    add_action("cmd_wander", "wander");
  }
  add_action("cmd_enter", "enter");
}

status cmd_enter(string str)
{
  if(!id(str)) return 0;

  write("\n\tYou open the door of the "+query_carType()+".\n");
  write("You hop in.\n");
  write("\n");

  move_object(this_player(), this_object());
  tell_room(environment(), (string)this_player()->query_name()+" opens the door of the "+query_carType()+" and hops in.\n", ({ this_object() }));
  long();
  return 1;
}

status cmd_drive(string str) {
  object oldenv;
  if(!str) return 0;


  oldenv=environment();
  if(!command(str, this_object()))
  {
    write("You can't drive that direction!\n");
    return 1;
  }
  else if(oldenv == environment()) {
    write("You went nowhere, but accomplished something.\n");
    return 1;
  }
  str=(string)"/room/room"->convert_dir(str);
  dir=str;
  write("\n");
  write("You press the gas pedal and start heading "+str+".\n");
  write("\n");
  long();
  while(remove_call_out("drive") != -1);
  call_out("drive", 1, this_player());
  return 1;
}


void drive(object driver)
{
  if(!command(dir, this_object()))
  {
    tell_object(driver, "\nBAM! You slammed into a wall!\n\n");
    tell_room(environment(), "\nBAM! The "+query_carType()+" slammed into a wall!\n\n");
    while(remove_call_out("drive") != -1);
    return;
  }
  while(remove_call_out("drive") != -1);
  long();
  call_out("drive", 1, driver);
}


string short() {
  if(inside())
  {
    return query_carType();
  }
  return query_carType();
}


void catch_tell(string str){
  tell_room(this_object(), "@"+str+"\n");
}
