inherit"room/room";

int dir;

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "An obsidian plane.";  
   long_desc = 
   "You find yourself standing on a 10' square piece of black obsidian rock"+
",\nthat appears to be suspended in mid air.  All around you hang similiar "+
"\nslabs of rock, magestically floating.  You see no sky, or ground, but "+ 
"\nseem to be in a huge room, with only blackness for the ceiling and ground."+
"\n  These great planes of shining black rock are each 10' apart, and you may"+
"\nbe able to jump between them, although you don't know exactly what is belo"+
"w\nor above you in this strange cavern.\n"; 

dest_dir = ({
   "players/blue/plane/plane_start","north",
   "players/blue/plane/plane_start","south",
   "players/blue/plane/plane_start","east",
   "players/blue/plane/plane_start","west"
});
   }
}

move_check() {
   int ste,luc, level, str, rand, roll;
   object player;
      player=this_player();
   ste=player->query_attrib("ste");
   luc=player->query_attrib("luc");
   level=this_player()->query_level();
   str=player->query_attrib("str");
      rand=random(65);
 roll=rand - (ste/2) - (luc/2) - (str/2) - level;
   if( roll < 0 || roll == 0) {
      return 0;
   }   
   if(roll > 0 && roll < 20) {
   write("Your hands grip the next square, but it slips out of your grasp!n");
   say(capitalize(this_player()->query_name()) + " touches the next square but"+
      " it slips to jump to the next square"+
" but misses and is sentntumbling into the blackness below.n");
say(capitalize(player->query_name()) +" attempts to jump to the next square"+
" but misses and is sent\ntumbling into the blackness below.\n");
      do_fall();
   }
if(roll ==20 || roll >20) {
      write("You miss the next square completely and tumble into the darkness"+
         " below.\n");
say(capitalize(player->query_name()) +" attempts to jump to the next square"+
" but misses and is sentntumbling into the blackness below.n");
      do_fall();
   }
   return 1;
}

do_fall() {
   int start;
   int n;
   n=(random(19) + 1);
   write( n + "\n");
   write("Falling....\n\nFalling....\n\nFalling....\n\n");
   write("You see only darkness below you...\n\n");
   write("Suddenlly, below you see strange squares, crossing each other in"+
   " two lines.  You are looking down on the spot you fell through!  Good new"+
   "s?\nYou notice yourself falling towards the group of obsidian rocks that"+
" you so\nquickly left a second ago.   You attempt to grab on to one as it"+
   " comes closer.\n");
   if( random(10) > 7) {
      move_object(this_player(), "players/blue/plane/plane_start");
   } else {
   move_object(this_player(), "players/blue/plane/plane"+n);
   }
   write("\nYou plummet into the hard obsidian stone.\n");
   command("look",this_player());
  say(capitalize(this_player()->query_name()) + " plummets out of nowhere "+
      " and slams painfully into the floor next to you.\n");
   write("You say: Ouch.\n");
   say(capitalize(this_player()->query_name()) + " says: Ouch.\n");
   return 1;
}

