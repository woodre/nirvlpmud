inherit "obj/treasure.c";

#define tp this_player()
#define tpname tp->query_name()

init()
{
   ::init();
   add_action("deliver","deliver");
   add_action("select","choose");
   add_action("select","select");
   add_action("select","eat");
}

reset(arg)
{
   if(!arg) {
      set_id("box");
      set_alias("chocolates");
      set_short("A box of delicious Belgian chocolates");
      set_long("This is a box filled with the most delicious assortment of chocolates that you\n"+
         "have ever seen.  They look simply delicious, and your mouth is watering just to\n"+
         "look at them.  Why don't you 'choose' one?\n"+
         "You can send them to someone by courier too.  Type 'deliver <player>'.\n");
      set_weight(1);
      set_value(250);
   }
}

query_price() { return 250; }

select(str)
{
   if(!str || (str!="chocolate" && str!="choc")) return 0;
   if(random(tp->query_attrib("luc"))<=5)
      {
      write("As you open the box, a pin is pulled from an intricate circuit set into the\n");
      write("base of the box.  The pin was maintaining an electrical contact which is now\n");
      write("broken.  Electrons stop flowing around this part of the circuit, and the drop\n");
      write("in current sets up a magnetic flux through the axis of the IC board.  A\n");
      write("sensitive magnetometer detects this change, and reconverts it into current.\n");
      write("This new flow of electrons is channeled through a very thin magnesium-alloy\n");
      write("filament, which is encased in semtex, a light, pliable, but highly explosive\n");
      write("compound, developped by the Czech military during the cold war.  The filament\n");
      write("is vaporized instantly, and the heat produced triggers an accelerating chemical\n");
      write("chain reaction in the semtex.  The semtex immediately surrounding the filament\n");
      write("heats up to its point of decomposition, and then is broken down into its\n");
      write("constituent atoms.  These rapidly recombine to reach a state of minimum\n");
      write("potential energy.  The energy from the bonds broken in this process is freed\n");
      write("mostly as heat energy, which then feeds a similar reaction in more of the\n");
      write("semtex.  Eventually, within about 1/500th of a second, the entire box is turned\n");
      write("into carbon dioxide, water, and a trace of phosphorous pentoxide.  And lots of\n");
      write("free energy.  It is this energy that causes most of the damage.  It burns all\n");
      write("of your clothing off, as well as most of your skin, and melts your ears.  It\n");
      write("also heats the air around it, causing it to expand in a pressure wave, which\n");
      write("slams against your eardrums, deafening you.\n");
      write("You have set off a candygram bomb, in case you didn't suss that out.\n");
      write("You are in very bad shape, and your hair is a real mess.\n");
      say(tpname+" opens a box of candy, and it explodes.\n");
      destruct(this_object());
      return 1;
   }
   write("You open the box and pull out "+choice()+".\n");
   write("You pop it into your mouth, and it melts deliciously as you bite into it.\n");
   return 1;
}

choice()
{
   int i;
   
   i=random(8);
   if(i==0) return "a light truffle";
   else if(i==1) return "a rich truffle";
   else if(i==2) return "a praline";
   else if(i==3) return "a chocolate liqueur";
   else if(i==4) return "a dark toffee almond crunch";
   else if(i==5) return "a chewy caramel";
   else if(i==6) return "a chocolate cream";
   else if(i==7) return "a coffee cream";
}

deliver(str)
{
   object target;
   
   if(!(target=find_player(str)))
      {
      write("Sorry, that player is not on at the moment.\n");
      return 1;
   } else if(tp->query_money() < 50)
      {
      write("Sorry!  You have insufficient funds to pay the delivery boy!");
      return 1;
   }
   write("A man in a uniform appears, and takes the box from you.\n");
   write("You tip him 50 coins, and he runs off smiling.\n");
   tell_room(environment(target),"A man dressed in a silly uniform walks into the room.\n");
   tell_room(environment(target),"He says: 'Candygram!  Candygram for "+target->query_name()+"!'\n");
   tell_object(target,"He hands you a box, and runs off.\n");
   move_object(this_object(),target);
   tp->add_money(-50);
   return 1;
}
