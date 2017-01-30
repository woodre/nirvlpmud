#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The Inner Chamber";
long_desc =
"  This is the inner chamber of the Templar Castle. Here\n"+
"people come to join the knights cause.  A large altar\n"+
"stands before you, a golden cross imprinted upon its\n"+
"side. Next to the altar is a large broadsword, which\n"+
"leans against a wooden stand. This room is rather dark\n"+
"even with several torches ringing it. A stairway leads\n"+
"up to the recruitment chambers.\n"+
"If you have 3 Knights that have sponsored you, you may\n"+
"'"+HIW+"join"+NORM+"'.\n";

items = ({
"altar",
"This is the altar of the Templars, where the future of the knights\n"+
"come to express their wishes to join the knights. A large cross is\n"+
"imprinted on its marble front",
"cross",
"A beautiful cross of the Knights",
"stairway",
"A narrow winding stairway that leads up to the recruitment chambers",
"broadsword",
"A huge broadsword, made primarily for ceremony",
"sword",
"A huge broadsword, made primarily for ceremony",
"stand",
"A well crafted wooden stand that holds the sword",
"torches",
"Several wooden torches that are held on the walls by\n"+
"iron sconces",
});

dest_dir = ({
  "/players/maledicta/templar/rooms/main","west",
  "/players/maledicta/templar/rooms/recruit_cham.c","up",
});

}

init(){
  ::init();
add_action("join", "join");
  this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }


join() {
object spbrd;
object wgob;
int wok;
  if (this_player()->query_guild_file() == "players/boltar/templar/templar") {
    write("You have already joined this guild :)\n");
    return 1;
  }
  if (this_player()->query_guild_exp() == 1234) {
	write("You are not allowed to join this guild.\n");
	return 1;
	}
  if(present("KnightTemplar", tp)){
   write("You are already a member of this guild.\n");
   return 1;
   }
  wgob = present("warrior_gob", this_player());
 if(wgob){
   if(wgob->query_paladin() && wgob->query_chosen_align() == "good") wok = 1;
   if(wgob->query_knight()) wok = 1;
   }
if(!wok){
   if(tp->query_guild_name() || tp->query_guild_exp() || tp->query_guild_rank() || tp->query_guild_file()){
      write("You are already in another guild.\n");
      return 1;
      }
   if(this_player()->query_level() < 6) {
      write("You must be level 6 to join the Knights.\n");
      return 1;
      }
  }

  if(this_player()->query_alignment() < 10) {
    write("You are not GOOD! How can you join the Templars?\n");
    write("Try again when you have changed your evil ways.\n");
    return 1;
    }

spbrd=call_other("/players/maledicta/templar/rooms/recruit_cham","query_board",0);

if(!spbrd->query_sponsored(this_player()->query_real_name())){
    write("You first must find 3 Templar Knights who will sponsor you.\n");
    return 1;
    }
if(time()-spbrd->query_date(this_player()->query_real_name()) < 24*3600*7) {
    write("You have not been on the sponsor board for seven days.\n");
    return 1;
    }  
if(wok){
  move_object(clone_object("players/maledicta/templar/honorary.c"), this_player());
  spbrd=call_other("/players/boltar/templar/sponsorroom","query_board",0);
  spbrd->remove_entry(this_player()->query_real_name());
  write("You take a giant step through the giant arch of the Knights Templar.\n");
  write("You are given your cross as a symbol of your membership.\n");
  new_shout(this_player()->query_name()+" has just joined the Knights Templar.\n");
  if(wgob->query_glvl() > 55){ this_player()->add_guild_rank(3); }
  else if(wgob->query_glvl() > 45){ this_player()->add_guild_rank(2); }
  else{ this_player()->add_guild_rank(1); } 
  command("fixtitle", this_player());
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
  spbrd=call_other("/players/boltar/templar/sponsorroom","query_board",0);
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
