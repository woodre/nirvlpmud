inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"
#include DEFS_OFFICES

string officeName;


init() {
add_action("mme","toy");
::init();
}

reset(arg)
{
  officeName = capitalize(DIAMOND);

  if(!present("terminal"))
  {
    move_object(clone_object(
    BOARDDIR + "/councilboard.c"),
    this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc=officeName+" Chambers";
    long_desc=
"     The "+FUNKYNAME+" "+officeName+" Chambers is a circular room\n"+
"with walls and ceiling made completely of transparent crystal.\n"+
"This crystal dome houses a large low-standing circular table.\n"+
"Surrounding this table rest several mats, one for each Council\n"+
"Member.\n"; 

dest_dir=({
"/players/dune/closed/guild/rooms/hallway1.c","surface",
});
    items=({
"mats","The mats are square pillows",
"crystal","The crystal is completely transparent",
"table","The table is a gathering place for Council discussions",
});
}
}

mme(str) {
if(str == "me") {
if (call_other(OFFICED, "checkStone", TP, "diamond"))
if(!present("puptoy",this_object()));;
tell_object(find_player("puppy"), this_player()->query_name()+" grabs a toy from the Cyber guild!\n");
move_object(clone_object("/players/puppy/closed/toy.c"),this_player());
{
write("The CyberDaemon hands you a special toy from Puppy.\n");
return 1;

}
}
}
