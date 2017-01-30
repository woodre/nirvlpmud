
catch_tell(str) {
 string a, b, c;
 object ob;
 if(!this_player()) return 1;
  if(this_object()->query_attack()) {
    if(sscanf(str, "%s leaves %s.", a, b) == 2) {
    if(b == "up" || b == "wimpy") {
      say((this_object()->query_name()) + " boggles profusely.\n");
      return 1;
    } else {
        tell_object(this_object()->query_attack(),
        this_object()->query_name() + " tracks you.\n");
          call_out("movement_tr", random(4), b);
      }
    }
  }
}

movement_tr(str) {
   if(environment(this_object()))
   if(this_object()->query_attack())
  if(!present(this_object()->query_attack(), environment(this_object()))) {
  command(str, this_object());
  }
  return 1;
}
