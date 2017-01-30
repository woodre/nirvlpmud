#include "/players/daranath/guild/defs.h"

inherit "room/room";
object ob,ob2;

reset(arg) {
if(arg) return;

  set_light(1);
  short_desc= "Necromancer Information Center";
  long_desc= 
    "The Necromancer Information Center is a small chamber that you can use to\n"+
    "learn about the guild in order to make a decision wether or not\n"+
    "to join. It is recommended that you read the items available\n"+
    "through the learn command, for if you decide to join, you\n"+
    "agree to abide by everything that is presented here. The\n"+
    "Necromancers are shaping up to be a difficult, yet rewarding\n"+
    "guild to be in, so choose wisely...\n\n"+
    "     -Daranath ColdsBlood, Creator of the Necromancers\n\n"+
    "Commands here -> learn and join\n";

  dest_dir=({
    "/room/church.c","church",
  });
}

init() {
  ::init();
add_action("learn_list","learn_list");
add_action("learn","learn");
add_action("join","join");
}

learn(str) {
  if(!str) {write("What would you like to learn about?\n"+
     "learn_list for a list of items.\n"); return 1; }
if(str == "parts") {cat("/players/daranath/guild/docs/parts_list.txt"); return 1; }
if(str == "tool") {cat("/players/daranath/guild/docs/tool.txt"); return 1; }
if(str == "compouch") {cat("/players/daranath/guild/docs/compouch.txt"); return 1; }
if(str == "harvest") {cat("/players/daranath/guild/docs/harvest.txt"); return 1; }
if(str == "preserve") {cat("/players/daranath/guild/docs/preserve.txt"); return 1; }
if(str == "autopsy") {cat("/players/daranath/guild/docs/autopsy.txt"); return 1; }
if(str == "level1") {cat("/players/daranath/guild/docs/level1.txt"); return 1; }
if(str == "level2") {cat("/players/daranath/guild/docs/level2.txt"); return 1; }
if(str == "level3") {cat("/players/daranath/guild/docs/level3.txt"); return 1; }
if(str == "level4") {cat("/players/daranath/guild/docs/level4.txt"); return 1; }
if(str == "level5") {cat("/players/daranath/guild/docs/level5.txt"); return 1; }
if(str == "level6") {cat("/players/daranath/guild/docs/level6.txt"); return 1; }
if(str == "level7") {cat("/players/daranath/guild/docs/level7.txt"); return 1; }
if(str == "level8") {cat("/players/daranath/guild/docs/level8.txt"); return 1; }
if(str == "level9") {cat("/players/daranath/guild/docs/level9.txt"); return 1; }
if(str == "level10") {cat("/players/daranath/guild/docs/level10.txt"); return 1; }
if(str == "hist1") {cat("/players/daranath/guild/docs/hist1.txt"); return 1; }
if(str == "hist2") {cat("/players/daranath/guild/docs/hist2.txt"); return 1; }
if(str == "hist3") {cat("/players/daranath/guild/docs/hist3.txt"); return 1; }
if(str == "hist4") {cat("/players/daranath/guild/docs/hist4.txt"); return 1; }
if(str == "rules") {cat("/players/daranath/guild/docs/rules.txt"); return 1; }
if(str == "leave_guild") {cat("/players/daranath/guild/docs/leave_guild.txt"); return 1; }
if(str == "rod") {cat("/players/daranath/guild/docs/rod.txt"); return 1; }
if(str == "basic") {cat("/players/daranath/guild/docs/basic.txt"); return 1; }
if(str == "overview") {cat("/players/daranath/guild/docs/overview.txt"); return 1; }
if(str == "join") {cat("/players/daranath/guild/docs/join_guild.txt"); return 1; }
if(str == "others") {cat("/players/daranath/guild/docs/others.txt"); return 1; }
if(str == "roleplay") {cat("/players/daranath/guild/docs/roleplay.txt"); return 1; }
if(str == "value") {cat("/players/daranath/guild/docs/value.txt"); return 1; }
else { write("What would you like to learn about?\n"+
       "learn_list for a list of items.\n");
return 1; }
}

learn_list() {
write("A few items to learn about the Necromancer Guild:\n\n");
write("Basic guild stuff:\n");
write("join, overview, rules, value, rod, leave_guild\n\n");
write("The history of the Necromancer Guild:\n");
write("hist1, hist2, hist3, hist4\n\n");
write("Standard abilities:\n");
write("basic, parts, preserve, autopsy, harvest, compouch, tool\n\n");
write("A few items of note:\n");
write("others, roleplay\n\n");
write("Usage: learn <item>\n");
return 1; 
}

join() {
if(tp->query_level() < 5) {
write("You must be at least level 5 to join the Necromancers.\n");
return 1; }
if(tp->query_guild_name() || tp->query_guild_rank() || tp->query_guild_file() || tp->query_guild_exp()) {
write("Sorry, only someone who is unconnected to any other guild may join\n"+
      "the Necromancers. If you are not in any guild, then your player\n"+
      "may have an error. Please speak with a guild wiz.\n");
return 1; }
if(tp->query_level() > 5 || tp->query_extra_level() > 0) {
write("You must be willing to dedicate your life when you first make contact with\n"+
      "the Realm of Death and join the Necromancers. A sacrifice is required\n"+
      "to the Realm of Death.\n"+
      "Hit 'Y' if you are willing to be reduced to level 5: (y/n) ");
  input_to("accept");
return 1; }

  tp->add_xp(10000 - this_player()->query_exp());
  tp->set_level(5);
  tp->set_extra_level(0);
  ob = clone_object("/players/daranath/guild/obj/misc/com_pouch.c");
  move_object(ob,tp);
  ob2 = clone_object("/players/daranath/guild/guildob.c");
  move_object(ob2,tp);
  command("save",tp);

say(tp->query_name()+ " is led to the Necromancer stronghold by a spirit.\n");
write("A spirit appears and leads you to the guild hall.\n");
this_player()->move_player("to the stronghold#/players/daranath/guild/room/necro2.c");
return 1; 
}

accept(str) {
  if(!str) {write("Hit 'Y' if you are willing to be reduced to level 5: ");
   input_to("accept"); return 1; }
  if(str != "Y" && str != "y") {
   write("Thank you for considering the Necromancers.\n");
   return 1; }

  tp->add_exp(10000 - this_player()->query_exp());
  tp->set_level(5);
  tp->set_extra_level(0);
  ob = clone_object("/players/daranath/guild/obj/misc/com_pouch.c");
  move_object(ob,tp);
  ob2 = clone_object("/players/daranath/guild/guildob.c");
  move_object(ob2,tp);
  command("save",tp);

say(tp->query_name()+" is led to the Necromancer stronghold by a spirit.\n");
write("A spirit appears suddenly and leads you to the guild hall.\n");
this_player()->move_player("to the stronghold#/players/daranath/guild/room/necro2.c");
return 1;
}
