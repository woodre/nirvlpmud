id(str) { return str == "stataverager" || str == "statavg"; }

init() { 
  if(this_player()->query_level() < 40) destruct(this_object()); 
  add_action("stat","statav");
}

stat(str) {
object targ;
int sta,h,i,l;
if(!str) return 0;
  targ = find_player(str);
  if(!targ) { write("that target is not in play.\n"); return 1; }
  sta = allocate(8);
  sta[0] = targ->query_attrib("str");
  sta[1] = targ->query_attrib("sta");
  sta[2] = targ->query_attrib("mag");
  sta[3] = targ->query_attrib("pie");
  sta[4] = targ->query_attrib("ste");
  sta[5] = targ->query_attrib("luc");
  sta[6] = targ->query_attrib("wil");
  sta[7] = targ->query_attrib("int");
  i = 0;
  for(h=0;h<8;h++) {
   i += sta[h]; }
  write("Str: "+sta[0]+" Sta: "+sta[1]+" Mag: "+sta[2]+" Pie: "+sta[3]+" Ste: "+sta[4]+" Luc: "+sta[5]+" Wil: "+sta[6]+" Int: "+sta[7]+"\n");
    write(capitalize(str)+" stats average : "+i/8+"\n");
return 1; }
