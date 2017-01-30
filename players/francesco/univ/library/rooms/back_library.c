/*  ->> more /open/maledicta/entrance.c  */


#include "/players/francesco/univ//ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

string *entered1;
string *entered2;
string *entered3;
string *entered4;
string *entered5;
string *entered6;
string *entered7;
string *entered8;
string *entered9;
string *entered10;
string *entered11;
string *entered12;
string *entered13;
string *entered14;
string *entered15;
string *entered16;
string *entered17;
string *entered18;
string *entered19;
string *entered20;
string *entered21;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Within the shelves";
long_desc =
"  This is inner part of the library of the Department of Mechanical\n"+
"Engineering.  In front of you there are long lines of shelves which\n"+
"can supposedly hold thousands of books.  A simpler shelf supports\n"+
"a touch screen computer.  Next to this shelf there is a card catalog\n"+
"which can be opened in order to search for information.  These two \n"+
"items are helpful for making an effective search about the books which\n"+
"are in the library.  Known the book or the subject to search for, it\n"+
"is possible to wander around the shelves.  A doorway will head you\n"+
"back towards the librarian desk.\n";

entered1 = ({ });
entered2 = ({ });
entered3 = ({ });
entered4 = ({ });
entered5 = ({ });
entered6 = ({ });
entered7 = ({ });
entered8 = ({ });
entered9 = ({ });
entered10 = ({ });
entered11 = ({ });
entered12 = ({ });
entered13 = ({ });
entered14 = ({ });
entered15 = ({ });
entered16 = ({ });
entered17 = ({ });
entered18 = ({ });
entered19 = ({ });
entered20 = ({ });
entered21 = ({ });



items = ({
  "shelves",
  "About 7 feet tall, made by strong metal frame",
  "shelf",
  "A vertical computer holder",
  "books",
  "Oh my!  How many might they be?",
  "doorway",
  "A revolving door made by transarent glass",
  "computer",
  "It has no keyboard, only the screen is accessible and the mouse usable",
  "catalog",
  "It has sliding drawers, each classified by subject",
  });

dest_dir = ({
  "/players/francesco/univ/library/rooms/front_library.c","back",
});

}

  init(){
  ::init();
  add_action("touch_puter", "touch");
  add_action("click_box","click");	
  add_action("slide_drawer", "slide");
  add_action("read_subjects","read");
  add_action("wander_around","wander");
}

touch_puter(str){
  if(!str) { write("Touch what?\n"); return 1;}
   if(str=="screen") {
   write("You touch the screen of the computer and a dialog box appears.\n"+
         "You might want to click it with the mouse.\n"); 
   return 1;}
  write("What do you want to touch?\n"); 
  return 1;
}

click_box(str){
  if(!str){ write("Click what?\n"); return 1; }
   if(str == "box"){
   write("You click on the dialog box......\n"+
         "The screen changes.......\n"+
         "A list appears that you can read.......\n");               
  return 1;
  }
   write("You cant click it!\n");
return 1;
}

slide_drawer(str){
  if(!str) { write("Slide what?\n"); return 1;}
   if(str=="drawer") {
   write("You slide the first drawer of the catalog........\n"+
         "A long list of subjects appears......\n"+
         "You might want to read it.......\n"); 
   return 1;}
  write("What do you want to slide???\n"); 
  return 1;
}
read_subjects(str){
  if(!str){ write("Read what?\n"); return 1; }
   if(str == "list"){
   write("\n    You read the list.......You see also the map of the library....\n"+
         "       It is organized in three rows each made by seven shelves.\n\n"+
"   Basic Sciences       Basic Engineering        Mechanical Engineering\n\n"+
"   Calculus             Mechanics of Materials   Manufacturing\n"+
"   Geometry             Thermodynamics           Applied Mechanics\n"+
"   Physics              Fluid Dynamics           Engines\n"+
"   Drawing              Operations Research      Machines\n"+
"   Chemistry            Corrosion                Design of Machines\n"+
"   Computer Science     Electrotechnics          Robotics\n"+
"   Management           Metallurgy               Productions Systems\n\n");               
  return 1;
  }
   write("You cant read it!\n");
return 1;
}

