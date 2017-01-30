int dusted;
reset(arg) {
        if(arg) return;
        dusted=0;
}

id( str ) {
        if(str=="altar") return 1;
        return 0;
}

long() {
        if(!dusted)
        write("This is a small altar, upon it you notice a thick layer of dust.\n");
        else write("This is a small altar, it seems to be dusted recently.\n");
}

short()
  { if(dusted) return "A small altar";
    return "A small dusty altar"; }
init()
{
  add_action( "dust","dust");
}
dust(str)
{ object scroll;
  if(str!="altar") { write("Dust what?!?\n"); return 1; }
  if(dusted) { write("The altar has been dusted recently, it doesn't need to be cleaned again.\n"); return 1;}
  dusted=1;
  write("You dust the altar and find a scroll.\n");
  scroll=clone_object("/players/trix/castle/quest/monst/scroll");
  move_object(scroll,this_player());
  return 1;
}
get() {
        return 0;
}
drop() {
        return 0;
}
