inherit "/obj/treasure";
init() {
   if(this_player())
     if(this_player()->query_real_name()!="grimm") {
    write("I'm sorry, but you have been banished from the game.\n"+
          "Mail Sandman, Boltar, Or Grimm to be reinstated.\n");
    if(this_player()) command("quit",this_player());
  }
}
reset(arg) {
  if(arg) return;
  set_weight(100000);
  set_short("Soul fixer");
  set_long("It fixes somethin in your soul...\n");
}
id(str) { return str=="grimmsfixer"; }
query_auto_load() { return "/players/grimm/fixer:"; }
drop() { return 1; }
