inherit "room/room";

reset(arg){

if(!present("Morgenes")) {
   move_object(clone_object("/players/dune/closed/castle/monsters/doctor.c"),
   this_object());}

 if(!arg){
 set_light(1);
 short_desc="Doctor Morgenes' Chambers";
 long_desc=
"\n"+
"\n"+
"\n"+
"  __%$#______*______           ___<>_=__!__\n"+
"   |              |             |        | \n"+
"   |              |   ,,,,,     |     _  | \n"+
"   |          @   |   ;>:);     |    ||  | \n"+
"----------------------`````-------------------\n"+
"     The hallway leads to a large narrow room.\n"+
"Cages of strange creatures, wooden boxes, scrolls,\n"+
"and hundreds of other unexplainable items lie lazily\n"+
"sorted upon the floors and the many wooden tables.\n";

items=({
 "cages", "The cages are full of small creatures",
 "creatures","The creatures are ones you've never seen before",
 "boxes","Boxes with strange runes lie upon the ground",
 "scrolls","Several scrolls lie upon the tables",
 "tables","The tables are sturdy yet very unattractive",
 "floors","The floors are cluttered with junk",
 });

  dest_dir=({
 "/players/dune/room/floor3.c","hallway",
      });
  }   }

realm() { return "NT"; }
