/* New emotions and speach for the Bards. */

#define tp this_player()->query_name()

/* A new say.  Note that it uses :, so that player do not HAVE to use this.
   This is not for wiz pts, I just don't like the way that say looks now.
*/
new_say(str)  {
string message;
  if(!str || sscanf(str, "%s", message) != 1)  {
    write("What would you like to say?\n");
    return 1;
        }
  else if(sscanf(str, "%s!!!", message))  {
    write("You yell \""+str+"\"\n");
    say(tp+" yells \""+str+"\"\n");
    return 1;
        }
  else if(sscanf(str, "%s!", message))  {
    write("You exclaim \""+str+"\"\n");
    say(tp+" exclaims \""+str+"\"\n");
    return 1;
        }
  else if(sscanf(str, "%s???", message))  {
    write("You wonder \""+str+"\"\n");
    say(tp+" wonders \""+str+"\"\n");
    return 1;
        }
  else if(sscanf(str, "%s?", message))  {
    write("You ask \""+str+"\"\n");
    say(tp+" asks \""+str+"\"\n");
    return 1;
        }
  else if(sscanf(str, "%s", message))  {
    write("You say \""+str+"\"\n");
    say(tp+" says \""+str+"\"\n");
    return 1;
        }
  else  {
    write("ERROR - TELL SABER\n");
    return 1;
        }
        }

juggle()  {
  write("You conjure four balls of pastel colored light and deftly\n"+
     "juggle them between your hands.\n");
  say(tp+" conjures four balls of pastel colored light and proceeds\n"+
     "to deftly juggle them between "+TP->query_possessive()+" hands.\n");
  return 1;
        }

juggle2()  {
  write("You lazily juggle four balls of colored light with one hand.\n");
  say(tp+" lazily juggles four balls of colored light with one hand.\n");
  return 1;
        }

scarf(str)  {
object ob;
 if(!str)  {
  write("You conjure a scarf from thin air.\n"+
     "  Aren't hidden pockets wonderful?\n");
  say(tp+" conjures a scarf from thin air.\n");
  return 1;
        }
 ob = present(str,ENV);
  if(!ob)  {
    write(CAP+" is not here.\n");
    return 1;
        }
  write("You conjure a scarf from behind "+CAP+"'s ear.\n"+
     "  Aren't hidden pockets wonderful?\n");
  say(tp+" conjures a scarf from behind "+CAP+"'s ear.  Wow!\n",ob);
  tell_object(ob, tp+" conjures a scarf from behind your ear.\n"+
     "  Hay, where did that come from?\n");
  return 1;
        }

blueli(str)  {
object ob;
 if(!str)  {
  write("You briefly surround yourself with an aura of blue magic.\n");
  say(tp+" surrounds "+TP->query_objective()+"self with an aura of sinister blue magic.\n");
  return 1;
        }
 ob = present(str,ENV);
  if(!ob)  {
    write(CAP+" is not here right now.\n");
    return 1;
        }
  write("You point at "+CAP+", surrounding "+ob->query_objective()+" with an aura of pulsating blue magic.\n");
  say(tp+" points at "+CAP+", surrounding "+ob->query_objective()+" with an aura of pulsating blue magic.\n",ob);
  tell_object(ob, tp+" points at you, surrounding you with an aura of pulsating blue magic.\n"+
     "You feel different.\n");
  return 1;
        }

disappear(str)  {
object ob;
 if(!str)  {
  write("Muttering a brief incantation, you momentarily cloak yourself in invisibility.\n");
  say(tp+" disappears in a puff of smoke.\n");
  return 1;
        }
  ob = present(str,ENV);
  if(!ob)  {
    write("Who do you want to make disappear?\n");
    return 1;
        }
  write("You incant sharply and point at "+CAP+", binding "+ob->query_objective()+"\n"+
     "with a momentary cloak of invisibility.\n");
  say(tp+" incants sharply and points at "+CAP+", causing "+ob->query_objective()+" to\n"+
     "disappear in a puff of blue smoke.\n",ob);
  tell_object(ob, tp+" incants sharply and points at you.\n"+
     "You disappear in a puff of blue smoke.\n");
  return 1;
        }

