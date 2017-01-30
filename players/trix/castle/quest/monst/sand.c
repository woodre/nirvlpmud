int volte;
reset(arg) {
        if(arg) return;
        volte=0;
}

id( str ) {
        if(str=="sand"||str=="heap") return 1;
        return 0;
}

long() {
        write( "This is a heap of sand, left here during the construction of Trixtown's Sewer.\n"+
               "you notice something glittering hidden in the sand.\n");
}

short()
  { return "A heap of sand"; }
init()
{
  add_action( "dig","dig");
}
dig()
{ object hook;
 if(!present("trixshovel",this_player())) {write("You can't dig without the proper tool.\n"); return 1;}
  volte++;
  if(volte<3) { write("You dig in the sand but the stuff is still buried.\n"); return 1;}
  if(volte==3) { write("You dig in the sand and find an iron hook.\n"); 
                hook=clone_object("/players/trix/castle/quest/monst/hook");
                move_object(hook,this_player());
                return 1; }
  write("You dig in the sand but in vain, someone preceeded you.\n");
  return 1;
}
get() {
        return 0;
}
drop() {
        return 0;
}
