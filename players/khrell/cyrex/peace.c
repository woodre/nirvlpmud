/*
 prison.c
*/

short() { return "Cyrex's prison of peace and quiet"; }

long() {
  write("   You are in Cyrex's white marble prison.  The atmosphere in\n");
  write("here is not that all bad.  It has the sweet fragrance of some\n");
  write("unknown place.  The room has no windows whatsoever, but the\n");
  write("lighting is extremely bright.  There is even a strange draft\n");
  write("coming from some unknown area.  The walls are so smooth and shiny\n");
  write("that you can even see your own reflection.  It feels like you're\n");
  write("being watched and observed from all directions on the other side.\n");
  write("\n");
  write("There are no possible exits.\n");
}

reset(arg) {
  if (arg) return;

  set_light(1);
}


init() {
string name;
name=this_player()->query_real_name();
if(name=="cyrex")
return 0;
  add_action("Cyrex","Lancer");
  add_action("Pray",  "Pray");
  add_action("quit",  "quit");
  add_action("shout", "shout");
  add_action("tell",  "tell");
  add_action("kill",  "kill");
  add_action("lsdir", "ls");
  add_action("goto",  "goto");
  add_action("Goto",  "Goto");
  add_action("Clone", "Clone");
  add_action("clone", "clone");
  add_action("summon","summon");
  add_action("bring", "bring");
  add_action("home",  "home");
  add_action("north", "n");
  add_action("south", "s");
  add_action("east",  "e");
  add_action("west",  "w");
  add_action("up",    "u");
  add_action("down",  "d");
}

Cyrex(arg) {
 this_player()->move_player("into the mirror#players/cyrex/workroom");
return 1;
}

Pray(arg) {
 this_player()->move_player("into the bright light#room/church");
return 1;
}

quit() {
  write("You're not getting out that way!\n");
  return 1;
}

shout() {
  write("Shout all you want.  No one will be able to hear you!\n");
  return 1;
}

tell() {
  write("Nope!  Your'e not telling nobody anything!\n");
  return 1;
}

kill() {
  write("Don't think so!  Strictly no killing will be done in here!\n");
  return 1;
}

lsdir() {
  write("Too bad wiz!  Can't see your directory from in here.\n");
  return 1;
}

goto() {
  write("Too bad wiz!  Can't goto anyone from in here.\n");
  return 1;
}

Goto() {
  write("Too bad wiz!  Can't Goto anyone from in here.\n");
  return 1;
}

Clone() {
  write("Too bad wiz!  Can't Clone anything from in here.\n");
  return 1;
}

clone() {
  write("Too bad wiz!  Can't clone anything from in here.\n");
  return 1;
}

summon() {
  write("Too bad wiz!  Can't summon anyone from in here.\n");
  return 1;
}

bring() {
  write("Too bad wiz!  Can't bring anyone from in here.\n");
  return 1;
}

home() {
  write("Too bad wiz!  Can't go home either.\n");
  return 1;
}

north() {
  write("You run straight into a wall!  You hurt your nose!\n");
  return 1;
}

south() {
  write("You run straight into a wall!  You hurt your head!\n");
  return 1;
}

east() {
  write("Your run straight into a wall!  You stupid fool!\n");
  return 1;
}

west() {
  write("Your run straight into a wall!  You are such an ass!\n");
  return 1;
}

up() {
  write("You hit your head extremely hard as you attempt this.\n");
  return 1;
}

down() {
  write("Too bad you don't have a jackhammer huh??  duh!\n");
  return 1;
}

