#include "/players/pavlik/guild/mages/macs"
#include "/players/pavlik/guild/mages/rooms/ROOMS"
#define ITEMS 5
inherit "room/room";

object ob;
string *item_list;

reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Great Library";
long_desc=
"You are in the Great Library, a magnficent hall filled with magical\n"+
"tomes and artifacts gathered from all over the world.  This hall of\n"+
"magic is the Mage's most prized possesion, a collection of the most\n"+
"powerful magic ever created is stored within these walls.  Wizards\n"+
"come to the library for their research and studies.  The library is\n"+
"open to all members of the Mages guild.  There is a small sign at\n"+
"the main desk.\n"+
"There is a shimmering portal on the north wall.\n";

items=({
"sign",
" -- The Great Library: -- \n"+
"Here is the collected knowledge of the Mages Guild.  This room contains\n"+
"magical artifacts and rare books of Magic.  Guild Members can research\n"+
"this vast knowledge to better themselves in the guild.  Those that have\n"+
"donated generously to the Guild may also be able to withdraw valuable\n"+
"items to help them.\n"+
"Commands:\n"+
"  exchange <#>     - turn standard exp to guild exp (at a rate of 3:1)\n"+
"                     ex: exchange 100 turns 100 exp to 33 guild exp\n"+
"  list             - list gifts avaliable for withdraw.\n"+
"  withdraw <#>     - take an item from the library (costs donation pts)",
"books",
"Magical Texts are stacked neatly along the gigantic shelves that march\n"+
"across the room",
"shelves",
"Magical Texts are stacked neatly along the gigantic shelves that march\n"+
"across the room",
"desk",
"The main desk is where the presiding Librarian handles all transactions.\n"+
"There is a small silver bell on top of the desk.",
"portal",
"A magical gateway shimmering within a myraid of colors.  Only the\n"+
"strongest of wizards dare pass through the portal. <portal> to enter",
});


dest_dir=({
  "players/pavlik/guild/mages/rooms/guild_room2", "west",
});

item_list=({
 /* 	name		    cost      file                 */
 "1",	"Skull Ring",	    "2000",   "players/pavlik/armor/skull_ring",
 "2",	"Anything Armor",   "5000",   "players/pavlik/armor/anything_armor",
 "3",	"Wand of Healing",  "12000",  "players/pavlik/items/wand_of_healing",
});

   }
}

query_mguild(){ return "The Library"; }

init(){
  ::init();
  add_action("cmd_read","read");
  add_action("guild_move","gm");
  add_action("exchange","exchange");
  add_action("ring_bell","ring");
  add_action("enter_portal","portal");
  add_action("cmd_enter", "enter");
  add_action("list_stuff","list");
  add_action("withdraw_item","withdraw");
  mage_check();
}

list_stuff() {
  int i;

  write("\n");
  write("#\tItem:\t\t\tCost:\n");
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  for(i=0; i<sizeof(item_list); i+=4) {
    write(item_list[i]+")\t"+item_list[i+1]+"\t\t"+item_list[i+2]+"\n");
  }
  return 1;
}

withdraw_item(str) {
  int i, cost;
  string name, what;

  if(!str) {
    write("Use: withdraw <item#>\n");
    return 1;
  }

  for(i=0; i<sizeof(item_list); i+=4) {
    if(str == item_list[i]) {
      name = item_list[i+1];
      sscanf(item_list[i+2], "%d", cost);
      what = item_list[i+3];
    }
  }

  if(!name) {
    write("Use: withdraw <item#>\n");
    return 1;
  }

  if(guild->query_donation() < cost) {
    write("You do not have the donation points for this.\n");
    return 1;
  }

  write("You withdraw "+name+".\n");
  guild->add_donation(-cost);
  move_object(clone_object(what), this_player());

  return 1;
}

enter_portal(){
  if(!KNOW("dragon")) {
    write("You are not ready to enter this portal yet.\n");
    return 1;
    }
  write("You step into the magic portal.\n"+
  "You are magically teleported to the chambers beneath the tower.\n");
  say(capitalize(this_player()->query_name())+" enters the portal.\n");
  move_object(this_player(), "players/pavlik/guild/mages/rooms/summon_room");
  write(environment(this_player())->short()+"\n");
  say(capitalize(this_player()->query_name())+" shimmers into view.\n");
  return 1;
}

ring_bell(str){
  if(str == "bell"){
  write(
  "You reach out and tap the small silver bell twice.\n"+
  "The tiny ball chimes twice very very softly.\n"+
  "Shortly after, a weird mist gather behind the desk.  The mist\n"+
  "solidifies into an older Wizard in slate gray robes.\n"+
  "Descartes' gaze sweeps the room and his eyes come to rest on you.\n"+
  "His brows knit in frustration, he points to the sign on the desk,\n"+
  "and then turns back into a misty form and disappears.\n");
   return 1;
   }
}

minxp_check(amount){
  int lvl, elvl;
  int minxp, min;
  lvl = this_player()->query_level();
  elvl = this_player()->query_extra_level();
  if(!elvl) minxp = "/room/adv_guild"->get_next_exp(lvl-1);
  else minxp = "/room/exlv_guild"->get_next_exp(elvl-1);


  min = this_player()->query_exp() - minxp;
  if(this_player()->query_exp() - amount < minxp){
    write("You cannot afford to exchange "+amount+" Xp.\n"+
    "The most Xp you can allocate right now is: "+min+" Xp.\n");
    return 0;
    }

  return 1;
}

exchange(str){
  int much;
  object obj;

  if(!str){
    write("Use: exchange <#>.\n");
    return 1;
    }

  sscanf(str, "%d", much);

  if(much < 3){
    write("You must exchange at least 3 Xp.\n");
    return 1;
    }

  if(!minxp_check(much))
    return 1;

  write(
  "You stroll over to the main desk and tap the tiny silver bell.\n"+
  "A few moments later an old wizard appears behind the desk.  The\n"+
  "old mage carefully looks you over and then takes out a small\n"+
  "writing pad and scribbles something down.  "+HIC+"He rips off the paper\n"+
  "and hands it to you [don't forget to look at the paper!]\n"+NORM+
  "There is a quiet 'poosh' sound, and Descartes is gone!\n");
  obj = clone_object("players/pavlik/guild/mages/obj/exchange_paper");
  move_object(obj, this_player());
  obj->set_amount(much/3);
  this_player()->add_exp(-much);
  return 1;
}

cmd_enter(str)
{
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "portal") {
    notify_fail("You may only \"enter portal\".\n");
    return 0;
  }
  return enter_portal();
}

int cmd_read(string str)
{
  if(str != "sign") return 0;
  long(str);
  return 1;
}
