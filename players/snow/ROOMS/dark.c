inherit "room/room";
 
reset(arg){
 
if(!present("smith"))  {
move_object(clone_object("/players/snow/closed/q/smith.c"),this_object());
    }
 
 if(!arg){
 
 set_light(0);
  short_desc="Darkness";
 long_desc=
    "You find yourself floating in some sort of dark matter.\n"+
    "It is very warm in here. Occasional sparks seem to fly from\n"+
    "the darkness around you. You hear loud banging, crashing\n"+
    "noises. Vague shadows seem to flow around you.\n";
 
items=({
  "sparks","As if metal were being forged and hammered, the sparks fly",
  "shadows","You blink a few times and see a giant form",
           });
 
  dest_dir=({
    "/players/snow/shadows/hilltop.c","fall"});
  }   }
 
query_realm() { return "NT"; }
