#include "../defs.h"
cmd(str){
object tar;
  if(!str){
  write("You furl your eyebrow and look around with cold dead eyes.\n");
  say(tpn+"'s eyebrow furls and "+tp->query_pronoun()+" looks around with cold dead eyes.\n");
  return 1;
  }
  tar = present(str,environment(tp));
  if(!tar){
    notify_fail(capitalize(str)+" is not here to stare at.\n");
    return 0;
  }
  if(living(tar)){
    write("You stare at "+tar->query_name()+" with cold dead eyes.\n");
    say(tpn+" stares at "+tar->query_name()+" with cold dead eyes.\n");
    return 1;
  }
    write("You stare at "+str+" with cold dead eyes.\n");
    say(tpn+" stares at "+str+" with cold dead eyes.\n");
  return 1;
}
