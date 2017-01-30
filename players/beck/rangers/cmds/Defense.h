show_defense(str,me,who,space){
   if(str == "block"){ return me+" blocks the attack, with a defensive chop.";}
   if(str == "backflip"){ return me+" does a backflip and dodges "+capitalize(who)+"."; }
   if(str == "shiho-nage"){ return me+" grabs "+capitalize(who)+"'s arm and throws them using shiho-nage."; }
   if(str == "irimi-nage"){ return me+" moves toward "+capitalize(who)+" and throws them with irimi-nage."; }
   if(str == "kaiten-nage"){ return me+" gives "+capitalize(who)+" a rotary kaiten-nage throw."; }
   if(str == "kote-gaeshi"){ return me+" grabs "+capitalize(who)+"'s wrist and applies kote-gaeshi."; }
   if(str == "ikkyo"){ return me+" pins "+capitalize(who)+"'s arm with ikkyo technique."; }
   if(str == "nikyo"){ return me+" turns "+capitalize(who)+"'s wrist inward with nikyo."; }
   if(str == "sankyo"){ return me+" twists "+capitalize(who)+"'s wrist with sankyo."; }
   if(str == "yonkyo"){ return me+" pins "+capitalize(who)+"'s wrist with yonkyo technique."; }
   if(str == "koshi-nage"){ return me+" gives "+capitalize(who)+" a hip throw using koshi-nage."; }
   if(str == "tenchi-nage"){ return me+" applies a tenchi-nage, heaven and earth throw."; }
   if(str == "juji-garami"){ return me+" entangles and throws "+capitalize(who)+" with juji-garami."; }
   if(str == "aiki-otoshi"){ return me+" gives "+capitalize(who)+" an aiki drop using aiki-otoshi."; }
   if(str == "sumi-otoshi"){ return me+" gives "+capitalize(who)+" a corner drop with applied sumi-otoshi."; }
   if(str == "kokyu-nage"){ return me+" gives "+capitalize(who)+" an elegant breath throw using your kokyu-nage."; }
   if(str == "aiki-nage"){ return me+" gives "+capitalize(who)+" an aiki throw using aiki-nage."; }
   return "Your defense fails...notify Beck by mail";
}
identify_defense(){
   COMM->SeeDefense();
   return 1;
}
