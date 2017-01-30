inherit"/room/room";
int i;

reset(arg) {
  short_desc = "Temple of Lloth";
  long_desc = "Temple dedicated to the goddess Lloth. The temple is massive in size. It has\n"+
              "been carved with great drow skill.  To the west is a statue of a exquisitely\n"+
              "beautiful female drow standing in a pile of spiders.  It is some 20 feet tall\n"+
              "and lit by colored faerie fire.\n";
  dest_dir=({"players/mouzar/castle/under/temple7","north",
	     "players/mouzar/castle/under/temple9","south",
	     "players/mouzar/castle/under/temple5","west",
	     "players/mouzar/castle/under/under21","east",
	     "players/mouzar/castle/under/temple4","northwest",
	     "players/mouzar/castle/under/temple6","southwest",});
  items=({ "statue","To the west you see a 20 feet tall statue of a exquisitely beatiful female drow\n"+
                    "wear what seems to be clothing of clinging spiders.  The female has a beatifully\n"+
                    "twisted smile that sends shivers down your spine.",});
  monster();
  set_light(1);
} 

monster() {
  int count, who;
  object monster;
  count = random (2);
  if(!present("pristess") || !present("mother") || !present("student")) {
    for(i = 0; i < count+1; i++){
     switch(random(4)){
      case 0:
        move_object(clone_object("/players/mouzar/castle/under/mon/drlmother"), this_object());
        break;
      case 1:
	move_object(clone_object("/players/mouzar/castle/under/mon/drstudent"), this_object());
        break;
      case 2:
	move_object(clone_object("/players/mouzar/castle/under/mon/drpriestess"), this_object());
        break;
      case 3:
        move_object(clone_object("/players/mouzar/castle/under/mon/drhpriestess"), this_object());
        break;
      case 4:
        break;
    }
   }
}
}
