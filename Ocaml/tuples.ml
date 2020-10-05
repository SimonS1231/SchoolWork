(* Author:      Simon Schoelkopf
 * Instructor:  William Killian
 * Date:        10/1/2020
 * Assignment:  Lab 3 - Tuples and HOFs
 * Description: This is a compilation of functions with a focus on 
                tuples and high order functions
 *)
(* ***** DOCUMENT ALL FUNCTIONS YOU WRITE OR COMPLETE ***** *)

(* 'a * 'b * ('b * 'a) list -> 'a

  This function accepts a three value tuple containing a 
  default value, a key, and a list of (key, value) tuples.
  The function then searches the list for the key and returns
  the value associated if it finds it. If it does not find the key
  it treturns the default value
  hi
*)
let rec assoc (d,k,l) = 
  match l with
    | [] -> d
    | (x,y) :: tl -> 
      if x = k then y
      else assoc(d,k,List.tl l) 
;;

(* 'a list -> 'a list

  This function takes in a list and removes the duplicate entries
  using tuples
*)
let removeDuplicates l = 
  let rec helper (seen,rest) = 
      match rest with 
      | [] -> seen
      | h::t -> 
        let seen' = 
          match List.mem h seen with
            |false -> h::seen
            |true -> seen
        in
        let rest' = List.tl rest in 
	  helper (seen',rest') 
  in
      List.rev (helper ([],l))


(* ('a -> 'a * bool) * 'a -> 'a

  This function takes in another function and a value b as
  parameters and returns the result once the inner function 
  returns the (b', false) tuple
*)
let rec wwhile (f,b) =
  match f (b) with
    |(x,false) -> x
    |(x,true) -> wwhile (f,x)
  

(* ('a -> 'a) * 'a -> 'a)

  This function takes in another function and a value b
  as parameters. It then calls the wwhile function until
  f(b)=b
*)
let fixpoint (f,b) = wwhile ( 
  (fun x -> if f(x) = x then (f(x), false) else (f(x), true)),b)


(* ffor: int * int * (int -> unit) -> unit
   Applies the function f to all the integers between low and high
   inclusive; the results get thrown away.
 *)

let rec ffor (low,high,f) = 
  if low>high 
  then () 
  else let _ = f low in ffor (low+1,high,f)


  let g x = truncate (1e6 *. cos (1e-6 *. float x));;
  let h x = x * x * 1;;
