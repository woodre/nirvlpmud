set_power(str){
int plvl;

  plvl = TPGO->query_plevel();
  if(!str){
    write("You have the following power levels available:\n\n"+
      "\t  low\n"+"\t  medium\n"+"\t  high\n");
    if(extralevel > 4)
      write("\t  "+QMI("color")+"OVERLOAD"+NORM+"\n");
    write("set_power <type> to change the setting.\n");           
    return plvl;
  }
  if(str == "low"){
    if(level < 10) plvl = 3;
    else if(level < 15) plvl = 5;
    else if(extralevel < 5) plvl = 7;
    else plvl = 8;
    write("Power level set to "+QMI("color")+"Low"+NORM+".\n");
    return plvl;
  }
  if(str == "medium"){
    if(level < 10) plvl = 6;
    else if(level < 15) plvl = 10;
    else if(extralevel < 5) plvl = 14;
    else plvl = 17;
    write("Power level set to "+QMI("color")+"Medium"+NORM+".\n");
    return plvl;
  }
  if(str == "high"){
    if(level < 10) plvl = 10;
    else if(level < 15) plvl = 15;
    else if(extralevel < 5) plvl = 20;
    else plvl = 20;
    write("Power level set to "+QMI("color")+"High"+NORM+".\n");
    return plvl;
  }
  if(str == "overload" || str == "OVERLOAD"){
    if(extralevel < 5){
      write("Type: set_power with no arguments for a listing of settings.\n");
      return plvl;
    }
    plvl = 25;
    write("Power level set to "+QMI("color")+"OVERLOAD"+NORM+".\n");
    return plvl;
  }
  write("Type: set_power with no arguments for a listing of settings.\n");
  return plvl;
}
