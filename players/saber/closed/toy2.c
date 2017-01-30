id(str) {return str == "jacket"; }
short() {return "A leather jacket";}
   long() { write (
       "A black leather jacket worn by the infamous Saber\n");
      }
   get() { return 1; }
   query_weight() { return 0; }
   query_value() { return 0; }
drop() {return 1;}

 /*
   object user;
   user = this_player()->query_real_name();
   if(!("user"=="saber")) {
       write("You cannot use this!\n");
*/
init() {
if(((this_player()->query_real_name())=="saber" || (this_player()->query_real_name()) == "trump")) {
    add_action( "eye_gleam", "gleam");
   add_action( "sparkle", "sparkle");
    add_action( "lick_lips", "lips");
   add_action( "eyebrow_arch", "arch");
   add_action( "rogue_smile", "smiles");
   add_action( "holocaust_eyes", "eyess");
   add_action( "elaborate_bow", "bows");
   add_action( "boogs_and_froogs", "boogs");
   add_action( "axp","axp");
   add_action ( "light_cigarette", "lite");
   add_action ( "identify_object","iden" );
   add_action( "bring_player", "bringto");
   add_action ( "bring_player", "bring");
   add_action ( "power_get", "get!");
   add_action ( "power_drop", "drop!");
   add_action( "goin", "goin");
   add_action ("money", "money");
   add_action ("echo_to", "echoto");
   add_action ( "dungeon_player", "dun");
   add_action ( "church_player", "chr");
   add_action ("echo_all", "echoall");
   add_action ("echor", "echor");
   add_action ("no_fight", "no");
   add_action ("force", "force");
   add_action("gst", "gst");
   add_action ("rgst", "rgst");
}
}
no_fight() {
 object ob;
   ob=first_inventory(environment(this_player()));
    while (ob) {
if (living(ob)) {
if (ob->query_attack()) {
(ob->query_attack())->stop_fight();
  ob->stop_fight();
}
}
ob = next_inventory(ob);
}
write("You raise a hand, and the fighting stops.\n");
say(this_player()->query_name()+" raises a hand, and the fighting stops.\n");
return 1;
}
static echor(str) {
   if (!str) {
    write ("Echo what?\n");
return 1;
}
  say (str + "\n");
   write ("You echo: "+str+" \n");
return 1;
}
power_get(str) {
  object ob;
  if(!str) return 0;
  ob = present(str,environment (this_player()));
   if(!ob) {
     write ("No "+str+" here.\n");
     return 1;
}
write ("You take: "+ob->short() + ".\n");
move_object(ob,this_player());
return 1;
}
/*power_drop(str) {
  object ob;
   if (!str) return 0;
   ob=present(str,this_player());
   if (!ob) {
       write ("You dont have a "+str+" .\n");
return 1;
}
write ("You drop "ob->short() + ".\n");
move_object(ob,environment(this_player()));
return 1;
*/
goin (string str) {
   object retard;
retard=find_player(str);
    if (!retard) return 0;
  move_object (this_player(), retard);
return 1;
}
money(str) {
 int x;
  if (!str) return 0;
   if (sscanf(str,"%d", x) != 1) {
       write ("snytax: money <amount> \n");
return 1;
}
   this_player()-> add_money(x);
       write("Adding "+x+" coins.\n");
return 1;
}
static echo_to(str)
{
       object ob;
       string who;
       string msg;
   if (!str || sscanf(str, "%s %s", who, msg) != 2) {
       write("Echoto what ?\n");
        return 1;
}
ob = find_living(lower_case(who));
  if (!ob) {
      write("no player with that name.\n");
       return 1;
}
tell_object(ob, msg + "\n");
write ("you echo: " + msg + "\n");
return 1;
}
static echo_all(str) {
       if (!str) {
        write("Echoall what?\n");
        return 1;
}
shout(str + "\n");
write ("You echo: " + str + "\n");
return 1;
}
light_cigarette() {
   write("You light a cigarette.\n");
say("Saber lights a cigarette.\n");
   return 1;}

bring_player(str) {
   object ob;
   string bye, there;

if(!str) return 0;
    ob = find_player(str);
   if(!ob) ob=find_living(str);
   if(!ob) {
   write (capitalize(str) + "is not online at this time.\n");
       return 1;
      }
    there = environment(ob);
 tell_object(ob, "Without warning you are covered in a blue aura...\n" +
       "You feel your stomach wince as you are moved through reality...\n" +
      "You have arrived somewhere new...\n");
   move_object(ob, environment(this_player()));
    say (capitalize(str) + " materializes in a aura of blue power.\n");
    write (capitalize(str) + " answers your summons.\n");
    return 1;
}

