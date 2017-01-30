#define TP this_player()
#define TE tell_object
#define LASE "/players/snow/closed/mechs/laser.c"
#define HELI "/players/snow/closed/mechs/shuriken.c"
#define WHIR "/players/snow/closed/mechs/whirli.c"
#define ROLL "/players/snow/closed/mechs/rolling.c"
#define FLAK "/players/snow/closed/mechs/flake.c"
#define LASERCOST 20000
#define HELICOST 12000
#define WHIRCOST 3000
#define ROLLCOST 6000
#define FLAKCOST 2000
 
inherit "room/room";
 
init() {
 add_action("buy","order");
 add_action("list","mechlist");
 add_action("mechsign","mechsign");
 ::init();
}
 
reset(arg){
 
if(!present("mechsmith")) {
   move_object(clone_object("/players/snow/closed/cyber/rooms/MechsmitH.c"),
   this_object());}
 
 if(!arg){
 set_light(1);
 short_desc="The MechShop";
 long_desc=
"   Bright flourescent lights and stark white walls make this\n"+
"room seem more like an operating room than a machine shop.\n"+
"This is where the dreaded attack robots of the CyberNinjas\n"+
"are made.   You can 'order <mech>', 'mechlist', or 'mechsign'.\n";
 
items=({
 "lights","The smooth flourescent floods the room with unnatural light",
 "walls","Blank walls... nothing on them",
 });
 
  dest_dir=({
 "/players/snow/closed/cyber/rooms/shop.c","up",
      });
  }   }
 
object IP(object ob) {
/* This function is similar to a #define, it just
 * returns the guild object on the player specified.
 */
   object guild_object;
   guild_object = present("implants", ob);
   return guild_object;
}
 
buy(string str) {
  int cost;
  int name;
  if(!present("mechsmith")) {
    TE(TP, "There is no mechsmith here to put mechs together for you.\n");
    return 1;}
  if(!str) {
    write("Mechsmith says: What kind of mech would you like to order?\n");
  return 1;
  }
  str = lower_case(str);
  if(!findMech(str)) {
    write("Mechsmith says: I don't make that here.\n");
    return 1; }
  name = findGoodMechName(str);
  cost = findCostOfMech(name);
  if(IP(TP)->balance() < cost) {
    TE(TP, "Mechsmith says: You don't have enough credits to order a "+str+"\n");
    return 1;}
  if(find_living("mech"+lower_case(TP->query_real_name()))) {
    TE(TP, "Mechsmith says: You already have a mech.\n");
    return 1; }
  IP(TP)->addToBalance(-cost);
    IP(TP)->save_me();
  giveCustomerMech(name);
  TE(TP, "The mechsmith takes your order and turns to the back wall...\n"+
         "You see him pushing buttons and muttering...\n"+"\n"+
         "An opening appears in the floor and your mech rises out.\n");
  TE(TP, "Mechsmith says: Thanks for your service.\n");
  return 1;
}
 
int findMech(string str) {
  switch(str) {
    case "laser":               return 1;
    case "laser mech":          return 1;
    case "lasermech":           return 1;
    case "laserball":           return 1;
    case "shuriken":            return 1;
    case "heli":                return 1;
    case "helishuriken":        return 1;
    case "helishuriken mech":   return 1;
    case "whirli":              return 1;
    case "whirlimech":          return 1;
    case "whirli mech":         return 1;
    case "rollingmech":         return 1;
    case "rolling":             return 1;
    case "flakemech":           return 1;
    case "flake":               return 1;
  }
  return 0;
}
 
string findGoodMechName(string str) {
  switch(str) {
    case "laser":                return "lasermech";
    case "laser mech":           return "lasermech";
    case "laserball":            return "lasermech";
    case "lasermech":            return "lasermech";
    case "shuriken":             return "helishuriken";
    case "heli":                 return "helishuriken";
    case "helishuriken":         return "helishuriken";
    case "helishuriken mech":    return "helishuriken";
    case "whirli":               return "whirlimech";
    case "whirlimech":           return "whirlimech";
    case "whirli mech":          return "whirlimech";
    case "rollingmech":          return "rollingmech";
    case "rolling":              return "rollingmech";
    case "flakemech":            return "flakemech";
    case "flake":                return "flakemech";
  }
  return "error (this shouldn't happen)";
}
 
int findCostOfMech(string str) {
  switch(str) {
    case "lasermech":      return LASERCOST;
    case "helishuriken":   return HELICOST;
    case "rollingmech":    return ROLLCOST;
    case "whirlimech":     return WHIRCOST;
    case "flakemech":      return FLAKCOST;
    }
  return 1;
}
 
giveCustomerMech(string str) {
  object mech;
  switch(str) {
case "lasermech":     mech = clone_object(LASE); break;
case "helishuriken":  mech = clone_object(HELI); break;
case "rollingmech":   mech = clone_object(ROLL); break;
case "whirlimech":    mech = clone_object(WHIR); break;
case "flakemech":     mech = clone_object(FLAK); break;
    }
  move_object(mech, this_object());
  mech->set_master(TP);
  return 1;
}
 
list() {
  write(
"   You take a look at the menu:\n\n"+
"ITEM                              COST\n"+
"*********************************************\n"+
"LaserBall                           20000\n"+
"HeliShuriken                        12000\n"+
"RollingMech                         6000\n"+
"WhirliMech                          3000\n"+
"FlakeMech                           2000\n"+
"*********************************************\n");
    return 1;
}
 
mechsign() {
  write(
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"+
"After you order your mech. Type 'mech help'.\n"+
"If you ever see a mech without a master, you\n"+
"may type 'mechtake' to claim it for your own.\n"+
"Mechtake only works if you do not own a mech.\n"+
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
  return 1;
}
