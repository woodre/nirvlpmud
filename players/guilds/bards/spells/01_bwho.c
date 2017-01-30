#include "/players/guilds/bards/def.h"


status sort_level(object ob1,object ob2) {
  int l1,xl1,l2,xl2;
  l1=(int)ob1->query_level();
  xl1=(int)ob1->query_extra_level();
  l2=(int)ob2->query_level();
  xl2=(int)ob2->query_extra_level();
  if(l1+xl1 > l2+xl2)
    return 0;
  else
    return 1;
}

status main() {
    int number, b;
    object *ob;
    object ob2;

    ob = sort_array(users(),"sort_level",this_object());
   
    write("\n");
    write(HIM+
" () - () = () - () = () - () = () - () = () - () = () - () = () - () = () - ()\n"+
" |                                                                           |\n"+
" |"+NORM+BOLD+"     Name          Lvl  /  X-Lvl     Gender        Guild      MiniGuild    "+
NORM+HIM+"|\n"+
" |                                                                           |\n"+NORM);
  for (b = 0; b < sizeof(ob); b += 1) {
    if (ob[b]->query_level() > 19)
      continue;
    if(ob[b]->query_invis() && ob[b]->query_level() >= TP->query_level())   
      continue;
    write(HIM+" |     "+NORM);
      
    write(pad(""+ob[b]->query_name(), 15));
    write(pad(""+ob[b]->query_level(), 9));
    write(pad(""+ob[b]->query_extra_level(), 8));
    write(pad(""+ob[b]->query_gender(), 13));
    if (ob[b]->query_guild_name() == 0) {
      write("-----         ");
    } else {
      write(pad(""+ob[b]->query_guild_name(), 14));
    }
    if (ob2=present("base_obj", ob[b])) {
      write(pad(""+ob2->query_newguild(), 11));
    } else {
      write("           ");
    }
    write(HIM+"|\n"+NORM);
    
  }
  write(
HIM+" |                                                                           |\n"+
  " () - () = () - () = () - () = () - () = () - () = () - () = () - () = () - ()\n"+NORM);
  write("\n");
  return 1;
}
