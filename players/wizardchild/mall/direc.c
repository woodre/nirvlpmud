/* direc.c: directory */
short() { return "A general directory"; }
long()  {
  write("There are two parts to this directory: a map, and a listing.\n");
  write("To list a certain type of shop, type \"list <type>\", where type\n");
  write("is one of the following:\n");
  write(" foods\ttoys\tclothing\tmisc\tall\n");
  write("To view the map, type \"view map\".\n");
}
id(str) { 
return str == "directory" || str == "map" || str == "general directory"; 
}
init() { 
  add_action("list", "list");
  add_action("view", "view");
}
list(str) {
  string foo,foo2;
  if(!str) {
    write("Usage: list <type>\n");
    return 1;
  }
  if(str == "all") {
    list("foods");
    list("toys");
    list("clothing");
    list("misc");
    return 1;
  }
  str = "/players/wizardchild/mall/"+str;
  if(file_size(str) < 1 || sscanf(str, "%s.%s", foo,foo2)) 
    write("Unknown type.\n");
  else
    cat(str);
  return 1;
}
view(str) {
  if(!id(str)) return 0;
  cat("/players/wizardchild/mall/MAP");
  return 1;
}
