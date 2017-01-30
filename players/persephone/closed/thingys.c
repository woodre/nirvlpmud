inherit "room/room";
init(){
  ::init();
  add_action("peace","peace");
  add_action("peace","fog");
  add_action("peace","calm");
  add_action("call","call");
  add_action("call","Call");
  add_action("call","summon");
  add_action("call","animate");
  add_action("call","pearl");
  add_action("call","change");
  add_action("call","bede");
  add_action("call","dragon");
  add_action("call","ghoul");
  add_action("attack","attack");
  add_action("attack","attak");
  add_action("can","CAN");
  add_action("can","can");
  add_action("can","Can");
  add_action("heal","heal");
  add_action("heal","mheal");
  add_action("heal","cure");
  add_action("heal","h");
  add_action("quit","quit");
  add_action("stun","stun");
  add_action("stun","hold");
  add_action("stun","grasp");
  add_action("stun","gra");
  add_action("stun","demon");
  add_action("stun","drain");
  add_action("stun","vamp");
  add_action("stun","energise");
  add_action("stun","midas");
  add_action("stun","energize");
  add_action("stun","demonwrath");
  add_action("stun","dw");
  add_action("stun","FREEZE");
  add_action("stun","peace");
  add_action("stun","calm");
  add_action("stun","scan");
  add_action("stun","chain");
  add_action("stun","deathknight");
  add_action("stun","freeze");
  add_action("stun","damn");
  add_action("stun","freeze");
  add_action("dest","destruct");
  add_action("dest","Destruct");
  add_action("dest","destroy");
  add_action("shelter","shelter");
  add_action("death","disrupt");
  add_action("death","holocaust");
  add_action("death","flamestrike");
  add_action("death","death");
  add_action("levitate","levitate");
  add_action("adren","adren");
  add_action("recall","recall");
  add_action("swarm","swarm");
  add_action("peace","hold");

}
peace(arg){
 if(!arg){
  write("This area is to chaotic to cast peace.\n\n");
 return 1;
 }
 if(arg){
  write("This area is to chaotic to cast peace\n\n");
 return 1;
 }
}
attack(arg){
 if(!arg){
  write("Your pet refuses to attack\n\n");
 return 1;
 }
 if(arg){
  write("Your pet refuses to attack\n\n");
 return 1;
 }
}
quit(arg){
 if(!arg){
  write("You really do not want to quit here\n\n");
 return 1;
 }
 if(arg){
  write("You really do not want to quit here\n\n");
 return 1;
 }
}
call(arg){
 if(!arg){
  write("No matter how hard you call your pet does not respond\n\n");
 return 1;
 }
 if(arg){
  write("No matter how hard you call your pet does not respond\n\n");
 return 1;
 }
}
stun(arg){
 if(!arg){
  write("You seem to have incorrectly cast the spell\n\n");
 return 1;
 }
 if(arg){
  write("You seem to have incorrectly cast the spell\n\n");
 return 1;
 }
}
shelter(arg){
 if(!arg){
  write("You seem unable to erect your shelter in this environment\n\n");
 return 1;
 }
 if(arg){
  write("You seem unable to erect your shelter in this environment\n\n");
 return 1;
 }
}
death(arg){
 if(!arg){
  write("The spell fails!\n\n");
 return 1;
 }
 if(arg){
  write("The spell fails!\n\n");
 return 1;
 }
}
levitate(arg){
 if(!arg){
  write("Your spell seems to fail no matter what you do\n\n");
 return 1;
 }
 if(arg){
  write("Your spell seems to fail no matter what you do\n\n");
 return 1;
 }
}
adren(arg){
 if(!arg){
  write("You cannot get your adrenillin pumping\n\n");
 return 1;
 }
 if(arg){
  write("You cannot get your adrenillin pumping\n\n");
 return 1;
 }
}
recall(arg){
 if(!arg){
  write("You cannot remember what you were trying to recall\n\n");
 return 1;
 }
 if(arg){
  write("You cannot remember what you were trying to recall\n\n");
 return 1;
 }
}
swarm(arg){
 if(!arg){
  write("The swarm flies about lazily\n\n");
 return 1;
 }
 if(arg){
  write("The swarm flies about lazily\n\n");
 return 1;
 }
}
can(arg){
 if(!arg){
  write("You feel it ill advisable to canabalise your stats\n\n");
 return 1;
 }
 if(arg){
  write("You feel it ill advisable to canabalise your stats\n\n");
 return 1;
 }
}
heal(arg){
 if(!arg){
  write("You forget how to heal\n\n");
 return 1;
 }
 if(arg){
  write("You forget how to heal\n\n");
 return 1;
 }
}

