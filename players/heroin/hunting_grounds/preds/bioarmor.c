inherit "obj/armor";

reset(arg)
{
::reset(arg) ;
set_short("Biomechanical armor");
set_long("This armor is made of an unknown substance.  However, you\n"+
"are fairly confident that it is semi-organic.  The armor seems to\n"+
"conform to the body of the owner.  If you wear it, You better hope\n"+
"that you can control it.\n");
set_ac(4);
/* insert by mizan (AC 4++ armors need to be cleared by sandman... if you
  did already, sorry for the inconvenience, you set back to ac5. */
set_weight(3);
/* Changed value from 20,000 to 800. These are found on weak monsters and
 * a 20k value is extremely unreasonable. - Snow */
set_value(800);
set_alias("Biomechanical armor");
set_name("Biomechanical armor");
set_type("armor");
}

query_save_flag() { return 0; }
