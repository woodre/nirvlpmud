inherit "room/room";
object sign;
reset(arg){
  set_light(1);
short_desc="The arteria carotis interna";
long_desc="You are in the main artery, leading to Hippo's brains.\n"+
   "It's very dark in here, but you feel you are approaching\n"+
   "a very special place. You just have to continue your way\n"+
   "to the famous brains of the great Hippo.\n";
dest_dir=
({
"/players/hippo/quest_1/willosi.c","willosi",
"/players/hippo/rooms/aorta.c","aorta",
});
}
