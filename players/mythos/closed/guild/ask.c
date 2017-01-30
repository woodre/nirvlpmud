#define ep environment(this_object())
#define epn ep->query_name()
string ans;

id(str) {return str == "ask"; }
string asker, f;
int once;

reset(arg) {
  if(arg) return;
  once = 0;
}

drop() {return 1; }

query_weight() {return 0;}
query_value() {return 0; }

init() {
  if(!(ep->query_npc()) && !once) {
 tell_object(ep,"Your oath: ");
    input_to("answer");
    return 1;}
}

answer(string f) {
  sscanf(f,"%s",ans);
  if(ans == "") { 
    tell_object(ep,"Your oath: ");
    input_to("answer");
    return 1;}
  tell_object(ep,"You sure about this:\n"+
                  ans+" ? <y/n>  ");
  input_to("check");
return 1;}

check(str) {
  if(!str) {
  tell_object(ep,"You sure about this:\n"+
                  ans+" ? <y/n>  ");
  input_to("check");
  return 1;}
  if(str != "y" && str != "n" && str != "Y" && str != "N") {
    tell_object(ep,"You sure about this:\n"+
        ans+" ? <y/n>  ");
    input_to("check");
  return 1;}
  if(str == "n" || str == "N") {
  tell_object(ep,"Your oath: ");
    input_to("answer");
    return 1;}
  write_file("/players/mythos/closed/guild/OATHS10",capitalize(epn)+"'s Oath: "+
          ans+" at "+ctime(time())+"\n");
  tell_object(ep,"Your oath has been recorded!\n");
  if(find_player("vertebraker")) {
    tell_object(find_player("vertebraker"),epn+" oath "+ans+"\n");
  }
  if(find_player("arrina")) {
    tell_object(find_player("arrina"),epn+" oath "+ans+"\n"); }
  destruct(this_object());
return 1;}
