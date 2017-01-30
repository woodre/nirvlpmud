short() {return "Tunnel";}
long() {
 write("   Strangely, you have stumbled upon some sort of tunnel...to your\n");
 write("Surprise, this tunnel seems extraordinary new. As you stare at your\n");
 write("new surroundings, you notice that the tunnel walls look like they\n");
  write("are all computerized with streaks of light flashing by. Due to all the\n");
  write("blinking lights, you seem to be getting a headache. You sense a\n");
  write("wierd feeling about the lights...\n");
 write("\n");
 write("The only obvious exit is west.\n");
}

reset(arg) {
 if(arg) return;
 set_light(1);
}

init() {
 add_action("west", "west");
add_action("touch", "touch");
add_action("light", "light");
}

west(arg) {
 this_player()->move_player("west#players/cyrex/shaft11");
return 1;
}
touch(arg) {
if(!arg){
write("Touch what?\n");
return 1;
}
if(arg!="light"){
write("Touch what?\n");
return 1;
}
if(arg == "light") {
light();
return 1;
}
else {
return 0;
}
}
light(arg) {
write("You feel your head spinning then you faint.\n");
write("You awaken after awhile and find yourself in a strange place.\n\n");
 this_player()->move_player("into the lights#players/cyrex/quest/rchamber");
return 1;
}
