inherit "obj/treasure";

int x,y,duration,firstPass, oldAC,oldWC,oldSTR,oldSTA,oldMAG,oldLUC,oldSTE,oldDEX,newAC,newWC,newSTR,newSTA,newMAG,newLUC,newSTE,newDEX;
string *messages;
reset(arg)  {
  if(arg) return;
  set_id("debuff");
  set_alias("dischord");
  set_weight(0);
  set_value(0);
}

query_auto_load() { return "/players/sparrow/areas/darkGauntlet/obj/deBuff.c"; }

init(arg) { 
  if(!duration) { duration = 5; } 
  if(environment()){
    tell_object(environment(),
     "You begin to feel disoriented, you can barely stand.\n");
    tell_room(environment(environment()),capitalize(environment()->query_name())+" begins to sway and look disoriented.\n",({ environment() }));
    oldAC = (int)environment()->query_ac();
    oldWC = (int)environment()->query_wc();
    oldSTR = (int)environment()->query_attrib("str");
    oldSTA = (int)environment()->query_attrib("sta");
    oldMAG = (int)environment()->query_attrib("mag");
    oldLUC = (int)environment()->query_attrib("luc");
    oldSTE = (int)environment()->query_attrib("ste");
    oldDEX = (int)environment()->query_attrib("dex");
    newAC = oldAC - (random(5)+10);
    if(newAC < 0) { newAC = 0; }
    newWC = oldWC - (15+random(5));
    if(newWC < 0) { newWC = 0; }
    newSTR = oldSTR - (10 + random(10));
    if(newSTR < 1) { newSTR = 1; }
    newSTA = oldSTA - (10 + random(10));
    if(newSTA < 1) { newSTA = 1; }
    newMAG = oldMAG - (10 + random(10));
    if(newMAG < 1) { newMAG = 1; }
    newLUC = oldLUC - (10 + random(10));
    if(newLUC < 1) { newLUC = 1; }
    newSTE = oldSTE - (10 + random(10));
    if(newSTE < 1) { newSTE = 1; }	     
    newDEX = oldDEX - (10 + random(10));
    if(newDEX < 1) { newDEX = 1; }
    environment()->set_wc(newWC);
    environment()->set_ac(newAC);
    environment()->set_attrib("str",newSTR);
    environment()->set_attrib("sta",newSTA);
    environment()->set_attrib("mag",newMAG);
    environment()->set_attrib("luc",newLUC);
    environment()->set_attrib("ste",newSTE);
    environment()->set_attrib("dex",newDEX);
    messages = ({
      "Muse's voice seems like a choir, the music depresses you.\n",
      "The pounding notes seem to drain all of the strength out of you.\n",
      "The hypnotic rythms and confusing lyrics leave you dumbfounded.\n",
      "Muse's face slowly fades to it's true lich form and flashes back suddenly.\n",
      "You feel a wave of hopelessness wash over you as Muse continues her song.\n"
    });
    call_out("deBuff", 1);
  }
  ::init(arg);
}

void deBuff() {
  y= random(5);
  tell_room(environment(environment()), messages[y]);  
  if(duration > 0) {
    this_object()->add_duration(-1);
    call_out("deBuff", (1+random(3)));
  }
  else {
    tell_object(environment(),"You recover as Muse ends her song.\n");
    environment()->set_wc(oldWC);
    environment()->set_ac(oldAC);
    environment()->set_attrib("str",oldSTR);
    environment()->set_attrib("sta",oldSTA);
    environment()->set_attrib("mag",oldMAG);
    environment()->set_attrib("luc",oldLUC);
    environment()->set_attrib("ste",oldSTE);
    environment()->set_attrib("dex",oldDEX);
    destruct(this_object());
  }
  return;
}
  
get() { return 0; }

drop() {
  if(environment()->is_dieing()) {
    environment()->set_wc(oldWC);
    environment()->set_ac(oldAC);
    environment()->set_attrib("str",oldSTR);
    environment()->set_attrib("sta",oldSTA);
    environment()->set_attrib("mag",oldMAG);
    environment()->set_attrib("luc",oldLUC);
    environment()->set_attrib("ste",oldSTE);
    environment()->set_attrib("dex",oldDEX);  
    destruct(this_object());
  }
  else return 1;
}

set_duration(x) { duration=x; }
add_duration(x) { duration = duration + x; }