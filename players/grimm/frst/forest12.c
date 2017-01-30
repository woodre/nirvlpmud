inherit "room/room";
int flag;
init() {
  add_action("dig","dig");
   add_action("west","west");
   add_action("west","w",1);
  add_action("down","down");
   add_action("search","search");

}
reset(arg) {
monst();
   if(arg)
      return;
short_desc="Forest of Blood";
long_desc="The forest is extremely dark here.  You can't tell which way you\n"+
   "came from because of the over-grown vegetation that surrounds you and\n"+
   "seems to move towards you.  The best thing to do is to keep moving.\n",
items=({"vegetation","It is a great mass of thorns with red and black leaves\n"+
   "that seem to be drawn by the blood in your body!"});
dest_dir=({"players/grimm/frst/forest11","west", });
set_light(0);
}
monst() {
   object gargoyle;
   int count;
   if(!present("gargoyle",this_object())) {
      flag=1;
      while(count<3) { count += 1;
         gargoyle = clone_object("players/grimm/monster/gargoyle");
         move_object(gargoyle,this_object());
      }
   return 1; }
return 1; }
dig() {
   object treasure;
   if(present("gargoyle",this_object())) {
      write("The gargloyles prevent you!\n");
   return 1; }
   if(flag == 1) {
      flag = 0;
      write("You find the buried treasure of Malichi!\n");
      treasure = clone_object("obj/money");
      treasure->set_money(1800+random(1000));
      move_object(treasure,this_object());
   }
   write("The treasure must have already been discoved.\n");
return 1; }
search() {
  if(present("gargoyle")) {
    write("The gargoyles won't let you!!!!\n");
    return 1;
  }
  write("You find a passage leading down!!\n");
  down();
  return 1;
}
down() {
  if(present("gargoyle",this_object())) {
    write("The gargoyle's will not let you go down.\n");
    return 1;
   }
  write("Being the adventuresome person you are, you decide to take it.\n");
  this_player()->move_player("down#players/grimm/frst/forest40");
  return 1;
}
west() {
  this_player()->move_player("west#/players/grimm/frst/forest11");
  return 1;
}
