/* made this Do something [5.31.01] - Vertebraker */
id(str) { return str == "orb" || str == "ebony orb"; }

short() {
   return "An Ebony Orb";
}

long() {
   write("A pulsing ebony orb, exuding evil!\n");
}

query_weight() {
   return 1;
}

query_value() {
   return 1000;
}

get() {
   return 1;
}

void
reset(status arg)
{
    if(arg) return;
    call_out("bada_bing", 666);
}

void
bada_bing()
{
    object e;
    if(!(e = environment()))
    {
      destruct(this_object());
      return;
    }
    if((status)e->is_player())
    {
      tell_object(e, "\
Evil floods into your soul.\n");
      e->add_alignment(-(111 + random(55)));
      if(0 == random(10))
        tell_object(e, "\
The Ebony Orb pulses darkly.\n");
    }

    call_out("bada_bing", 666);
}
