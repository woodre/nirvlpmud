inherit "room/room";
#include "../all.h"
#include "../misc/help.h"


#define GUILD (string)this_player()->query_guild_name() == "fallen"
#define NOGUILD (string)this_player()->query_guild_name() != "fallen"
#define GXP query_guild_exp()

int uncovered, *mag_cost, *set_cost, geeber, chh, y, z, guild_exp;
object circle;
string *peeps, *excluded, why;
object *touched;

void reset(int arg){
  if(arg) return;
  touched = ({});
  uncovered = 1;
  geeber = 0;
  set_cost = ({ 800000, 1600000, 2400000, 3200000, 4000000,
                4800000, 5600000, 6400000, 7200000, 8000000 });
  mag_cost = ({ 1000000, 2000000, 3000000, 4000000, 6000000, 8000000 });
  excluded = ({ "maledicta", "zeus", "zeustest", "cobaintest", });
  short_desc = "The Fallen Lands";
  set_light(0);
  dest_dir=({});
}

string short(){ return "The Fallen Lands"; }

void long(){
  if(!uncovered)
    write(
"You are standing in a very secluded part of the forest.  Directly to\n"+
"the south is a large rock covered by plants.  It seems to protrude\n"+
"from the ground like a giant dagger, with the side facing you being\n"+
"extremely flat.  Towering evergreen trees are all around you.  There\n"+
"is a small trail leading to the north that is the only way out.\n"+
"    No obvious exits.\n");
  else write(
"You are standing in a very secluded part of the forest.  Directly to\n"+
"the south is a large rock that is protrucing out of the ground like a\n"+
"giant dagger, with theside facing you being extremely flat.  Towering\n"+
"evergreen trees are all around you.  There is a small trail leading to\n"+
"the north that is the only way out.\n"+
"    No obvious exits.\n");
}

int query_touched(object me){
    if(!touched || !sizeof(touched)) return 0;
    if(member_array(me, touched) > -1) return 1;
    return 0;
}

int sub_touched(object me){
    if(query_touched(me)){
        touched -= ({ me });
        return 1;
    }
    return 0;
}

int add_touched(object me){
    if(!query_touched(me)){
        touched += ({ me });
        return 1;
    }
    return 0;
}

int check_touch(){
  if(query_touched(this_player())) return 1;
  else return 0;
}

void load_spells(object x){
  object y;
  if(!x) return 0;
  y = present("circle_object", x);
  if(y && (string)x->query_guild_name() == "fallen")
    y->load_spells();
}


int north_dir2(){
  write("You walk north...\n\n");
  this_player()->move_player("north#/players/guilds/fallen/rooms/path.c");
  if(query_touched(this_player())) sub_touched(this_player());
  return 1;
}

int read_cmd(string str){
  if(!uncovered) return 0;
  if(str == "writing"){
    write(
          "Within this circle we inscrible our ways...\n"+
          "our strengths and our weaknesses....\n"+
          "who we are...\n"+
          "\n"+
          "You may 'seek' more 'information'...\n"+
          "If you wish to follow this path,\n"+
          "you need only trace the symbols.\n");
    return 1;
  }
  return 0;
}

int uncover_cmd(string str){
  if(!str) return 0;
  if(str == "rock" || str == "stone" || str == "circle" || str == "rock face"){
    if(uncovered){
      write("The "+str+" is already uncovered.\n");
      return 1;
    }
    if(!uncovered){
      write(
        "You reach up and move the branches and plants away from the rock...\n"+
        "You reveal a large circle carved into the face of the rock.\n");
      say(TP->QN+" moves the plants aside.\n");
      uncovered = 1;
      return 1;
    }
    return 1;
  }
  else return 0;
  return 1;
}

