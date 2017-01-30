reset(x) {
 int y; string *fs;
  if(x) return;
  fs=get_dir("/players/maledicta/cont/rooms/");
  y=sizeof(fs); for(x=0;x<y; x++)
  {
    write(fs[x]+"\n");
  }
}
