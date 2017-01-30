mapping map;
id(str){ return str == "wibble"; }
short(){ return map["chicken"]; }
init(){
map = ([ "chicken" : "weasel" ]);
map += ([ "frog" : "womble" ]);
map += ([ "fire" : "hot" ]);
write(keys(map));
write(map["chicken"]+"\n");
write(map["frog"]+"\n");
}
