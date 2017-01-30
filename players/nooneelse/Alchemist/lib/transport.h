/*
  transport.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------- send components to another alchemist --------------- */
transport(str) {
  object who_obj;
  string component, who;
  int nbr_items;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 40) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  component = "";
  who = "";
  nbr_items = 0;
  if (!str || sscanf(str, "%d %s %s", nbr_items, component, who)!=3) {
    write(NORM+CYN+"use: transport <#> <component> <who>\n"+NORM);
    return 1;
  }
  who_obj = find_player(who);
  if (MY_PLAYER==obj) {
    write(NORM+CYN+"Nice try. You cannot transport yourself.\n"+NORM);
    return 1;
  }
  if (!who || !who_obj || who_obj->query_invis()>0) {
    write(NORM+CYN+capitalize(who)+" can't be found.\n"+NORM);
    return 1;
  }
  if (!present("Alchemist Pouch", who_obj)) {
    write(NORM+CYN+capitalize(who)+" isn't an Alchemist and and wouldn't have\n"+
          " any use for components.\n"+NORM);
    return 1;
  }
  if (nbr_items <= 0) {
    write(NORM+CYN+"You must specify how many of the component to send.  "+
          "use: transport <#> <component> <who>\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity(component)<nbr_items) {
    write(NORM+CYN+"You don't have that many "+component+"\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  /* take the components out of my pouch */
  MY_POUCH->subtract_quantity(component, nbr_items);
  /* add the components to the other player's pouch */
  present("Alchemist Pouch", who_obj)->add_quantity(component, nbr_items);
  MY_PLAYER->add_spell_point(- 50);
  write(NORM+CYN+"You concentrate for a moment and send "+nbr_items+
        " of "+component+" to "+capitalize(who)+".\n"+NORM);
  tell_object(who_obj, NORM+CYN+"You feel your pouch jerk as "+MY_NAME_CAP+
                       " send you some "+component+".\n"+NORM);
  tell_room(environment(who_obj),
              NORM+CYN+capitalize(who)+" looks at "+who_obj->query_possessive()+
              " pouch as it jerks once.\n"+NORM);
  return 1;
}
