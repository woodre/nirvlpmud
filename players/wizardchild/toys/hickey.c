/* hickey.c: allows players to give hickeys */
#define HICKEY "/players/wizardchild/toys/hickey_ob"
#define THIS this_player()
ansi_char(x) {
  return pad("",1,27)+"["+(x ? "32" : "0")+"m";
}
get() { return 1; }
drop() { return 1; }
id(str) { return str == "hickey_give"; }
query_auto_load() { return "/players/wizardchild/toys/hickey.c:"; }
init() { add_action("hickey","hickey"); }
hickey(str) {
  object h,w;
  string wh,we;
  status here;
  if(!str || str == "") {
    write("You have to give the hickey to someone.\n");
    return 1;
  }
  if(sscanf(str, "%s %s", wh, we) < 2) {
    wh = str;
    we = "neck";
  }
  if(!(w = find_player(wh)) || 
       w->query_invis() > THIS->query_level() ||
       in_editor(w)) {
    write("I couldn't find that player.\n");
    return 1;
  }
  if(w == THIS) {
    write("It doesn't work that way. Only kinky people do that.\n");
    return 1;
  }
  if(present("hickey",w)) {
    write("That person already has one hickey. People might say strange things about them.\n");
    return 1;
  }
  h = clone_object(HICKEY);
  here = (present(w,environment(THIS))?1:0);
  write("You give "+capitalize(wh)+" a hickey on their "+
        ansi_char(1)+we+ansi_char(0)+(!here?" from afar":"")+".\n");
  say(THIS->query_name()+" gives "+capitalize(wh)+" a hickey on their "+
      ansi_char(1)+we+ansi_char(0)+(!here?" from afar":"")+".\n",w);
  tell_object(w,this_player()->query_name()+" gives you a"
   +" hickey on your "+ansi_char(1)+we+ansi_char(0)+
   (!here?" from afar":"")+".\n");
  if(!here)
    w->remote_say(THIS->query_name()+" gives "+capitalize(wh)+
     " a hickey on their "+ansi_char(1)+we+ansi_char(0)+" from afar.\n");
  move_object(h,w);
  h->set_string(
  capitalize(wh)+" has a hickey on their "+ansi_char(1)+we+ansi_char(0)+"!");
  return 1;
}
