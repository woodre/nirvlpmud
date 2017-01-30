#include <ansi.h>

int halo;
object shadow;

void start_knight_shadow(object obj){
  if(obj->query_level() < 21){
    shadow(obj, 1);
    shadow = obj;
  }
  else destruct(this_object());
}

void end_knight_shadow(){
  destruct(this_object());
}

string short(){
  return (halo ? (HIW+"()"+NORM+" ") : "") + (string)shadow->short();
}

void add_money(int x){
  object gob;
  if(!(gob = present("knight_object", shadow))){
    shadow->add_money(x);
    end_knight_shadow();
    return;
  }
  if(x > 0 && (!this_player() || 
   (int)this_player()->query_level() < 21)) {
    int gc;
    gc = x / 10;
    if(gc){
      tell_object(shadow,
        "You tithe "+HIY+gc+NORM+" gold coins"
       +" to the Gods.\n");
      if(environment(shadow)){
        object stack;
        stack = clone_object("/obj/money");
        stack->set_money(gc);
        stack->short();
        tell_room(environment(shadow),
         (string)shadow->query_name()+" tosses "
        +lower_case((string)stack->query_descr())
        +" into the air.\nIt disappears.\n", ({shadow}));
        destruct(stack);
      }
      x -= gc;
      gob->add_donation(gc);
    }
  }
  shadow->add_money(x);
}

int knight_shadowed(){
  return 1;
}

void set_knight_halo(int x){
  halo = x;
}

int query_knight_halo(){
  return halo;
}