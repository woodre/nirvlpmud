#include "/players/fred/mages/defs.h"

cmd_risk(str){
 int x, z, v;
 object ob;
 string what;
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}  
   if(USER->query_sp() < 5) {
     write("You don't have enough energy.\n"); return 1;}   
   if(INT < 20) {
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}   
   if(RANK < 1){
     write("You have not mastered this art yet.\n"); return 1; }
   if(!str){
     write("What would you like to assess?\n"); return 1;}
   ob = present(str, ENV(TP));
   if(!ob){
     write(capitalize(str)+" is not here.\n"); return 1; }
   x = ob->query_wc();   
   z = ob->query_ac();
   v = ob->calculate_worth();
   write("     Some helpful facts about "+BOLD+YEL+capitalize(str)+NORM+" are:\n\n");
   if(x > 50){
    write("        Is armed with power of a GOD FOOL!!\n"); }
   else if(x > 40){
    write("        Is armed with the power of a lesser god!\n"); }
   else if(x > 24){
    write("        Is armed with the power of a demi-god!\n"); }
   else if(x > 19){
    write("        Is armed with a mighty weapon!\n"); }
   else if(x > 15){
    write("        Is armed with an excellent weapon!\n"); }
   else if(x > 11){
    write("        Is armed with a good weapon.\n"); }
   else if(x > 5){
    write("        Isn't well-armed.\n"); }
   else{
    write("        Probably isn't armed at all.\n"); }
  if(z > 35){
    write("        Is a friggin' tank!!\n"); }
  else if(z > 30){
    write("        Is almost impenatrable!\n"); }
  else if(z > 20){
    write("        Is heavily armored.\n"); }
  else if(z > 15){
    write("        Is well armored.\n"); }
  else if(z > 10){
    write("        Is only slightly armored.\n"); }
  else if(z > 5){
    write("        Is poorly armored.\n"); }
  else{
    write("        Is almost naked....\n"); }
  if(v > 200000){
    write("        HOLY EXPERIENCE BATMAN!!\n"); }
  else if(v > 150000){
    write("        WOO Wee that's a nice chunk of experience right there!\n"); }
  else if(v > 100000){
    write("        Well worth killing, this thing oozes experience!\n"); }
  else if(v > 75000){
    write("        Not the biggest kill but nothing to scoff at either.\n"); }
  else if(v > 50000){
    write("        Is worth a good amount of experience.\n"); }
  else if(v > 20000){
    write("        Is worth a fair amount of experience.\n"); }
  else if(v > 10000){
    write("        Is worth a smidge above average experience.\n"); }
  else if(v > 5000){
    write("        Is about average experience.\n"); }
  else if(v > 2000){
    write("        Is below average experience but might be good for lower levels.\n"); }
  else if(v > 500){
    write("        Worth little to nothing but if you're a noob go crazy.\n"); }
  else{
    write("        Why don't you just hunt down Harry ya loser!!\n"); }
   USER->add_spell_point(-5);
   return 1;
}
