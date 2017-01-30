int prayrandom;

pray(arg){
 if(arg=="to gaea"){
/* put in code to take away max sp and max hp */
  if(glvl>20){
   if(change>0){
    write("allready changed!\n");
   return 1;}
   glvl=glvl+3;
   prayrandom=random(3);
   if(prayrandom==2){
    write("Change to to wolf-high\n");
    change=600;
    /* do high wolf ac/wc changes */
   return 1;}
   if(prayrandom==1){
    write("Change to to wolf-med\n");
    change=900;
    /* do med wolf ac/wc changes */
   return 1;}
   if(prayrandom==0){
    write("Change to to wolf-low\n");
    change=600;
    /* do low wolf ac/wc changes */
   return 1;}
  return 1;}
  glvl=glvl+1;
  write("You pray\n");
 return 1;}
return 0;}