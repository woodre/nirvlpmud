#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!present("fungus")) {
    int a;
     a=0;
    while(a<5){
     int b;
     b = random(4);
if(b == 0) move_object(clone_object("/players/daranath/mons/fungi0.c"),this_object());
if(b == 1) move_object(clone_object("/players/daranath/mons/fungi1.c"),this_object());
if(b == 2) move_object(clone_object("/players/daranath/mons/fungi2.c"),this_object());
if(b == 3) move_object(clone_object("/players/daranath/mons/fungi3.c"),this_object());
     a++;
   }
}
move_object(clone_object("/players/daranath/mons/elven_slave.c"),this_object());
move_object(clone_object("/players/daranath/mons/fungi4.c"),this_object());
move_object(clone_object("/players/daranath/mons/fungi0.c"),this_object());
move_object(clone_object("/players/daranath/mons/fungi0.c"),this_object());

 if(!arg){

  set_light(1);
  short_desc="UnderDark Farm";
  long_desc=
   "The rows of fungus growing within the farm thin a bit here, with a dirt\n"+
   "path trailing off to the east. The green luminescent glow is strong in\n"+
   "the far corner of the cavern, surrounding you within its embrace. The\n"+
   "farm continues to the north and the west.\n";

items=({
 "ceiling", "The domed ceiling is made of natural rock and stone",
 "wall", "The walls consist of the same dark grey stone as the rest\n"+
         "of the surrounding areas within the UnderDark",
 "mushrooms", "Mushrooms of all sizes and colors dominate the growths\n"+
              "within the farm, most of them are lined up in rows. A few\n"+
              "are moving about the area, however",
 "chamber", "The large chamber is circular in nature, a naturally formed\n"+
            "cave within the rock",
 "cavern", "The large cavern is naturally formed here, and taken over for\n"+
           "the farm",
 "glow", "The luminescent glow within the chamber is fungal in nature",
 "farm", "The farm here within the UnderDark is kept up by elven slaves\n"+
         "The elves are not being watched over, and you cannot figure out\n"+
         "what is keeping them in line",
 "rows", "The rows of mushrooms are neatly tended and well kept",
 "darkness", "The darkness leaves you wondering what might be hidden in"+
             "every corner",
 "path", "The small path heads off to the east. It leads to a small hut",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/farm7.c","north",
 "/players/daranath/underdark/level1/farm9.c","east",
 "/players/daranath/underdark/level1/farm5.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing amongst the fungus farm.\n");
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
