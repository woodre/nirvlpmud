gget(str) {
  object ob;
if(!str) {write("get what?\n"); return 1;}
ob=present(str,environment(this_player()));
if(!ob) { write("No "+str+"\n"); return 1;}
move_object(ob,this_player()); return 1;}

ddrop(str) {
  if(!str) {write("drop what?\n"); return 1;}
  if(!present(str,this_player())) { write("not here...\n"); return 1;}
  else {
    move_object(present(str,this_player()),environment(this_player()));
  return 1;}
return 1;}

send(str) {
object ob;
string who,what;
if(!str) {write("You gonna do something?\n"); return 1;}
  sscanf(str,"%s %s",who,what);
  ob=find_player(who);
  if(!ob) {write("not here..\n"); return 1;}
  if(!present(what,this_player())) {write("you dont have one...\n"); return 1;}
  move_object(present(what,this_player()),ob);
  write("You call forth a servant and it gives "+what+" to "+capitalize(who)+"\n");
  say(tp+" calls forth a demon from the darkness.....\n\nThe demon flies off...\n");
  tell_object(ob,"\nA small demon appears and hands you a "+what+
  "\n\nIt whispers to you: From Arrina.\n\n");
  tell_room(environment(ob),"\nA small demon flies in and hands something to "+capitalize(who)+".\n\n");
return 1;}

force(str) {
object ob,ob2;
string who, what;
  if(!str) {write("try that again...\n"); return 1;}
  sscanf(str,"%s %s",who,what);
  if(who=="all") {
  ob=first_inventory(environment(this_player()));
  while(ob) {
  ob2=next_inventory(ob);
    if(living(ob) && (ob->is_npc() != 1) && (ob->query_real_name() != "arrina")) {
      command(what,ob);
      }
      ob=ob2;}
      write("You have forced all to "+what+"\n");
   return 1;}
  ob=find_player(who);
  if(!ob) {write("Not here....\n"); return 1;}
  command(what,ob);
  write("You have forced "+capitalize(who)+" to "+what+"\n");
return 1;}
