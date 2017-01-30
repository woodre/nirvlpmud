/* This spell links a healer to another player
/* In the call_out, arr[0] is this_player and arr[1] is the target

/* Step 1 */
int do_link(string str) {
  object target;
  string who;
  notify_fail("Link with whom?\n");
  if(!str) return 0;
  if(sscanf(str,"with %s",who) !=1) return 0;
  if(!who) return 0;
  target=present(who,environment(TP));
  if(!target) {
    write("That person is not here.\n");
    return 1;
  }
  write("You take a silent breath and close your eyes, preparing yourself\n"+
        "for the difficult task you are about to undertake.\n");
  say(TPN+" takes a deep breath and closes "+TP->query_possessive()+" eyes, preparing "+TP->query_objective()+"self\n"+
      "for some difficult task.\n");
  call_out("link_2",4,({ TP, target }) );
  return 1;
}
/* Step 2 */
void link_2(object *arr) {
  tell_object(arr[0],"You open your eyes.\n");
  tell_room(environment(arr[0]),
    arr[0]->query_name()+" opens "+arr[0]->query_possessive()+" eyes.\n", ({ arr[0] }));
  call_out("link_3",2,arr);
}

/* Step 3 */
void link_3(object *arr) {
  if(!present(arr[1],environment(arr[0]))) {
    tell_object(arr[0],"That person is no longer here.\n");
    return;
  }
  if(arr[0]->query_sp() < 40) {
    tell_object(arr[0],"The link fizzles before it even truly begins.\n");
    tell_room(environment(arr[0]),arr[0]->query_name()+" shakes "+arr[0]->query_pronoun()+"self as though waking from a bad dream.\n",({arr[0]}));
    return;
  }
  arr[0]->add_spell_point(-40);
  tell_object(arr[0],"You grasp "+arr[1]->query_name()+" by the shoulders and stare into "+
              arr[1]->query_possessive()+" eyes.\n");
  tell_room(environment(arr[0]),arr[0]->query_name()+" grasps "+arr[1]->query_name()+" by the shoulders and stares\n"+
              "into "+arr[1]->query_possessive()+" eyes.\n",({ arr[0] }));
  call_out("link_4",3,arr);
}

/* Step 4: Start the link */
void link_4(object *arr) {
  if(!present(arr[1],environment(arr[0]))) {
    tell_object(arr[0],"The person you were linking to is no longer here.\n");
    return;
  }
  if(arr[0]->query_sp() < 50) {
    tell_object(arr[0],"The link fizzles before it even truly begins.\n");
    tell_room(environment(arr[0]),arr[0]->query_name()+" shakes "+arr[0]->query_pronoun()+"self as though waking from a bad dream.\n",({arr[0]}));
    return;
  }
  arr[0]->add_spell_point(-50);
  tell_object(arr[0],"You are now linked to "+arr[1]->query_name()+"!\n");
  tell_object(arr[1],"You are now linked to "+arr[0]->query_name()+"!\n");
  tell_room(environment(arr[0]),"A visible crackle of energy seems to leap between "+arr[0]->query_name()+" and\n"+
            arr[1]->query_name()+" as they finally break eye contact.\n",({ arr[0], arr[1] }));
  call_out("link_cycle",1,arr);
}

/* The link's "heartbeat" */
void link_cycle(object *arr) {
  int diff;
  if(!arr[0] || !arr[1] || !interactive(arr[0]) || !interactive(arr[1]) ||
     arr[1]->is_ghost() || arr[0]->is_ghost()) {
    tell_object(arr[0],"The link has been broken!\n");
    tell_object(arr[1],"The link has been broken!\n");
    return;
  }
  diff=(int)arr[0]->query_hp()-(int)arr[1]->query_hp();
  if(diff>0) {
    arr[0]->add_hit_point(-(diff/2));
    arr[1]->add_hit_point(diff/2);
  }
  call_out("link_cycle",1,arr);
}

