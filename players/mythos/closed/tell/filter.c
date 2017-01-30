id(str) { return str == "filter"; }
drop() { return 1; }

init() {
  if(this_player()) if(this_player()->query_level() < 200) { destruct(this_object()); return 1; }

  add_action("filter","filter");
}

filter(str) {
string moo, moo2, moo3;
string me, me2, m3;
int x;
x = 1;

  if(sscanf(str,"%s %s",moo,moo2) != 2) { write(" filter <file> <whattofilter>\n"); return 1; }


for(x=1;x<1000000000;x++) {
  moo3 = read_file(moo,x,1);
  if(moo3)
  if(sscanf(moo3,"%s"+moo2+"%s",me,m3) ) write_file(moo+"bak",moo3);
}
}
