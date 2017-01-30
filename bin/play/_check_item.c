/* _check_item.c
 * 
 * by illarion@nirvana, dec 2004
 *
 * Allows players to recommend an item for dtype update
 * lets them know if it's already been recommended
 * or updated.  objects from /obj/ are automatically
 * disallowed
 */
 
#define DAEMON "/obj/user/check_item_daemon.c"
 
mapping lusers;

reset() {
  if(!lusers)
    lusers=([]);
}

cmd_check_item(str) {
  object ob;
  string file,junk,junk2;
  if(!str) {
    write("Please specify the item you'd like to check.\n");
    return 1;
  }
  if(this_player()->query_real_name()=="guest") return 1;
  ob=present(str,this_player());
  if(!ob)
    ob=present(str,environment(this_player()));
  if(!ob) {
    write("That item is not present in your room or in your inventory.\n");
    return 1;
  }
  if(living(ob) && !ob->is_npc()) {
    write("Monsters only, please.\n");
    return 1;
  }
  file=object_name(ob);
  if(sscanf(file,"%s#%s",junk,junk2)==2)
    file=junk;
  junk=DAEMON->check_item(file);
  if(junk) {
    write("That item has already been "+junk+".\n");
    return 1;
  }
  write("You may type a one line recommendation for this item if you wish.\n"
       +"If you'd rather not, just hit enter.\n"
       +"Your recommendation:");
  lusers[this_player()]=file;
  input_to("enter_recommendation");
  return 1;
}

enter_recommendation(str) {
  if(!lusers[this_player()]) {
    write("Illarion messed something up.  Please let him know.\n");
    return 1;
  }
  DAEMON->add_item(lusers[this_player()],this_player()->query_real_name(),str);
  lusers=m_delete(lusers,this_player());
  write("Item logged!\nThank you for your submission.\n");
  return 1;
}
