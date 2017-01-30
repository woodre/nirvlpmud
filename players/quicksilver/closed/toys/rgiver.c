init()
{
  add_action("destme","dme");
  if(this_player()->query_real_name()=="esoterica")
     give_rose();
}

get() { return 0; }
drop() { return 0; }
id(str) { return str=="giver"; }

destme(str) {
	destruct(this_object());
        return 1;
}

give_rose() {
   tell_object(find_player("esoterica"), "A drow steps out from a dark corner of the room.\nSilently, he hands you a rose and returns to the shadows.\n");
   move_object(clone_object("players/quicksilver/closed/qrose.c"), find_player("esoterica"));
}
