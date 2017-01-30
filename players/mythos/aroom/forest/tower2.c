#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("masakado")) {
   
move_object(clone_object("/players/mythos/amon/forest/masakado.c"),this_object());
  }
  if(!arg) {
  set_light(-1);
    short_desc = "Tower 2nd Level";
    long_desc =
    "You have entered the Tower.  All is dark and frightening.\n"+
    "You barely make out a figure in the corner of the room.\n"+
    "He has and aura of darkness.  You see stairs at the \n"+
    "far end of the room.  A book plaque is set near it.\n"+
    "You also notice a strange wind seems to blow here.....\n";
  items = ({
    "stairs","The 'wall' near the stairs seems a bit odd",
    "wall","The wall seems to be made out of wooden panels.  One of them \n"+
              "seems indented, maybe you should 'touch' it",
    "up","You see stairs at the far end of the room...",
    "back","You may return to the forest ....",
    "plaque","It is hard to make out what it says.  \n"+
    "You may want to 'read' it carfully",
  });

  dest_dir = ({
  "/players/mythos/aroom/forest/tower3.c","up",
  "/players/mythos/aroom/forest/tower.c","back",
  });
} }
  init()  {
    ::init();

if(this_player())
  this_player()->set_fight_area();
    add_action("touch_panel","touch");
    add_action("read","read");
/*
    add_action("kkill","kill");
    add_action("kkill","missle",2);
    add_action("kkill","fireball",2);
    add_action("kkill","shock",2);
    add_action("kkill","sonic",2);
*/
}

touch_panel() {
 
call_other(this_player(),"move_player","touch#players/mythos/aroom/forest/towerh.c");
  say(tp+" touches something along the wall and disappears.\n");
return 1;
}

read(str) {
  if(str == "plaque") {
    write("\n");
    write("In the name of Yasha, and by the power invested in me,\n"+
      "I have trapped these creatures.  Nevermore, shall they\n"+
      "roam the earth and spew destruction!\n"+
      "                                          -The Hunter\n\n");
  return 1; }
  else {
    write("Read what?\n");
return 1; }
return 1; }

kkill(str) {
  if(!str)  return 0;
  if(present(str,this_object())) {
  if(present("masakado",this_object())) {
      present("masakado",this_object())->attack_object(this_player()); 
  } } else {
  write("That is not here.\n"); return 1;}
}

exit(ob) { if(!ob) return; else ob->clear_fight_area(); }
