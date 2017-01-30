object owner;
string *t;
short() { return 0; }
get()   { return 1; }
drop()  { return 1; }
query_auto_load() {
  string out; int i,so;
  out = "/players/wizardchild/shop/tattoo:";
  for(i = 0,so=sizeof(t); i < so; i++) 
    out += "["+t[i]+"]";
  return out;
}
init() {
  owner = this_player();
}
reset(arg) { if(arg) return ; t = ({ }); }
init_arg(str) {
  string rest,tmp;
  rest = str;
  while(sscanf(rest, "[%s]%s",tmp,rest) >= 1) 
    t += ({ tmp });
/* sscanf(rest, "[%s]",tmp); */
/*  t += ({ tmp }); */
}
id(str) { 
  int i; 
  return str == "ND" || str == "tattoo" ||
    (sscanf(str, "tattoo %d", i) && i < sizeof(t));
}
long(which) {
  int i;
  if(!sscanf(which, "tattoo %d", i)) i = 1;
  i--;
  if(i >= sizeof(t)) {
    write("You don't have that many tattoos.\n");
    return 1;
  }
  if(i < 0) {
    write("Kind of pointless looking at any less than 1 of them.\n");
    return 1;
  }
  show_tattoo(i, 0);
  return 1;
}
show_tattoo(num, who) {
  string name, s, e;
  sscanf(t[num], "%s$NAME$%s",s,e);
  if(!who) name = "your";
  else name = owner->query_possessive();
  if(!who)
    write(capitalize(s)+name+e+".\n");
  else
    return owner->query_name()+" has a tattoo of "+s+name+e;
}
query_num() { return sizeof(t); }
add_tattoo(design, place) {
  if(query_num() == 5) return ;
  t += ({ design +" $NAME$ "+ place });
}
extra_look() {
  int i,so; string out;
  out = "";
  for(i=0,so=sizeof(t);i<so;i++) {
    out += show_tattoo(i,1);
    if(i != so-1)
      out += ".\n";
  }
  return out;
}