wander_around(str){
 int i;

 if(!str) { write("Wander where??\n"); return 1;}

 if(str=="calculus") {
   for(i=0; i < sizeof(entered1); i++){
   if(entered1[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}
   entered1 += ({ this_player()->query_real_name() });
   write("You go wandering through the Calculus books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/calculus.c");
   return 1;}
 if(str=="geometry") {
   for(i=0; i < sizeof(entered2); i++){
   if(entered2[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered2 += ({ this_player()->query_real_name() });
   write("You go wandering through the Geometry books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/geometry.c");
   return 1;}
 if(str=="physics") {
   for(i=0; i < sizeof(entered3); i++){
   if(entered3[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered3 += ({ this_player()->query_real_name() });
   write("You go wandering through the Physics books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/physics.c");
   return 1;}
 if(str=="drawing") {
   for(i=0; i < sizeof(entered4); i++){
   if(entered4[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered4 += ({ this_player()->query_real_name() });
   write("You go wandering through the Drawing books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/drawing.c");
   return 1;}
 if(str=="computer science") {
   for(i=0; i < sizeof(entered5); i++){
   if(entered5[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered5 += ({ this_player()->query_real_name() });
   write("You go wandering through the Computer Science books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/computer_science.c");
   return 1;}
 if(str=="chemistry") {
   for(i=0; i < sizeof(entered6); i++){
   if(entered6[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered6 += ({ this_player()->query_real_name() });
   write("You go wandering through the Chemistry books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/chemistry.c");
   return 1;}
 if(str=="management") {
   for(i=0; i < sizeof(entered7); i++){
   if(entered7[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered7 += ({ this_player()->query_real_name() });
   write("You go wandering through the Management books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/management.c");
   return 1;}
 if(str=="mechanics of materials") {
   for(i=0; i < sizeof(entered8); i++){
   if(entered8[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered8 += ({ this_player()->query_real_name() });
   write("You go wandering through the Mechanics of  Materials books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/mechanics_of_materials.c");
   return 1;}
 if(str=="thermodynamics") {
   for(i=0; i < sizeof(entered9); i++){
   if(entered9[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered9 += ({ this_player()->query_real_name() });
   write("You go wandering through the Thermodynamics books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/thermodynamics.c");
   return 1;}
 if(str=="fluid dynamics") {
   for(i=0; i < sizeof(entered10); i++){
   if(entered10[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered10 += ({ this_player()->query_real_name() });
   write("You go wandering through the Fluid Mechanics books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/fluid_dynamics.c");
   return 1;}
 if(str=="operations research") {
   for(i=0; i < sizeof(entered11); i++){
   if(entered11[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered11 += ({ this_player()->query_real_name() });
   write("You go wandering through the Operations Research books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/operations_research.c");
   return 1;}
 if(str=="corrosion") {
   for(i=0; i < sizeof(entered12); i++){
   if(entered12[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered12 += ({ this_player()->query_real_name() });
   write("You go wandering through the Corrosion books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/corrosion.c");
   return 1;}
 if(str=="electrotechnics") {
   for(i=0; i < sizeof(entered13); i++){
   if(entered13[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered13 += ({ this_player()->query_real_name() });
   write("You go wandering through the Electrotechnics books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/electrotechnics.c");
   return 1;}
 if(str=="metallurgy") {
   for(i=0; i < sizeof(entered14); i++){
   if(entered14[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered14 += ({ this_player()->query_real_name() });
   write("You go wandering through the Metallurgy books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/metallurgy.c");
   return 1;}
 if(str=="manufacturing") {
   for(i=0; i < sizeof(entered15); i++){
   if(entered15[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered15 += ({ this_player()->query_real_name() });
   write("You go wandering through the Manufacturing books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/manufacturing.c");
   return 1;}
 if(str=="applied mechanics") {
   for(i=0; i < sizeof(entered16); i++){
   if(entered16[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered16 += ({ this_player()->query_real_name() });
   write("You go wandering through the Applied Mechanics books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/applied_mechanics.c");
   return 1;}
 if(str=="engines") {
   for(i=0; i < sizeof(entered17); i++){
   if(entered17[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered17 += ({ this_player()->query_real_name() });
   write("You go wandering through the Engines books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/engines.c");
   return 1;}
 if(str=="machines") {
   for(i=0; i < sizeof(entered18); i++){
   if(entered18[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered18 += ({ this_player()->query_real_name() });
   write("You go wandering through the Machines books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/machines.c");
   return 1;}
 if(str=="design of machines") {
   for(i=0; i < sizeof(entered19); i++){
   if(entered19[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered19 += ({ this_player()->query_real_name() });
   write("You go wandering through the Design of Machines books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/design_of_machines.c");
   return 1;}
 if(str=="robotics") {
   for(i=0; i < sizeof(entered20); i++){
   if(entered20[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered20 += ({ this_player()->query_real_name() });
   write("You go wandering through the Robotics books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/robotics.c");
   return 1;} 
 if(str=="production systems") {
   for(i=0; i < sizeof(entered21); i++){
   if(entered21[i] == this_player()->query_real_name()){
   write("You have already done this subject.\n");
   return 1;}}   
   entered21 += ({ this_player()->query_real_name() });
   write("You go wandering through the Production Systems books.\n\n");
   tp->move_player("blah#players/francesco/univ/library/rooms/production_systems.c");
   return 1;}
 write("It is not possible to wander there.\n"); 
  return 1;
}

 realm(){ return "NT"; }
 
