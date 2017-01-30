/* OLD MONSTER GUIDE */

int wc,hp,ac;
calc_stats(int lev) {
   switch(lev) {
      case 1: hp = 15; wc = 5; ac = 3; break;
      case 2: hp = 30; wc = 6; ac = 3; break;
      case 3: hp = 45; wc = 7; ac = 4; break;
      case 4: hp = 60; wc = 8; ac = 4; break;
      case 5: hp = 75; wc = 9; ac = 5; break;
      case 6: hp = 90; wc = 10; ac = 5; break;
      case 7: hp = 105; wc = 11; ac = 6; break;
      case 8: hp = 100+random(40); wc = 10+random(4); ac = 6+random(2); break;
      case 9: hp = 120+random(30); wc = 11+random(4); ac = ac = 6+random(2); break;
      case 10: hp = 130+random(40); wc = 12+random(4); ac = 6+random(4); break;
      case 11: hp = 150+random(30); wc = 13+random(4); ac = 7+random(4); break;
      case 12: hp = 160+random(40); wc = 14+random(4); ac = 7+random(4); break;
      case 13: hp = 175+random(40); wc = 15+random(4); ac = 8+random(4); break;
      case 14: hp = 190+random(40); wc = 16+random(4); ac = 9+random(4); break;
      case 15: hp = 200+random(50); wc = 18+random(4); ac = 10+random(4); break;
      case 16: hp = 380+random(40); wc = 20+random(4); ac = 11+random(4); break;
      case 17: hp = 400+random(50); wc = 22+random(4); ac = 12+random(4); break;
      case 18: hp = 425+random(50); wc = 24+random(4); ac = 13+random(4); break;
      case 19: hp = 450+random(50); wc = 26+random(4); ac = 14+random(4); break;
      case 20: hp = 475+random(50); wc = 28+random(4); ac = 15+random(4); break;
   }
}


get_value(str) {
   if(str == "hp") return hp;
   if(str == "wc") return wc;
   if(str == "ac") return ac;
}
