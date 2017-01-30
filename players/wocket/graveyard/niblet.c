reset(x) { if(x) return;
  if(!root()) call_out("dest_me", 1);
}

dest_me() { destruct(this_object()); }
