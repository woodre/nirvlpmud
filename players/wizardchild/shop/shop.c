inherit "room/room";
reset(arg) {
  if(arg) return ;
  set_light(1);
  short_desc = "Bubba's Body Shop";
  long_desc =
 "  This small shop is where Bubba does his work. Along one wall is his art\n"
+"collection: pictures of the tattoos he can give you cover its entire length\n"
+"and height. Opposite of that wall, pictures of Bubba's most frequent clients\n"
+"(at least that's how they appear) show Bubba's art off.\n"
+"And then, of course, there is Bubba himself.\n";
dest_dir = 
({"/room/plane12","out"});
move_object(clone_object("/players/wizardchild/shop/bubba"),this_object());
}
