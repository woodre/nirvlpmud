id(str){
  return (str == "eros"); 
}

short(){
  string dshort;
  dshort = "Eros";
  dshort += " (neutral)";
  return dshort;
}

long(){
  string dlong;
  dlong = "Eros(tm) is a small little toy of Wocket.  Please do not touch.\n";
  write(dlong);
  return 1;
}

myCmds(){
  localcmd();
  write ("\n");
  return 1;
}
