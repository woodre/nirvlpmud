/* ------------ Fake quicktyper aliases ------------ */
rfake_quicktyper(str)  {
  if (this_player()->query_level()<wizard_level) return;

  str2=str;
  str=query_verb();
  if (!str) return;
  if (str=="whow") {
    who = sort_list_of_players(users(), arg);
    for (i = 0; i < sizeof(who); i++) {
      if (who[i]->query_level() > 19) {
        if (who[i]->query_invis() > 0)
          write("(");
        else
          write(" ");
        if (in_editor(who[i]))
          write("[");
        else
          write(" ");
        if (who[i]->query_real_name()=="logon")
          write("<logon> --- logging in");
        else
          write(ladjust(who[i]->query_real_name(),16));
        if (in_editor(who[i]))
          write("]");
        else
          write(" ");
        if (who[i]->query_invis() > 0)
          write(")");
        else
          write(" ");
        write(ladjust(who[i]->query_gender_string(),6)+" ");
        write(ladjust(who[i]->query_level(),8)+" ");
        if (present("vampire fangs", who[i])) write("vampire "+" ");
        else
        if (present("seal", who[i])) write("mason   "+" ");
        else
        if (present("badge", who[i])) write("dopple"+" ");
        else
        if (present("mrobe", who[i])) write("monk  "+" ");
        else
        if (present("books", who[i])) write("necroman"+" ");
        else
        if (present("thief guild", who[i])) write("thief   "+" ");
        else
        if (present("pentagram", who[i])) write("alchemis"+" ");
        else
        if (who[i]->query_guild_name()=="MAGES") write("mage    "+" ");
        else
        write("         ");
        if (environment(who[i]))
          write(file_name(environment(who[i])));
        else
          write("<location unknown>");
        write("\n");
      }
    }
    return 1;
  }
  if (str=="l") {
    if (str2 && sscanf(str2, "at %s", what)==1) {
      command("look at "+what, this_player());
      return 1;
    }
    write("Room's file name: ");
    write(file_name(environment(this_player()))+"\n");
    command("look", this_player());
    return 1;
  }
  if (str=="log" || str=="elog") {
    write("\n=====> Error log:\n");
    command("cat /log/pain", this_player());
    write("\n=====> Bug/Idea/Typo log:\n");
    command("cat /log/pain.rep", this_player());
    return 1;
  }
  return;
}

