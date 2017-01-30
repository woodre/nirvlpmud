
string *alias_cmd, *real_cmd;

set_up_alias() {
   
   alias_cmd = ({ "n", "s", "e", "w", "ne", "nw", "se", "sw", "u", "d" });
   
   real_cmd = ({ "north", "south", "east", "west", "northeast",
                 "northwest", "southeast", "southwest", "up", "down" });
}


