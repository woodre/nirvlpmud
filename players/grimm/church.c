#include "/players/grimm/header"
inherit "room/room";
int amulet, wait;
reset(arg) {
  amulet = 0;
  monster();
  if(arg) return;
  short_desc="Old Church";
  long_desc="This is a very old church.  It must have used it before \n"+
            "the vampires took over.  You sense a feeling of safety being\n"+
           "in this church, many people must have come here for sanctuary.\n"+
           "As in most churches, you can see a cross hanging on the wall and\n"+
           "in front of you there is an altar.\n",
  items=({"cross","The cross is very large and intact.  Apparently vampires can't touch it"});
  dest_dir=({"/players/grimm/street12","south", });
  set_light(1);
  make_altar();
}
init() {
   add_action("pray","pray");
   add_action("south","south");
   add_action("south","s",1);
}
pray() {
  write("As you start to pray a heavenly voice starts talking to you.\n");
  if(!amulet) {
  move_object(clone_object(DIR2(amulet)),this_player());
  amulet = 1;
  }
  if(!present("vampy",this_player())) {
    move_object(clone_object(DIR2(prayer)),this_player());
  }
  return 1;
}
monster() {
   object man, cloth;
   if(!present("old man")) {
      man = clone_object(DIR8(oldman));
      cloth = clone_object(DIR2(cloth));
      move_object(cloth,man);
      move_object(man,this_object());
   }
}
make_altar() {
  object altar;
  if(!present("altar",this_object())) {
    altar = clone_object("/players/grimm/object/altar");
    move_object(altar,this_object());
  }
}
south() {
this_player()->move_player("south#/players/grimm/street12");
return 1;
}
