int do_emtp(string str) {
  object space;
  if((string)environment(TP)->realm()=="NT") {
    write("Something here prevents you from teleporting away.\n");
    return 1;
  }
  write("You carefully intone the magic incantation needed to perform an\n"+
        "emergency teleport.  With a disconcerting jerk, you send yourself\n"+
        "hurtling through space and time on a random course.\n\n");
  say(TPN+" carefully intones a magical spell, then glows brightly and vanishes.\n");
  space=clone_object("/players/feldegast/realm/void");
  move_object(TP,space);
  call_out("emtp_2",4,TP);
  return 1;
}
void emtp_2(object player) {
  object space;
  string where;
  space=environment(player);
  while(!(where=(string)call_other("obj/base_tele","teleport"))) ;
  move_object(player,where);
  command("look",player);
  destruct(space);
}
