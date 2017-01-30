
int opened, i, n, num, i;
string attrib, raise;

id(str) { return str == "grimoire" || str == "book"; }

short() { return "An ancient grimoire"; }

long() {
   write("A very old leather book of ancient make.\n");
   if(opened == 1) {
     write("It is open.\n");
     return 1;
   } else
   write("It is closed.\n");
}

init() {
   add_action("open","open");
   add_action("close","close");
   add_action("read","read");
}

open(str) {
   if(str == "grimoire" || str == "book") {
   if(opened == 1) {
     write("The grimoire is already open.\n");
     return 1;
   }
   i = random(20);
   if(i > 12) {
     write("You open the book to roughly and the pages crumble to dust.\n");
     destruct(this_object());
     return 1;
   }
   write("You open the grimoire very carefully.\n");
   opened = 1;
   } else
   write("Open what?\n");
   return 1;
}

close(str) {
   if(str == "grimoire" || str == "book") {
   if(opened == 0) {
     write("The grimoire is not open.\n");
     return 1;
   }
   i = random(20);
   if(i > 12) {
     write("You close the grimoire too roughly and the pages crumble to dust.\n");
     destruct(this_object());
     return 1;
   }
   write("You close the grimoire.\n");
   opened = 0;
   return 1;
   } else
   write("Close what?\n");
   return 1;
}

read(str) {
string moo;
   if(str == "grimoire" || str == "book") {
   if(opened == 0) {
     write("The grimoire must be opened first.\n");
     return 1;
   }
   i = random(7);
   if(i == 0) { attrib = "strength"; moo = "str"; }
   if(i == 1) { attrib = "stamina"; moo = "sta"; }
   if(i == 2) { attrib = "will_power"; moo = "wil"; }
   if(i == 3) { attrib = "piety"; moo = "pie"; }
   if(i == 4) { attrib = "stealth"; moo = "ste"; }
   if(i == 5) { attrib = "luck"; moo = "luc"; }
   if(i == 6) { attrib = "magic_aptitude"; moo = "mag"; }
   raise = "raise_"+attrib;
   i = random(3);
   if(i == 0) { num = -1; }
   if(i == 1) { num = 1; }
   if(i == 2) { num = 0; }
  if(this_player()->query_attrib(moo) < 20 || num < 0)
   call_other(this_player(), raise, num);
   write("The grimoire explodes into a spray of dust.\n");
   destruct(this_object());
   return 1;
   } else
   write("Read what?\n");
   return 1;
}

