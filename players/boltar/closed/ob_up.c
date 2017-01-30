int start;
init(arg) {
     add_action("upd","upd");
     add_action("st","st");
  }
upd(str) {
object ob;
string f;
int i;
  ob=present("wiz_soul",this_player());
  f =str;
   i =start;
  while(i < 20000) {
    i=i+1;
  str = f +"#"+i;
  write(str+"\n");
  ob->update_object(str);
  }
}
st(arg) {
   sscanf(arg,"%d",start);
   return 1;
}
