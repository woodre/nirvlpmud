id(str) { return str == "btell" || str == "mtell"; }
init() { add_action("mtell","mtell"); }
drop() { return 1; }
mtell(str) {
  string msg,who;
  sscanf(str,"%s %s",who,msg);
  msg = format(msg,40);
  if(find_player(who)) { tell_object(find_player(who),"Braxana <mythos> tells you: "+msg+"\n");
   write("You tell "+who+" "+msg+"\n");
   return 1; }
  else { write("NOt here.\n");
}
return 1; }
