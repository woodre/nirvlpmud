tango(str) {
   object partner;
   string name;
   if (!str) return "It takes TWO to tango! ;)\n";
   partner = present(str,HERE);
   name = capitalize(str);
   if((!partner)||(partner==USER)||(!(call_other(partner,"is_player")))) {
      write("It takes TWO to tango! ;)\n");
      return 1;
      }
   write(
   "You place your rose seductively between your teeth, and lead "+
   name+" in\nan arduous tango!\n"
   );
   say(NAME+" places "+POS+" rose seductively between "+POS+" teeth, "+
   NAME+"places "+POS+" rose seductively between "+POS+" teeth, and "+
   "leads "+name+" in\nan arduous tango!\n",
   partner);
   tell_object(partner,
   NAME+" places "+POS+" rose seductively between "+POS+" teeth, "+
   "and leads you in\nan arduous tango!\n"
   );
return 1;
   }
