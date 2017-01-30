/**********************************************
*
*     This room is purely for the initiation
*     of new members into the guild.  The one
*     who sponsors the new member must bring
*     the new member to the entrance of the 
*     Library.  The Sponsorer then goes to 
*     this room, sets it up, and summons the new 
*     member. The initiation is done and the new 
*     member leaves 'back' (ending up in /hall.c)
*     The Sponsorer then 'close's the room and 
*     moved to /library3.c.  Thus ending the 
*     initiation sequence. (why as to the rather
*     twisted way of going about initiation:
*     1) mystery, 2) makes it harder to figure
*     out some of the secrets of the guild)
*
************************************************/

#include "/players/mythos/closed/guild/def.h"
inherit "room/room";

reset(arg) {
  if(!present("altar")) {
  move_object(clone_object("/players/mythos/closed/guild/ceremony/altar.c"),this_object());
  }
  if(!arg) {
  set_light(1);
    short_desc = "somewhere";
    long_desc =
    "You have entered a large room.  The walls and ceiling are \n"+
    "a silver coloring, while the floor is made of black marble.\n"+
    "In the center of the room is a black altar.\n";
  items = ({
    "back","This way you may return to the library entrance",
  });
} }
realm() {return "NT"; }
init() {
  ::init();
  if(this_player()->query_real_name() == "vertebraker") {
    tell_object(this_player(),"To do the initiation:\n\tFirst, check.\n"+
          "\tSecond, setup.\n"+
          "\tThird, summon <name> -must be at the Library entrance.\n"+
          "\tFourth, start.\n");
    tell_object(this_player(),"\tFifth, tell neonate 'back' for library.\n"+
          "\tFinal, close the Room of Ceremonies.\n\n"+
          "For this type 'help_init'\n");}
  add_action("summon","summon");
  add_action("close","close");
  add_action("back","back");
  add_action("start","start");
  add_action("setup","setup");
  add_action("check","check");
  add_action("help_init","help_init");
}

summon(str) {
if(this_player()->query_real_name() == "vertebraker") {
  if(!str) {write("Summon who?\n"); return 1;}
  if(find_player(str)->query_current_room() == "/players/mythos/lroom/hall.c") {
    tell_object(find_player(str),"Everything turns dark...\n"+
               "Suddenly you sense that something has changed...\n\n"+
               "You have been summoned to be initiated into the Dark Ones.\n\n");
    tell_room(environment(find_player(str)),capitalize(str)+" vanishes!\n");
    move_object(find_player(str),"/players/mythos/closed/guild/init.c");
    command("l",find_player(str));
    write("You have summoned "+capitalize(str)+" here to be initiated.\n");
    this_player()->add_spell_point(-20);
    return 1;}
    else{
    write(capitalize(str)+" is not at the Library Entrance!\n");
    return 1;}
return 1;}
  write("You may not do that!\n");
return 1;}

close() {
object next_ob ,ob;
if(this_player()->query_real_name() == "vertebraker") {
  write("You have closed the Room of Ceremonies.\n");
  move_object(this_player(),"/players/mythos/lroom/library3.c");
  this_player()->add_spell_point(-20);
  ob=first_inventory(this_object());
  while(ob) {
	next_ob = next_inventory(ob);
	destruct(ob);
	ob = next_ob;
    }
    tell_object(this_player(),"Done\n");
  destruct(this_object());
return 1;}
  write("You may not do that!\n");
return 1;}

back() {
  tell_room(environment(this_player()),capitalize(this_player()->query_name())+" leaves back.\n");
  move_object(this_player(),"/players/mythos/lroom/hall.c");
  command("l",this_player());
  return 1;}

setup() {
if(this_player()->query_real_name() == "vertebraker") {
if(!present("nameless")) { 
  move_object(clone_object("/players/mythos/closed/guild/ceremony/nameless.c"),this_object()); }
if(!present("archivist")) { 
  move_object(clone_object("/players/mythos/closed/guild/ceremony/archivist.c"),this_object()); }
if(!present("praetor")) { 
  move_object(clone_object("/players/mythos/closed/guild/ceremony/overseer.c"),this_object()); }
if(!present("warden")) { 
  move_object(clone_object("/players/mythos/closed/guild/ceremony/warden.c"),this_object()); }
if(!present("mythos")) { 
  move_object(clone_object("/players/mythos/closed/guild/ceremony/mythos.c"),this_object()); } 
write("You have setup the ceremony\n");
return 1;}
  write("You may not do that!\n");
return 1;}

start(str) {
object ob;
if(this_player()->query_real_name() == "vertebraker") { 
if(!str) {write("For who is the ceremony?\n"); return 1;}
  write("The ceremony begins....\n");
  ob=clone_object("/players/mythos/closed/guild/ceremony/ceremony.c");
  ob->set_initiate(str);
  ob->set_sponsor(this_player()->query_real_name());
  move_object(ob,this_object());
  move_object(clone_object("/players/mythos/closed/guild/ceremony/quiet.c"),find_player(str));
return 1;}
  write("You may not do that!\n");
return 1;}

help_init() {
  if(this_player()->query_real_name() == "vertebraker") {
    tell_object(this_player(),"To do the initiation:\n\tFirst, check.\n"+
          "\tSecond, setup.\n"+
          "\tThird, summon <name> -must be at the Library entrance.\n"+
          "\tFourth, start.\n");
    tell_object(this_player(),"\tFifth, tell neophyte 'back' for library.\n"+
          "\tFinal, close the Room of Ceremonies.\n\n"+
          "For this type 'help_init'\n");
          return 1;}
   write("What?\n");
   return 1;}

check(str) {
object ob;
if(!str) {write("To use check <name>\n"); return 1;}
ob=find_player(str);
if(!ob) {write("Not here...\n"); return 1;}
  if((ob->query_guild_exp() != 0) ||  (ob->query_guild_file() != 0) ||
     (ob->query_guild_name() != 0) || (ob->query_guild_rank() != 0)) {
     write("Either this person is still in another guild\n"+
           "or needs to have a wiz look at "+ob->query_objective()+".\n");
  return 1;}
if(present(pact,ob)) {write("This person has already been initiated!\n"); return 1;}
  write("The Dark Fae resonates with the soul of "+capitalize(ob->query_name())+".\n"+
         "You may continue....\n");
return 1;}
