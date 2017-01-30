/*
 *  The gypsy ability to tell a fortune.  (v2.0)
 *
 */

tell_fortune(str)  {
  object ob;
  string fortune;
  int check, plevel, pac, pwc, m_stuff, p_stuff;

  if(!str) str = this_player()->query_real_name();

  ob = present(str, environment(TP));
  if(!ob)  ob = present(str, TP);
    if(!ob)  {
      write("How can you tell the fortune of something you can't see?\n");
      return 1;
        }

  if(!living(ob))  {
  if(ob->weapon_class() > 0)  {
    if(ob->weapon_class() > 15)  {
      fortune = "The cards reveal that this is a weapon of great power";  }
    if(ob->weapon_class() > 18)  {
      fortune = "The cards reveal that this is a weapon of legendary power";  }
    if(ob->weapon_class() > 9 && ob->weapon_class() < 16)  {
      fortune = "The cards reveal nothing special about this weapon";  }
    if(ob->weapon_class() < 10)  {
      fortune = "The cards reveal nothing auspicious about this weapon";  }
    check = 1;
        }
    if(ob->armor_class() > 0 || ob->armor_class() < 0)  {
    if((ob->armor_class() > 4) ||
    (ob->armor_class() > 1 && ob->query_type() != "armor"))  {
      fortune = "The cards reveal that this is armor of legendary power";  }
    else if(ob->armor_class() < 0)  {
      fortune = "The cards give an ominous message";  }
    else { fortune = "The cards reveal nothing special about this armor";  }
    check = 1;
        }
    if(check < 1)  {
      if(ob->query_value() > 800)  {
      fortune = "The cards reveal signs of wealth in your future";  }
      else { fortune = "The cards reveal nothing about the "+ob->short()+" ";  }
        }

    write("You deal out your illustrated cards as you look at "+ob->short()+".\n"+
      "\n"+fortune+".\n");
    say(tp+" looks at "+ob->short()+" as "+TP->query_pronoun()+" lays out "+GENDER+" illustrated cards.\n");
    return 1;
        }

  if(ob->is_player())  {
    int chance;
    chance = random(24);

  if(chance == 0)  fortune = "Your future is clouded.  This auguary can determine nothing...";
  if(chance == 1)  fortune = "Seek friends in unlikely places";
  if(chance == 2)  fortune = "Today is a good day for adventure";
  if(chance == 3)  fortune = "Keep vigil against misfortune due to carelessness";
  if(chance == 4)  fortune = "Your omens are auspicious.  Make the most of your day";
  if(chance == 5)  fortune = "The fates may be unfriendly.  Be careful";
  if(chance == 6)  fortune = "Keep company with your friends and avoid your enemies";
  if(chance == 7)  fortune = "Cut your loses and create your own destiny";
  if(chance == 8)  fortune = "Belief in yourself can help you overcome any obstacle";
  if(chance == 9)  fortune = "Remove all the stops and go wild.  It is your time";
  if(chance == 10) fortune = "Watch for those attempting to decieve you";
  if(chance == 11) fortune = "A quick wit may be mightier than a strong sword arm";
  if(chance == 12) fortune = "Wishes can come true, and dreams may happen.  Make the most of your chances";
  if(chance == 13) fortune = "Color coordination will bring you strength";
  if(chance == 14) fortune = "Today is a good day for travel and exploration";
  if(chance == 15) fortune = "When you hear the music, dance to your own tune";
  if(chance == 16) fortune = "Financial aid will come from those in positions of power";
  if(chance == 17) fortune = "A fresh start is your key to happiness";
  if(chance == 18) fortune = "Spend time with your friends.  They may not know it, but they need you";
  if(chance == 19) fortune = "To your own self be true.  The rest will follow";
  if(chance == 20) fortune = "The future can be now = plan for it";
  if(chance == 21) fortune = "Free yourself from preconceptions";
  if(chance == 22) fortune = "Unorthodox behavior may bring unexpected results";
  if(chance == 23) fortune = "It is time to approach that special person";

  if(ob->query_name() != this_player()->query_name())  {
      say(tp+" looks at "+ob->query_name()+" as "+TP->query_pronoun()+" lays out "+GENDER+" illustrated cards.\n");
      write("You deal out your illustrated cards as you look at "+ob->query_name()+".\n"+
      "\n"+ob->query_name()+"'s fortune is:\n"+fortune+".\n");
      tell_object(ob, "\n"+tp+" tells you that your fortune is:\n"+fortune+".\n");
  return 1;
        }
      say(tp+" deals out "+GENDER+" illustrated cards.\n");
    write("You deal out your illustrated cards.  Your fortune is:\n"+fortune+".\n");
    return 1;
        }

  if(!ob->is_player())  {
    plevel = TP->query_level();  pac = TP->query_ac();  pwc = TP->query_wc();
    p_stuff = plevel + pac + pwc;
    m_stuff = ob->query_wc() + ob->query_ac() + ob->query_level();

  if(p_stuff > m_stuff+20) fortune = "that this battle will hardly be a challenge";
  if(p_stuff>m_stuff+10 && p_stuff<m_stuff+21) fortune = "that this will be a very easy battle";
   if(p_stuff>m_stuff+5 && p_stuff<m_stuff+11)  fortune = "that this will be an easy battle";
  if(p_stuff>m_stuff && p_stuff<m_stuff+6)     fortune = "that you should triumph in this battle..";
  if(p_stuff+5>m_stuff && p_stuff<m_stuff+1)   fortune = "that this battle will be a well matched";
  if(p_stuff+10>m_stuff && p_stuff+6<m_stuff) fortune = "nothing.  They can not see the outcome";
    if(p_stuff+15>m_stuff && p_stuff+11<m_stuff) fortune = "that your battle omens are not auspicious";
  if(p_stuff+20>m_stuff && p_stuff+16<m_stuff) fortune = "that your death is near..";

    write("You deal out your illustrated cards as you look at "+ob->short()+".\n"+
      "\nThe cards tell you "+fortune+".\n");
    say(tp+" looks at "+ob->short()+" as "+TP->query_pronoun()+" lays out "+GENDER+" illustrated cards.\n");
    return 1;
        }

        }
