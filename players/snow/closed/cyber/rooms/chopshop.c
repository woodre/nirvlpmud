#define TP this_player()
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
 add_action("register","register");
 add_action("join_member","join");
 add_action("leave_ninjas","leaveNinjas");
 add_action("purchase","purchase");
 add_action("equip_list","list");
 ::init();
}
 
 
reset(arg){
if(!present("doctor")) {
   move_object(clone_object("/players/snow/closed/cyber/rooms/DoctoR.c"),
   this_object());}
 if(!arg){
 set_light(1);
 short_desc="CyberNinja Chop Shop";
 long_desc=
"Welcome to the CHOP shop.\n"+
"     Hundreds of moniters and blinking lights fill every wall and\n"+
"corner of this large complex.  All around you, tables and hanging\n"+
"platforms are loaded with the latest electronic technology.  On one\n"+
"side wall, large metal cages protect various cybernetic enhancements.\n"+
"Centered in the room, a huge mechanical bed lies suspended in a mass\n"+
"of wires and monitering equipment.  Several splatters of blood stain\n"+
"everything within a 10' radius around the bed.\n"+
"Please type 'register' to list the services available to you.\n";
 
items=({
 "moniters", "The moniters display internal views of organs",
 "lights","The lights blink on and off in various colors",
 "bed","This is the operation table for new implants or enhancements",
 "tables","The tables are burdened with spare parts and circuit boards",
 "platforms","The platforms descend to about chest height",
 "blood","Both fresh and dried blood lie splattered about",
 });
 
  dest_dir=({
 "/players/snow/closed/cyber/rooms/hallway1.c","east",
      });
  }   }
 
register() {
  string gender, gen;
  gender = TP->query_gender();
  if(gender == "male") gen = "his";
  if(gender == "female") gen = "her";
  if(gender == "creature") gen = "its";
  TE(TP,
  "Services available:\n"+
  "\n"+
  "list......................list all enhancements available.\n"+
  "cyberware.................gives you an enhancement manual.\n"+
  "purchase <enhancement>....buy a new enhancement and have it\n"+
  "                          surgically implanted in your body.\n"+
  "join......................insert new implants and become\n"+
  "                          a new CyberNinja\n"+
  "leaveNinjas...............remove all hardware, honorably commit\n"+
  "                          seppuku (kill yourself), and leave\n"+
  "                          the CyberNinjas.\n");
  TR(TP, TP->query_name()+" registers "+gen+" name.\n");
  return 1;
}
 
