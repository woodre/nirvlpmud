inherit "/obj/treasure";
 
reset(arg) {
  if(arg) return;
  set_short("Faction Beta Tester");
  set_long(
"This is a beta tester of the guild-factions.  If by some chance I have not\n"+
"yet told you of the factions, type \"info\" to read up on them (the info\n"+
"is a couple pages long, so get ready to hit 'pause').  The current plan\n"+
"in the beta testing is to allow all of the GC's to have ALL of the faction\n"+
"marks for a while so they can learn them all.  After a while, each GC will\n"+
"need to mail me as to which of the factions they would like to stay in.\n"+
"As of right now there are 12 GC's and since there will be 4 factions, each\n"+
"faction will have 3 GC's to it.  When I remove this beta-board and put up\n"+
"a message on the CPR's board, it will be first come first serve as to\n"+
"which of the factions you'll be posted to (directions will be posted at\n"+
"that time).  To rejoin, or obtain any of the faction marks type \"getem\"\n"+
"and you'll be supplied with all of the missing marks.  Your job right now\n"+
"is to test every function in the factions to try to locate any bugs, typos\n"+
"or forseeable ways that the players can abuse their newfound powers and to\n"+
"mail me ANYTHING thereof.  I would like to reemphasize, again, that NO\n"+
"player other than the GC's should be told of the plans dealing with the\n"+
"factions.\n\nThey will find out soon enough.\n\n        Grimm\n\n"
);
  set_weight(99999);
}
 
id(str) {
  return str=="beta" || str=="beta tester" || str=="tester"; }
 
init() {
  add_action("info","info");
  add_action("getem","getem");
}
 
info() {
  string it;
  int ln;
  ln=1;
  it=read_file("/players/grimm/factions/dopps",ln);
  while(it) {
    write(it);
    ln++;
    it=read_file("/players/grimm/factions/dopps",ln);
  }
  return 1;
}
 
getem() {
  object fact;
  if(!present("Dopple-Barbarian",this_player())) {
    write("Barbarians being reinstated.\n");
    move_object(clone_object("/players/grimm/closed/obj/barb"),this_player());
  }
  if(!present("Dopple-Mystic",this_player())) {
    write("Mystics being reinstated.\n");
    move_object(clone_object("/players/grimm/closed/obj/mystic"),this_player());
  }
/*
  if(!present("Dopple-Ninjas",this_player())) {
    write("(Ninja's Faction is still being worked on)\n");
    write("Ninjas being reinstated.\n");
    move_object(clone_object("/players/grimm/closed/obj/ninja"),this_player());
  }
  if(!present("band-scooter",this_player())) {
    write("Chronomancers being reinstated.\n");
    move_object(clone_object("/players/scooter/closed/g/band"),this_player());
  }
*/
  write("Done.\n");
  return 1;
}
