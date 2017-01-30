inherit "room/room";

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "Elvis' Storeroom";
   long_desc = "This is where elvis keeps his things.  Be gone.\n";

   dest_dir =  ({
      "players/blue/stores/nov_shop","west"
      });

   if(!(present("heal",this_object()))) {
      object heal;
      heal=clone_object("obj/heal");
      move_object(heal, this_object());
      }
/*
   if(!(present("hole", this_object()))) {
      object hole;
      hole=clone_object("players/blue/closed/lilhole");
      move_object(hole, this_object());
      }
*/
   }
}
