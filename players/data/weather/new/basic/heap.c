#pragma strong_types

#include <gender.h>
#include <libs.h>

virtual inherit "basic/synonym";
inherit "basic/gender";

private nosave mixed tmp_amount;
private        mixed amount, additional_attributes;
private        string *heap_ids, *heap_element_ids, *amount_attributes;


varargs status add_amount(mixed a, string attr, status silently) {
  int i;
  string *tmp;
  if (mappingp(a)) {
    if (attr || !amount_attributes)
      raise_error("Bad argument 2 to add_amount()\n");
    tmp = m_indices(a);
    if (sizeof(tmp - amount_attributes))
      raise_error("Amount incompatible to heap\n");
    if (!amount)
      amount = ([]);
    for (i = sizeof(tmp); i--; )
      if (amount[tmp[i]] + a[tmp[i]] < 0)
        return 0;  // wasn't possible, but no error case
    for (i = sizeof(tmp); i--; )
      amount[tmp[i]] += a[tmp[i]];
  }
  else if (attr) {
    if (!intp(a))
      raise_error("Bad argument 1 to add_amount()\n");
    if (!amount_attributes ||
        (i = member(amount_attributes, attr)) < 0)
      raise_error("Attribute not found\n");
    if (!amount)
      amount = ([]);
    if (amount[amount_attributes[i]] + a < 0)
      return 0;
    amount[amount_attributes[i]] += a;
  }
  else {
    if (!intp(a) || amount + a < 0)
      return 0;
    amount += a;
  }
  return 1;
}

