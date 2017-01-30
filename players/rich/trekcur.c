id(str)
{
   return str == "gargle" || str == " gargle" || str == "ghfgrjfh";
}

short() {
    return 0;
}

long() {
    return 0;
}

query_value() { return 0; }









get() {
    return 0;
}

drop() {
return 1;
}
query_weight() {
    return 0;
}

query_auto_load() {
  return "players/rich/trekcur.c:";
  }
init() {
   if(!present("gargle")) {
    call_other(this_player(),"set_title","The Trekkie");
    write("You feel that the main inspiration in your life comes from\n");
    write(" watching star trek re-runs.\n");

    }
    add_action("beep", "beep");

}


beep(str) {
  if (str=="Jean-Luc Sucks") {
            if (present("beverly",environment(this_player()))) {
               destruct(this_object());
               write("Your title will revert when you change levels.\n");
               return 1;
               }
  return 1;
  }
   return 1;
  }
reset(arg) {}
