inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_id("string");
  set_short("A long piece of string");
  set_long(
"This is a long piece of string.  It looks rather new.  Looking at the\n"+
"piece of string, you get the feeling you could tie it to something.\n"+
"The string by itself looks pretty worthless.\n");
  set_weight(1);
  set_value(random(15));
}

void init(){
  ::init();
  add_action("tie_cmd", "tie");
}

status tie_cmd(string str)
{
  object ruby;
  if(!str || str == "string" || str == "string to")
  {
    write("Tie string to what?\n");
    return 1;
  }
  if(str == "string to ruby")
  {
    ruby = present("zeus_red_ruby");
    if(!ruby) return 0;
    else 
    {
      write("You tie the string around the red ruby and make an amulet.\n");
      destruct(ruby);
      MO(CO("/players/zeus/realm/OBJ/ruby_amulet.c"), TP);
      destruct(TO);
      return 1;
    }
    return 1;
  }
  else return 0;
  return 1;
}
