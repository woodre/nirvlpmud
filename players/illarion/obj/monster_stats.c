/* Take a monster's level and a percent variance, and come up with some
 * stats.  I plan to expand it until you can pick what stat to vary,
 * and raise and lower hp/wc/ac in proportion to each other.
 */
mixed determine_stats(int level,string *variances) {
  int money;
  mapping map;
  map=(["hp":15,"wc":5,"ac":3]);
  switch(level) {
    case  1: map["hp"]= 15; map["wc"]=  5; map["ac"]=  3; money=  30; break;
    case  2: map["hp"]= 30; map["wc"]=  6; map["ac"]=  3; money=  60; break;
    case  3: map["hp"]= 45; map["wc"]=  7; map["ac"]=  4; money= 100; break;
    case  4: map["hp"]= 60; map["wc"]=  8; map["ac"]=  4; money= 150; break;
    case  5: map["hp"]= 75; map["wc"]=  9; map["ac"]=  5; money= 200; break;
    case  6: map["hp"]= 90; map["wc"]= 10; map["ac"]=  5; money= 250; break;
    case  7: map["hp"]=105; map["wc"]= 11; map["ac"]=  6; money= 300; break;
    case  8: map["hp"]=120; map["wc"]= 12; map["ac"]=  7; money= 350; break;
    case  9: map["hp"]=135; map["wc"]= 13; map["ac"]=  7; money= 400; break;
    case 10: map["hp"]=150; map["wc"]= 14; map["ac"]=  8; money= 450; break;
    case 11: map["hp"]=165; map["wc"]= 15; map["ac"]=  9; money= 500; break;
    case 12: map["hp"]=180; map["wc"]= 16; map["ac"]=  9; money= 600; break;
    case 13: map["hp"]=195; map["wc"]= 17; map["ac"]= 10; money= 700; break;
    case 14: map["hp"]=210; map["wc"]= 18; map["ac"]= 11; money= 850; break;
    case 15: map["hp"]=225; map["wc"]= 20; map["ac"]= 12; money= 875; break;
    case 16: map["hp"]=400; map["wc"]= 22; map["ac"]= 13; money= 890; break;
    case 17: map["hp"]=425; map["wc"]= 24; map["ac"]= 14; money= 950; break;
    case 18: map["hp"]=450; map["wc"]= 26; map["ac"]= 15; money=1000; break;
    case 19: map["hp"]=475; map["wc"]= 28; map["ac"]= 16; money=2000; break;
    case 20: map["hp"]=500; map["wc"]= 30; map["ac"]= 17; money=5000; break;
    default: return;
  }
  if(variances && sizeof(variances)) {
    int x,y,var;
    string *stats;
    stats=({"hp","wc","ac"});
    for(y=0;y<3;y++) {
      if((x=member_array(stats[y],variances))!=-1 && 
                    sscanf(variances[x+1],"%d",var))
        map[stats[y]]+=(map[stats[y]]*var/100);
    }
  }
  return ({map["hp"],map["wc"],map["ac"],money});
}
