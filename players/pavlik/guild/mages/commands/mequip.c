#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("mequip");
  set_name("Mage Equip");
  set_color_name(HIC+"Mage Equip"+NORM);
  set_rank(1);
  set_descrip(
	"Display what equipment you are currently using.\n"
  );
}


cmd()
{
  object ob, obj;
  int i;

  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  command("armors", this_player());
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  return 1;
}


find_armor_type(str) {
  object ob;
  int i;

  ob = all_inventory(tp);
  for(i=0; i<sizeof(ob); i++) {
    if(ob[i]->query_type() == str && ob[i]->query_worn())
      return ob[i];
  }
  return 0;
}

