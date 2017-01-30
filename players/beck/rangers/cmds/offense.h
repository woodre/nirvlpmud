show_offense(str,me,who){
if(str == "chop"){ return me+" gives "+capitalize(who)+" a chop to the head."; }
if(str == "butterfly"){ return me+" does an artistic butterfly kick to "+capitalize(who)+"."; }
if(str == "slap"){ return me+" slaps "+capitalize(who)+" in the face."; }
if(str == "scratch"){ return me+" scratches "+capitalize(who)+"'s face with your nails."; }
if(str == "throw"){ return me+" grabs "+capitalize(who)+" and throws them to the floor."; }
if(str == "laugh"){ return me+" laughs in "+capitalize(who)+"'s face...as cocky as "+me+" is."; }
if(str == "death"){ return me+" reaches out with one finger, and lightly deliver the DEATH TOUCH to "+capitalize(who)+"!"; }
if(str == "elbow"){ return me+" turns and bashes "+capitalize(who)+" with the side of the elbow."; }
if(str == "press"){ return me+" raises "+capitalize(who)+" up in a gorilla press, and drops them to the ground."; }
if(str == "axe"){ return me+" raises their foot and crashes it down on the shoulder of "+capitalize(who)+".";}
if(str == "punch"){ return me+ " gives "+capitalize(who)+" a solid punch to the chest.";}
return "Your offense fails...notify Beck by mail.";
}
identify_offense(){
   COMM->see_offense();
   return 1;
}
