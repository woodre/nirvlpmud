inherit "obj/treasure";
int placed;
static desc2;

reset(arg) {
    if(!arg) {
      set_id("plate");
      set_short("A silver plate");
      set_long("A priceless silver plate.  Looks good enough for the gods.\n");
      set_weight(4);
      set_value(1000);
}
}
init() {
    ::init();
      add_action("put","put");
      add_action("present","present");
      add_action("qgive","give");
}

put(str) {
     object head;
     head=present("head", this_player());
 if(str != "head on plate") return 0;
 if(!present("head", this_player())) { write("You must have a head.\n");
    return 1; }
 if(placed==1) { write("You have already done that.\n"); return 1; }
 write("You place Keivjam's head on the plate.\n");
  log_file("lew.rep", this_player()->query_real_name()+" placed the head.\n");
  desc2="Keivjam's head on a silver plate.\n"+
        "The Gods would love to have this.\n";
 call_other(head, "put");
 call_other(this_object(), "set_long", desc2);
 placed=1;
  ggive();
  write("I have changed it no longer needs be given to a god. -Bp\n");
 return 1;
}
present() {
    object god1, god2;
    god1=find_living("boltar");
    god2=find_player("sandman");
    if(!god1) {
      if(!god2) {
        write("You should wait until the Gods are on.\n");
        return 1;
      }
     write("Sandman might like the head.\n"); return 1;
    }
    if(!god2) { write("Boltar might like the head.\n");
    return 1; }
}
qgive(str) {
    string who, what;
    object wizard;
    if(this_player()->query_real_name()=="mccleod") {
    log_file("lew", "Mcleod\n");
    write("You must see me, Lew, to finish this one.\n");
    return 1;
    }
    if(!str || sscanf(str, "%s to %s", what, who) !=2) return 0;
    if(what != "plate") return 0;
    if(who == "sandman") call_other(this_object(), "ggive");
    if(who == "boltar") call_other(this_object(), "ggive");
    if(who == "lew") call_other(this_object(), "ggive");
   log_file("lew",this_player()->query_real_name()+" gave plate to"+who+"\n");
    return 0;
}
ggive() {
    if(placed != 1) return 1;
    write("You have completed this quest.\n");
    call_other(this_player(), "set_quest", "keivjam");
    return 1;
}
drop() { log_file("lew.rep", this_player()->query_real_name()+" dropped the plate.\n");
    write("The plate disentigrates as you drop it.\n");
    destruct(this_object());
    return 0;
}
query_save_flag() { return 1; }
