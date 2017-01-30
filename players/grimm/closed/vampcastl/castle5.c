#include "/players/grimm/header"
inherit "room/room";
int passage, flag, no_cobwebs;
realm() { return "NT"; }
reset(arg) {
monster();
flag=0;
if(arg)
   return;
short_desc="Dark Corner";
long_desc="You have walked into a dark corner.  There are cobwebs everywhere\n";
dest_dir=({"players/grimm/closed/vampcastl/castle3","north"});
set_light(1);
}
init() {
  add_action("north","north");
  add_action("move","move");
  add_action("move","clean");
  add_action("move","push");
  add_action("look","look");
  add_action("examine","la");
  add_action("look","l");
  add_action("examine","exa",1);
  add_action("enter","south");
  add_action("enter","enter");
  add_action("insert","insert");
  add_action("insert","put");
  ::init();
}
monster() {
   int count;
   object monster;
   if(!present("spider")) 
      while(count < 7) {
         count += 1;
         monster = clone_object("players/grimm/monster/spider");
         move_object(monster,this_object());
      }
return 1; 
}
move(str) {
  if(!str) return;
  if(str != "cobwebs" && str != "cobweb") {
    write("Move what?\n");
    return 1;
  }
  if(present("spider")) {
    write("The spiders keep spinning more!\n");
    return 1;
  }
  write("As you clean away the cobwebs you notice a unique hole in the wall.\n");
  no_cobwebs = 1;
  return 1;
}
look(str) {
  if (!str) return;
  if (str != "at hole") return;
  if (!no_cobwebs) return 0;
  write("It seems to be a man made hole.  As you look into the hole you can\n"+
        "guess that it is about 2 feet deep and about 5 inches in diameter\n");
  return 1;
}
examine(str) {
  if (!str) return;
  if (str != "hole") return;
  if (!no_cobwebs) return 0;
  write("It seems to be a man made hole.  As you look into the hole you can\n"+
        "guess that it is about 2 feet deep and about 5 inches in diameter\n");
  return 1;
}
insert(str) {
  if(!str) return 0;
  if(!no_cobwebs) return 0;
  if(str !="the jewel in hole" && str != "jewel in hole") {
    write("You try to put the "+str+" into the hole, but i don't think that is\n"+
          "what was intended to be inserted.\n");
    return 1;
  }
  if(!present("vamp_jewel",this_player())) {
    return;
  }
  write("As you insert the jewel into the hole you can feel the ground\n"+
        "start to shake.\n");
  write("\nA passage into the wall has opened up!!\n");
  passage = 1;
  return 1;
}
enter(str) {
  object werewolf;
  if (!str) return;
  if(str != "passage") return;
  if (!no_cobwebs || !passage) return 0;
  if(this_player()->query_npc()) {
    say("An evil voice says:  No dead may enter the crypt of Malachi!\n");
    return 1;
  }
  write("Feeling brave you decide to enter the passage way....\n");
  if(flag==0) {
    flag=1;
    write("As you try to enter the passage an evil undead creature throws\n"+
          "you back and says:\n     \"No mere mortal shall get to my master"+
          " without\n      first besting me!\"\n");
    if(!present("stalker")) {
      werewolf = clone_object("players/grimm/monster/stalker");
        move_object(werewolf,this_object());
      return 1;
    }
    return 1;
  }
  this_player()->move_player("into the passage#players/grimm/closed/vampcastl/castle20");
  return 1;
}
north() {
  this_player()->move_player("north#players/grimm/closed/vampcastl/castle3");
  return 1;
}
