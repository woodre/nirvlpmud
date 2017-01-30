/* Copied from Mythos' Healer Block */

init() {
  add_action("nosymbs","advance");
}

nosymbs() {
object venom;
venom = present("venom_object", this_player());

  if(venom) {
	  if(venom->query_venomed()){
    write("You cannot advance while changed!\n");
    return 1;
	  }
   return;
  }
return;
}

get() { return 0; }
