/*
  flea_powder.c
*/

inherit "/obj/treasure";

int nbr_of_dustings;

init() {
  ::init();

  add_action("dust_fleas", "dust");
}

dust_fleas(str) {
  string str2;
  object who, obj;
  int i;

  if (!str) return 0;
  if (str=="fleas") {
    if (!present("flea", this_player())) {
      write("You start to dust yourself for fleas, but stop when you "+
            "can't spot any.\n");
      return 1;
    }
    destruct(present("flea", this_player()));
    write("You open the packet and sprinkle some dust on the fleas.\n");
    say(this_player()->query_name()+
        " opens a packet and sprinkles some dust on "+
        this_player()->query_possessive()+"self.\n", this_player());
    nbr_of_dustings=nbr_of_dustings-1;
    if (nbr_of_dustings <= 0) {
      write("You've used up all the powder and the package disintegrates.\n");
      destruct(this_object());
    }
    return 1;
  }
  str2=0;
  sscanf(str, "fleas on %s", str2);
  if (!str2) {
    write("Dust fleas on who?\n");
    return 1;
  }
  who=0;
  who=present(str2, environment(this_player()));
  if (!who) {
    write(capitalize(str2)+" isn't here.\n");
    return 1;
  }
  for (i=0; i<5; i++) {
    obj=0;
    obj=present("flea", who);
    if (obj) destruct(obj);
  }
  write("You open the packet and sprinkle some dust on "+
        capitalize(str2)+".\n");
  say(this_player()->query_name()+
      " opens a packet and sprinkles some dust on "+capitalize(str2)+".\n",
      this_player());
  nbr_of_dustings=nbr_of_dustings-1;
  if (nbr_of_dustings <= 0) destruct(this_object());
  return 1;
}

reset(arg) {
  if (arg) return 0;

  set_id("flea powder");
  set_alias("powder");
  set_short("Flea powder");
  set_long("Flea powder.\n\n"+
           "To get rid of pesty fleas:\n"+
           "    on yourself 'dust fleas'\n"+
           "    on someone/something else 'dust fleas on <who>'\n"+
           "\n  A small label says: Made by Nooneelse's Doodads Inc.\n");
  set_value(100);
  set_weight(1);
  nbr_of_dustings=3;
}
