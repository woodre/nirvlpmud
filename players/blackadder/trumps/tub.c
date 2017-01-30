int local_weight;
int uses;

init() {
   add_action("trump","trump");
}

id(str) {
   return str == "trump" || str == "card";
}

short() {
   return "A hot tub trump";
}

long() {
   write("A trump card bearing the image of a hot tub.\n");
   write("As you gaze at it the scene becomes quite real!\n");
}

query_value() {
   if (uses == 0) return 0;
    return 100;
}

query_weight() { return 1; }

get() { return 1; }

can_put_and_get() {return 1; }

add_weight(w) {
}

trump(str)
{
   string here_realm, dest_realm;
   if (str != "tub" && str != "hot tub")
      return 0;
   if (uses == 0) {
      write("The face of the card has darkened.  You can barely make it out.\n");
      write("You are all trumped out!\n");
      return 1;
   }
   here_realm=environment(this_player())->realm();
  "/players/blackadder/hideaway"->realm();
   dest_realm=find_object("players/blackadder/hideaway")->realm();
   if((here_realm==dest_realm) && (dest_realm!="NT")) {
       uses -= 1;
       say(call_other(this_player(),"query_name",0) + " trumps out.\n");
       write("Reality slowly dissolves and is reformed\n");
       call_other(this_player(),"move_player","via trump#/players/blackadder/hideaway");
       say(call_other(this_player(),"query_name",0) + " trumps in.\n");
       return 1; }
   else {
       write("Something prevents the trump from functioning.\n");
       return 1; }
}

reset(arg) {
   if(!arg)
   uses = 4;
      return; }
