/*
  zulu.h -- Adopted from Nooneelse's clairaudience spell
*/

#define ME 50
#define ZULU "/players/cosmo/closed/toolcmds/zulu.c"

zulu(str) {
  string name, toggle;
  object target, ob, others;
  if (!str) {
    write("You must specify a player and on/off.\n");
    write("Use: zulu <who on/off>\n");
    return 1;
  }
  if(sscanf(str,"%s %s",name,toggle) != 2) {
    write("You must specify a player and on/off.\n");
    write("Use: zulu <who on/off>\n");
    return 1;
  }
  target=find_player(name);
  if (!target) {
    write("You can't find "+name+".\n");
    return 1;
  }
  if (target->query_level() > ME) {
    write("You can't use zulu on a higher level player.\n");
    return 1;
  }
  others = first_inventory(environment(target));
  while (others) {
    if (others->query_level() > ME) {
      write("You can't use zulu on a room with a higher level player in it.\n");
      break;
    }
    others=next_inventory(others);
  }
  if (toggle=="on") {
    ob=clone_object(ZULU);
    ob->set_owner("cosmo");
    move_object(ob, target);
    write("Operation Zulu commenced on "+capitalize(name)+"\n");
  }
  else {
    ob=present("zulu",target);
    if(!ob) { write("Object is not on target. Strange.\n"); return 1; }
    destruct(ob);
    write("Operation Zulu terminated on "+capitalize(name)+"\n");
  }
  return 1;
}
