reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="grabber") return 1;
        return 0;
}

long() {
        write( "grabber\n");
}

short()
  { return "a grabber"; }
init()
{
  add_action( "grab","grab");
}

grab()
{ string prova;
  int x;
  prova=allocate(50);
  prova=cat("/players/trix/filpro");
  write("hey hey\n");
  for(x=0;x<8;x++){
  write(x+"] "+prova[x]+"\n");
  }
 return 1;
}
get() {
        return 1;
}
drop() {
        return 0;
}
