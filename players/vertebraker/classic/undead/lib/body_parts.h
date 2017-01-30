#define VALID_BPARTS ({ "head","right leg","left leg","right arm","left arm"})

string bp_strtoint(string str){
  switch(str) {
    case "head": return V_HEAD;
    case "left arm": return V_LARM;
    case "right arm": return V_RARM;
    case "right leg": return V_RLEG;
    case "left leg": return V_LLEG;
  }
}

