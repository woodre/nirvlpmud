inherit "room/room";
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "Bridge";
long_desc = "    You have finally found the nerve center of the SDF-1! Like\n"+
            "the barrier room, you see some incredible machines and c\n"+
            "consoles.  This is where the battle of brains and strategies\n"+
            "occurred..You could imagine shouting orders across this once\n"+
            "busy bridge.  Now you only see some panels and machines that a\n"+
            "are heavily damaged and the corpses of some personnel who were\n"+
            "damaged along with it...\n\n";
dest_dir = ({"players/cyrex/barrier", "west",
 "players/cyrex/cgprivate", "south",
 "players/cyrex/cargobay", "east",
});
}