equip_list() {
TE(TP, "Enhancements available for sale.....\n");
TE(TP,pad("ITEM",26)+pad("DESCRIPTION",30)+"COST (in @'s)\n");
TE(TP,
"_____________________________________________________________________\n"+
"cybereyes                 see/move in the dark              "+
itemFunc("cybereyes", 2, 0)+"\n"+
"organic converter         decorpse/regenerate/rejuvenate    "+
itemFunc("organic_converter", 2, 0)+"\n"+
"droid                     a handy porter                    "+
itemFunc("droid", 2, 0)+"\n"+
"bionics                   more powerful in combat           "+
itemFunc("bionics", 2, 0)+"\n"+
"blades                    more powerful in combat           "+
itemFunc("blades", 2, 0)+"\n"+
"electricflux              discharge at an enemy             "+
itemFunc("electricflux", 2, 0)+"\n"+
"magneticflux              discharge at an enemy             "+
itemFunc("magneticflux", 2, 0)+"\n"+
"heatflux                  discharge at an enemy             "+
itemFunc("heatflux", 2, 0)+"\n"+
"biolight                  bioluminescense                   "+
itemFunc("biolight", 2, 0)+"\n"+
"emotion controller (emt)  peace/aggression/nausea           "+
itemFunc("emt", 2, 0)+"\n"+
"leg actuators (legs)      increased speed (speedster)       "+
itemFunc("legs", 2, 0)+"\n"+
"matter converter          intramuscular matter converter    "+
itemFunc("matter_converter", 2, 0)+"\n"+
"sub-dermal armor (armor)  added protection in combat        "+
itemFunc("armor", 2, 0)+"\n"+
"_____________________________________________________________________\n");
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
 
leave_ninjas() {
/* So members can leave the guild */
  string file;
  int guild_xp, guild_rank, real_exp;
  object corpse;
  if(!present("doctor")) {
    TE(TP, "You cannot have this operation without the doctor.\n");
    return 1;}
  if(!IP(TP)) {
    write("You are not in this guild.\n");
    return 1; }
  guild_xp = IP(TP)->guild_exp();
  guild_rank = IP(TP)->guild_lev();
  real_exp = call_other(TP, "query_exp", 0);
  IP(TP)->set_xp(-guild_xp);
  IP(TP)->set_rank(-guild_rank);
  IP(TP)->set_guild_name(0);
  IP(TP)->save_me();
  TP->set_guild_name(0);
  TP->set_title("the Ex-CyberNinja");
  TP->add_guild_exp(-TP->query_guild_exp());
  TP->add_guild_rank(-TP->query_guild_rank());
  TP->set_guild_file(0);
  TP->set_home("room/church");
  file = "/players/snow/closed/cyber/ninjas/"+
         this_player()->query_real_name()+".o";
  if(file_size(file) >= 0) rm(file);
  TE(TP, "You disconnect your cyberlinks.\n"+
         "Your implants are surgically removed.\n"+
         "The doctor hands you a long-bladed dagger.\n"+
         "You kneel and honorably commit seppuku.\n"+
         "No longer are you a CyberNinja.\n");
  call_other("/players/snow/closed/cyber/newdaem.c", "overchannel",
          capitalize(TP->query_real_name())+
          " has honorably quit the Ninjas.\n");
  say(capitalize(TP->query_real_name())+" has left the guild.\n");
  write_file(log+"LEAVE", RN+" left the guild. ("+ctime()+")\n");
  TP->hit_player(10000);
  destruct(present("implants", this_player()));
  move_object(this_player(), "/room/church.c");
  return 1;
}
 
join_member() {
/* Way for interested player to join guild */
  int xp;
  object ob, recruitob;
  if(TP->query_ghost()) {
    write("Your immaterial state cannot be surgically altered.\n");
     return 1; }
  if(TP->query_name() == "guest") {
    write("Get out of here.\n"); destruct(TP); return 1; }
  if(!present("either implants", TP)) {
    write("You must be recruited first, before you join.\n");
    return 1; }
  if(present("implants", TP)) {
    write("You already have implants on you.\n");
    return 1; }
  xp = TP->query_guild_exp();
  if(xp) {
    write("You are already in a guild.\n");
    write("If you think this is an error, contact an Emperor.\n");
    return 1; }
  if(!present("doctor")) {
    TE(TP, "You cannot have this operation without the doctor.\n");
    return 1;}
  if(already_in_a_guild(this_player())) {
    TE(TP,"You may only be a member of one guild.\n");
    return 1;}
  if(TP->query_level() < 6) {
    TE(TP, "You must be at least level six to join the CyberNinjas.\n");
    return 1; }
  else {
    write_file(log+"JOIN", RN+" joined the guild. ("+ctime()+")\n");
    ob=clone_object("/players/snow/closed/cyber/implants.c");
    move_object(ob, this_player());
    TP->set_guild_name("cyberninja");
    TP->add_guild_exp(1);
    TP->set_guild_file("/players/snow/closed/cyber/implants.c");
    TP->save_me();
    IP(TP)->save_me();
    if(present("temporary implants", this_player())) {
      recruitob = present("temporary implants", this_player());
      destruct(recruitob);
      TE(TP,"You no longer need the Way of the CyberNinja.\n"); }
    TE(TP,"Implants are surgically placed inside your body.\n");
    TE(TP,"Your electronics are connected to the CyberNet.\n");
    TE(TP,".....You are now a CyberNinja!\n");
    TE(TP,"Type 'cyber' to see the general guild help list.\n");
    call_other("/players/snow/closed/cyber/newdaem.c", "overchannel",
       capitalize(TP->query_name())+" has joined the Ninjas!\n");
    say(capitalize(TP->query_name())+" has joined the Ninjas!\n");
    }
  return 1;
}
 
int already_in_a_guild(object ob) {
/* Checks if player is in another guild */
  if((ob->query_guild_name() != 0) ||
     (ob->query_guild_exp() != 0)  ||
     (ob->query_guild_file() != 0) ||
     (ob->query_guild_rank() != 0)) {
       return 1;}
  return 0;
}
 
purchase(string item) {
/* Way to buy new enhancements */
  int cost;
  string str;
  if(!IP(TP)) {
    TE(TP, "You must be a CyberNinja to purchase enhancements.\n");
    return 1; }
  if(!present("doctor")) {
    TE(TP, "You cannot have this operation without the doctor.\n");
    return 1;}
  if(!item) {
    TE(TP, "Purchase what?\n");
    return 1; }
  if(!isAnItem(item)) {
    TE(TP, "We do not sell "+item+"\n");
    return 1;}
  str = itemRealName(item);
  if(itemFunc(str, 1, 0) == 2) {
    write("You may only have one FluX generator.\n");
    return 1; }
  if(itemFunc(str, 1, 0)) {
    TE(TP, "You have already purchased a "+str+"\n");
    return 1;}
  cost = itemFunc(str, 2, 0);
  if(IP(TP)->balance() < cost) {
    TE(TP, "You do not have enough credits to buy a "+str+"\n");
    return 1;}
  IP(TP)->addToBalance(-cost);
  itemFunc(str, 3, 1);
  write_file(log+"PURCHASE",
    RN+" purchased the "+str+" enhancement. ("+ctime()+")\n");
  TE(TP, "You purchase "+str+"\n");
  IP(TP)->save_me();
  IP(TP)->update_implants();
return 1;
}
 
int isAnItem (string str) {
 switch(str) {
   case "cybereyes":          return 1; break;
   case "organic converter":  return 1; break;
   case "converter":          return 1; break;
   case "droid":              return 1; break;
   case "bionics":            return 1; break;
   case "blades":             return 1; break;
   case "eflux":              return 1; break;
   case "mflux":              return 1; break;
   case "hflux":              return 1; break;
   case "electricflux":       return 1; break;
   case "electric flux":      return 1; break;
   case "mangeticflux":       return 1; break;
   case "magnetic flux":      return 1; break;
   case "heatflux":           return 1; break;
   case "heat flux":          return 1; break;
   case "biolight":           return 1; break;
   case "controller":         return 1; break;
   case "emotion controller": return 1; break;
   case "emt":                return 1; break;
   case "legs":               return 1; break;
   case "leg actuators":      return 1; break;
   case "matter converter":   return 1; break;
   case "armor":              return 1; break;
   }
 return 0;
}
 
string itemRealName (string str) {
 string id;
 switch(str) {
   case "cybereyes":          id = "cybereyes"; break;
   case "organic converter":  id = "organic_converter"; break;
   case "converter":          id = "organic_converter"; break;
   case "droid":              id = "droid"; break;
   case "bionics":            id = "bionics"; break;
   case "blades":             id = "blades"; break;
   case "eflux":              id = "electricflux"; break;
   case "hflux":              id = "heatflux"; break;
   case "mflux":              id = "magneticflux"; break;
   case "electricflux":       id = "electricflux"; break;
   case "electric flux":      id = "electricflux"; break;
   case "magnetic flux":      id = "magneticflux"; break;
   case "magneticflux":       id = "magneticflux"; break;
   case "heatflux":           id = "heatflux"; break;
   case "heat flux":          id = "heatflux"; break;
   case "biolight":           id = "biolight"; break;
   case "emotion controller": id = "emt"; break;
   case "controller":         id = "emt"; break;
   case "emt":                id = "emt"; break;
   case "leg actuators":      id = "legs"; break;
   case "legs":               id = "legs"; break;
   case "matter converter":   id = "matter_converter"; break;
   case "armor":              id = "armor"; break;
   }
 return id;
}
 
int itemFunc (string str, int flag, int new) {
 switch(str) {
   case "cybereyes":
        if(flag == 1) {if(IP(TP)->item_eyes()) return 1; }
        if(flag == 2) return 20000;
        if(flag == 3) IP(TP)->set_eyes(new); break;
   case "organic_converter":
        if(flag == 1) {if(IP(TP)->item_corpse()) return 1;}
        if(flag == 2) return 60000;
        if(flag == 3) IP(TP)->set_corpse(new); break;
   case "droid":
        if(flag == 1) {if(IP(TP)->item_activate_droid()) return 1;}
        if(flag == 2) return 70000;
        if(flag == 3) IP(TP)->set_activate_droid(new); break;
   case "bionics":
        if(flag == 1) {if(IP(TP)->item_bionics()) return 1;}
        if(flag == 2) return 60000;
        if(flag == 3) IP(TP)->set_bionics(new); break;
   case "blades":
        if(flag == 1) {if(IP(TP)->item_blades()) return 1;}
        if(flag == 2) return 30000;
        if(flag == 3) IP(TP)->set_blades(new); break;
   case "electricflux":
        if(flag == 1) {
          if(IP(TP)->item_electricflux() ||
             IP(TP)->item_magneticflux() ||
             IP(TP)->item_heatflux()) return 2;}
        if(flag == 2) return 20000;
        if(flag == 3) IP(TP)->set_electricflux(new); break;
   case "magneticflux":
        if(flag == 1) {
          if(IP(TP)->item_electricflux() ||
             IP(TP)->item_magneticflux() ||
             IP(TP)->item_heatflux()) return 2;}
        if(flag == 2) return 20000;
        if(flag == 3) IP(TP)->set_magneticflux(new); break;
   case "heatflux":
        if(flag == 1) {
          if(IP(TP)->item_electricflux() ||
             IP(TP)->item_magneticflux() ||
             IP(TP)->item_heatflux()) return 2;}
        if(flag == 2) return 20000;
        if(flag == 3) IP(TP)->set_heatflux(new); break;
   case "biolight":
        if(flag == 1) {if(IP(TP)->item_biolight()) return 1;}
        if(flag == 2) return 10000;
        if(flag == 3) IP(TP)->set_flash(new); break;
   case "emt":
        if(flag == 1) {if(IP(TP)->item_emt()) return 1;}
        if(flag == 2) return 40000;
        if(flag == 3) IP(TP)->set_emt(new); break;
   case "legs":
        if(flag == 1) {if(IP(TP)->item_legs()) return 1;}
        if(flag == 2) return 10000;
        if(flag == 3) IP(TP)->set_legs(new); break;
   case "matter_converter":
        if(flag == 1) {if(IP(TP)->item_convert()) return 1;}
        if(flag == 2) return 50000;
        if(flag == 3) IP(TP)->set_convert(new); break;
   case "armor":
        if(flag == 1) {if(IP(TP)->query_armor()) return 1;}
        if(flag == 2) return 40000;
        if(flag == 3) IP(TP)->set_armor(new); break;
   }
 return 0;
}
 
feel() { return "no"; }