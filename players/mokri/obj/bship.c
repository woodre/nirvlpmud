#include "/players/mokri/define.h"
inherit "/obj/treasure.c";

string *shots, *ships;
object owner;

reset(int arg) {
   if(arg) return;
   set_id("board");
   set_name("battleship");
   set_alias("board");
   set_weight(1);
   set_value(100);
   set_short("A Battleship Board");
   set_long("\nTry to shoot all of the ships in 24 shots or less!\n" +
      "There are 3 ships: A Big ship (4 tiles long), a Medium\n"+
      "ship (3 tiles long), and a Small ship (2 tiles long).\n\n"+
      "Commands\n"+
      "======================================================\n"+
      "shoot letternumber Take a shot at tile letternumber.\n"+
      "                   Example: shoot a4\n"+
      "bshipstart         Begin a new game.\n"+
      "bshipshow          Display the current status of the board.\n"+
      "bshipstop          Quit the current game.\n"+
      "bshipwinners       Display of the last people to win the game.\n\n");
}

int checkShip(int x) {

   if(x == 4) {
      if(member(shots,ships[0]) > -1 && member(shots,ships[1]) > -1 && member(shots,ships[2]) > -1 && member(shots,ships[3]) > -1)
         return 0;
      else
         return 1;
   }

   if(x == 3) {
      if(member(shots,ships[4]) > -1 && member(shots,ships[5]) > -1 && member(shots,ships[6]) > -1)
         return 0;
      else
         return 1;
   }

   if(x == 2) {
      if(member(shots,ships[7]) > -1 && member(shots,ships[8]) > -1)
         return 0;
      else
         return 1;
   }

   return -1;

}

showBoard() {
   int x,y,check4,check3,check2,shipPosition;

   if(!owner || owner != this_player() || !ships || !sizeof(ships)) {
      write("Please 'bshipstart' first.\n");
      return 1;
   }

   for(x = 1; x < 10; x++) {
      write("  =================================================\n");
      if(x < 9)
         write(x + " ");
      else
         write("     A     B     C     D     E     F     G     H\n");
      for(y = 1; y < 10; y++) {
         shipPosition = member(ships,x+"^"+y);
         if(x < 9) {
            if(member(shots,x+"^"+y) != -1) {
               if(shipPosition != -1)
                  write("| " + RED + "HIT" + NORM + " ");
               else
                  write("|  X  ");
            }
            else {
               if(sizeof(shots) < 24 || shipPosition == -1)
                  write("|     ");
               if(sizeof(shots) == 24 && shipPosition != -1) {
                  if(shipPosition >= 0 && shipPosition <= 3)
                     write("|  " + GRN + "B" + NORM + "  ");
                  if(shipPosition >= 4 && shipPosition <= 6)
                     write("|  " + GRN + "M" + NORM + "  ");
                  if(shipPosition >= 7)
                     write("|  " + GRN + "S" + NORM + "  ");
               }
            }
          }
       }
      write("\n");
   }

   check4 = checkShip(4);
   check3 = checkShip(3);
   check2 = checkShip(2);

   write("Big Ship:        ");
   if(check4 == 0)
      write(RED+"DEAD\n"+NORM);
   else
      write(GRN+"ALIVE\n"+NORM);

   write("Medium Ship:     ");
   if(check3 == 0)
      write(RED+"DEAD\n"+NORM);
   else
      write(GRN+"ALIVE\n"+NORM);

   write("Small Ship:      ");
   if(check2 == 0)
      write(RED+"DEAD\n"+NORM);
   else
      write(GRN+"ALIVE\n"+NORM);

   write("Shots Remaining: " + (24 - sizeof(shots)) + "\n");

   if(check4 == 0 && check3 == 0 && check2 == 0) {
      write("You win! Yay!\n");
      write_file("/open/mokri/games/bshipwinners",CAP(this_player()->query_real_name()) + "\t\t" + ctime() + "\t" + sizeof(shots) + " shots\n");
      bshipstop();
      return;
   }

   if(sizeof(shots) == 24) {
      write("You are out of shots.\nYou lose!\n");
      bshipstop();
      return;
   }

   return;

}

