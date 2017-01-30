
string who;

id(str) { return(str=="quest_ob"); }

get(arg) { return 0; }

set_who(str) {
     who=str;
}

query_who(str) {
     return who;
}

call_set_quest_string() {
     call_out("set_quest_string", 10);
}

set_quest_string() {
     object ob;
     ob=present(who);
     if (present("demon")) {
          call_out("set_quest_string", 10);
          return;
     }
     ob->set_quest("staff");
     tell_object(ob, "\nYou have successfully completed this quest.\n");
     tell_object(ob, "->> ");
     call_out("self_destruct", 2);
}

self_destruct() {
     destruct(this_object());
}
