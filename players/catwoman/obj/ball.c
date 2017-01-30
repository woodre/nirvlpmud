#define CHARGES	3
/* added finite number of uses. -Bp
*/
int uses;
id(str) { return str=="ball"; }

short() { return "A crystal ball"; }

long() {
write("A magical crystal ball.  Type VIEW <item> to see information about\nthe wc or ac of an item.\n");
}
query_weight() { return 1; }
query_value()  { return 100; }
take() { return 1; }
get() { return 1; }

init() { add_action("ident","view"); }

ident(str)
{
   object ob;
   int ac;
   int wc;
    if(!str) {
      notify_fail("Identify what?\n");
      return 0;
    }

   ob = present(str,this_player());
   if(!ob) {
      notify_fail("You don't see that here.\n");
      return 0;
   }
   ac = ob->is_armor();
   wc = call_other(ob,"weapon_class");
   if(wc) {
      string damage;
	if (call_other(this_player(),"query_level") > 20) {
		write("WC = "+wc+"\n");
	}
      if(wc >= 19)
	 damage = "bone crushing";
      else
      if(wc >= 17)
         damage = "very serious";
      else
      if(wc >= 15)
	 damage = "serious";
      else
      if(wc >= 12)
	 damage = "above average";
      else
      if(wc >= 9)
	 damage = "average";
      else
      if(wc >= 6)
	 damage = "below average";
      else
      if(wc >= 3)
         damage = "hardly any";
       else
	 damage = "no";
       write("You could use it as a weapon that does " + damage +" damage.\n");
    }
    if(ac) {
       string protection;
       ac = ob->armor_class();
	if (call_other(this_player(),"query_level") > 20) {
		write("AC = "+ac+"\n");
	}
	if (ac > 7) 
	  protection = "illegal";
	else
	if (ac > 6)
	  protection = "ungodly";
	else
       if(ac > 5)
	 protection = "unbelievable";
       else
       if(ac == 5)
	 protection = "excellent";
       else
       if(ac == 4)
	 protection = "very good";
       else
       if(ac == 3)
	 protection = "good";
       else
       if(ac == 2)
	 protection = "fair";
       else
       if(ac == 1 || ac == 0)
	 protection = "some";
       else
	 protection = "no";

      write("If worn as armor this item would provide you with " +
	     protection + " protection.\n");
   }

      call_other(ob,"identify_string");

  if(!ac && !wc) write("This object would not be much use as a weapon or an armor.\n");
  uses += 1;
  if (uses > CHARGES) {
    write("The crystal ball crumbles into dust\n");
    destruct(this_object());
  }
       return 1;
/*        return ac || wc; */
}
query_save_flag() { return 1; }


