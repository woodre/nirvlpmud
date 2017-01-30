inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Main Hall of Tower";
long_desc="You are in the main hall of the Tower of Mages.  The walls of\n"+
 "this large room are actually a huge spiraling staircase that leads up\n"+
 "into the Tower.  The stairs wind up and up and up until you can't see\n"+
 "them anymore.  The Hall itself is an elaborate room decorated with\n"+
 "mystical artworks from all over the world.  Merchants gather here to\n"+
 "sell the many strange items the Mages need to cast their spells.\n"+
 "There is a small bakery to the North, a Shop to the West.\n";

dest_dir=({
 "/players/pavlik/guild/mages/room/tower.c", "leave",
 "/players/pavlik/guild/mages/room/bakery", "north",
 "/players/pavlik/guild/mages/room/lil_shop", "west",
 "/players/pavlik/guild/mages/room/stairs1", "up",
});

call_out("ran_messages", 10);
   }
}

ran_messages(){
 int x;
x = random(10);
if(x == 0){
tell_room(this_object(),
"A Mage-Apprentice bumps into and drops a huge pile of books on the ground\n"+
"The apprenctice glares at you coldy and starts picking up his books.\n");
   }
if(x == 1){
tell_room(this_object(),
"A vendor sells a jar of bat guano to a Wizard.\n");
   }
if(x == 2){
tell_room(this_object(),
"Several wizards stop at the gate to discuss something in a quiet voices.\n");
   }
if(x == 3){
tell_room(this_object(),
"A Vendor and a Mage haggle of the price of some herbs.\n");
   }
if(x == 4){
tell_room(this_object(),
"Somebody whispers to you: Pssst.  Hey Buddy.\n"+
"You turn around but there is nobody there.\n");
   }
if(x == 5){
tell_room(this_object(),
"A Mage-Instructor stomps out of the tower swearing profusely.\n"+
"You notice a large scorch mark in the seat of his robes.\n");
   }
if(x == 6){
tell_room(this_object(),
"You hear a young voice:\n"+
"'Hey!  What happens if I spit on somebody from all the way up here?'\n");
   }
if(x == 7){
tell_room(this_object(),
"A Mage hands a list of spell components to his Apprentice.\n"+
"The young mageling runs of to buy the necessary items.\n");
   }
if(x == 8){
tell_room(this_object(),
"A Merchant walks out of the Bakery.\n"+
"Burp!\n"+
"The Merchant pats his bulging belly and smiles.\n");
   }
if(x == 9){
tell_room(this_object(),
"A smiling merchant with a full purse enters the Bakery.\n");
   }
call_out("ran_messages", 25);
return 1;
}
