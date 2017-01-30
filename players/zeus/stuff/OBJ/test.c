inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string wizzos;

reset(arg){

  set_short("A pill");
  set_long("test\n");
  set_weight(1);
  set_value(0);

}

  init(){
  ::init();
  add_action("search_cmd", "wizsearch");
}

id(str){ return str == "pill"; }

status search_cmd(string str){
  int x;
  string bob;
  if(!str)
  {
    write("You must search for the name of a wizard.\n");
    return 1;
  }
  wizzos = explode(read_file("/players/zeus/OBJ/wiz_list"),"\n");
  if(sscanf(str, "%s", bob))
  {
    for(x = 0; x < sizeof(wizzos); x++)
    {
      if(wizzos[x] == bob)
      {
        write(wizzos[x]+"\n");
        return 1;
      }
    }
    else {
      write("That wizard is not on the list.\n");
      return 1;
    }
  }
  return 1;
}

