
   from hookers isn't necessarily enough to satisfy every potential client.
*/

inherit "std/space/defense";

int hullpts;                        /* our most important stat */
string owner_name;                  /* name of owning player */
string owner_corp_name;             /* name of owning corporation */
string ship_type;                   /* Death Star? Galaxy class starship?
int ship_level;                     /* Used to see if players of arbitrary
                                       levels can purchase one of these...
                                       I'm sure there are other uses. */
string ship_size;   /* Used in manouverability and
                                       other things.  Values are in
                                       tons.
                                    */
int fuel, max_fuel;                 /* internal fuel tanks for weapons etc */
int marines, max_marines;           /* how many marines our ship contains */


static object curfueltank,/* internal or external fuel? */
   bridge,/* the bridge */
   weapbay,/* weapons bay */
   locker,/* stowage locker */
   airlock,/* airlock */
   devbay,/* miscellaneous devices kept here */
   dockbay,/* docking bay (large and larger) */
   trans,/* transporter room */
   cargo,/* cargo bay */
   engine,/* engine bay */
   *fuel_tanks;/* Our external fuel tanks */

object *on_board;   /* the players on board us */

create(){


query_hullpts(){ return hullpts; }
add_hullpts(i){ hullpts += i; }

query_owner_name(){ return owner_name; }
set_owner_name(s){ owner_name = s; }

query_ship_type(){ return ship_type; }
set_ship_type(s){ ship_type = s; }

query_ship_level(){ return ship_level; }
set_ship_level(s){ ship_level = s; }

query_curfueltank(){ return curfueltank; }
set_curfueltank(o){ if(objectp(o)) curfueltank = o; }

query_fuel(){
  if(curfueltank == this_object()) return fuel;
  else return curfueltank->query_fuel() + fuel;
}
add_fuel(i){
        if(curfueltank != this_object()){
           curfueltank->add_fuel(i);
        }
        if(i > query_max_fuel()){
           i = query_max_fuel() - query_fuel();
        }
        fuel += i;
        return i;
}

query_max_fuel(){ return max_fuel; }
set_max_fuel(i){ max_fuel = i; }

query_marines(){ return marines; }
add_marines(i){ marines += i; }

query_max_marines(){ return max_marines; }
set_max_marines(i){ max_marines = i; }

query_fighters(){ return fighters; }
add_fighters(i){ fighters += i; }

query_max_fighters(){ return max_fighters; }
set_max_fighters(i){ max_fighters = i; }

device_present(mixed what){
   string *devnames;
   int i;
   if(stringp(what)){
          /* we got a string */
          string trash, garbage;
          devnames = keys(devices);
      if(sscanf(what, "%s/%s", trash, garbage)){
          /* someone gave us a file name to compare.  ok. */
                for(i=0; i < sizeof(devnames); i++){
                        if(filename(devices[devnames[i]]) == what){
                           return devices[devnames[i]];
                        }
                 }
                 return 0;
          }
          else {
                /* we got an id to compare */
                for(i=0; i < sizeof(devnames); i++){
                   if(filename(devices[devnames[i]]) == what){
                          return devices[devnames[i]];
                   }
                }
                return 0;
         }
         else if(objectp(what)){

}

   the on_board list for what and return true or false.
*/

query_on_board(string what){
   if(!what) return on_board;
   else if(member_array(what, on_board) == -1) return 0;
   return 1;
}


