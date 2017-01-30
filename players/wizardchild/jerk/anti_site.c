short() { return "Anti site device"; }
long() {
  write("This just prevents someone from logging on from a site.\n");
  return 1;
}
id(str) { return str == "anti site" || str == "device"; }
init() {
string foo,foo2;
if(this_player()->query_age() < 300 && this_player()->is_player()) {
write("Sorry, there is a temporary block on new players.\n");
      if(find_player("wizardchild"))
    tell_object(find_player("wizardchild"), "Player lost.\n");
    command("quit", this_player());
  }
}
