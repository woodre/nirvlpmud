#define USER "gaston"
object target;

int total;

start_shadow(ob) {
  shadow(ob,1);
  target=ob;
}

stop_shadow(ob) {
  shadow(ob,0);
  target=0;
  destruct(this_object());
}

hit_player(x) {
  object u;
  u=find_player(USER);
  tell_object(u,"\nDAMAGE = "+x);
  total+=x;
  tell_object(u,"\tTOTAL = "+total+"\n");
}
