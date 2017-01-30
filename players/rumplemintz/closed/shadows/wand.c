object me;
int nohits;
int level;
string name;
string cap_name;
shadow_me(who,nm,lev) {
  nohits=0;
  me=who;
  shadow(who,1);
  name=nm;
  cap_name=capitalize(name);
  level=lev;
}
query_name() { if(this_player()->query_invis()) return "Someone"; else return name; }
query_real_name() { return name; }

hit_player(str) {
  if(nohits==0) return;
  write("You were \"hit\" for "+str+" points damage!\n");
  return 1;
}

add_hp(str) {
  if(nohits==0) return;
  write(str+" points were added!\n");
  return 1;
}

set_nohits(x) {
  if(!intp(x)) sscanf(x,"%d",x);
  nohits=x;
  return 1;
}

setname(str) { name=str;  cap_name=capitalize(str); }
short() {
  string s;
  s=me->query_pretitle()+" "+cap_name+" "+me->query_title();
  if(me->query_invis()) s+="  ** INVIS **";
  if(me->query_invis()<this_player()->query_level())
    return s;
    else return 0;
}

setlevel(str) { level=str; }

query_level() { return level; }

catch_tell(str) {
    string one, two, target;
  if(sscanf(str,"%s rain of yellow Nerf balls! You hear %s laughing %s",one,target,two)==3) {
    tell_object(me,"You just got pelted with Nerf balls by "+target+".\n");
    tell_object(me,"Target acquired: "+target+".  Zeroing in...\n");
    if(find_living(lower_case(target))) bomb(lower_case(target));
    tell_object(me,"Target attacked.\n");
  } else tell_object(me,str);
}

bomb(str) {
    object ob;
  ob=find_living(str);
  if(!ob) return;
  tell_object(ob,"After your lone Nerf ball flies through the air, you see a shower of\n"+
"yellow coming your way.  As it approaches, you realize, in panic, that they are\n"+
"a mass of Nerf balls!  Not having enough time to flee, you promise yourself\n"+
"that you will never shoot another Nerf ball again.\n\n"+
"When the Nerf cloud clears, you are standing amidst tens of thousands of\n"+
"medium-sizes yellow balls.\n");
  if(environment(ob)!=environment(me)) {
    say(cap_name+" gets hit by a Nerf ball.  He then returns a barrage of his\n"+
"own Nerf balls into the sky.  When he is done shooting over tens of thousands,\n"+
"you can hear someone screaming in terrible agony.\n");
    tell_room(environment(ob),capitalize(str)+" shoots a lone Nerf ball into the air.  A few seconds later,\n"+
"a shower of yellow falls on him in retalliation.  When the yellow smoke clears,\n"+
"you see that he is standing among tens of thousands of Nerf balls.\n");
  } else {
    say(cap_name+" gets hit by a Nerf ball, shot by "+capitalize(str)+"!\n"+
cap_name+" pulls out an automatic Nerf rifle and pelts "+capitalize(str)+"\n"+
"with a tens of thousands of his own Nerf balls!\n",ob);
  }
}
