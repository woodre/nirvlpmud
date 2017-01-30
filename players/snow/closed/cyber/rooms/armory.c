#define TP  this_player()
#define CAP capitalize
#define TPN CAP(TP->query_name())
#define EO  environment(ob)
#define ET  environment(TP)
#define FP  find_player
#define TE  tell_object
#define TR  tell_room
#define WHO capitalize(who)
#define RN  TP->query_real_name()
#define log "/players/snow/closed/cyber/log/"

inherit "room/room";


init() {
    add_action("order", "buy");
    add_action("register","register");
    ::init();
}

reset(arg) {
if (!present("armorer")) {
   move_object(clone_object
   ("players/snow/closed/cyber/rooms/ArmoreR.c"),
   this_object()); }

if (!arg) {
 set_light( 1);
 short_desc="CyberNinja Armory";
 long_desc=
"     The CyberNinja armory sells very special armor to CyberNinjas.\n"+
"The armor here is not like normal armor.  It is designed especially\n"+
"with the ninja in mind.  Type 'register' to see what you can do here\n";

   items=({
         });

  dest_dir=({
    "/players/snow/closed/cyber/rooms/shop.c","east",
      });
  }   }


register() {
  string gender, gen;
  gender = TP->query_gender();
  if(gender == "male") gen = "his";
  if(gender == "female") gen = "her";
  if(gender == "creature") gen = "its";
  TE(TP,
  "Services available:\n\n"+
  "buy <design>......buy some ninja armor with the color/design\n"+
  "                  you specified.  The armor comes in a folded\n"+
  "                  package.\n"+
  "                  For you, armor would cost "+findCost()+" @'s.\n");
  TR(TP, TP->query_name()+" registers "+gen+" name.\n");
  return 1;
}

object IP(object ob) {
/* This function is similar to a #define, it just
 * returns the guild object on the player specified.
 */
   object guild_object;
   guild_object = present("implants", ob);
   return guild_object;
}

int findCost() {
  int cost;
  cost = ((int)IP(TP)->query_art_level());
  if(cost >= 8) cost = 8;
  cost = cost * 1000;
  if(cost <= 4000) cost = 4000;
  return cost;
}

order(string str) {
 object pack;
 int cost;
 cost = findCost();
 if(IP(TP)->balance() < cost) {
   write("You do not have enough credits.\n");
   write("CyberNinja armor for you would cost "+cost+" @'s.\n");
   return 1; }
 pack = clone_object("players/snow/closed/cyber/armor/fold.c");
 pack->set_color(str);
 if(!str) {
    write("You buy a brand new set of CyberNinja armor.\n");
    say(TPN+" buys a set of brand new CyberNinja armor.\n"); }
 else {
    write("You buy a set of "+str+" CyberNinja armor.\n");
    say(TPN+" buys a set of "+str+" CyberNinja armor.\n"); }
 IP(TP)->addToBalance(-cost);
 IP(TP)->set_garbcolor(str);
  IP(TP)->save_me();
 move_object(pack, TP);
 return 1;
}
