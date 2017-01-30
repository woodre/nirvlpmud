inherit	"room/room";
object cab;

reset(arg) { 
  object china;
  if(!cab) {
       cab=clone_object("players/bastion/obj/cont");
       cab->set_name("cabinet");
       cab->set_alias("china cabinet");
       cab->set_short("china cabinet");
       cab->set_long("Through the crystal panes of the doors you see an\n"+
            "array of fine china.\n");
       cab->set_max_weight(1000);
       cab->set_can_open(1);
       move_object(cab, this_object()); }
  if(!present("china", cab)) {
       china=clone_object("obj/treasure");
       china->set_id("china");
       china->set_alias("fine alias");
       china->set_short("fine china");
       china->set_long("It is probably very valuable.\n");
       china->set_weight(2);
       china->set_value(1000);
       move_object(china, cab); }
  if(!arg) {
  set_light(1);
  short_desc = "Dining Room";
  long_desc = 
   "You have entered what appears to be a dining room. A long table\n"+
   "surrounded by cushioned mahogany chairs occupies the center of the\n"+
   "room. A china cabinet stands against the eastern wall, and against\n"+
   "the western, a serving table. A set of doors leads south, while\n"+
   "two other doors lead east and west respectively.\n";
  dest_dir = ({"players/bastion/isle/wiz/sitting", "east",
               "players/bastion/isle/wiz/e_hall1", "south",
               "players/bastion/isle/wiz/subhall", "west"});
  }
}
