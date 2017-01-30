#define MO move_object
#define TP this_player()
inherit "obj/monster";
 
reset(arg){
   if(arg) return 0;
   ::reset(arg);
   set_alias("__dm__");
   set_long(
"     This is one of the methods in which the CyberNinja guild\n"+
"maintains a high level of security.\n");
   set_level(100);
   enable_commands();
   set_can_kill(0);
   set_aggressive(0);
 activate();
}
 
init() {
  if(!present("either implants", TP)) {
     if(living(TP) && TP->query_interactive()) {
       if(!TP->query_npc() && !TP->query_ghost() && !(TP->query_level() > 19)) {
         tell_object(TP,
"A demonic image of black metal and red steam haunts your vision...\n"+
"             .::::d:?88888888888?::8b::::.\n"+
"           .:::d8888:?88888888??a888888b:::.\n"+
"         .:::d8888888a8888888aa8888888888b:::.\n"+
"        ::::dP::::::::88888888888::::::::Yb::::\n"+
"      ::::d8:::::::::::Y8888888P:::::::::::8b::::\n"+
"     .::::88::::::::::::Y88888P::::::::::::88::::.\n"+
"     :::::Y8baaaaaaaaaa88P:T:Y88aaaaaaaaaad8P:::::\n"+
"     :::::::Y88888888888P::|::Y88888888888P:::::::\n"+
"     ::::::::::::::::888:::|:::888::::::::::::::::\n"+
"     `:::::::::::::::8888888888888b::::::::::::::'\n"+
"      :::::::::::::::88888888888888::::::::::::::\n"+
"       :::::::::::::d88888888888888:::::::::::::\n"+
"        ::::::::::::88::88::88:::88::::::::::::\n"+
"         `::::::::::88::88::88:::88::::::::::'\n"+
"You have infiltrated CyberNinja Guild Headquarters and have been caught!\n"+
"\n");
        tell_room(environment(TP),
"The CyberNinja DEATH MACHINE makes its kill!\n");
        TP->hit_player(1000000);
      }
    }
  }
  if(TP->query_real_name() == "snow"
  || TP->query_real_name() == "dune") {
    add_action("activate","activate_death");
  }
}
 
activate() {
  int rand;
  object ob, room;
  rand = random(18) + 1;
  call_out("activate", 1);
  findRoom(rand, this_object());
  return 1;
}
 
findRoom(int rand, object ob) {
  switch(rand) {
    case 1:    MO(ob, "/players/dune/closed/guild/rooms/holodeckA.c"); break;
    case 2:    MO(ob, "/players/dune/closed/guild/rooms/holodeckB.c"); break;
    case 3:    MO(ob, "/players/dune/closed/guild/rooms/holodeckC.c"); break;
    case 4:    MO(ob, "/players/dune/closed/guild/rooms/chopshop.c"); break;
    case 5:    MO(ob, "/players/dune/closed/guild/rooms/hallway1.c"); break;
    case 6:    MO(ob, "/players/dune/closed/guild/rooms/meditation.c"); break;
    case 7:    MO(ob, "/players/dune/closed/guild/rooms/teleport.c"); break;
    case 8:    MO(ob, "/players/dune/closed/guild/rooms/guildhall.c"); break;
    case 9:    MO(ob, "/players/dune/closed/guild/rooms/bar.c"); break;
    case 10:    MO(ob, "/players/dune/closed/guild/rooms/meeting.c"); break;
    case 11:    MO(ob, "/players/dune/closed/guild/rooms/arenalounge.c"); break;
    case 12:   MO(ob, "/players/dune/closed/guild/rooms/armory.c"); break;
    case 13:   MO(ob, "/players/dune/closed/guild/rooms/shop.c"); break;
    case 14:   MO(ob, "/players/dune/closed/guild/rooms/weaponry.c"); break;
    case 15:   MO(ob, "/players/dune/closed/guild/rooms/hallway2.c"); break;
    case 16:   MO(ob, "/players/dune/closed/guild/rooms/lore1.c"); break;
    case 17:   MO(ob, "/players/dune/closed/guild/rooms/lore2.c"); break;
    case 18:   MO(ob, "/players/dune/closed/guild/rooms/mechshop.c"); break;
    }
}
