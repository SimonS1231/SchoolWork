(* Author:      Simon Schoelkopf
 * Instructor:  William Killian
 * Date:        9/3/2020
 * Assignment:  Lab 1 - Introduction to OCaml
 * Description: This is a compilation of functions that do various things
 *)

(* BEGIN PROVIDED FUNCTIONS *)

(* explode : string -> char list
 * (explode s) is the list of characters in the string s in the order in
 *   which they appear
 * e.g.  (explode "Hello") is ['H';'e';'l';'l';'o']
 *)

 (* This breaks a string into a list. I did not write this *)
let explode s =
        let rec _exp i =
                if i >= String.length s then [] else (s.[i])::(_exp (i+1)) in _exp 0;;

(* END PROVIDED FUNCTIONS *)


(* For ALL of the following method stubs (those with failwith "to be written"),
   add documentation comments including expected behavior *)


(* This takes in a int list and adds all of the integers together and returns the sum*)
let rec sumList l = 
        match l with
        | hd::_ -> List.hd l + sumList(List.tl l)
        | [] -> 0
;;

(*This function takes in an int and makes each digit a seperate item in a list then it returns that list*)
let rec digitsOfInt n =
        if n < 10 then [n]    
        else
        digitsOfInt (n / 10) @[n mod 10]
;;

(*This function sums each digit together repeatedly until it results in a single number. It returns the number of additions*)
let rec additivePersistence n = 
        if n < 10 then 0
        else additivePersistence(sumList(digitsOfInt(n))) + 1
        
;;

(*This function sums each digit together repeatedly until it results in a single number. It then returns that number*)
let rec digitalRoot n = 
        if n < 10 then n
        else digitalRoot(sumList(digitsOfInt(n)))
;;

(*This funchtion takes in a list and returns a reversed version of the that list*)
let rec listReverse l = 
        match List.length l with
        |1 -> [List.hd l]
        |_ -> listReverse (List.tl l) @[List.hd l];;

;;

(*this function determines if a string is a palindrome by returning a boolean expression*)
let palindrome w =
        let r = explode(w)
      in if r = listReverse(r) then true
        else false


;;
(* BEGIN PROVIDED FUNCTIONS *)

(* digits : int -> int list
 * (digits n) is the list of digits of n in the order in which they appear
 * in n
 * e.g. (digits 31243) is [3,1,2,4,3]
 *      (digits (-23422) is [2,3,4,2,2]
 *)
let digits n = digitsOfInt (abs n);;

(* END PROVIDED FUNCTIONS *)

(************** Add Testing Code Here ***************)(*

*)
