/*
  grafitti_wall.c - wall for writing grafitti
*/

#define GRAFITTI_TEXT "players/nooneelse/obj/grafitti_text"
#define GRAFITTI_TEXT_FILE "/players/nooneelse/obj/grafitti_texts.o"

string grafitti_texts, grafitti_authors;
int nbr_of_messages, nbr, i;

init() {
  add_action("read",     "read");
  add_action("scribble", "scribble");
  add_action("clean",    "clean");
}

read(str) {
  if (!id(str)) return;
  long(str);
}

scribble(str) {
  if (!str) return;
  if (nbr_of_messages >= 22) {
    write("Unfortunately the wall is full of trash.  "+
          "You'll have to wait a while.\n");
    return 1;
  }
  if (strlen(str) > 69) {
    write("Line is too long!  (max # of characters is 70)\n");
    return 1;
  }
  restore_object(GRAFITTI_TEXT);
  grafitti_texts[nbr_of_messages] = str;
  grafitti_authors[nbr_of_messages] = this_player()->query_real_name();
  nbr_of_messages = nbr_of_messages + 1;
  save_object(GRAFITTI_TEXT);
  say("With a nasty grin, "+this_player()->query_name()+
      " scribbles something on the wall.\n");
  write("Ok.\n");
  return 1;
}

clean(str) {
  int clean_nbr;
  if (this_player()->query_level() < 21) return;
  if (!str) return;
  if (str=="wall") {
    restore_object(GRAFITTI_TEXT);
    grafitti_texts = "";
    grafitti_authors = "";
    nbr_of_messages = 0;
    tell_room(environment(this_object()),
              "\nA little pixie flys in, erases the wall, "+
              "smiles at you and flys away.\n\n");
    save_object(GRAFITTI_TEXT);
    return 1;
  }
  sscanf(str, "%d", nbr);
  if (!nbr) return;
  if (nbr >= 22 || nbr < 1) {
    write("The max is 22.\n");
    return 1;
  }
  if (nbr > nbr_of_messages) {
    write("There are only "+nbr_of_messages+".\n");
    return 1;
  }
  nbr = nbr - 1;
  clean_nbr = nbr;
  restore_object(GRAFITTI_TEXT);
  nbr = clean_nbr;
  grafitti_texts[nbr] = "";
  grafitti_authors[nbr] = "";
  shuffle_board();
  nbr_of_messages = nbr_of_messages - 1;
  tell_room(environment(this_object()),
            "\nA little pixie flys in, erases some junk off from the wall,\n"+
            "smiles at you and flys away.\n\n");
  save_object(GRAFITTI_TEXT);
  return 1;
}

reset(arg) {
  if (arg) return;

  grafitti_texts = allocate(23);
  grafitti_authors = allocate(23);
  if (file_size(GRAFITTI_TEXT_FILE)==-1) {
    for (i=0; i<22; i++) {
      grafitti_texts[i] = "";
      grafitti_authors[i] = "";
    }
    nbr_of_messages = 0;
    save_object(GRAFITTI_TEXT);
  }
  else
  if (file_size(GRAFITTI_TEXT_FILE) >= 1) {
    restore_object(GRAFITTI_TEXT);
  }
  enable_commands();
  call_out("clean_wall", 7200);
}

clean_wall() {
  if (nbr_of_messages > 18  && environment(this_object())) {
    restore_object(GRAFITTI_TEXT);
    grafitti_texts[0] = "";
    grafitti_authors[0] = "";
    shuffle_board();
    nbr_of_messages = nbr_of_messages - 1;
    tell_room(environment(this_object()),
              "\nA little pixie flys in, erases some junk off from the wall,\n"+
              "smiles at you and flys away.\n\n");
    save_object(GRAFITTI_TEXT);
  }
  call_out("clean_wall", 7200);
}

short() { return "A wall to write grafitti on"; }

long() {
  int j;
  restore_object(GRAFITTI_TEXT);
  say(this_player()->query_name()+" curiously reads the wall.\n");
  write("_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n\n");
  if (nbr_of_messages > 0) {
    for (i=0; i<nbr_of_messages; i++) {
      write(grafitti_texts[i]);
      j=i+1;
      if (this_player()->query_level() >= 21)
        write("   { # "+j+" by: "+grafitti_authors[i]+" }");
      write("\n");
    }
  }
  write("\n_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n"+
        "    A small label says: Made by Nooneelse's Doodads Inc.\n\n"+
        "    To write your own graffiti, use 'scribble <message>'\n");
  if (this_player()->query_level() >= 21)
    write("(As a wizard, you can clean the wall with 'clean <msg #>'\n"+
          " or clean the entire wall with 'clean wall'.)\n");
  return 1;
}

shuffle_board() {
  if (nbr >= nbr_of_messages) return;
  for (i=nbr; i<22; i++) {
    grafitti_texts[i] = grafitti_texts[i+1];
    grafitti_authors[i] = grafitti_authors[i+1];
    grafitti_texts[i+1] = "";
    grafitti_authors[i+1] = "";
  }
}

id(str) { return (str=="wall" || str=="graffiti"); }
