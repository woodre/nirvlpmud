/*
 * monster_guide.c - uses the same stats as /doc/build/RULES/monster.guide,
 * but actually tells the calling object what those stats are.
 * It's only good for levels 1-20, what the guide actually covers
 */
 
#define GOLD ({65,90,120,150,200,250,300,350,400,450,500,550,600,750,\
    1000,1500,2100,3500,4000,5000,6000,7000,8000,10000,11000,14000})
 
int wc_guide(int level) {
  if(level <15) return level+4;
  else return level*2-10;
}
int ac_guide(int level) {
  if(level>11) return level-3;
  else return ({3,3,4,4,5,5,6,7,7,8,9})[level-1];
}
int hp_guide(int level) {
  if(level<16) return level*15;
  else return level*25;
}
int gold_guide(int level) {
  if(level>26) level=26;
  return GOLD[level-1];
}
varargs int randomize(int x,int percent) {
  int variance;
  if(percent<0 || percent > 100)
    percent=20;
/*  x *= 100; */
  variance=x*percent/100;
  x=x-variance+random(1+variance*2);
/*  return x/100; */
  return x;
}
void make_monster(int level,object mon,int variance) {
  int wc;
  int ac;
  int hp;
  int gold;
  mon->set_level(level);
  wc=wc_guide(level);
  ac=ac_guide(level);
  hp=hp_guide(level);
  gold=gold_guide(level);
  mon->set_wc(randomize(wc,variance));
  mon->set_ac(randomize(ac,variance));
  mon->set_hp(randomize(hp,variance));
  mon->add_money(randomize(gold,variance));
}
