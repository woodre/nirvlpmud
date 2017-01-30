object fol;

dfollow(str) {
string kj;
object dfol;
if(!str || str == this_player()->query_real_name()) {
write("Usage: dfollow <name>\n");
  write("Spell dispelled.\n"); return 1;}
if(str == "stop") { 
  if(present("follow_1",this_player())) {
  destruct(present("follow_1",this_player()));
  write("Follow off.\n");  }
  return 1;}  
if(present(str, environment(this_player()))) { 
  if(present(str, environment(this_player()))->is_player()) {
    write("Please use the normal 'follow' command that\n"+
          "is now within the normal player file.  Type help\n"+
          "follow for more.\n"+
          "Note: to follow a monster use this dfollow.\n");
   return 1;}
   write("Follow on.\nTo turn off type <dfollow stop>\n");
   this_player()->add_spell_point(-10);
   if(present("follow_1",this_player())) {
  destruct(present("follow_1",this_player()));
  }
  kj = crypt("following",0);
   fol = clone_object("/players/mythos/closed/guild/spells/follow.c");
  fol->set_reference(kj);
  fol->set_foll(str);
  move_object(fol,tp);
    dfol = clone_object("/players/mythos/closed/guild/spells/dref.c");
  dfol->set_reference(kj);
  dfol->set_who(tpn);
  move_object(dfol,present(str, environment(this_player())));
  fol->start();
   return 1;}
   write("Not here to follow.\n");
return 1;}
