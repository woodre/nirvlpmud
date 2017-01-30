new_sc(){
  USER->score();
  if(level < 20){
    write(
      " I ["+(USER->query_intoxination()*100)/(level+3)+"%] "+
      " F ["+(USER->query_stuffed()*100)/(level*8)+"%] "+
      " S ["+(USER->query_soaked()*100)/(level*8)+"%]\n"); 
    if(USER->query_fight_area())
      write(" Fight Zone: "+HIR+"PK Area"+NORM+"   ");
    else write(" Fight Zone: "+BOLD+"NON-PK Area"+NORM+"  ");
    if(environment(USER)->realm() == "NT")
      write(" Room Port: "+BOLD+"Non-Port"+NORM+"\n");
    else write(" Room Port: "+BOLD+"Port"+NORM+"\n");
    return 1;
  }
  return 1;
}
