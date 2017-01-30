#include "/players/guilds/bards/def.h"
#include "/players/guilds/bards/lib/ansi_pad.h"


status sort_bard_level(object ob1,object ob2) {
  if(ob1->query_bard_level() < ob2->query_bard_level())
    return 1;
  else
    return 0;
}
status main() {

  int b;
  object *instruments, ob2;
  string name;

  instruments = (mixed)CHANNEL->query_instruments();
  instruments = sort_array(instruments,"sort_bard_level",this_object());

  write("\n");
  write(HIM
       +"()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()\n"
       +"()"+NORM+BOLD+"  Name        Bard Lvl    Gender     Title    "
       +"                  "+NORM+HIM+"()\n");

  for (b = 0; b < sizeof(instruments); b += 1) {
    ob2=environment(instruments[b]);
    if(ob2->query_level() > 19 && ob2->query_invis() > 19)
      continue;
    write("() "+NORM);
    name=(string)ob2->query_name();
    if(ob2->query_invis()) name+="*";
    if(!instruments[b]->query_on()) name+="#";
    write(pad(name, 15));
    write(pad(""+instruments[b]->query_bard_level(), 11));
    write(pad(""+ob2->query_gender(), 9));
    write(ansi_pad((string)ob2->query_title(),27));
    write(HIM+" ()\n");
  }
    write(HIM+
      "()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()-<>-()\n"+NORM);
    write("        * - invisible   # - bard talk muffled\n");
    return 1;
}
