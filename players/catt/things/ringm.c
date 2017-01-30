query_auto_load() {
return "/players/catt/things/ringm:" ;
}
#define TP this_player()
id(str) { return str == "ring"; }
get() {return 1;}
short() { return "Ring of Vows"; }
long() {
write("A ring hard made at the forge with great power bestowed unto it.\n" +
      "It is plain silver with no embellishments. A token and proof of\n" +
"love to all those who see it. Although plain great power is in it.\n"+
"some of the powers so far are: place, rest, rose, and blackrose.\n");
return 1; }
reset(arg) {
if(arg) return;
}
init() {
   add_action("place","place");
   add_action("rest","rest");
  add_action("blackrose","blackrose");
  add_action("rose","rose");
}
blackrose() {
  object blackrose;
  if(this_player()->query_real_name() == "catt") {

  blackrose = clone_object("/players/catt/things/blackrose");
  move_object(blackrose, this_player());
return 1;
}
}
rose() {
  object rose;
  if(this_player()->query_real_name() == "wendy") {
  rose = clone_object("/players/catt/things/rose");
  move_object(rose, this_player());
  return 1;
       }
}
place() {
 if(this_player()->query_real_name() == "wendy" || "catt") {
  write("The Ring of Vows is placed upon your hand\n"+
        "The sky brightens and birds sing your praises\n");
say("The Ring of Vows is placed upon "+
this_player()->query_possessive()+"'s hand\n");
  }}
rest() {
if(this_player()->query_real_name() == "wendy" || "catt") {
move_object(this_player(), "/players/catt/workroom.c");
write("You are now at the tower of the the Demon Lord\n");
}}
