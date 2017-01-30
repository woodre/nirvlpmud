string msg;
id(str){ return str == "welt"; }
reset(arg)
{
   if(arg) return;
   call_out("ticktock",50,1);
}
drop(){ return 1; }
init_bruise(word)
{
   set_string("A big welt shows on the left cheek, it reads \"" + word + "\" in mirror writing");
}
set_string(str)
{
   msg = str;
}
extra_look()
{
   return msg;
}
ticktock(num)
{
   if(num==1)
      {
      set_string("A faded bruise shows on the left cheek");
      call_out("ticktock",100,2);
   }
   if(num==2)
      {
      set_string("A very faint bruise shows on the left cheek");
      call_out("ticktock",100,3);
   }
   else if(num == 3)
      {
      destruct(this_object());
   }
}

query_save_flag(){ return 1; }
