xp_bonus(){
  switch(XP) {
  case 13000000..9999999999:
  bxp = 12;
  break;
  case 9000000..12999999:
  bxp = 10;	
  break;
  case 6500000..8999999:
  bxp = 8;
  break;
  case 5000000..6499999:
  bxp = 6;
  break;
  case 3500000..4999999:
  bxp = 4;
  break;
  default:
  bxp = 0;
  break;
  }
}	

ignite_blade(string str){

  if(!str) { 
    write("ignite what?\n"); 
    return 1; 
  }
  if(!wep_life) { 
    write("It is out of power.\n");
    return 1; 
  }
  if(ignited) {
    if( !JEDI || JEDI->query_saber_type() != 1 ) {  
    write("It is already ignited!\n");
    return 1; 
    }
    if( ignited < 2 ) {
      ignited = 2;
      write("You ignite the second blade of your Lightsaber.\n");
      return 1;
    }
  }
if(str == "lightsaber" ||
   str == "saber"){
  if(JEDI) {
    if(Rank > 7 && SKILL > 9) {
      set_class(17);
    }
    else if(Rank > 5 && SKILL > 5) {
      set_class(14);
    }
   else set_class(12);
  }
  else set_class(10);
  ignited = 1;
  if(!wielded) wield(str);
if(!JEDI){
tell_room(environment(USER),
""+USER->query_name()+" fumbles with the lightsaber and finally gets it to ignite.\n"); }	
else{
tell_room(environment(USER),
""+USER->query_name()+""+
" ignites "+USER->query_possessive()+" lightsaber with a...\n\n"+
""+wep_color+"           -   -  --  --- ----  ------- SNAP HISS -------  ---- ---  --  -   -"+NORM+"\n\n\n");
set_message_hit(({
  wep_color+"massacre"+NORM," to small fragments",
  wep_color+"smashed"+NORM," with a bone crushing sound",
  wep_color+"mauled"+NORM,"",
  wep_color+"hit"+NORM," very hard",
  wep_color+"hit"+NORM," hard",
  "hit","",
  "grazed"," with a glancing blow"}));
  set_light(1);
   return 1;
   }
  }
return 0;
}