setPiece(int length) {
   int coord1, coord2, coord1Modifier, coord2Modifier, x;
   string spaceTmp, *shipsOriginal;

   shipsOriginal = ships;

   coord1 = random(8) + 1;
   coord2 = random(8) + 1;

   if(!random(2)) {
      coord1Modifier = 1;
      coord2Modifier = 0;
   } else {
      coord1Modifier = 0;
      coord2Modifier = 1;
   }

   if(random(2)) {
      coord1Modifier *= -1;
      coord2Modifier *= -1;
   }

   if(coord1Modifier != 0 && coord1 < length)
      coord1Modifier = 1;

   if(coord1Modifier != 0 && coord1 + length > 9)
      coord1Modifier = -1;

   if(coord2Modifier != 0 && coord2 < length)
      coord2Modifier = 1;

   if(coord2Modifier != 0 && coord2 + length > 9)
      coord2Modifier = -1;

   for(x = 0; x < length; x++) {
      spaceTmp = coord2 + "^" + coord1;
      if(member(ships,spaceTmp) != -1) {
         ships = shipsOriginal;
         setPiece(length);
         return;
       }

      ships += spaceTmp;
      coord1 += coord1Modifier;
      coord2 += coord2Modifier;
   }

}

setBoard() {

   owner = this_player();

   shots = ({ });
   ships = ({ });

   setPiece(4);
   setPiece(3);
   setPiece(2);

   showBoard();

}

shoot(string str) {
   string coord1,coord2;

   if(!owner || owner != this_player() || !ships || !sizeof(ships)) {
      write("Please 'bshipstart' first.\n");
      return 1;
   }

   if(!str || strlen(str) != 2) {
      write("Please enter your shot in the form LETTERNUMBER.\nExample: shoot A5\n");
      return 1;
   }

   coord1 = extract(str,0,0);
   coord2 = extract(str,1,1);

   coord1 = CAP(coord1);

   if(coord1 != "A" && coord1 != "B" && coord1 != "C" && coord1 != "D" && coord1 != "E" && coord1 != "F" && coord1 != "G" && coord1 != "H") {
      write("The first coordindate must be a letter between A and G.\n");
      return 1;
   }

   if(coord2 != "1" && coord2 != "2" && coord2 != "3" && coord2 != "4" && coord2 != "5" && coord2 != "6" && coord2 != "7" && coord2 != "8") {
      write("The second coordinate must be a number between 1 and 8.\n");
      return 1;
   }

   if(coord1 == "A") coord1 = "1";
   if(coord1 == "B") coord1 = "2";
   if(coord1 == "C") coord1 = "3";
   if(coord1 == "D") coord1 = "4";
   if(coord1 == "E") coord1 = "5";
   if(coord1 == "F") coord1 = "6";
   if(coord1 == "G") coord1 = "7";
   if(coord1 == "H") coord1 = "8";

   if(member(shots,coord2 + "^" + coord1) != -1) {
      write("You have already fired a shot at that coordinate.\n");
      return 1;
   }

   shots += coord2 + "^" + coord1;
   showBoard();
   return 1;

}

int bshipstop() {
   write("You are done playing.\nType 'bshipstart' to play again!\n");
   ships = ({ });
   shots = ({ });
   owner = this_object();
   return 1;
}

int bshipshow() {

   if(!owner || owner != this_player() || !ships || !sizeof(ships)) {
      write("Please 'bshipstart' first.\n");
      return 1;
   }

   showBoard();
   return 1;
}

int bshipstart() {
   setBoard();
   return 1;
}

int bshipwinners() {

  tail("/open/mokri/games/bshipwinners");
  return 1;
}

init() {
   ::init();

   add_action("shoot","shoot");
   add_action("bshipstop","bshipstop");
   add_action("bshipshow","bshipshow");
   add_action("bshipstart","bshipstart");
   add_action("bshipwinners","bshipwinners");

}
