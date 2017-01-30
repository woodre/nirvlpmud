inherit "room/room";
int i;
object term;
reset(arg) {
  monster();
  if(arg=="force" && !present("shadow",present("titan")))
    move_object(clone_object("/players/grimm/weapons/shadow"),present("titan"));
  if(arg) return;
  move_object(clone_object("players/grimm/weapons/shadow"),term);
  short_desc="Black Room";
long_desc="This is the home of a very upset looking individual.  The room\n"+
"is totally black.  The walls look as though they have been burned many\n"+
"times and are now covered in ash.\n";
  dest_dir=({"players/grimm/rooms/haphaz_k12d1","up"});
set_light(1);

}
monster() {
int count;

   if(!present("titan")) {
      term = clone_object("players/grimm/monster/exterm");
      move_object(term, this_object());
   }
}
