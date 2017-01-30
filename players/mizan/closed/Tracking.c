/* backed-up version, with no delay */

catch_tell(str) {
 string a, b, c;
 object ob;
 if(!this_player()) return 1;
  if(this_object()->query_attack()) {
    if(sscanf(str, "%s leaves %s.", a, b) == 2) {
    if(b != "up" || b != "wimpy") {
        tell_object(this_object()->query_attack(),
        this_object()->query_name() + " tracks you.\n");
        command(b, this_object());
      }
    }
  }
}

