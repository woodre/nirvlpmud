main(){

   object victim;
   string tmpaln;
   int hurt;
   hurt = set_light(0);
   if( hurt > 0 && hurt < 2){
   hurt = 1; }
  if( hurt > 1 && hurt < 3){
   hurt = 2; } 
if( hurt > 2 && hurt < 4){
   hurt = 4; }   
 if( hurt > 3 && hurt < 5){
   hurt = 4; }  
 if( hurt > 4 && hurt < 6){
   hurt = 5; }  
if( hurt > -1 && hurt < 1){
   hurt = 0; }   
 if( hurt > -2 && hurt < 0){
   hurt = -1; }  
 if( hurt > -3 && hurt < -1){
   hurt = -2; } 
 if( hurt > -4 && hurt < -2){
   hurt = -3; } 
 if( hurt > -5 && hurt < -3){
   hurt = -4; } 
 if( hurt > -6 && hurt < -4){
   hurt = -5; }    
/*
      write("The light is "+hurt+" <--\n");
*/
write("The light level in here is "+(int)this_player()->query_current_light()); write("\n");
      return 1;
}       
