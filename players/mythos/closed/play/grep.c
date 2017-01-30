id(str) { return str == "grep"; }

init() { add_action("ggrep","ggrep"); }

ggrep() {
  string name,null;
  string base,user;
  string diry,moo;
  int h,j;
  moo = object_name(this_object());
  sscanf(moo,"%s#%s",name,null);
  base = explode(name,"/");
  if(base[0] == "players") user = "players/"+base[1];
  else user = base[0];
  diry = get_dir("/"+user+"/");
  h = 0;
  j = 1;
  while(h<sizeof(diry)) {
    write(diry[h]);
    write("  ");
    j = j + 1;
    if(j == 4) { j = 1; write("\n"); }
    h += 1;
  }
return 1; }