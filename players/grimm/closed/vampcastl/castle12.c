inherit "room/room";
int flag;
realm() { return "NT"; }
reset(arg) {
  flag = 0;
  if(arg) return;
  short_desc="Ball Room";
  long_desc=
    "You have entered into the ballroom of the Castle of Malachi.  The\n"+
    "air here is extremely thick, making it hard to breath.  As you\n"+
    "look around the ballroom you are impressed with its overwhelming\n"+
    "size.  You can here music be played in here, but you are not sure\n"+
    "were it comes from.  It looks as if many great dances were held\n"+
    "in this room.  Just standing here makes you feel like dancing.\n";
  dest_dir=({"players/grimm/closed/vampcastl/castle11","west"});
  set_light(1);
}
init() {
   add_action("dance","dance");
   ::init();
}
dance() {
   object monster, sceptre;
   if(flag==1) {
      write("You start to dance, but growing bored you quit.\n");
   return 1; }
   write("As you start to dance the queen vampire appears and joins you!!\n");
   write("Sensing you aren't her child, she turns to attack you!!!\n");
   monster = clone_object("players/grimm/monster/queenvamp");
   sceptre = clone_object("players/grimm/object/sceptre");
   move_object(sceptre,monster);
   move_object(monster,this_object());
   flag = 1;
return 1; 
}
