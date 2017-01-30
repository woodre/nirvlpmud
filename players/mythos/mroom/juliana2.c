#include "/players/mythos/closed/ansi.h"
inherit "room/room";
object ob, ob2, ob3;
int z;
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle3.c"),this_object()); }
  if(!present("dj")) {
    ob = clone_object("/players/mythos/mmon/dj.c");
    z = random(10);
    if(z == 0) { ob->set_short("DJ Anthony Lloyd Gulley"); ob->set_alias("anthony"); 
    ob->set_long("\n");
    ob2 = clone_object("/players/mythos/mwep/mike.c");
    ob3 = clone_object("/players/mythos/mmisc/fan.c");}
    if(z == 1) { ob->set_short("DJ Eddy Henry"); ob->set_alias("eddy"); 
    ob->set_long("\n");
    ob2 = clone_object("/players/mythos/mwep/mike.c");
    ob3 = clone_object("/players/mythos/mmisc/fan.c");}
    if(z == 2) { ob->set_short("DJ Paul Baynham"); ob->set_alias("paul"); 
    ob->set_long("\n");
    ob2 = clone_object("/players/mythos/mwep/mike.c");
    ob3 = clone_object("/players/mythos/mmisc/fan.c");}
    if(z == 3 || z == 4) { ob->set_short("DJ David '3D' Ward"); ob->set_alias("david"); 
    ob->set_long("\n");
    ob->set_ac(19);
    ob2 = clone_object("/players/mythos/mwep/voice.c");
    ob3 = clone_object("/players/mythos/marmor/jacket.c");}
    if(z == 5 || z == 6) { ob->set_short("DJ Captain Kirk"); ob->set_alias("kirk"); 
    ob->set_long("\n");
    ob->set_wc(45);
    ob2 = clone_object("/players/mythos/mwep/voice.c");
    ob3 = clone_object("/players/mythos/marmor/shirt.c");}
    if(z > 6) { ob->set_short("DJ John Robinson"); ob->set_alias("john"); 
    ob->set_long("\n");
    ob->set_wc(43);
    ob->set_mult(2);
    ob->set_mult_chance(30);
    ob->set_mult_dam1(40);
    ob->set_mult_dam2(40);
    ob2 = clone_object("/players/mythos/mwep/music.c");
    ob3 = clone_object("/players/mythos/marmor/rhythm.c");}
    move_object(ob,this_object());
    move_object(ob2,ob); 
    move_object(ob3,ob);
    command("wield dj_weapon",ob);}
  if(!arg) {
  set_light(1);
    short_desc = "<<Juliana's Tokyo- DJ Consol>> ";
    long_desc =
    HIR+"                          DJ CONSOL\n\n"+NORM+
        "You have entered the place where all the action takes place- where\n"+
        "the music is mixed and played, where the DJs move the crowds and make\n"+
        "the dance a DANCE!\n";
  items = ({
    "front","Head to the front of Juliana's- exit is that way",
    "bar","Go to the bar to chat and relax",
    "floor","Go in and DANCE",
  });

  dest_dir = ({
  "/players/mythos/mroom/juliana1.c","front",
  "/players/mythos/mroom/juliana4.c","bar",
  "/players/mythos/mroom/juliana3.c","floor",
  });
} }
