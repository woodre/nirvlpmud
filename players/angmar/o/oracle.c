#pragma strong_types

inherit "obj/monster";

string str1,str2,str3; /* Remember up to 3 players */

void
remember(string str) {  /* Remember the name */
  str3=str2;
  str2=str1;
  str1=lower_case(str);
}

status
here_before(string str) { /* Check if remembered */
  str=lower_case(str);
  if (str == str1 ||
      str == str2 ||
      str == str3)
    return 1;
  return 0;
}

void
forget(string str) { /* Clear out player from remembered */
  str=lower_case(str);
  if(str==str1) str1="";
  if(str==str2) str2="";
  if(str==str3) str3="";
}

void
reset(status arg){
  if (arg)
    return;
  monster::reset(arg);
  set_name("oracle");
  set_short("The all-wise oracle");
  set_long(
"He sits here alone meditating over things incomprehensible\n"+
"to ordinary humans.  If you have a problem, he might be\n"+
"able to help you.\n");
  set_level(30);
  set_hp(10000);
  set_ac(9999);
  set_wc(200);
  set_al(100);
  
  /* catch_tell setup */
  set_object(this_object());
  set_function("handle_give");
  set_type("gives");
  set_match("");
  set_function("handle_arrival");
  set_type("arrives");
  set_match("");
}

void
handle_give(string str) {
  string a, b;
 
  if (sscanf(str,"%s gives %s to Oracle.\n", a, b) == 2) {
    say("The Oracle smiles and says: 'Thank you, "+a+".'\n");
    if (b == "doomsgiver" && present("angmar_doomsgiver"))
      call_out("give_password", 2, a);
  }
}

void
give_password(string a) {
  string cur_pass;
  object a_doomsgiver;
  cur_pass = (string)"players/angmar/castle/treasury"->query_password();
  say("The Oracle says: 'Now listen carefully. The password to the doors\n" +
      "changes all the time. It is '" +cur_pass+"' right now.'\n");
  say("The Oracle says: 'It can change any minute, so hurry! " +
      "And good luck!'\n");
  a_doomsgiver = present("angmar_doomsgiver", this_object());
  if (a_doomsgiver) destruct(a_doomsgiver);
/*
  destruct(present("angmar_doomsgiver"), this_object());
*/
  forget(a);
  "players/angmar/castle/treasury"->prevent_reset();
}

void
handle_arrival(string str) {
  string who, junk;
  object client;
  
  if (sscanf(str, "%s arrives%s", who, junk) != 2)
    return;
  client = present(lower_case(who), environment(this_object()));
  if (!client)
    return;
  if (!here_before(lower_case(who)))
    call_out("first_timer", 2, client);
  else
    call_out("repeat_customer", 2, client);
  return;
}

void
first_timer(object client) {
  say("The Oracle says:  Hello "+client->query_name()+"!\n");
  if (present("trlock1", client) &&
      present("trlock2", client) &&
      present("trlock3", client)) {
    say("The Oracle smiles.\n");
    say("The Oracle says: 'I can see that you have found the rings\n");
    say("                  Looking for the password, eh?'\n");
    say("The Oracle laughs.\n");
    say("The Oracle says: 'Well, I do nothing for free, you see.'\n");
    say("The Oracle lowers his voice and leans closer to you.\n");
    say("The Oracle says: 'If you could find the famous sword Doomsgiver \n"+
        "                  and give it to me, I might help you.'\n");
    say("The Oracle says: 'It is said to be found somewhere deep in the \n"+
        "                  castle of Angmar, but beware! The legend also \n"+
        "                  tells about a fearful spirit guarding the\n" +
        "                  mighty sword!'\n");
    say("The oracle returns to his meditating and says no more.\n");
    remember((string)client->query_name());
    return;
  }
  return;
}

void
repeat_customer(object client) {
  say("The Oracle says:  Welcome back "+client->query_name()+"!\n");
  if (present("trlock1", client) &&
      present("trlock2", client) &&
      present("trlock3", client)) {
    if (present("angmar_doomsgiver", client)) {
      say("The Oracle says: 'I see you have the Doomsgiver " +
          client->query_name()+"!'\n");
      say("The Oracle says: 'Give that evil sword to me and I shall give \n" +
          "                   you the password you seek.'\n");
      return;
    }
    say("The Oracle says: 'Did you get the sword for me as you promised?'\n");
    return;
  }
  say("The Oracle sighs.\n"+
      "The Oracle says: 'Lost the rings?  Too bad.  There is no way to get\n"+
      "to the treasure without the rings.  Sorry.'\n");
  forget((string)client->query_name());
  return;
}