sing1(str)  {
object ob;
  if(!str)  {
  write("You sing part of an old Irish love ballad.\n");
  say(tp+" sings part of an old Irish love ballad.\n"+
    "  You covertly wipe away a single tear.\n");
  return 1;
        }
  ob = present(str,ENV);
    if(!ob)  {
    write(CAP+" is not here to sing to.\n");
    return 1;
        }
  write("You sing "+CAP+" part of an old Irish love ballad.\n");
  say(tp+" sings "+CAP+" part of an old Irish love ballad.\n"+
    "  You covertly wipe away a single tear.\n",ob);
  tell_object(ob, tp+" sings you part of an old Irish love ballad.\n"+
    "  Your heart fills with longing.\n");
  return 1;
        }

sing2()  {
  write("You chant part of an old Irish battle song.\n"+
    "  You feel your blood stir and pulse quicken!\n");
  say(tp+" chants part of an old Irish battle song.\n"+
    "  You feel your blood stir and pulse quicken!\n");
  return 1;
        }

holo(str)  {
object ob;
  if(!str)  {
  write("You look up with dark holocaust eyes.\n");
  say(tp+" looks up with dark holocaust eyes.\n");
  return 1;
        }
  ob = present(str,ENV);
    if(!ob)  {
    write(CAP+" is not here to look at.\n");
    return 1;
        }
  write("You look up at "+CAP+" with dark holocaust eyes.\n");
  say(tp+" looks up at "+CAP+" with dark holocaust eyes.\n",ob);
  tell_object(ob, tp+" looks up at you with dark holocaust eyes.\n");
  return 1;
        }

strings()  {
  write("You lightly strum the strings of your instrument.\n"+
    "  The image of a melody dances through your mind.\n");
  say(tp+" lightly strums the strings of "+TP->query_possessive()+" "+TO->query_instrument()+".\n"+
    "  The image of a melody dances through your mind.\n");
  return 1;
        }

clearth()  {
  write("You clear your throat loudly.\n");
  say(tp+" clears "+TP->query_possessive()+" throat with a loud sound.\n"+
    "  You think "+TP->query_pronoun()+" must have something important to say.\n");
  return 1;
        }

tune()  {
  write("You absently tune your "+TO->query_instrument()+"\n");
  say(tp+" tunes "+TP->query_possessive()+" "+TO->query_instrument()+".\n");
  return 1;
        }

sparkle(str)  {
object ob;
  if(!str)  {
  write("You look up with a sparkle in your eyes.\n");
  say(tp+" looks up with a sparkle in "+TP->query_possessive()+" eyes.\n");
  return 1;
        }
  ob = present(str,ENV);
    if(!ob)  {
    write(CAP+" is not here to look at.\n");
    return 1;
        }
  write("You look up at "+CAP+" with a sparkle in your eyes.\n");
  say(tp+" looks up at "+CAP+" with a sparkle in "+TP-query_possessive()+" eyes.\n",ob);
  tell_object(ob, tp+" looks up at you with a sparkle in "+TP->query_possessive()+" eyes.\n");
  return 1;
        }

bows(str)  {
object ob;
  if(!str)  {
  write("You make an elaborate bow.\n");
  say(tp+" makes an elaborate bow.\n");
  return 1;
        }
  ob = present(str,ENV);
    if(!ob)  {
    write(CAP+" is not here to bow to.\n");
    return 1;
        }
  write("You make an elaborate bow to "+CAP+".\n");
  say(tp+" makes an elaborate bow to "+CAP+".\n");
  return 1;
        }

handkiss(str)  {
object ob;
  if(!str)  {
  write("Whose hand do you want to kiss?\n");
  return 1;
        }
  ob = present(str,ENV);
    if(!ob)  {
    write(CAP+" is not here to have their hand kissed.\n");
    return 1;
        }
  write("Bowing slightly, you kiss "+CAP+"'s hand.\n");
  say(tp+" bows slightly, takes the hand of "+CAP+" and kisses it lightly.\n",ob);
  tell_object(ob, tp+" bows slightly, takes your hand and kisses it lightly.\n");
  return 1;
        }

