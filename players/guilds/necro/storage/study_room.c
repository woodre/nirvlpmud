#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(1);
   short_desc = "Necromantic Library";
  long_desc=
  "Blackened walls close all about this small chamber, deep within\n"+
  "the fabled tower of Sorcere. Dark red viens of a foreign metal run\n"+
  "throughout the stone, bringing a sense of life to the obsidian\n"+
  "walls. An erie red light glows softly from the floor, carved in\n"+
  "the shape of a large series of triangles all about.\n";

items=({
  "plaque","The small metallic plaque holds a number of intrustions\n"+
           "upon it. <read> the <plaque> for more info",
  "wall", "The black stone of the walls is set with a dark red\n"+
          "ruby veins running all throughout them\n",
  "stone", "The stone of the walls is very rare and valuable",
 });

  dest_dir=({
   "/players/daranath/guild/room/necro5.c","north",
   "/players/daranath/guild/room/necro3.c","west",
           });
  }
}

init(){
 ::init();
  add_action("search","search");
  add_action("study","study");
  add_action("read","read");
  add_action("cost","cost");
  add_action("spell_help","spell_help");
  add_action("spell_list","spell_list");
}

search() {
write("Bits of bone and areas of dried blood are all about.\n");
say (tpn +" searches the area\n");
 return 1;  }

read(str) {
if(!str) {
write("A ghostly voice intones: \n"+
      "What would you like to read?\n");
return 1; }
if(str == "plaque") {
write("The plaque reads:\n\n"+
      "Welcome to the necromantic library. Here all necromancers\n"+
      "can do a number of things. They include:\n"+
      "<spell_list> spell_list shows you what spells Necromancers\n"+
      "             have and what level of excellence you have attained\n"+
      "             in each spell.\n"+
      "<spell_help> spell_help gives a Necromancer detailed help on\n"+
      "             an individual spell.\n"+
      "<study> A Necromancer needs to study in order to improve with\n"+
      "        thier spells.\n"+
      "<cost> Cost lists the experience point cost for studying spells\n"+
      "\nThe darkness comes from deep with the corpse.\n\n");
return 1; }
  else {
write("There is nothing upon that to read.\n");
return 1; }
}

cost(str) {
  if(!str) {
write("A ghostly voice intones: \n"+
      "Which cost listing would you like to see?\n"+
      "options are: Initiate, Master, Necromancer and Avatar\n");
return 1; }
  if(str == "initiate" || str == "Initiate") {
write("The cost to study spells for guild spell levels 1-3 is: \n"+
      "To get a spell from 0% to 50% - 500 exp per 5% \n"+
      "To get a spell from 55% to 75% - 1000 exp per 5% \n"+
      "To get a spell from 80% to 95% - 2500 exp per 5% \n"+
      "\nThe darkness comes from deep within the corpse.\n");
return 1; }
  if(str == "master" || str == "Master") {
write("The cost to study spells for guild spell levels 4-6 is: \n"+
      "To get a spell from 0% to 50% - 1000 exp per 5% \n"+
      "To get a spell from 55% to 75% - 2000 exp per 5% \n"+
      "To get a spell from 80% to 95% - 5000 exp per 5% \n"+
      "\nThe darkness comes from deep within the corpse.\n");
return 1; }
  if(str == "necromancer" || str == "Necromancer") {
write("The cost to study spells for guild spell levels 7-10 is: \n"+
      "To get a spell from 0% to 50% - 2000 exp per 5% \n"+
      "To get a spell from 55% to 75% - 4000 exp per 5% \n"+
      "To get a spell from 80% to 95% - 10000 exp per 5% \n"+
      "\nThe darkness comes from deep within the corpse.\n");
return 1; }
  if(str == "avatar" || str == "Avatar") {
write("The cost to study spells for Avatar spells are: \n"+
      "To get a spell from 0% to 50% - 2500 exp per 5% \n"+
      "To get a spell from 55% to 75% - 5000 exp per 5% \n"+
      "To get a spell from 80% to 95% - 12500 exp per 5% \n"+
      "\nThe darkness comes from deep within the corpse.\n");
return 1; }
  else {
write("A ghostly voice intones: \n"+
      "Options are: Initiate, Master, Necromancer and Avatar\n");
return 1; }
}

gravesite() { return "YES"; }
arate() { return "YES"; }
realm() { return "NT"; }

