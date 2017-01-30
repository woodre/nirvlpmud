inherit "/obj/weapon";
#include "/players/jareel/ansi.h"
#include "/players/jareel/define.h"

#define WEP HIB+"( "+NORM+RED+"( "+CYN+"~ The Goddess Blesses you for your atonement ~"+RED+" ) "+HIB+")"+NORM
#define WEP2 HIB+"( "+NORM+RED+"( "+CYN+"~ The Goddess Blesses "+TPN+" for "+GEN+" atonement ~"+RED+" ) "+HIB+")"+NORM

reset(arg){
  if(arg) return;
    ::reset(arg);
    
  set_alt_name("staff");
  set_alias("healing staff");
  set_name(YEL+"Revive, "+HIB+"Healing Staff of Virtue"+NORM);
  set_long(
    "Revive is a simple wooded staff engraved with simple ornate runes of healing.\n"+
    "It has helped many a clever healer recover in combat and it has mad the foolish\n"+
    "suffer for not understanding the simple power that lies within.\n");
  set_read("staff\n");
  set_class(1);
  set_type("staff");
  set_weight(3);
  set_value(10000);
  set_hit_func(this_object());
}

query_wear() {
   return 1;
}

weapon_breaks() {
   return 1;
}

weapon_hit(attacker){
     
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
  a = random(3);
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

  if(a==0){
    if(!attacker) return 1;
    write(WEP+"\n"+NORM);
    say(WEP2+"\n"+NORM);
  TP->hit_player(1);
  }
 
  if(b==0){
    if(!attacker) return 1;
    write(WEP+"\n"+NORM);
    say(WEP2+"\n"+NORM);
  TP->hit_player(1+random(2));
  }
 
  if(c==0){
    if(!attacker) return 1;
     write(WEP+"\n"+NORM);
    say(WEP2+"\n"+NORM);
  TP->hit_player(1);
  }

  if(d==0){
    if(!attacker) return 1;
       write(WEP+"\n"+NORM);
    say(WEP2+"\n"+NORM);
  TP->hit_player(1);
  }

  if(e==0){
    if(!attacker) return 1;
    write(WEP+"\n"+NORM);
    say(WEP2+"\n"+NORM);
  TP->hit_player(2);
  }

  if(f==0){
    if(!attacker) return 1;
    write(WEP+"\n"+NORM);
    say(WEP2+"\n"+NORM);
  TP->hit_player(3);
  }   

  if(g==0){
    if(!attacker) return 1;
    write(WEP+"\n"+NORM);
    say(WEP2+"\n"+NORM);
  TP->hit_player(random(2));
  }

  if(h==0){
    if(!attacker) return 1;
    write(WEP+WEP+"\n"+NORM);
    say(WEP2+WEP2+"\n"+NORM);
  TP->hit_player(1);
  }

  if(i==0){
    if(!attacker) return 1;
    write(WEP+WEP+"\n"+NORM);
    say(WEP2+WEP2+"\n"+NORM);
  TP->hit_player(2);
  }

  if(j==0){
    if(!attacker) return 1;
    write(WEP+WEP+"\n"+NORM);
    say(WEP2+WEP2+"\n"+NORM);
  TP->hit_player(3);
  }

  if(k==0){
    if(!attacker) return 1;
    write(WEP+WEP+"\n"+NORM);
    say(WEP2+WEP2+"\n"+NORM);
  TP->hit_player(2);
  }

  if(l==0){
    if(!attacker) return 1;
    write(WEP+WEP+"\n"+NORM);
    say(WEP2+WEP2+"\n"+NORM);
  TP->hit_player(2);
  }
  

  if(a==2){
    if(!attacker) return 1;
    write(WEP+WEP+"\n"+NORM);
    say(WEP2+WEP2+"\n"+NORM);
  TP->hit_player(3);
  }

  if(a==1){
    if(!attacker) return 1;
    write(WEP+WEP+"\n"+NORM);
    say(WEP2+WEP2+"\n"+NORM);
  TP->hit_player(1);
  }

  if(a==0){
    if(!attacker) return 1;
    write(WEP+WEP+"\n"+NORM);
    say(WEP2+WEP2+"\n"+NORM);
  TP->hit_player(3);
  }
  return 1;
}


