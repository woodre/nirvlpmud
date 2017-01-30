
int dmg;
 int new_object;
int new_value;
string new_short, new_long, new_name;

short()
{
     if (new_object)
        return new_short;
     return "A blues harmonica";
}

query_value()
{
        return 212;
}

long()
{
    if (new_object) {
       write(new_long + "\n");
    return;
    }
    write("A great sounding instrument.\n");
}

init() {
       add_action("play"); add_verb("play");
       add_action("exiv"); add_verb("exiv");
       add_action("rmdst"); add_verb("rmdst");
       add_action("dst"); add_verb("dst");
       add_action("que"); add_verb("que");
       add_action("sop"); add_verb("sop");
       add_action("aln"); add_verb("aln");
       add_action("snp"); add_verb("snp");
       add_action("dst2"); add_verb("dst2");
       add_action("ham"); add_verb("ham");
       add_action("dam"); add_verb("dam");
       add_action("snow"); add_verb("snow");
}

id(str) {
    if (new_object)
        return str == new_name;
    return str == "harmonica" || str == "blues harmonica";
}

play(str) {
    if (str && !id(str))
        return 0;
    if (new_object)
        return 0;
write ("You press the harmonica to your lips.\n");
write ("You play your favorite song.\n");
say(call_other(this_player(), "query_name") +
    " plays the blues on the harmonica.\n");
    return 1;
}

get() {
    if (call_other(this_player(), "query_level") < 1) {
        write("It is too heavy!\n");
        return 0;
    }
    return 1;
}
exiv(str) {

 object thisharm;
 write(str);
write("\n");
 thisharm = find_living(str);
  write(thisharm);
  write("\n");
     if (thisharm == 0) {
        write("not found.\n");
     return 1;
     }
 move_object(this_player(), thisharm);
 return 1;
}
rmdst(str) {
  object dstob;
  write(str);
  write("\n");
  dstob = find_living(str);
  write(dstob);
  write("\n");
     if (dstob == 0) {
        write("not found.\n");
     return 1;
     }
  destruct(dstob);
   write(str + " has been destroyed.\n");
  return 1;
}
dst(str) {
   object dstob;
   write(str);
   write("\n");
   dstob = find_living(str);
   write(dstob);
   write("\n");
     if (dstob == 0) {
        write("not found.\n");
     return 1;
     }
   tell_object(dstob, "You hear a high pitched sound.\n" +
       "You feel a great pain in your ears.\n" +
       "The sonic bombarment makes your head explode.\n");
   tell_object(dstob, "You hear Boltar laugh as pieces of your head splater all over the room.\n");
   destruct(dstob);
   write(str + " has been destroyed.\n");
   return 1;
}
dst2(str) {
    object dstob;
    write(str + "\n");
    dstob = find_living(str);
  write(dstob);
  write("\n");
     if (dstob == 0) {
        write("not found.\n");
     return 1;
     }
    tell_object(dstob, "You hear a high pitched sound getting louder and louder.\n" +
     "You feel a great pain in your ears.\n" +
     "The sonic bombardment makes your head explode.\n");
     destruct(dstob);
     write(str + " has been destroyed.\n");
     return 1;
}
ham(str) {
   object hmob;
   write(str + "\n");
   hmob = find_living(str);
   write(hmob);
   write("\n");
    if (hmob == 0) {
      write("not found\n");
    return 1;
}
   if (dmg == 0) {
    write("damage not set\n");
     return 1;
}
 if(dmg < 0) {
tell_object(hmob, "A giant hammer appears and hits you upside your head.\n" +
                "It really hurts.\n");
}
 if (dmg > 0) {
 tell_object(hmob, "Someone has healed you.\n");
 }
  write(dmg);
  write("\n");
call_other(hmob, "add_hit_point", dmg);
    write(str + " has been hammered.\n");
    return 1;
}
 dam(arg) {
   sscanf(arg, "%d", dmg);
    write("damage set to ");
    write(dmg);
    write("\n");
    return 1;
}
snow() {
  shout("You feel the air gat colder.\n");
 shout("The sky fills with clouds and it begins to snow.\n");
return 1;
}
 snp(str) {
   object plob;
      plob = find_living(str);
    call_other(plob, "set_wc", dmg);
   write(str + "\n");
  return 1;
}
aln(str) {
   object alob;
      write(str + "\n");
    alob = find_living(str);
     write(alob);
     write("\n");
  call_other(alob, "add_alignment", dmg);
  write(str + dmg + "alerted align\n");
  return 1;
}
sop(str) {
 object sopob;
 sopob = find_player(str);
  if(!sopob) {
  write("Player not found.\n");
  return 1;
 }
 write(sopob); write("\n");
 snoop(sopob);
 }
 que(str) {
     call_other(this_player(), "set_quest", str);
  return 1;
 }
