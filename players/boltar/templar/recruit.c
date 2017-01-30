/* Orginal code from Bern's Clerics, 
   Modified to become The Knight's Templar by Boltar.
  11/11/99  Added the tablet - Dragnar
*/
#define BOARD "players/boltar/templar/items/sponsorboard.c"
reset(arg) {
  if (arg) return;
  if(!present("tablet")) 
    move_object(clone_object("players/boltar/templar/items/tablet"),this_object());
  set_light(1);
}

short() { return "Knights Templar Arch"; }
     
long() {
   write("This is a room of high stone walls leading to a an arched ceiling.\n"+
         "Above, high on the walls are several statues depicting events\n"+
         "throughout Templar history. In the middle of the room is a \n"+
         "large stone arch, it is inscribed with its purpose.\n"+
         "You feel that it requires a closer look.\n");
         write("There is also a large plaque hanging from the north wall.\n");
  write("    There is only one obvious exit: west\n");
  if (this_player()->query_guild_file() == "players/boltar/templar/templar")
    write("But with your special sight you see another opening to the south.\n"+
          "And the arch beckons you to the north.\n");
}
init() {
add_action("info","info");
         add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
     add_action("look", "read");
add_action("west","west", 1);
add_action("south","south", 1);
add_action("north","north", 1);
add_action("join","join");
}
north(){
if(!present("KnightInvite", this_player())) return 0;
  this_player()->move_player("through the arch#players/maledicta/hope/rooms/hportal");
  return 1;
} 
west() {
  this_player()->move_player("west#players/boltar/templar/enter");
  return 1;
}

south() {
  if (this_player()->query_guild_file() != "players/boltar/templar/templar") return 0;
  this_player()->move_player("to the Templar hall#players/boltar/templar/adv_guild");
  return 1;
}


join() {
object spbrd;
  if (this_player()->query_guild_file() == "players/boltar/templar/templar") {
    write("You have already joined this guild :)\n");
    return 1;
  }
  if (this_player()->query_guild_exp() == 1234) {
	write("You are not allowed to join this guild.\n");
	return 1;
	}
  if (this_player()->query_guild_exp()) {
    write("You already belong to another guild.\n");
    write("But you are welcome to retire from that guild to join the Templars.\n");
    return 1;
  }
  if(this_player()->query_level() < 6) {
     write("You must be level 6 to join the Knights.\n");
     return 1;
  }
  if(this_player()->query_alignment() < 10) {
    write("You are not GOOD! how can you join the Templars?\n");
    write("Try again when you have changed your ways.\n");
    return 1;
   }
  spbrd=call_other("/players/boltar/templar/sponsorroom","query_board",0);
  if(!spbrd->query_sponsored(this_player()->query_real_name())) {
    write("You first must find 3 Templar Knights who will sponsor you.\n");
    return 1;
    }
  if(time()-spbrd->query_date(this_player()->query_real_name()) < 24*3600*7) {
    write("You have not been on the sponsor board for seven days.\n");
    return 1;
    }
  this_player()->add_guild_rank(-this_player()->query_guild_rank());
  this_player()->add_guild_rank(1);
  this_player()->add_guild_exp(1);
  this_player()->set_guild_file("players/boltar/templar/templar");
  if(this_player()->query_attrib("ste") > 10 ) this_player()->set_attrib("ste",10);
  if(this_player()->query_attrib("mag") > 12) this_player()->set_attrib("mag",12);
  call_other(this_player(),"reset",1);
  call_other(this_player(),"save_me",0);
  
  spbrd->remove_entry(this_player()->query_real_name());
  write("You take a giant step through the giant arch of the Knights Templar.\n");
  write("You feel a tingle as your attributes are adjusted to match the Knights.\n");
  move_object(clone_object("players/boltar/templar/templar"), this_player());
  write("Congratulations on joining the Knights Templar!\n");
  write("You are given your cross as a symbol of your membership.\n");
  command("fixtitle", this_player());
  new_shout(this_player()->query_name()+" has just joined the Knights Templar.\n");
  return 1;
}


convert() {
int old;
if (this_player()->query_guild_file() == "players/boltar/templar/templar") {
    write("You have already joined this guild :)\n");
    return 1;
  }
write("A wise decision!\n");
write("One moment...\n");
old = this_player()->query_guild_exp();
this_player()->add_guild_exp(-old);
join();
return 1;
}

new_shout(str) {  object list;
  object cross;
  int i;
  list = users();
  for(i=0; i<sizeof(list); i++) {
    cross = present("KnightTemplar",list[i]);
    if (cross && !cross->query_block()) {
      tell_object(list[i],str);
    }
  }
return 1;
}
info(str) {
  if (!str) {
    cat("/players/boltar/templar/info/join");
    return 1;
  }
  if (file_size("/players/boltar/templar/info/"+str)) {
    cat("/players/boltar/templar/info/"+str);
    return 1;
  }
  write("There is no information on that.\n");
  return 1;
}
look(str) {
   if (!str) {
   return 0;
  }
  if (str == "at plaque" || str == "at sign") {
  write("\n"+
 "                       ---------------------\n"+
 "                       | S | A | T | O | R |\n"+
 "                       ---------------------\n"+
 "                       | A | R | E | P | O |\n"+
 "                       ---------------------\n"+
 "                       | T | E | N | E | T |\n"+
 "                       ---------------------\n"+
 "                       | O | P | E | R | A |\n"+
 "                       ---------------------\n"+
 "                       | R | O | T | A | S |\n"+
 "                       ---------------------\n"+
 "\n\n");
  say(this_player()->query_name()+" reads the plaque.\n");
   return 1;
  }
 if (str == "at arch" || str == "at archway" || str == "at stone arch") {
   write("The Archway is inscribed with the following:\n");
   write("     This arch is for those whom have been sponsored to become\n"+
         "     one of the Knights Templar by one of the brother Knights.\n");
   write("     Those whom walk through this arch are forever bound as \n"+
         "     a Knight Templar. Before taking this step you should \n"+
         "     think carefully to decide if this is the road you should\n"+
         "     follow.\n"+
         "The inscription continues:\n"+
         "      The arch will provide more information by commanding information\n"+
         "      from it with the command of info, or info basics.\n"+
         "      To walk through the arch and become a Knight, simply join.\n"+
         "\n\n");
      say(this_player()->query_name()+" examines the stone arch.\n");
      return 1;
      }
if (str == "at statue" || str == "at statues") {
   write("These painted stone statues with bits of gold leaf show many\n"+
         "of the great battles fought and good deeds done by the templars\n"+
         "throughout the ages.\n");
   write("\n");
   say(this_player()->query_name()+" looks upward towards the statues.\n");
   return 1;
   }
return 0;
}