status touch_cmd(string str){
  if(!str) return 0;
  if(!uncovered) return 0;
  if(str == "circle" || str == "the circle"){
    if(query_touched(this_player())){
      write("You are already touching the circle.\n");
     return 1;
    }
    write("You place your hand on the circle.\n");
    load_spells(TP);
    say(TP->QN+" places "+TP->POS+" hand on the circle.\n");
    add_touched(this_player());
  }
  else if(str == "1" || str == "symbol 1" && GUILD){
    cat("/players/guilds/fallen/misc/symbol1");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "2" || str == "symbol 2" && GUILD){
    cat("/players/guilds/fallen/misc/symbol2");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "3" || str == "symbol 3" && GUILD){
    cat("/players/guilds/fallen/misc/symbol3");
        say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "4" || str == "symbol 4" && GUILD){
    cat("/players/guilds/fallen/misc/symbol4");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "5" || str == "symbol 5" && GUILD){
    cat("/players/guilds/fallen/misc/symbol5");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "6" || str == "symbol 6" && GUILD){
    cat("/players/guilds/fallen/misc/symbol6");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "7" || str == "symbol 7" && GUILD){
    cat("/players/guilds/fallen/misc/symbol7");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else return 0;
  return 1;
}

status look_cmd(string str){
  if(!str) return 0;
  if(str == "at writing" || str == "writing"){
    if(uncovered){
      write(
"There is some writing engraved into the rock next to the circle\n"+
"which can be 'read'.\n");
      return 1;
    }
    else return 0;
  }
  if(str == "at circle" || str == "circle"){
    if(uncovered){
      write(
"Carved on the face of the rock is a large circle with many bizarre\n"+
"symbols engraved in and around it.  There is some writing to the\n"+
"right of the circle.\n");
      return 1;
    }
    else return 0;
  }
  if(str == "at symbols" || str == "symbols"){
    if(uncovered){
      write(
"There are many strange symbols engraved within and around the circle.\n"+
"Each one is very detailed and none of them look the same.  There is\n"+
"a row of them that run down the center of the symbol, plus six others\n"+
"that are larger than most of the others.  You can feel the power that\n"+
"resides within them.\n");
      return 1;
    }
  }
  if(str == "at rock" || str == "rock"){
    if(!uncovered){
      write(
"The large, dagger shaped rock is protruding out of the ground, pointing\n"+
"unnaturally at the sky.  The side facing north is very flat, and covered\n"+
"by plants.  You could uncover it to see the face of the rock.\n");
      return 1;
    }
    if(uncovered){
      write(
"The large, dagger shaped rock is protruding out of the ground, pointing\n"+
"unnaturally at the sky.  The side facing north is very flat, and not\n"+
"obstructed by anything.  A large circle is carved into the rocks face.\n");
      return 1;
    }
    return 1;
  }
  if(str == "at trees" || str == "trees"){
    write(
"Towering evergreen trees reach high into the sky all around you.\n"+
"Their branches fan out, blocking out all of the light.\n");
    return 1;
  }
  if(str == "at branches" || str == "branches"){
    write("The branches of the trees are blocking out all of the light.\n");
    return 1;
  }
  if(str == "at trail" || str == "trail"){
    write("A barely noticable trail leads to the north.\n");
    return 1;
  }
  else return 0;
}

int smear_cmd(string str){  /*  drop to level 17 */
  int newxp, newxp2;
  if(!uncovered) return 0;
  if(str != "blood on the circle") return 0;
  newxp = 1040028;  /* level 17 */
  write("You cut your hand and smear blood on the circle.\n"+
    "The circle begins to glow, lighting up the forest.\n\n"+
    "Suddenly you feel a wrenching deep down...\n"+
    "You may now read the incantation.\n\n");
  TP->set_level(17);
  TP->set_extra_level(0);
  if(TP->query_exp() > newxp){
    newxp2 = (int)this_player()->query_exp() - newxp;
    TP->add_exp(newxp2 * -1);
  }
  TP->save();
  TP->reset();
  write_file("/players/guilds/fallen/log/JOIN", ctime(time())+
    "   "+capitalize((string)TP->QRN)+" lost "+newxp2+
    " when "+TP->query_pronoun()+" joined.\n");
  return 1;
}

void randmsg(){
  int dogooder;
  dogooder = random(5);
  switch(dogooder){
    case 0:
      write(BOLD+
      "\n\tThe only true power comes from complete knowledge.\n\n"+NORM);
      break;
    case 1:
      write(BOLD+
      "\n\tKilling newbies will get you nowhere.\n\n"+NORM);
      break;
    case 2:
      write(BOLD+
      "\n\tTrue power comes with true bravery...  face your foes.\n\n"+NORM);
      break;
    case 3:
      write(BOLD+"\n\tStrength is but a tool of true power.\n\n"+NORM);
      break;
    case 4:
      write(BOLD+"\n\tAssert your bravery to overcome spell failure.\n\n"+NORM);
      break;
  }
}

int learn(string str){
  if(TP->query_level() < 21){
    write_file("/players/guilds/fallen/log/ADV", ctime(time())+
      " - "+capitalize((string)TP->QRN)+" lrnd "+str+"  [L "+
      TP->query_level()+"+"+TP->query_extra_level()+"] "+
      "gxp: "+circle->GXP+"\n");
  }
  write(
    "\n\tEnergy surges from the circle...\n"+
    "\tYou are filled with knowledge...\n"+
    "\tYou have learned the spell '"+str+"'...\n\n");
    present("circle_object", this_player())->set_skills(str);
    TP->save();
/*  Taking out for now, testing on LD requires it - Rumplemintz
    present("circle_object", this_player())->update_obj(1);
*/
    call_other(TP, "reset", 1);
    return 1;
}

int check(string str){  /* does this_player have str spell */
    if(!present("circle_object", this_player())) return 1;
    if(present("circle_object", this_player())->query_skills(str)) return 0;
    else return 1;
}

void stats(object bob){   /* If enough guild exp, increased mag, ste, end */
  int x,y,z,w;
  if(!bob) return;
  circle = present("circle_object", bob);
  if(!circle) return;
  /*  Set endurance to max - 8 mil gxp for max */
  y = (int)bob->query_level();
  w = (int)circle->query_guild_exp();
  if(y > 19) y = 19;
  if(w < 1000000){  /* mainly based on stealth, with level  [cap of 38] */
    x = 8 + (y / 2) + ((int)bob->query_attrib("ste") + (w / 100000));
    if(x > 38) x = 38;
  }
  else   /* mainly based on gxp, with stealth and level   [cap of 80] */
    x = y + (int)bob->query_attrib("ste") + (w / 195000);
  if(x < 25) x = 25;
  else if(x > 80) x = 80;
  if(x > circle->query_max_endurance()) circle->set_max_endurance(x);

/*  10.31.02 - COMMENTED OUT ATTRIB INCREASES DUE TO ATTRIB SYSTEM CHANGES
  if(bob->query_level() < 20){
    for(z = 0; z < 6; z++){
      if(bob->query_attrib("mag") == (20 + z)){
        if(circle->GXP >= mag_cost[z]){
          geeber = 1;
          bob->set_attrib("mag", (21 + z));
          tell_object(bob, "\tYour magic increases.\n");
        }
      }
    }
    for(z = 0; z < 10; z++){
      if(bob->query_attrib("ste") == (20 + z)){
        if(circle->GXP >= ste_cost[z]){
          geeber = 1;
          bob->set_attrib("ste", (21 + z));
          tell_object(bob, "\tYour stealth increases.\n");
        }
      }
    }
  }
  END 10.31.02 COMMENTS BY ZEUS  */

  if(circle->GXP >= 8000000){
    circle->set_guild_exp(8000000);
    circle->set_perc(0);
  }
}


int guilded(object guy){
  if(!guy) return 0;
  if((string)guy->query_guild_name() && (string)guy->query_guild_name() != "none") return 0;
  if(guy->query_guild_rank()) return 0;
  if(guy->query_guild_exp()) return 0;
  return 1;
}

int seek_cmd(string str){
  int x;
  if(!str) return 0;
  if(!uncovered) return 0;
  if(!query_touched(TP)){
    write("You are not touching the circle.\n");
    return 1;
  }
  circle = present("circle_object", TP);
  geeber = 0;
  if(TP->test_dark()) return 1;  /* no dark seek */
  if(str == "rules") cat("/players/guilds/fallen/misc/rules");
  else if(str == "story"){         /* info on area */
    write("You may seek the story of the following chapters...\n\n"+
      "    Chapter 1:  Conquest\n"+
      "    Chapter 2:  New Beginning\n"+
      "    Chapter 3:  Retaliation\n"+
      "    Chapter 4:  Conclusion\n"+
      "    Chapter 5:  The Circle today\n\n");
  }
  else if(str == "1" || str == "chapter 1" || str == "conquest")
    cat("/players/guilds/fallen/misc/chp1");
  else if(str == "2" || str == "chapter 2" || str == "new beginning")
    cat("/players/guilds/fallen/misc/chp2");
  else if(str == "3" || str == "chapter 3" || str == "retaliation")
    cat("/players/guilds/fallen/misc/chp3");
  else if(str == "4" || str == "chapter 4" || str == "conclusion")
    cat("/players/guilds/fallen/misc/chp4");
  else if(str == "5" || str == "chapter 5" || str == "the circle today")
    cat("/players/guilds/fallen/misc/chp5");
  else if(str == "information" || str == "info"){     /* info on guild */
    if(GUILD){
      write(
        "\n\n\t\tThe Fallen\n"+RED+
        " ********************************************************\n"+
        " *\t\t\t\t\t\t\t*\n"+
        " *  "+NORM+
        "seek power\t\tadvance your abilities"+RED+
        "\t\t*\n *  "+NORM+
        "seek knowledge\tknow of your abilities"+RED+
        "\t\t*\n *  "+NORM+
        "chelp\t\tbasic commands"+RED+
        "\t\t\t*\n *  "+NORM+
        "seek rules\t\tthe rules of the Fallen"+RED+
        "\t\t*\n *  "+NORM+
        "seek story\t\tthe history of the Fallen Lands"+RED+
        "\t*\n *  "+NORM+
        "touch symbol [1-7]\tthe wisdom of the Circle"+RED+
        "\t*\n *  "+NORM+
        "seek facts\t\tsee older news info"+RED+
        "\t\t*\n *  "+NORM+
        "seek masters\tsee the masters of the Circle"+RED+
        "\t*\n *  "+NORM+
        "free self\t\tleave this path"+RED+
        "\t\t\t*\n *\t\t\t\t\t\t\t*\n"+
        " ********************************************************\n"+NORM+
        "\n\n");
    }
    else if(NOGUILD) cat("/players/guilds/fallen/misc/info");
  }
  else if(str == "facts") cat("/players/guilds/fallen/misc/player_facts");
  else if(str == "masters"){
    peeps = get_dir("/players/guilds/fallen/circle_member/*.o");
    chh = sizeof(peeps);
    y = 0;
    write(RED+pad(" ", 26)+"Masters of the Circle\n"+NORM);
    for(z = 0; z < chh; z++){
      sscanf(peeps[z], "%s.", why);
      if(restore_object("players/guilds/fallen/circle_member/"+why)){
        if(guild_exp == 8000000 && index(excluded, why) < 0){
          y++;
          write(pad(" ",30)+y+pad(".",3)+capitalize(why)+"\n");
        }
      }
      why = 0;
    }
    write("\n");
    return 1;
  }
  else if(str == "knowledge"){         /* info on spells */
    if(GUILD && circle){
      write("These are your spells...\n\n");
      circle->tell_skills(1);
      write("You may 'seek' information on any of them.\n");
    }
    else if(GUILD && !circle){
      write("You lost your guild object!\n");
      MO(CO("/players/guilds/fallen/circle.c"), TP);
      command("restoreme", TP);
      if(TP->query_level() < 21){
        write_file("/players/guilds/fallen/log/restore", ctime(time())+
        "   "+capitalize((string)TP->QRN)+
        " restored guild obj from ghall.\n");
      }
    }
  }
  else if(str == "power"){      /* get new spells/stats */
    circle = present("circle_object", TP);
    if(NOGUILD && circle){
      if(TP->query_level() > 19){
        write("\nYou have the obj but not the name...\n"+
          "\t\tContact Zeus.\n\n");
        return 1;
      }
      return 1;
    }
    if(GUILD && !circle){
      write("You lost your guild object!\n");
      MO(CO("/players/guilds/fallen/circle.c"), TP);
      if(TP->query_level() < 21){
        write_file("/players/guilds/fallen/log/restore", ctime(time())+
          "   "+TP->QRN+" restored guild obj from ghall.\n");
      }
      return 1;
    }
    else if(GUILD && circle){
      if((int)TP->query_level() < 19){
        write_file("/players/guilds/fallen/log/EXP", ctime(time())+
          " - "+capitalize((string)TP->QRN)+"   gxp: "+circle->GXP+
          "   xp: "+TP->query_exp()+"\n");
      }
      else if((int)TP->query_level() == 19){
        write_file("/players/guilds/fallen/log/EXP_19", ctime(time())+
          " - "+capitalize((string)TP->QRN)+"   gxp: "+circle->GXP+
          "   xp: "+TP->query_exp()+"\n");
      }
      x = random(7);
      switch(x){
        case 0:
          write("You close your eyes and seek guidance from the circle.\n");
         break;
        case 1:
          write("You close your eyes and let the circle guide you.\n");
          break;
        case 2:
          write("You close your eyes and look within yourself.\n");
          break;
        case 3:
          write("You close your eyes and let the shadows guide you.\n");
          break;
        case 4:
          write("You close your eyes and allow the circle to guide"+
            " your mind.\n");
          break;
        case 5:
          write("You close your eyes as shadows drift around you.\n");
          break;
        case 6:
          write("You close your eyes as shadows rise up around you.\n");
          break;
      }
      stats(TP);
      if(circle->GXP >=0 && check("focus")) learn("focus");
      else if(circle->GXP >= 50000 && check("beckon shadows")) learn("beckon shadows");
      else if(circle->GXP >= 100000 && check("wither corpse")) learn("wither corpse");
      else if(circle->GXP >= 250000 && check("drain")) learn("drain");
      else if(circle->GXP >= 450000 && check("teleport")) learn("teleport");
      else if(circle->GXP >= 600000 && check("shield")) learn("shield");
      else if(circle->GXP >= 750000 && check("weaken")) learn("weaken");
      else if(circle->GXP >= 950000 && check("meditate")) learn("meditate");
      else if(circle->GXP >= 1200000 && check("web")) learn("web");
      else if(circle->GXP >= 1500000 && check("blast")) learn("blast");
      else if(circle->GXP >= 1800000 && check("empower")) learn("empower");
      else if(circle->GXP >= 1950000 && check("know") && TP->query_level() > 17)
        learn("know");
      else if(circle->GXP >= 2100000 && check("shadowform")) learn("shadowform");
      else if(circle->GXP >= 2400000 && check("descend")) learn("descend");
      else if(circle->GXP >= 2700000 && check("shadowcloak")) learn("shadowcloak");
      else if(circle->GXP >= 3000000 && check("dark assistance")) learn("dark assistance");
      else if(circle->GXP >= 3300000 && check("repulsion")) learn("repulsion");
      else if(circle->GXP >= 3600000 && check("vanish")) learn("vanish");
      else if(circle->GXP >= 3900000 && check("rage")) learn("rage");
      else if(circle->GXP >= 4300000 && check("dark prayer")) learn("dark prayer");
      else if(circle->GXP >= 5000000 && check("weave")) learn("weave");
      else if(circle->GXP >= 5500000 && check("see")) learn("see");
      else if(circle->GXP >= 6000000 && check("vigor")) learn("vigor");
      else if(circle->GXP >= 7000000 && check("embrace")) learn("embrace");
      else if(circle->GXP >= 8000000 && check("siphon")) learn("siphon");
      else if(!geeber){
        x = random(3);
        switch(x){
          case 0:
            write("You are not ready yet to advance your knowledge.\n");
            break;
          case 1:
            write("You open your eyes and feel the same.\n");
            break;
          case 2:
            write("You open your eyes and feel nothing new.\n");
            break;
        }
        if(!random(20)) randmsg();
      }
      circle = present("circle_object", TP);
      TP->save();
      circle->save_circle(1);
      /*  circle->update_obj(1); not necessary */
      call_other(TP, "reset", 1);
      return 1;
    }  /* end GUILD and circle */
    return 1;
  } /* end seek power */
  else if(circle && !check(str)) info(str);
  else return 0;
  return 1;
}




void join2(object x){
  tell_object(x,
    "\nYou slowly drag your finger over the symbols in the circle...\n"+
    "You feel a strange force guiding your finger over them...\n");
  tell_room(environment(x), x->QN+
    " continues to trace the symbols...\n", ({ x }));
}

void join3(object x){
  if(!random(2)){
    tell_object(x,
    "\nAs you reach the last symbol a gust of wind blows through the trees.\n");
  tell_room(environment(x), "As "+x->QN+" reaches the last symbol "+
    "a gust of wind blows through the trees.\n", ({ x }));
  }
  else {
    tell_object(x,
    "\nAs you reach the last symbol, a noise off in the forest is heard.\n");
  tell_room(environment(x), "You hear a noise off in the forest.\n", ({ x }));
  }
}

void join4(object x){
  tell_room(environment(x),
    "\nThe symbols of the circle begin to glow a soft bluish hue...\n");
}

void join5(object x){
  tell_object(x,
    "\nYou close your eyes....\n"+
    "You can feel something deep down inside you...  ");
  if(x->query_alignment() > 0) tell_object(x, "warmth...\n");
  else if(x->query_alignment() < 0) tell_object(x, "so cold...\n");
  else tell_object(x, "unknown...\n");
  tell_room(environment(x), x->QN+" closes "+x->POS+" eyes.\n", ({ x }));
}

void join6(object x){
  tell_object(x,
    "\nThe sensation slowly spreads throughout your body...\n");
  if(x->query_alignment() > 0){
    tell_object(x, "You are engulfed from within by warmth \n");
    if((int)x->query_level() != 30){
      x->add_alignment((int)x->query_alignment() * 2 /
      (30 - (int)x->query_level()) + (1400));
    }
    x->heal_self(400);  /* free heal for good players */
  }
  else if(x->query_alignment() < 0){
    tell_object(x, "You are engulfed from within by the coldness \n");
    if((int)x->query_level() != 30){
      x->add_alignment((int)x->query_alignment() * 2 /
      (30 - (int)x->query_level()) - (1400));
    }
  }
  else
    tell_object(x, "You are immersed in the power of the circle.\n");
  tell_room(environment(x), "The circle continues to glow...\n", ({ x }));
}

void join7(object x){
  object circle;
  tell_object(x,
    "\nAs you open your eyes, you can feel a connection with the circle...\n"+
    "The glow slowly fades as you finish tracing the last symbol.\n"+
    "\n\n\nYou may wish to 'seek information' again.\n\n");
  tell_room(environment(x),
    x->QN+" opens "+x->POS+" eyes...\n"+
    "As "+x->QN+" finishes tracing the symbols, the glow slowly fades.\n",
    ({ x }));
  x->set_guild_name("fallen");
  x->save_me();
  x->reset();
  circle = clone_object("/players/guilds/fallen/circle.c");
  move_object(circle, x);
  circle->set_perc(20);
  circle->set_end_mon(1);
  stats(x);
  x->save();
  circle = present("circle_object", x);
  circle->update_obj(1, x);
  call_other(x, "reset", 1);
}

int trace_cmd(string str){                 /* to join guild */
  if(!uncovered) return 0;
  if(str == "symbols" || str == "the symbols"){
    if(!query_touched(TP)){
      write("You are not touching the circle.\n");
      return 1;
    }
    if(!guilded(TP)){                  /* are you guilded */
      write("You trace your finger along the symbols but nothing happens.\n"+
        "You still feel an allegiance to another guild.\n");
      return 1;
    }
    if(TP->query_level() < 10){        /* min level check */
      write("You trace your finger along the symbols but nothing happens.\n"+
        "You must be at least level 10 to begin.\n");
      return 1;
    }
/*
    if(TP->query_level() > 17)                          /* max level check /*
    {
      write("You trace your finger along the symbols but nothing happens.\n"+
        "You cannot exceed level 17 to begin.\n"+
        "If you wish to become level 17 you may:\n"+
        "  'smear blood on the circle'\n");
      return 1;
    }
    if(TP->query_exp() > 1367106)
    {
      int xp_dif;
      xp_dif = (int)TP->query_exp() - 1367106;
      write("Your experience has been lowered so that you may join.\n");
      TP->add_exp((int)TP->query_exp() - xp_dif);
      write_file("/players/guilds/fallen/log/JOIN", ctime(time())+
        "   "+capitalize((string)TP->QRN)+" lost "+xp_dif+
        " when "+TP->query_pronoun()+" joined.\n");
    }
*/
    /* miniguild checks */
    if(present("blade_obj", TP)) command("break_knife", TP);
    if(present("feline_obj", TP)) command("i_am_no_feline", TP);
    if(present("gothic_obj", TP)) command("i_am_no_goth", TP);
    if(present("gypsy_obj", TP)) command("i_am_no_gypsy", TP);
    if(present("kender_obj", TP)) command("i_am_no_kender", TP);
    if(present("larn_obj", TP)) command("abandon_larn", TP);
    if(present("succubus_obj", TP)) command("i_am_no_succubus", TP);
    say(TP->QN+" starts tracing "+TP->POS+" finger along the symbols...\n");
    write("\n\nYou begin to trace your finger along the symbols...\n");
    call_out("join2", 6, this_player());
    call_out("join3", 12, this_player());
    call_out("join4", 18, this_player());
    call_out("join5", 24, this_player());
    call_out("join6", 32, this_player());
    call_out("join7", 40, this_player());
    write_file("/players/guilds/fallen/log/JOIN", ctime(time())+
      " - "+capitalize((string)TP->QRN)+" [L "+
      TP->query_level()+"] joined.\n");

    return 1;
  }
  return 0;
}

int free_cmd(string str){
  int gexp, grank;
  object circle;
  if(!str) return 0;
  if(NOGUILD) return 0;
  if(!uncovered) return 0;
  if(str == "sparks"){
    if((string)TP->QRN != "sparks") return 0;
    write("sparks-----\n");
      write_file("/players/guilds/fallen/log/LEAVE", ctime(time())+
        "   "+capitalize((string)TP->QRN)+" [L "+
        TP->query_level()+"+"+TP->query_extra_level()+"] - errored\n");
      rm("/players/guilds/fallen/circle_member/"+TP->QRN+".o");
      TP->set_home(0);
      TP->set_guild_name(0);
      TP->set_guild_file(0);
      TP->set_home("/room/church");
      command("save",TP);
      circle = present("circle_object", TP);
      if(!circle){ write("------done w/o gob\n"); return 1; }
      else destruct(circle);
      write("------done w/ gob\n");
      return 1;
  }
  if(str == "self"){
    if(!query_touched(TP)){
      write("You must be touching the circle.\n");
      return 1;
    }
    say(TP->QN+" is struck down by the force of the circle.\n");
    write("You forsake your chosen path...\n"+
      "You feel a strong pain shoot through your body...\n"+
      "You are left lying on the ground, writhing in pain...\n"+
      "But you gain your freedom...\n\n");
    sub_touched(TP);
    if(TP->query_level() < 20){
      circle = present("circle_object", TP);
      if(!circle) return 0;
      write_file("/players/guilds/fallen/log/LEAVE", ctime(time())+
        "   "+capitalize((string)TP->QRN)+" [L "+
        TP->query_level()+"+"+TP->query_extra_level()+"]  Gxp: "+
        circle->GXP+"\n");
      rm("/players/guilds/fallen/circle_member/"+TP->QRN+".o");
      TP->set_home(0);
      TP->set_guild_name(0);
      gexp = (int)TP->query_guild_exp();
      grank = (int)TP->query_guild_rank();
      TP->add_guild_rank(-grank);
      TP->add_guild_exp(-gexp);
      TP->set_guild_file(0);
      TP->set_attrib("mag", 1);
      TP->set_attrib("ste", 1);
      destruct(circle);
      TP->set_home("/room/church");
      command("save",TP);
      TP->heal_self(-666);
      TP->hit_player(666);
      return 1;
    }
    else {
      write("Don't be such a... player!\n");
      return 1;
    }
    return 1;
  }
  else return 0;
  return 1;
}

void init(){
  ::init();
  if(this_player()) check_touch();
  add_action("north_dir2",  "north");
  add_action("look_cmd",  "look");
  add_action("look_cmd",  "l");
  add_action("look_cmd",  "exa");
  add_action("look_cmd",  "examine");
  add_action("uncover_cmd", "uncover");
  add_action("read_cmd",  "read");
  add_action("touch_cmd", "touch");
  add_action("trace_cmd", "trace");
  add_action("free_cmd",  "free");
  add_action("seek_cmd",  "seek");
  add_action("smear_cmd", "smear");
}

int exit(){ if(this_player()) this_player()->clear_fight_area(); }
string realm(){ return "NT"; }
int okay_follow(){ return 1; }
