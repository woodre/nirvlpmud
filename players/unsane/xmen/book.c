inherit "obj/treasure";
reset(arg){
if(arg) return;
set_id("book");
set_short("A Book");
set_long("This is a tattered copy of Dante's Inferno.  You know, the greek story\n"+
"of the man's descent through Hell.  It sounds familiar at least.\n");
set_value(500);
set_weight(1);
set_read("This is pretty dull reading actually for someone who has lived the\n"+
"experience.  It does describe how to get past Plutus though.  But that\n"+
"part has been scratched out.\n");
}
