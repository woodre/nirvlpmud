/* alter.c - change physical attributes */
#define COST this_player()->query_msp()
#define GLEV 20
#define MUDLEV 15

void help() {
  write("]---------------> Coven Help <---------------[\n");
  write("Topic: Alter\n");
  write("Type: Sepll\n");
  write("Cost: "+COST+"sp\n");
  write("Level: "+GLEV+" guild, "+MUDLEV+"mud\n");
  write("Description: A master of the Art can change his or her physical\n");
  write("attributes, but only at great personal cost.  To do this, the\n");
  write("master must use \"alter sex\", \"alter race <human,dwarf,elf>\",\n");
  write("or alter <height,weight> <+,->.\n");
}

int main(string str) {
  object caster;
  string what,how;
  int oldf,oldi;
  caster=this_player();
  if(caster->query_level() < 15 || 
                    caster->query_guild_level() < 20) {
    notify_fail("You are not yet powerful enough to do this.\n");
    return 0;
  }
  if(caster->query_sp() < COST) {
    notify_fail("You lack the energy to do this.\n");
    return 0;
  }
  if(!str) {
    notify_fail("Alter what?\n");
    return 0;
  }
  if(str=="sex") what="sex";
  else if(sscanf(str,"%s %s",what,how) != 2) {
    notify_fail("Alter what?\n");
    return 0;
  }
  switch(what) {
    case "sex":
      caster->set_gender(
        (string)caster->query_gender()=="male"?"female":"male");
      break;
    case "race":
      if(member_array(how,({"human","dwarf","elf"}))==-1) {
        write(
"Not even your powers allow you to make that much of a change.\n");
        return 1;
      }
      caster->set_race(how);
      break;
    case "height":
      oldf=(int)caster->query_phys_attrib(1);
      oldi=(int)caster->query_phys_attrib(2);
      switch(how) {
        default:
          write("You may only alter height by + or -.\n");
          return 1;
        case "+":
          if(oldi<11)
            caster->add_phys_attrib(2,1);
          else
            if(oldf<7) /* can't pass 7' 11" */
              caster->add_phys_attrib(1,1);
            else {
              write(
"You have reached the greatest height possible for your powers.\n");
              return 1;
            }
          break;
        case "-":
          if(oldi>0)
            caster->add_phys_attrib(2,-1);
          else
            if(oldf>3) /* cant go lower than three feet */
              caster->add_phys_attrib(1,-1);
            else {
              write(
"Even a Master of the art can only become so short.\n");
              return 1;
            }
          break;
      }
      break;
    case "weight":
      if(present("fertility",caster)) {
        write(
"That is too dangerous and unpredictable to do while pregnant.\n");
        return 1;
      }
      if(how=="-") {
         if(caster->query_phys_attrib(3)>100)
          caster->add_phys_attrib(3,-1);
        else {
          write(
"Even a master of the art can only become so thin.\n");
          return 1;
        }
      } else if(how=="+") {
        if(caster->query_phys_attrib(3)<500)
          caster->add_phys_attrib(3,1);
        else {
          write(
"Even a master of the art can only expand so much.\n");
          return 1;
        }
      } else {
        write("You may only alter weight by \"+\" or \"-\".\n");
        return 1;
      }
      break;
    default:
      write(
"You may only alter sex, height, weight, and race.\n");
      return 1;
  }
  write("You draw deeply on your mastery of the Art, and the strength\n"+
        "within you.  Soon, you feel the black power seeping outward\n"+
        "from your heart, changing you, making you into something else.\n");
  say("A blackness of evil seems to surround "+caster->query_name()+
       ".\nThe feeling of blackness and power makes you shiver.\n");
  caster->add_spell_point(-((int)caster->query_msp()));
  return 1;
}
