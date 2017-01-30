tell_all() {
  object o; int i;
  o = users(); for(i = 0; i < sizeof(o); i++) {
  if(o[i]->query_real_name() != "boltar" && 
     o[i]->query_real_name() != "llew")
    tell_object(o[i], "Wizardchild whispers to everyone: "+
"OK everyone, it is Llew's birthday, so sing happy birthday to "+
"him on gossip with me when i start...:)\n");
  }
}
