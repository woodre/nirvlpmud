int opened,holed;
reset(arg) {
        if(arg) return;
        opened=0;
        holed=0;
}

id( str ) {
        if(str=="hatch") return 1;
        return 0;
}

long() {
        write( "A brass hatch covering a hole in the floor. Looking better at it you notice an\n"+
               "octogonal hole.\n");
}

short()
  { return "A brass hatch"; }
init()
{
  add_action( "open","open");
  add_action( "enter","enter");
  add_action( "put","put");
}
open(str)
{
if(str!="hatch") { write("Open what?!?\n"); return 0; }
if(!holed) { write("You try to open it but notice that it's locked.\n"); return 1; }
opened=1;
write("You lift the hatch up and discover a deep old pit going down in the darkness.\n");
return 1;
}
put(str)
{ string a,b;
  object amu;
  if((sscanf(str,"%s into %s",a,b)!=2) &&
      (sscanf(str,"%s in %s",a,b)!=2)) { write("Put what into where?\n"); return 0; }
  if(a!="amulet") { write("Put what?!?\n"); return 1; }
  if(b!="hole") { write("Put where?!?\n"); return 1; }
  amu=present("trixamulet",this_player());
  if(!amu) { write("You don't have the amulet!\n"); return 1;}
  write("You put the brass amulet into the hole on the hatch and hear a gear click.\n");
  move_object(amu,this_object()); 
  holed=1;
  return 1;
}
enter(str)
{
if(str!="pit" && str!="hatch") { if(opened) { write("Enter what?\n");}else{write("What?\n"); } return 0;}
if(!opened) { return;} 
this_player()->move_player("pit#"+"players/trix/castle/quest/pit1");
return 1;
}

get() {
        return 0;
}
drop() {
        return 0;
}
