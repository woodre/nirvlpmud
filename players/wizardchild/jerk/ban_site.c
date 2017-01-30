#define NM this_player()->query_real_name()
short() { return 0; }
long() { return 0; }
id(str) { return str == "ban_site"; }
init() {
  if(NM != "magnus" && NM != "janos" && NM != "perrin" && NM != "ulath"
  && NM != "vanyel" && NM != "maffoo" && NM != "seductress" && NM != "qagwaai"
  && NM != "beatrice" && NM != "gowron" && 
  this_player()->query_hostname() == "168,88,184,12") {
    write("You cannot create a new character from that site.\n");
    destruct(this_player());
  } else {
    write("Ok little EHS kiddy, remember that you are using a PRIVELEGE to be here.\n");
    write("Please do not abuse this privelege.\n");
  }
  return 1;
}
