/*  Changed so only guildless could use the 
    Newb Hall due to people exploiting it that
    were in guilds.  Fred [1/09/06]
*/

#include "/players/softly/closed/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int peeps;
reset(arg) {
if(!present("announce_board", this_object())){
move_object(clone_object("/players/softly/nhall/notice.c"), this_object());
}
if(arg) return;
        
  set_light(1);

  short_desc = "Hall of Apprentices [Main]";
  long_desc =
    "  You stand within the main Hall of the Apprentices. The walls here\n"+
    "are made of a white stone, each block carefully laid and set in a\n"+
    "silver mortar. The marble floor is polished to a high shine, and\n"+
    "large banners hang from the ceiling.  To the west is the healer of\n"+
    "the apprentices, and to the east is the halls armory.  A long spiral\n"+
    "staircase leads up to the halls portal chamber. To the north lies the\n"+
    "entry to the "+HIR+"School of the Apprentices"+NORM+".  A large door leads out to the\n"+
    "main road.\n"+
    HIG+"A healing aura surrounds this place... If you aren't in a guild\n"+
    "you will regenerate your wounds faster.\n"+NORM;

  items = ({
    "walls",
    "Polished white rock which is carefully laid in a silver mortar",
    "stone",
    "A heavy strong stone that is nearly unbreakable",
    "mortar",
    "An enchanted mortar that holds the hall together",
    "floor",
    "A polished marble floor that you can even see your reflection in",
    "banners",
    "Heavy cloth banners with the symbols of powerful lords imprinted in gold upon\n"+
    "their surface",
    "ceiling",
    "A high ceiling made of stone.  A spiral staircase disappears into its\n"+
    "center",
    "staircase",
    "A long marble staircase leading up to the portal chamber"
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ns1.c","north",
    "/players/softly/nhall/rooms/n2.c","west",
    "/players/softly/nhall/rooms/n3.c","east",
    "/players/softly/nhall/rooms/n4.c","up",
     "/players/vertebraker/misc/nhall/blacksmith.c","south",
    "/room/vill_green.c","out"
  });

}
init(){
  ::init();
  if(this_player()) /* added by Vertebraker [5.30.01] */
  if(this_player()->query_level() > 7 && this_player()->query_level() < 20)
  {
    write("You don't belong here!\n");
    move_object(this_player(), "/room/vill_green.c");
    tell_room(environment(tp), tpn+" arrives suddenly.\n", ({tp}));
    return 1;
  }
  peeps ++; while(remove_call_out("heal_em") != -1); call_out("heal_em", 2, this_player());
}


heal_em(ob) {
  if(!ob || !present(ob, this_object())) return;
  if(ob->query_guild_name()) return;
  if(ob->query_hp()==ob->query_mhp()) {
      tell_object(ob, "Your wounds have been fully healed.\n");
       return;
  }
  ob->heal_self(3 + random(3));
  call_out("heal_em", 2, ob);
}

exit(ob) {
  if(ob->is_player()) {
    peeps--;
    if(peeps <= 0) while(remove_call_out("heal_em") != -1);
  }
  return ::exit(ob);
}
