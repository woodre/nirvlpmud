inherit "players/pavlik/lib/room.c";

int lichen, grabbed;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The sewers";
long_desc=
  "You are in the maze of pipes of murky black sludge that make up the\n"+
  "sewers of Nirvana.  The ancient pipes create an underground palace for\n"+
  "for those that would come here.\n"+
  "A strange lichen grows on the walls and sheds some light here.\n"+
  "There is a bubbling sound to the north.\n";

dest_dir=({
 "/players/pavlik/examples/t2","north",
 "/players/pavlik/examples/t3","south",
});

lichen = 1;  grabbed = 0;

Sounds=({
 "default","You listen to the gurgling sound of the water as it tumbles around\n"+
    "your legs and down the pipe.\n",
 "north","The sound of running water is much stronger to the north",
 "lichen","The green plant doesn't make any noise.\n",
 "water","The water gurgles around your legs.\n",
});

Smells=({
 "default","Bah!  It smells like shit!  What did you expect?\n",
 "water","You stop and think twice about smelling the murky water.\n",
 "lichen","The glowing plant smells a bit like peppermint.  You think it\n"+
    "might be safe to eat.\n",
});

Search=({
 "default","Something in the water catches your eye.\n",
 "water","Something is moving around in the murky water.  Maybe you can try\n"+
    "and grab it.\n",
 "lichen","There is no reason to search the plant.\n",
});

Items=({
 "lichen","There is a small glowing plant here.  It looks quite healthy.\n"+
    "Maybe you could find out more by smelling it.\n",
 "water","The water is dark and murky.  You think you see something\n"+
    "moving around in it.\n",
 "north","You can't see very far in this dim light.\n",
});

load_chats(({
 "The murky sludge bubbles around your legs.\n",
 "Something splashes in the water behind you.\n",
 "You hear some strange noises to the north.\n",
}));

set_chat_frequency(60);

load_monsters(({
 "players/pavlik/cat.c",
 "players/pavlik/monsters/scathe.c",
}));

set_monster_frequency(100);

  }
}

init(){
 ::init();
 add_action("eatit","eat");
 add_action("grabit","grab");
}

eatit(str){
  if(str == "lichen"){
  if(lichen == 0){
    write("The lichen plant has already been eaten.\n");
    return 1;
  }
  write("You pick the glowing plant from the wall and nibble on it.\n");
  write("Mmmm....not bad!\n");
  say(capitalize(this_player()->query_name())+" plucks a lichen plant "+
  "off the wall and eats it.\n");
  change_atmo("item",
  "lichen","The lichen plant is no longer there.\n");
  change_atmo("smell",
  "lichen","The lichen plant is no longer there.\n");
  remove_atmo("search","lichen");
  remove_atmo("sound","lichen");
  lichen = 0;
  return 1;
  }
}

grabit(){
  if(grabbed > 2) return 0;
  if(random(30) > call_other(this_player(),"query_attrib","luc")){
    write("You try to snatch whatever it is from the water,\n"+
    "but you are too slow!\n");
    say(capitalize(this_player()->query_name())+" tries to grab "+
    "something out of the water and misses.\n");
    grabbed++;
    if(grabbed == 3){
      tell_room(this_object(),
      "The shiny object darts away through the murky water.\n"+
      "Whatever it was, it's gone now.\n");
    change_fish();
    }
    return 1;
  }
  else {
    write("You plunge your hands into the icy water and grab the\n"+
    "curious object.  You pull a rainbow colored fish out of the\n"+
    "water!  The fish flaps about furiously in your grip!\n");
    say(capitalize(this_player()->query_name())+" reaches into "+
    "the icy water and grabs a fish!\n");
    grabbed = 3;
    change_fish();
    return 1;
  }
}

change_fish(){
  remove_atmo("search","water");
  change_atmo("item",
  "water","The water is too murky to notice much.\n");
  remove_chat("Something splashes in the water behind you.\n");
  return 1;
}
