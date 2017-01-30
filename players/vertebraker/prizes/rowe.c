#include <ansi.h>
#define TARGET find_player("rowe")
#define ENVT   environment(TARGET)
#define DESC   "A "+HIG+"green cube"+NORM+" (floating)"

inherit "/obj/treasure";

static status cube_stealth;

reset(arg)
{
  if(arg || root()) return;
  
  set_id("cube");
  set_alias("green cube");
  set_short(DESC); 
  set_long(HIG+"\n\
\t____________________\n\
\t|_|_|_|_|_|_|_|_|_|_|\n\
\t|_|_|_|_|_|_|_|_|_|_|\n\
\t|_|_|_|_|_|_|_|_|_|_|\n\
\t|_|_|_|_|_|_|_|_|_|_|\n\
\t|_|_|_|_|_|_|_|_|_|_|\n\
\t|_|_|_|_|_|_|_|_|_|_|\n\
\t|_|_|_|_|_|_|_|_|_|_|\n\
\t|_|_|_|_|_|_|_|_|_|_|\n\
\t|_|_|_|_|_|_|_|_|_|_|\n\
\t|_|_|_|_|_|_|_|_|_|_|\n\n"+NORM);
  set_weight(0);
  set_value(0);
  call_out("float", 4);
}

long(str){
  ::long(str);
  if(this_player()==TARGET){
    write("You can toggle the cube's stealth mode by typing 'cube_stealth'.\n");
  }
}

short(){
  if(this_player()==TARGET || !cube_stealth)
    return DESC;
  else return "";
}

init(){
  add_action("cmd_cube_stealth","cube_stealth");
}

cmd_cube_stealth(str){
  cube_stealth = !cube_stealth;
  
  write("Cube stealth is "+(cube_stealth?"ON":"OFF")+"\n");
  return 1;
}

float()
{
  if(!this_object() || !environment())
    return;
  if(TARGET && ENVT && ENVT != environment() && environment() != TARGET)
  {
    if(!cube_stealth){
    tell_room(environment(),
      DESC+" floats out following Rowe.\n");
    }
    move_object(this_object(), ENVT);
    if(!cube_stealth){
    tell_room(ENVT,
      DESC+" floats in.\n");
    }
  }
  else if(TARGET && ENVT && ENVT == environment())
  {
    object atk;
    if((atk=TARGET->query_attack()) && random(3))
    {
      string msg;
      string dtype;
      switch(random(4))
      {
        case 0: 
        msg = "BLASTS "+atk->query_name()+" with an "+HIB+"electric shock"+NORM+"!";
        dtype="other|electric";
        break;
        case 1: 
        msg = "fires a tiny, intense "+RED+"laser beam"+NORM+" at "+atk->query_name()+"!";
        dtype="other|laser";
        break;
        case 2:
        msg = "shoots a "+HIK+"dark cloud"+NORM+" into "+atk->query_name()+"!";
        dtype="other|dark";
        break;
        case 3:
        msg = "ejects a sticky "+HIK+"black fluid"+NORM+" over "+atk->query_name()+"!";
        dtype="other|evil";
        break;
      }
      tell_room(environment(),
        DESC+" "+msg+"\n");
       atk->hit_player(5 + random(10), dtype);
    }
  }
  
  call_out("float", 4);
}

get()
{
  if(this_player() && this_player() == TARGET)
  {
    return 1;
  }
  else
    return 0;
}
