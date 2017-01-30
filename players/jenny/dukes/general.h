int gen;
int rostrack;
int enostrack;
int cleetustrack;
object glee;
if(gen == random(4) &&!find_object("/players/jenny/dukes/items/general.c") && !present("roscotracker") && !present("enostracker") && !present("cleetustracker")) {
MOCO("/players/jenny/dukes/items/general.c"),this_object()); }

if(!present("bo duke") && !present("luke duke") && present("general lee"))  {
glee = present("general lee");
destruct(glee);
MOCO("/players/jenny/dukes/items/general.c"),this_object()); 
MOCO("/players/jenny/dukes/mobs/luke.c"),this_object()); 
MOCO("/players/jenny/dukes/mobs/bo.c"),this_object()); }

if(!present("bo duke") && present("luke duke") && present("general lee"))  {
MOCO("/players/jenny/dukes/mobs/bo.c"),this_object()); }

if(!present("luke duke") && present("bo duke") && present("general lee"))  {
MOCO("/players/jenny/dukes/mobs/luke.c"),this_object()); }

if(rostrack == random(4) && !find_object("/players/jenny/dukes/items/roscotracker.c") && !present("general lee") && !present("cleetustracker") && !present("enostracker")) {
MOCO("/players/jenny/dukes/items/roscotracker.c"),this_object()); }

if(!present("rosco p. coltrane") && present("roscotracker"))  {
MOCO("/players/jenny/dukes/mobs/rosco.c"),this_object()); }

if(enostrack == random(4) && !find_object("/players/jenny/dukes/items/enostracker.c") && !present("general lee") && !present("cleetustracker") && !present("roscotracker")) {
MOCO("/players/jenny/dukes/items/enostracker.c"),this_object()); }

if(!present("enos strate") && present("enostracker"))  {
MOCO("/players/jenny/dukes/mobs/enos.c"),this_object()); }

if(cleetustrack == random(4) && !find_object("/players/jenny/dukes/items/cleetustracker.c") && !present("general lee") && !present("roscotracker") && !present("enostracker")) {
MOCO("/players/jenny/dukes/items/cleetustracker.c"),this_object()); }

if(!present("cleetus hogg") && present("cleetustracker"))  {
MOCO("/players/jenny/dukes/mobs/cleetus.c"),this_object()); }