dungeon_player(str) {
   object ob;
   string bye, there;

if(!str) return 0;
    ob = find_player(str);
    if(!ob) ob=find_living(str);
    if(!ob) {
    write (capitalize(str) + "is not online at this time.\n");
    return 1;
}
   there = environment(ob);
   tell_object(ob,"You are imprisoned "+ capitalize(str)+".\n");
   move_object(ob, "players/hawkeye/dungeon.c");
   tell_room(there, capitalize(str) +
      " is taken away.\n");
   write (capitalize(str) + " is imprisoned.\n");
   return 1;
}

church_player(str) {
   object ob;
   string bye, there;

if(!str) return 0;
    ob = find_player(str);
    if(!ob) ob=find_living(str);
    if(!ob) {
    write (capitalize(str) + "is not online at this time.\n");
    return 1;
}
   there = environment(ob);
   tell_object(ob,"You are escorted to the church.\n");
   move_object(ob, "room/church");
   tell_room(there, capitalize(str) +
      " is escorted to the church.\n");
   write (capitalize(str) + " is escorted to the church.\n");
   return 1;
}

identify_object(str) {
object ob;
   if(!environment(this_player())) {
      write("You must get it first.\n");
      return 1;
   }
   ob = player_inventory(str);
   if(!ob) {
      write("That is not in your inventory.\n");
      return 1;
   }
   if(ob) {
      write("You cast an identify spell...\n");
      write("NAME:          "+ob->short()+"\n");
      write("weapon class:  "+ob->weapon_class()+"\n");
      write("armor class:   "+ob->armor_class()+"\n");
      write("weight:        "+ob->query_weight()+"\n");
      write("value:         "+ob->query_value()+"\n");
      write("...and the scroll vanishes!\n");
      destruct(this_object());
      return 1;
   }
}
player_inventory(str) {
object ob;
   if(!str) return 0;
   ob = first_inventory(this_player());
   while(ob) {
      if (call_other(ob, "id", str)) return ob;
      ob = next_inventory(ob);
   }
   return 0;
}
axp(str) {
   string name;
   int num;
   object who;
   if(sscanf(str,"%s %d",name,num)!=2) return write("huh?\n");
   if(!name) {
   write("huh?\n");
   return 1;
   }
   if(!num) {
   write("huh?\n");
   return 1;
   }
   who = find_player(name);
   if(!who) {
write("He ain't here Saber.");
   }
   who->add_exp(num);
   write("Done\n");
   return 1;
}
force (str) {
    object player;
      string name,cmd;
if (!str) return 0;
if ((sscanf (str,"%s %s",name,cmd))<2) return 0;
   player=find_living(name);
 if (!player) { write ( capitalize(name) + "is not online. \n");
}
command(cmd,player);
return 1;
}

gst(str) {
   object ghob;
   ghob = find_living(str);
   call_other(ghob, "second_life", 0);
   write(str + " is now a ghost.\n");
   return 1;
}
rgst(str) {
   object ghob;
   string gstof;
   gstof = "ghost of " + str;
   ghob = find_player(gstof);
    /* tell_object(ghob, "\n\n\n" +
     "You feel a very strong force.\n" +
     "You are sucked away...\n" +
     "You reappear in a more solid form.\n");*/
   write(str + " is no longer a ghost.\n");
   return call_other(ghob, "remove_ghost", 0);
}

boogs_and_froogs() {
    write("You boog and froog and get funky.\n");
   say("Saber boogs and froogs and gets funky.\n");
   return 1;}

eye_gleam() {
write("You gaze about the room.\n\n" +
      "Your eyes gleam\n");
say("Saber gazes across the room.\n\n" +
    "His eyes gleam\n");
    return 1;}

sparkle() {
    write("You look up with a sparkle in your eyes.\n");
    say("Saber looks up with a sparkle in his eyes.\n");
    return 1;}

lick_lips() {
    write("You licks your lips, running your tongue over sharp white fangs.\n");
    say("Saber licks his lips, running his tongue over sharp white fangs.\n");
    return 1;}

eyebrow_arch() {
    write("You arch an eyebrow.\n");
    say("Saber arches an eyebrow.\n");
    return 1;}

rogue_smile() {
write("You smile like the rogue that you are.\n");
    say("Saber smiles like the rogue that he is.\n");
    return 1;}

holocaust_eyes() {
    write("You look up with dark holocaust eyes.\n");
    say("Saber looks up at you with dark holocaust eyes.\n");
    return 1;}

elaborate_bow() {
    write("You make an elaborate bow.\n");
    say("Saber makes an elavorate bow to you.\n");
    return 1;}

hand_kiss() {
    write("You kiss her hand.\n");
    say("Saber bows slightly, takes the hand of");
    return 1;}

