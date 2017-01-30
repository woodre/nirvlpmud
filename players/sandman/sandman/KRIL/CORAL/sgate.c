inherit "room/room";

init() {
   ::init();
   add_action("read","read");
   add_action("north","north");
   add_action("pay","pay");
}

north() {
   if(present("captain")) {
     write("The watch captain blocks your way.\n");
     write("\nCaptain says: Hey!! Can't you read the sign barbarians??\n");
     return 1;
   }
}


read(str) {
   if(str == "sign") {
   cat("/players/sandman/KRIL/CORAL/sign1");
   return 1;
   }
}

pay(str) {
   if(str == "fee") {
      if(this_player()->query_money() < 50) {
         write("Watch Captian growls: Are you kidding, get out of here!\n");
         return 1;
      }
       write("Watch Captain takes 50 gold from you.\n");
       write("Watch Captain says: Ok go in, move it along!\n");
       write("\n\nYou quickly enter the Coral gates into the city.\n");
        this_player()->add_money(-50);
       this_player()->move_player("gate#players/sandman/KRIL/CORAL/square1");
       return 1;
   }
   write("Pay what?\n");
   return 1;
}

reset(arg) {
     if(!present("captain")) {
move_object(clone_object("players/sandman/KRIL/MON/w_capt"), this_object());
     }
   if(arg) return;
   set_light(1);
   short_desc=("south gate");
   long_desc=
      "Before you stand the fabled mithril gates of Coral City. The bustle\n"
+     "here is amazing as thousands of people come and go from the jewel of\n"
+     "the human empire. Coral the beautiful, Coral the rich, but also\n"
+     "coral the corrupt. Everything in coral is yours for a price, but then\n"
+     "nothing is ever free in Coral. Even admittance has a price.\n"
+     "A sign is posted to the side of the gate here.\n";
   items=
   ({
     "mithril gates","A gift from the Dwarves of Mt. Thraxx after the first\n"
+                    "goblin wars, the gates stand a towering 10 stories\n"
+                    "tall. What is even more amazing is they are totally\n"
+                    "constructed of priceless mithril. Atop the gates stand\n"
+                    "exquisitely life like statues of the dwaren god Thraxx\n"
+                    "and the human god Anura (patron diety of Coral). This\n"
+                    "symbolizes the strained yet ancient alliance of dwarf\n"
+                    "and human kind",
     "sign","It is a nice sign, perhaps you should 'read' it",
   });
   dest_dir=
   ({
     "players/sandman/KRIL/CORAL/square1","north",
     "players/sandman/KRIL/SURR/scoral","south",
   });
}
