#define NAME "Snow"
#define DEST "room/plane10"
#define GRN "room/vill_green"
#define PUB "room/pub2"
 
id(str) { return str == "gate"; }
 
short() {
   return "The Dimension Gate";
}
 
long() {
   write(
"Before you rise a twin pair of ice towers. Between them arc constant \n"+
"streams of ice-blue energy. You have heard tales of gates between \n"+
"dimensions and this appears to be one of these. Do you dare to enter \n"+
"the gate? \n");
}
 
init() {
    add_action("enter","enter");
}

enter(arg) {

if(!arg) {
  notify_fail("Enter what?\n"); return 0 ;
  }
if(arg == "gate") {
  write("You bravely enter the gate. You are somewhere else.\n");
call_other(this_player(),"move_player",
          "through the gate and is gone#/players/snow/gate.c");
/*
write_file("/players/snow/log/gate",ctime(time())+" "+
      this_player()->query_real_name()+" entered the gate.\n");
*/
    return 1;
    }
}


 
reset(arg) {
  object room, q;
  object notice;
  object mystic;
  room = find_object("room/quest_room");
  if(!present("archwizard",room)) {
    q = clone_object("obj/quest_obj");
    q->set_name("archwizard");
    q->set_hint("Travel through the Interdimensional Gate and ask the\n"+
                "Archwizard Glarvinthal to give you a quest.\n");
    move_object(q,room);
  }
 if(!present("Ursa",room)) {
    q = clone_object("obj/quest_obj");
    q->set_name("Ursa");
    q->set_hint("Reanimate Ursa Major with:\n"+
                "  (1) The soul of a vampire and\n"+
                "  (2) The cold sphere of healing.\n");
    move_object(q,room);
  }
    if (arg)
        return;
    move_object(this_object(), DEST);
/* Don't need to preload, too wierd to fix in ld preloads -Bp
    call_other("/players/snow/ROOMS/fort_hall","clean_up");
    mystic = find_object("players/snow/ITEMS/mystic");
    if(mystic) mystic->reset(1);
    if(mystic && find_player("snow") ) tell_object(find_player("snow"),"Mystic RESET");
*/
    call_other("/players/snow/closed/test/aura","??");
/* this isn't used anymore.
    call_other("/players/snow/ITEMS/fix","??");
*/
    call_other("/players/snow/dervish/gob.c","???");
/*
    call_other("/players/snow/closed/stell.c","???");
    call_other("/players/quantos/castle.c","???");
*/
/*
   if(!present("announceboard",find_object("room/vill_green")))
   move_object(clone_object("/players/snow/ITEMS/notice.c"),"/room/vill_green");
*/
}
is_castle(){return 1;}
