#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"

mssle_hit(attacker){
     
  int a;
  int b;
  int c;
  int d;
  int e;
  int f;
  int g;
  int h;
  int i;
  int j;
  int k;
  int l;
  a = 1;
  b = random(2);
  c = random(3);
  d = random(3);
  e = random(3);
  f = random(3);
  g = random(3);
  h = random(3);
  i = random(3);
  j = random(3);
  k = random(3);
  l = random(3);

  if(a==1){
    if(!attacker) return 1;
    write("The head of "+TPN+"'s "+NAME+" glows with raw power!\n"+NORM);
    say("The head of "+TPN+"'s "+NAME+" glows with raw power!\n"+NORM);
}
 
  if(b==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(1+random(2));
  }
 
  if(c==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(2+random(2), "other|electric");
  }

  if(d==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(2+random(2), "other|electric");
  }

  if(e==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(random(2), "other|electric");
  }

  if(f==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(2+random(3), "other|electric|wind");
  }   

  if(g==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(random(2));
  }

  if(h==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(1+random(2));
  }

  if(i==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(2+random(2), "other|electric");
  }

  if(j==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(1+random(2));
  }

  if(k==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(2+random(3), "other|electric");
  }

  if(l==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(4+random(2), "other|electric");
  }
  

  if(b==2){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(3+random(2), "other|electric");
  }

  if(b==1){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(3+random(3), "other|electric");
  }

  if(b==0){
    if(!attacker) return 1;
    write(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
    say(TPN+"'s missile flies straight into "+MEAT+". , a "+RED+"direct"+NORM+" hit!\n");
  attacker->hit_player(3+random(2), "other|electric");
  }
  return 1;
}