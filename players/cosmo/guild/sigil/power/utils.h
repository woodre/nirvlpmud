query_pmess() {
/* Used in the gob long() to display the powerlevel */
int plvl;
  plvl = TPGO->query_plevel();
  if(level < 10){
    if(plvl < 4) return "low";
    else if(plvl < 7) return "medium";
    else if(plvl < 11) return "high";
    else return "error";
  }
  else if(level < 15){
    if(plvl < 6) return "low";
    else if(plvl < 11) return "medium";
    else if(plvl < 16) return "high";
    else return "error";
  }
  else if(extralevel < 5){
    if(plvl < 8) return "low";
    else if(plvl < 15) return "medium";
    else if(plvl < 21) return "high";
    else return "error";
  }
  else if(extralevel > 4){
    if(plvl < 9) return "low";
    else if(plvl < 18) return "medium";
    else if(plvl < 21) return "high";
    else if(plvl > 20) return "overload";
    else return "error";
  }
  else return "error";
}

query_dam1_msg(int num) {
/* Used in invoke.h and cone.h to get appropriate damage msgs */
  switch(num){
    case 45..1000: return QMI("dam1");
    case 40..44: return QMI("dam2");
    case 33..39: return QMI("dam3");
    case 27..32: return QMI("dam4");
    case 17..26: return QMI("dam5");
    case 10..16: return QMI("dam6");
    case 5..9: return QMI("dam7");
    case 1..4: return QMI("dam8");
    default: return "missed";
  }
}

query_dam2_msg(string str) {
/* Used in invoke.h and cone.h to get appropriate damage msgs */
  switch(random(100)+1){
    case 75..1000: return QMI(str+"msg1");
    case 50..74: return QMI(str+"msg2");
    case 25..49: return QMI(str+"msg3");
    case 1..24: return QMI(str+"msg4");
    default: return QMI(str+"msg4");
  }
}

int filter_invis(object who){
/* Used in gwho.h to filter the users() array */
     if(!environment(who)){ return 0; }
     if(TP->query_level() < who->query_invis()) return 0;
     return 1;
}
int filter_sigil(object who){
/* Used in gwho.h and channel.h to filter the users() array */
     if(!present("SIGIL_OB", who)) return 0;
     return 1;
}
