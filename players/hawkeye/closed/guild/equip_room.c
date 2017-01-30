inherit "room/room";
object ob,obj,ob1;
  string name;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Monk's Supply Room";
long_desc="This is the Supply room of the Monks Guild.  This room\n"+
  "is where fellow members can leave objects that might be found\n"+
  "handy by others.  This is the same room that is accesible by the\n"+
  "guild_equip abilties.  So, if you are carrying more than you need,\n"+
  "Drop some of it here to help out the less fortunate.\n"+
  "The Monk Welfare Machine is also here.  (if the welfare\n"+
  "is not here, type: machine, and it will appear.)\n";


dest_dir=({
   "players/hawkeye/closed/guild/advance", "south",
});

  if(!(present("welfare", this_object()))) {
  ob = clone_object("players/hawkeye/closed/monk/welfare.c");
      move_object(ob, this_object());
          }
   if(!(present("locker", this_object()))) {
  ob1 = clone_object("players/hawkeye/closed/guild/equip_locker");
     move_object(ob1, this_object());
             }
   }
}

init() {
 ::init();
   name = this_player()->query_real_name();
if(find_player(name) && !present("mrobe", this_player())) {
  move_object(this_player(), "players/hawkeye/closed/guild/join");
  tell_object(this_player(), "You are not a member!\n");
    }
add_action("machine", "machine");
        }

machine() {
  object ob;
 ob = present("welfare", this_object());
 if(!ob) {
 write("You take the Welfare Machine out of its secret compartment\n"+
       "and place it out where all the Monks can use it.\n");
     ob = clone_object("players/hawkeye/closed/monk/welfare");
     move_object(ob, this_object());
     return 1; }
  write("The Welfare Machine is already here!\n");
  return 1;
}
