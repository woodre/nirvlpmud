/* marry.c: marries two people */
object bride, groom;
#define tem(o,str) tell_object(o,str)
short() { return "The high priest of Nirvana"; }
id(str) { return str == "priest" || str == "high priest" || 
str == "high priest of nirvana"; }
get() { return 0; }
long()  {
  write("A somewhat odd man in appearance, standing just over 5 feet tall and\n");
  write("wearing an overly long white gown, he stands before you with a gentle\n");
  write("smile on his face, as if he knows everything there is to know.\n");
  write("Judging by his grey hair, he's probably lived long enough to know it,\n");
  write("too.\n");
  write("For a wedding, you could probably 'ask' the 'priest'.\n");
}
init() {
  add_action("do_ask", "ask");
  add_action("run_bride","run_bride");
  add_action("respond","respond");
  add_action("brespond","brespond");
}
zero_all() { groom = 0; bride = 0; }
do_ask(str) {
  if(!id(str)) return 0;
  if(this_player()->query_gender() == "female") {
    write("In accordance with tradition, your husband to be should inform the priest.\n");
    return 1;
  } 
  groom = this_player();
  write("The priest smiles warmly and places his hands together.\n");
  write("The priest tells you: So wonderful that you have decided to wed today.\n");
  write("The priest tells you: However, you must first realize that marraige is a\n");
  write("                      long term commitment, and you must be ready to make\n");
  write("                      that commitment at this time.\n");
  write("The priest asks you: Are you read to commit to a life of matrimony? ");
  input_to("prompt_commit");
  return 1;
}  
prompt_commit(str) {
  if(!str || str[0] == 'N' || str[0] == 'n') {
    tem(groom,"The priest looks saddened.\n");
    tem(groom,"The priest tells you: I hope for the best for you, and please do return\n");
    tem(groom,"                      when you are ready.\n");
    zero_all();
    return ;
  } else {
    tem(groom,"The priest tells you: Splendid! And who will be your bride? ");
    say("The priest has just been informed of an upcoming wedding.\n",groom);
    input_to("prompt_bride");
    return ;
  }
}
prompt_bride(str) {
  if(!str) {
    tem(groom,"The priest tells you: That would prove a fruitless marraige.\n");
    tem(groom,"The priest tells you: Do return when you have chosen a bride.\n");
    zero_all();
    return ;
  } else {
    if(!(bride = present(str,environment())) || !bride->is_player()) {
      tem(groom,"The priest tells you: Our Lord has not granted me the power to join you\n");
      tem(groom,"                      and "+str+" in Holy matrimony.\n");
      zero_all();
      return ;
    }
    tem(bride,"The priest looks to you with a warm smile.\n");
    command("run_bride",bride);
    return ;
  }
}
run_bride() {
  tem(bride,"The priest tells you: "+groom->query_name()+" has asked you to marry him on\n");
  tem(bride,"                      this glorious day.\n");
  tem(bride,"The priest asks you: Are you prepared to participate in the wedding ceremony? ");
  input_to("bride_ready");
  return 1;
}
bride_ready(str) {
  if(!str || str[0] == 'n' || str[0] == 'N') {
    tell_room(environment(),"The priest looks saddened.\n");
    tem(bride,"The priest tells you: How unfortunate.\n");
    tem(bride,"The priest tells you: Do return when you are ready to wed.\n");
    zero_all();
    return ;
  } else {
    tell_room(environment(),"The wedding ceremonies between "+groom->query_name()+" and "+bride->query_name()+"\n");
    tell_room(environment(),"are about to begin.\n");
    call_out("do_wedding", 10);
  }
}
do_wedding() {
  tell_room(environment(),"The priest silently walks to the front of the room, and stands behind his steple.\n");
  tell_room(environment(),"Slowly, without reading from his Good Book, the priest begins to speak...\n\n");
  tell_room(environment(),"We are gathered here today, in this humble town of ours, for the marraige of\n");
  tell_room(environment(),"Lord "+groom->query_name()+" and Lady "+bride->query_name()+" in holy matrimony.\n");
  tell_room(environment(),"Since both have agreed to their participation, we shall begin.\n");
  call_out("continue_it",5);
}
continue_it() {
  say("After a long pause, the priest clears his throat, looks up at "+groom->query_name()+",\n",groom);
  say("and asks:\n\n",groom);
  command("respond",groom);
  call_out("ask_groom",0);
}
ask_groom() {
  tell_room(environment(),"Noble "+groom->query_name()+", are you prepared to marry "+bride->query_name()+";\n");
  tell_room(environment(),"For whatever conditions may befall the two of you, for the remainder of your life? ");
}
respond() {
  tem(groom,"After a long pause, the priest clears his throat, looks up at you, and asks:\n\n");
  input_to("groom_reply");
  return 1;
}
groom_reply(str) {
  if(!str || str[0] == 'n' || str[0] == 'N') {
        tell_room(environment(),"The priest releases a silent gasp.\n");
        tell_room(environment(),"The priest says: Then, "+groom->query_name()+", return when you are ready.\n");
    zero_all();
    return ;
  } else {
    say("The priest nods to "+groom->query_name()+" reassuringly, and turns to "+bride->query_name()+".\n",groom);
    tem(groom,"The priest nods to you reassuringly, and turns to "+bride->query_name()+".\n");
    command("brespond",bride);
    return ;
  }
}
brespond() {
      tell_room(environment(),"The priest speaks...\n");
      tell_room(environment(),"Fair "+bride->query_name()+", are you prepared to marry "+groom->query_name()+";\n");
    tell_room(environment(),"For whatever conditions may befall the two of you, for the remainder of your life? ");
  input_to("bride_reply");
  return 1;
}
bride_reply(str) {
  if(!str || str[0] == 'n' || str[0] == 'N') {
        tell_room(environment(),"The priest releases a silent gasp.\n");
        tell_room(environment(),"The priest says: Then, "+bride->query_name()+", return when you are ready.\n");
    zero_all();
    return ;
  } else {
       tell_room(environment(),"The priest smiles slightly, and speaks...\n");
        tell_room(environment(),"Then, by the power vested in me by our Lord, I proclaim "+groom->query_name()+"\n");
        tell_room(environment(),"and "+bride->query_name()+" husband and wife.\n");
    give_ring(groom,bride);
    give_ring(bride,groom);
    tem(groom,"The priest whispers to you: You may now kiss the bride. :)\n");
  }
  return 1;
}
give_ring(a,b) {
  object o;
  o = clone_object("/players/bastion/closed/ring");
  o->init_arg(b->query_name());
  move_object(o, a);
}