spell_list(str) {
  if(!str) {
write("A ghostly voice intones: \n"+
      "Which listing would you like to see?\n"+
      "Options are: Initiate, Master, Necromancer and Avatar\n");
return 1; }
  if(str == "initiate" || str == "Initiate") {
/* Guild Level 1-3 spells listed here */
write("Initiate spell listing\n");
return 1; }
  if(str == "master" || str == "Master") {
/* Guild Level 4-6 spells listed here */
write("Master spell listing\n");
return 1; }
  if(str == "necromancer" || str == "Necromancer") {
/* Guild Level 7-10 spells listed here */
write("Necromancer spell listing\n");
return 1; }
  if(str == "avatar" || str == "Avatar") {
/* Guild level 11 spells (avatar = GC) */
write("Avatar spell listing\n");
return 1; }
  else {
write("A ghostly voice intones: \n"+
      "Options are: Initiate, Master, Necromancer and Avatar\n");
return 1; }
}

spell_help(str) {
  if(!str) { 
write("A ghostly voice intones: \n"+
      "Which spell would you like help with?\n");
return 1; }
 /*   Guild Level 1 Spells */
  if(str == "wraithform") {
cat("/players/daranath/guild/docs/wraithform.txt");
return 1; }
  if(str == "chill" || str == "chill touch") {
cat("/players/daranath/guild/docs/chill_touch.txt");
return 1; }
  if(str == "ncall" || str == "necromantic call" || str == "call") {
cat("/players/daranath/guild/docs/necro_call.txt");
return 1; }
  if(str == "embrace_death" || str == "death's embrace" || str == "enbrace") {
cat("/players/daranath/guild/docs/embrace_death.txt");
return 1; }
  if(str == "evaluate" || str == "evaluation") {
cat("/players/daranath/guild/docs/evaluation.txt");
return 1; }
  if(str == "preserve" || str == "preserve corpse") {
cat("/players/daranath/guild/docs/preserve.txt");
return 1; }
  if(str == "harvest" || str == "harvesting") {
cat("/players/daranath/guild/docs/harvest.txt");
return 1; }
  if(str == "craft" || str == "crafting") {
write("A ghostly voice intones: \n"+
      "Which crafting were you looking for?\n");
return 1; }
  if(str == "craft1" || str == "crafting1") {
cat("/players/daranath/guild/docs/crafting1.txt");
return 1; }
  if(str == "autopsy" || str == "autopsy corpse") {
cat("/players/daranath/guild/docs/autopsy.txt");
return 1; }
  if(str == "toolme" || str == "summon_tool"){
cat("/players/daranath/guild/docs/summon_tool.txt");
return 1; }
  /* Guild Level 2 Spells */
  if(str == "assassinate" || str == "assassination") {
cat("/players/daranath/guild/docs/assassinate.txt");
return 1; }
  if(str == "lifedrain" || str == "drain life") {
cat("/players/daranath/guild/docs/life_drain.txt");
return 1; }
  if(str == "consume" || str == "consume corpse") {
cat("/players/daranath/guild/docs/consume.txt");
return 1; }
  if(str == "ddoor" || str == "death's doorway" || str == "doorway") {
cat("/players/daranath/guild/docs/death_door.txt");
return 1; }
  /* Guild Level 3 Spells */
  if(str == "animate" || str == "animation") {
write("A ghostly voice intones: \n"+
      "Which animation are you looking for?\n");
return 1; }
  if(str == "animate1" || str == "animation1") {
cat("/players/daranath/guild/docs/animation1.txt");
return 1; }
  if(str == "control" || str == "control animation") {
cat("/players/daranath/guild/docs/control.txt");
return 1; }
  if(str == "pain" || str == "pain touch") {
cat("/players/daranath/guild/docs/pain_touch.txt");
return 1; }
  if(str == "touch") {
write("A ghostly voice intones: \n"+
      "Which touch spell were you looking for?\n");
return 1; }
  else {
write("A ghostly voice intones: \n"+
      "Which spell would you like help with?\n");
return 1; }
}

study(str) {
  if(!str) {
write("A ghostly voice intones: \n"+
      "Which spell would you like to study?\n");
return 1; }

  if(str == "preserve") {
  present("guild_ob",tp)->add_perc(0,5);
  tp->add_exp(-1000);
  write("You gain in the knowledge of preserving corpses.\n");
  return 1; }

  if(str == "harvest") {
  present("guild_ob",tp)->add_perc(1,5);
  tp->add_exp(-1000);
  write("You gain in the knowledge of harvesting from corpses.\n");
  return 1; }

  if(str == "wraithform") {
  present("guild_ob",tp)->add_perc(2,5);
  tp->add_exp(-1000);
  write("You gain in the knowledge of wraithform.\n");
  return 1; }

  else {
  write("There is no such spell available to you.\n");
  return 1; }
  }