static mixed negate_amount(mixed amount) {
  if (intp(amount))
    return -amount;
  else if (mappingp(amount))
    return mkmapping(m_indices(amount),map(m_values(amount),#'negate));
}

varargs status subtract_amount(mixed a, string attr) {
  return add_amount(negate_amount(a),attr);
}

void set_amount(mixed a) {
  if (mappingp(a) &&
      (!amount_attributes ||
       sizeof(m_indices(a) - amount_attributes)))
    return;

  if ((intp(a) && a < 0) ||
      (mappingp(a) && sizeof(filter(m_values(a), #'<=, -1))))
    return;
  amount = a;
}

varargs mixed query_amount(status real) {
  mixed tmp;
  tmp = (real ? amount : (tmp_amount || amount));
  if (mappingp(tmp))
    return copy(tmp);
  return tmp;
}

static void clear_tmp_amount() {
  tmp_amount = 0;
}

static void set_tmp_amount(mixed a) {
  tmp_amount = a;
  if (find_call_out("clear_tmp_amount") < 0)
    call_out("clear_tmp_amount",0);
}

int query_gender() {
  int *tmp;
  if (!amount_attributes)
    if (query_amount() != 1)
      return GND_PLURAL;
    else
      return gender::query_gender();
  else {
    if (fold_left(#'+,m_values(query_amount())) != 1)
      return GND_PLURAL;
    else
      return gender::query_gender();
  }
}

private status heap_id(string str) {
  return heap_ids && member(heap_ids, str) > -1;
}

private status heap_element_id(string str) {
  return heap_element_ids && member(heap_element_ids, str) > -1;
}

string* query_heap_id() {
  return heap_ids[0..];
}

string* query_heap_element_id() {
  return heap_element_ids[0..];
}

void set_heap_id(mixed id) {
  if (stringp(id))
    heap_ids = ({ id });
  else if (pointerp(id))
    heap_ids = id;
}

void set_heap_element_id (mixed id) {
  if (stringp(id))
    heap_element_ids = ({ id });
  else if (pointerp(id))
    heap_element_ids = id;
}

void set_id(mixed id) {
  closure plural;
  plural = symbol_function("plural_word", LIB_LANGUAGE);
  if (stringp(id)) {
    heap_element_ids = ({ id });
    heap_ids = ({ funcall(plural, id) });
  }
  else if (pointerp(id)) {
    heap_element_ids = id;
    heap_ids = map(id, plural);
  }
}

private status parse_id(string str) {
  string expr, match;
  int count, i, j, k, new;
  mapping tmp;
  mixed chunks;
  if (!str || !heap_ids || !heap_element_ids)
    return 0;
  expr = "( )*("+implode(heap_ids,"|")+"|"+implode(heap_element_ids,"|")+")";
 // expr = "( |)("+implode(heap_ids,"|")+"|"+implode(heap_element_ids,"|")+")";
  chunks = regexplode(str, expr);
  if (sizeof(chunks) < 2)
    return 0;
  if (!amount_attributes) {
    if (sizeof(chunks) > 3)
      return 0;
    while (chunks[1][0] == ' ')
      chunks[1] = chunks[1][1..];
    // heap_id = ({ "heap", "grains" })  
    // heap_element_id = ({ "grain" })
    // x grain      -> ({"", "grain", ""})      -> grain desc (amount 1)
    // x 2 grain    -> ({"2", "grain", ""})     -> what?
    // x 2 grains   -> ({"2", "grains", ""})    -> grain desc (amount 2)
    // x all grain  -> ({"all", "grain", ""})   -> grain desc (amount 1)
    // x all grains -> ({"all", "grain", "s"})  -> grain desc (amount 1)
    // x heap       -> ({"", "heap", "" })      -> grain desc (amount heap)
    // x 2 heap     -> ({"2", "heap", "" })     -> grain desc (amount 1)
    // x all heap   -> ({"all", "heap", "" })   -> grain desc (amount heap)
    // x all heaps  -> ({"all", "heap", "s" })  -> grain desc (amount heap)
    switch (chunks[0]) {
    case "a":
    case "an":
      count = 1;
    case "":
    case "all":
      if (heap_id(chunks[1])) {
        if (count == 1 && strlen(chunks[2]))  // strlen, Coogan, 08-Jul-2003
          return 0;
        set_tmp_amount(amount);
        return 1;
      }
      else if (heap_element_id(chunks[1])) {
        if (chunks[1] == "all" && !strlen(chunks[2])) //strlen,Coogan,8-Jul-2003
          return 0;
        if (amount > 0) {
          set_tmp_amount(1);
          return 1;
        }
        else
          return 0;
      }
      break;  // Coogan, 08-Jul-2003
    default:
      if (sizeof(regexp(({chunks[0]}), "^[1-9][0-9]*$"))) {
        count = to_int(chunks[0]);
      }
      else if (count = LIB_PARSE->parse_numeral(chunks[0])) {
        ;
      }
      else
        return 0;
      if ((count != 1 && heap_element_id(chunks[1])) ||
          (count == 1 && heap_id(chunks[1])) ||
          (count > amount))
        return 0;
      set_tmp_amount(count);
      return 1;
    }
  }
  else { // if (amount_attributes)
    tmp = ([ ]);
    expr = "( )*(,|and|,( )*and)( )*"; 
    // expr = ",and | ,and | , and |,| ,| , | and ";
    match = "( )*("+implode(amount_attributes,"|")+")";
    // match = "( |)("+implode(amount_attributes,"|")+")";
    // x 2 pc          -> ({ "2 platinum", " coin", "" })
    // x 2 pc and 2 gc -> ({ "2 platinum", " coin", " and 2 gold", " coin", ""})
    // x all gc        -> ({ "all gold", " coin", "" }) -> long desc gc
    // x all gold coins-> ({ "all gold", " coin", "" }) -> 2 gold coins.
    if (strlen(chunks[<1]))
      return 0;
    for (i = 0; i + 1 < sizeof(chunks); i += 2) {
      chunks[i] = regexplode(chunks[i], expr);
      while (chunks[i+1][0] == ' ')
        chunks[i+1] = chunks[i+1][1..];
      for (j = (i ? 2 : 0); j < sizeof(chunks[i]); j += 2) {
        chunks[i][j] = regexplode(chunks[i][j], match);
        if (sizeof(chunks[i][j]) == 1) {  /* no attribute */
          if (sizeof(chunks[i]) != 1 || sizeof(chunks) != 3)
            return 0;
          switch (chunks[i][j][0]) {
          case "a":
          case "an":
            count = 1;
          case "":
          case "all":
            // x all money -> ({({({""})}),"coins",""})
            if (heap_element_id(chunks[i+1])) {  // x all _coin_
              if (chunks[i][j][0] == "all")
                return 0;
              for (k = 0; k < sizeof(amount_attributes); k++) {
                if (amount[amount_attributes[k]]) {
                  tmp[amount_attributes[k]] = 1;
                  break;
                }
              }
              if (k == sizeof(amount_attributes))
                return 0;
              set_tmp_amount(tmp);
              return 1;
            }
            else if (count == 1)
              return 0; /* a coins or what ? */
            set_tmp_amount(copy(amount));
            return 1;
          default:
            // x 1 coin  -> ({({({ "1" })}), "coin", "" })  -> copper long desc
            // x 1 coins -> ({({({ "1" })}), "coins", "" }) -> what?
            // x 2 coin  -> ({({({ "2" })}), "coin", "" })  -> what?
            // x 5 coins -> ({({({ "5" })}), "coins", "" }) -> 5 copper coins
            if (sizeof(regexp(({chunks[i][j][0]}), "^[1-9][0-9]*$"))) {
              count = to_int(chunks[i][j][0]);
            }
            else if (count = LIB_PARSE->parse_numeral(chunks[i][j][0])) {
              ;
            }
            else
              return 0;
            if ((count == 1 && heap_id (chunks[i+1])) ||
                (count != 1 && heap_element_id (chunks[i+1])))
              return 0;
            for (k = 0; k < sizeof(amount_attributes); k++) {
              if (amount[amount_attributes[k]] < count) {
                tmp[amount_attributes[k]] = amount[amount_attributes[k]];
                count -= amount[amount_attributes[k]];
                continue;
              }
              tmp[amount_attributes[k]] = count;
              count = 0;
              break;
            }
            if (count)     // not enough
              return 0;
            set_tmp_amount(tmp);
            return 1;
          }
        }
        if (sizeof(chunks[i][j]) != 3)
          return 0;
        while (chunks[i][j][1][0] == ' ')
          chunks[i][j][1] = chunks[i][j][1][1..];
        chunks[i][j][1] = get_synonym(chunks[i][j][1]);
        if (tmp[chunks[i][j][1]])
          return 0; /* no double expressions */
        // x 2 gc and all silver coins
        //    -> ({({({ "2", "gold",""})}),
        //         "coin",
        //         ({""," and ",({"all","silver",""})}),
        //         "coins", ""})
        switch (chunks[i][j][0]) {
        case "a":
        case "an":
          count = 1;
        case "":
        case "all":
          if (heap_element_id(chunks[i+1])) {  /* single element ? */
            if (chunks[i][j][0] == "all")
              return 0;
            if (amount[chunks[i][j][1]])
              tmp[chunks[i][j][1]] = 1;
            else
              return 0;
          }
          else if (count == 1)
            return 0;
          else
            tmp[chunks[i][j][1]] = amount[chunks[i][j][1]];
          if (!tmp[chunks[i][j][1]])
            return 0;
          break;
        default:
          if (sizeof(regexp(({chunks[i][j][0]}), "^[1-9][0-9]*$"))) {
            count = to_int(chunks[i][j][0]);
          }
          else if (count = LIB_PARSE->parse_numeral(chunks[i][j][0])) {
            ;
          }
          else
            return 0;
#if 0  /* somebody replaced that here at unknown time (Coogan, 08-Jul-2003) */
          if ((count != 1 && heap_element_id (chunks[i+1])) ||
              (count == 1 && heap_id (chunks[i+1])) ||
              (count > amount[chunks[i][j][1]]))
            return 0;
#else
          if (count > amount[chunks[i][j][1]])
            return 0;
#endif
          tmp[chunks[i][j][1]] = count;
          break;
        }
      }
    }
    set_tmp_amount(tmp);
    return 1;
  }
}

status id(string str) {
  if (parse_id(str))
    return 1;
}

varargs void set_attributes(string *attr, mixed *additional) {
  int i;
  amount_attributes = attr[0..];
  if (additional) {
    additional_attributes = additional[0..];
    for (i = sizeof (additional); i--; )
      add_synonym(additional[i],attr[i]);
  }
}

status identify_heap(string *ids, string *element_ids, string *attrs) {
  int i;
  if ((sizeof(ids) != sizeof(heap_ids)) ||
      (sizeof(element_ids) != sizeof(heap_element_ids)) ||
      (attrs && !amount_attributes) ||
      (!attrs && amount_attributes))
    return 0;
  for (i = sizeof(ids); i--; )
    if (ids[i] != heap_ids[i])
      return 0;
  for (i = sizeof(element_ids); i--; )
    if (element_ids[i] != heap_element_ids[i])
      return 0;
  if (attrs)
    for (i = sizeof(attrs); i--; )
      if (attrs[i] != amount_attributes[i])
        return 0;
  return 1;
}

private object split_heap() {
  object heap;
  mixed tmp;
  int i, sum;
  string a;
  //DEBUG_POINT("alfe",({tmp_amount,amount_attributes,amount}));
  if (!tmp_amount)
    return 0;
  if (mappingp(tmp_amount)) {
    tmp = ([]);
    for (i = sizeof(amount_attributes); i--; ) {
      a = amount_attributes[i];
      tmp[a] = amount[a] - tmp_amount[a];
      sum += tmp[a];
    }
    if (!sum)
      return 0;
  }
  else {
    tmp = amount - tmp_amount;
    if (!tmp)
      return 0;
  }
  heap = clone_object(load_name(this_object()));
  //DEBUG_POINT("alfe",({heap,this_object()}));
  heap->set_heap_id(heap_ids[0..]);
  heap->set_heap_element_id(heap_element_ids[0..]);
  if (amount_attributes)
    heap->set_attributes(amount_attributes[0..], additional_attributes);
  heap->set_amount(tmp);
  amount = (amount_attributes ? copy(tmp_amount) : tmp_amount);
  return heap;
}

void notify_destruct() {
  // I don't know if this is an ugly hack, but it should work.
  // it results in the splitting of the money according to the
  // last matched id().
  if (load_name(previous_object()) != load_name(this_object()))
    move_object(this_object(),"room/void");
}

void notify_move(object from, object to) {
  object heap, last, next;
  if (from) {
    if (heap = split_heap())
      move_object(heap, from);
  }
  if (!tmp_amount)
    set_tmp_amount(mappingp(amount) ? copy(amount) : amount);
  for (next = first_inventory(to); next; next = next_inventory(next))
    if (next != this_object() &&
        next->identify_heap(heap_ids, heap_element_ids, amount_attributes)) {
      add_amount(next->query_amount(1), 0, 1);  // added ",0" Alfe 1996-Oct-02
      destruct(next);
      break;
    }
}

