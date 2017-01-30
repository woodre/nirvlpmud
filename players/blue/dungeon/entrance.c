inherit"room/room";

reset(arg) {

   int i,j,h,n;
   object snake, coins, bat, rat, cobra;

 if(!arg) {

  set_light(1);
   short_desc = "A basement";
   long_desc =
   "This is where all the annoying pests in Blue's castle get placed...\n"+
"From all around you hear screeches, yelps, squeaks, hisses, and the sounds"+
"\nof newbees running after the things that are making the above mentioned\n"+
"noises. From the looks of it, this place was a dark dungeon in the castles\n"+
           "old days of glory...now it's just a bit of a maze.\n";

dest_dir = ({
   "players/blue/dungeon/room1","north",
   "players/blue/dungeon/room2","south",
   "players/blue/dungeon/room3","east",
   "players/blue/dungeon/room4","west",
   "players/blue/castle/entry1","out"
  });

}

if(!present("snake", this_object())) {
   n=random(3);
   i=0;
   while(i<n) {
snake=clone_object("players/blue/monster/snake");
   move_object(snake,this_object());
coins=clone_object("obj/money");
   coins->set_money(10 + random(10));
   move_object(coins, snake);
   i += 1;
   }
}

if(!present("bat",this_object())) {
   n=random(3);
   h=0;
   while(h<n) {
bat=clone_object("players/blue/monster/bat");
   move_object(bat, this_object());
coins=clone_object("obj/money");
   coins->set_money(10+random(10));
   move_object(coins, bat);
   h +=1;
   }
}

if(!present("rat", this_object())) {
   n=random(3);
   j = 0;
   while(j<n) {
rat=clone_object("players/blue/monster/rat");
coins=clone_object("obj/money");
   coins->set_money(10 + random(10));
   move_object(coins, rat);
   j += 1;
   }
}

n = random(5);
if(n=1) {
if(!present("cobra", this_object())) {
cobra=clone_object("players/blue/monster/cobra");
   move_object(cobra, this_object());
coins=clone_object("obj/money");
   coins->set_money(50 + random(25));
   move_object(coins, cobra);
   }
}
}


init() {
  ::init();

   add_action("move_me", "north");
   add_action("move_me","south");
   add_action("move_me","east");
   add_action("move_me","west");
  }

move_me() {
   int w;
   w=random(20);
   if(w<6) {
   this_player()->move_player("out#players/blue/dungeon/entrance");
   return 1;
   }
   if(w==7) {
   this_player()->move_player("out#players/blue/dungeon/room1");
   return 1;
   }
   if(w==8) {
   this_player()->move_player("out#players/blue/dungeon/room2");
   return 1;
 }
   if(w==9) {
   this_player()->move_player("out#players/blue/dungeon/room3");
   return 1;
 }
   if(w==10) {
   this_player()->move_player("out#players/blue/dungeon/room4");
   return 1;
 }
   if(w==11) {
   this_player()->move_player("out#players/blue/dungeon/room5");
   return 1;
 }
   if(w==12) {
   this_player()->move_player("out#players/blue/dungeon/room6");
   return 1;
 }
   if(w==13) {
   this_player()->move_player("out#players/blue/dungeon/room7");
   return 1;
}
   if(w==14) {
   this_player()->move_player("out#players/blue/dungeon/room8");
   return 1;
}
   if(w==15) {
   this_player()->move_player("out#players/blue/dungeon/room9");
   return 1;
}
   if(w==16) {
   this_player()->move_player("out#players/blue/dungeon/room10");
   return 1;
 }
   if(w==17) {
   this_player()->move_player("out#players/blue/dungeon/room11");
   return 1;
 }
}
